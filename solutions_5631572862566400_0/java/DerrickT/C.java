import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C
{
	static String FILE_IN = "C-small-attempt3.in";
	static String FILE_OUT = "C.out";
	static Node[] nodes;

	static String solve(BufferedReader in) throws IOException
	{
		int N = Integer.parseInt(in.readLine());
		nodes = new Node[N];

		StringTokenizer st = new StringTokenizer(in.readLine());
		int next;

		for (int i = 0; i < N; i++)
			nodes[i] = new Node(i);

		for (int i = 0; i < N; i++)
		{
			next = Integer.parseInt(st.nextToken()) - 1;
			nodes[i].to = nodes[next];
		}

		for (int i = 0; i < N; i++)
			genList(i);

		int max = 0;

		for (int i = 0; i < N; i++)
		{
			Node cur = nodes[i];
			ArrayList<Integer> list = cur.list;
			int len = list.size();

			int first = list.get(0);
			int last = list.get(len - 1);
			int secondLast = list.get(len - 2);

			if (nodes[last].to.n == first)
			{
				int add = 0;

				max = Math.max(max, len + add);
			}
			else
			{
				int add = 0;

				for (int a = 0; a < N; a++)
					if (a != last)
					{
						ArrayList<Integer> l = nodes[a].list;
						int index = l.subList(1, l.size()).indexOf(last) + 1;
						if (index != 0)
						{
							boolean works = true;
							for (int j = index - 1; works && j >= 0; j--)
								if (list.contains(l.get(j)))
									works = false;

							if (works)
								add = Math.max(add, index);
						}
					}

				if(add == 0)
				{
					if(nodes[last].to.n == secondLast)
						max = Math.max(max, len);
				}
				else
					max = Math.max(max, len + add);
			}
		}

		return String.format("%d", max);
	}

	static void genList(int start)
	{
		ArrayList<Integer> visited = new ArrayList<Integer>();
		visited.add(start);

		int next;
		Node cur = nodes[start];

		boolean done = false;
		while (!done)
		{
			if (cur.to instanceof Node)
			{
				next = cur.to.n;

				if (!visited.contains(next))
				{
					visited.add(next);
					cur = nodes[next];
				}
				else
					done = true;
			}
			else
				done = true;
		}

		nodes[start].list = visited;
	}

	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader
				(new FileReader("files/" + FILE_IN));
		PrintWriter out = new PrintWriter(new BufferedWriter
				(new FileWriter("files/" + FILE_OUT)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++)
		{
			String result = solve(in);
			System.out.printf("Case #%d: %s%n", t, result);
			out.printf("Case #%d: %s%n", t, result);
		}

		System.out.println("Complete");
		in.close();
		out.close();
	}
}

class Node
{
	int n;
	Node to;
	ArrayList<Integer> list;

	public Node(int n)
	{
		this.n = n;
	}
}
