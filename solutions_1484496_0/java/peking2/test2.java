import java.io.*;
import java.util.*;

public class test2
{

	public static void main(String[] args) throws Exception
	{
		new test2().run();
	}

	PrintWriter out = null;
	int total = 0;
	int casenum = 0;

	boolean Match(int[] arr, int start, boolean[] visited,
			ArrayList<Integer> al, int sum)
	{
		if (sum == 0)
			return true;

		if (start == arr.length)
			return false;

		boolean ret = Match(arr, start + 1, visited, al, sum);
		if (ret)
			return ret;

		if (!visited[start])
		{
			al.add(arr[start]);
			sum -= arr[start];
			ret = Match(arr, start + 1, visited, al, sum);
			visited[start] = true;
			if (ret)
				return ret;
			visited[start] = false;
			sum += arr[start];
			al.remove(al.size() - 1);
		}

		return ret;
	}

	void Print(ArrayList<Integer> al)
	{
		for (int i : al)
			out.print(i + " ");

		out.println();
	}

	boolean Find(int[] arr, int start, boolean[] visited,
			ArrayList<Integer> al, int sum)
	{
		if (sum > total / 2)
			return false;

		ArrayList<Integer> al2 = new ArrayList<Integer>();
		if (sum > 0 && Match(arr, 0, visited, al2, sum))
		{
			out.printf("Case #%d:\n", casenum);
			Print(al);
			Print(al2);
			return true;
		}

		if (start == arr.length)
			return false;

		boolean ret = Find(arr, start + 1, visited, al, sum);
		if (ret)
			return ret;

		al.add(arr[start]);
		sum += arr[start];
		visited[start] = true;
		ret = Find(arr, start + 1, visited, al, sum);
		visited[start] = false;
		sum -= arr[start];
		al.remove(al.size() - 1);
		return ret;
	}

	void run() throws Exception
	{
		Scanner in = new Scanner(System.in);
		out = new PrintWriter(new FileWriter("gcj.txt"));

		int T = Integer.parseInt(in.nextLine());

		for (int t = 0; t < T; t++)
		{
			casenum = t + 1;
			int N = in.nextInt();
			int[] arr = new int[N];
			for (int i = 0; i < N; i++)
			{
				arr[i] = in.nextInt();
				total += arr[i];
			}

			boolean[] visited = new boolean[N];
			ArrayList<Integer> al = new ArrayList<Integer>();
			if (!Find(arr, 0, visited, al, 0))
				out.printf("Case #%d: %s\n", casenum, "Impossible");
		}

		out.close();
	}

}
