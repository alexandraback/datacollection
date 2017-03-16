import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;


public class main {

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		FileInputStream fs = new FileInputStream("in.txt");
		DataInputStream ds = new DataInputStream(fs);
		BufferedReader br = new BufferedReader(new InputStreamReader(ds));
		int n = Integer.parseInt(br.readLine()), i, j, inh;
		for(i = 0; i < n; i ++)
		{
			// Parse input
			int N = Integer.parseInt(br.readLine());
			Map<Integer, int[]> classes = new HashMap<Integer, int[]>();
			int c;
			for(c = 1; c <= N; c++)
			{
				String line[] = br.readLine().split(" ");
				int M = Integer.parseInt(line[0]);
				int[] inherits = new int[M];
				for(inh = 1; inh < line.length; inh ++)
				{
					inherits[inh-1] = Integer.parseInt(line[inh]);
				}
				classes.put(c, inherits);
			}
			// Execution
			boolean brilliant = false;
			for(c = 1; c <= N; c++)
			{
				int[] ways = new int[N+1];
				for(j = 0; j <= N; j++)ways[j] = 0;
				Stack stack = new Stack();
				Map<String, Boolean> used = new HashMap<String, Boolean>();
				stack.push(c);
				// Search next
				do{
					if(stack.empty())break;
					int[] inherits = classes.get(stack.peek());
					if(inherits.length == 0)
					{
						stack.pop();
						continue;
					}
					boolean found = false;
					for(j = 0; j < inherits.length; j++)
					{
						if(used.get(stack.peek() + "-" + inherits[j]) == null)
						{
							found = true;
							break;
						}
					}
					if(found)
					{
						used.put(stack.peek() + "-" + inherits[j], true);
						ways[inherits[j]] ++;
						stack.push(inherits[j]);
					}
					else
					{
						stack.pop();
					}
					if(stack.empty())
					{
						break;
					}
				}while(true);
				// System.out.print(c + ":");
				for(j = 1; j < ways.length; j ++)
				{
					// System.out.print(" " + j + "-" + ways[j] + ";");
					if(ways[j] >= 2)
					{
						brilliant = true;
					}
				}
				// System.out.println("");
			}
			
			// Response
			System.out.print("Case #" + (i+1)+": ");
			System.out.print(brilliant ? "Yes" : "No");
			System.out.println("");
		}
	}

}
