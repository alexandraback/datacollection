import java.util.*;
import java.io.*;
public class C 
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new File("C-small-2-attempt2.in"));
		
		PrintWriter out = new PrintWriter(new FileWriter("C0.out"));
		
		int T = in.nextInt();
		
		int r = in.nextInt();
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		
		out.println("Case #" + T + ":");
		
		for(int x = 0; x < r; x++)
		{
			int numsLeft = n;
			
			int[] used = new int[m + 1];
			
			for(int y = 0; y < k; y++)
			{
				long random = in.nextLong();
				
				ArrayList<Integer> currentNumbers = new ArrayList<Integer>();
				
				int[] currentUsed = Arrays.copyOf(used, used.length);
				
				for(int z = m; z >= 2; z--)
				{
					if(random % z == 0)
					{
						if(currentUsed[z] > 0)
						{
							currentUsed[z]--;
						}
						else
						{
							currentNumbers.add(z);
						}
						
						random /= z;
						z++;
					}
				}
				
				if(currentNumbers.size() == numsLeft)
				{
					for(int i = 0; i < currentNumbers.size(); i++)
					{
						out.print(currentNumbers.get(i));
					}
					numsLeft = 0;
					
					for(int i = y + 1; i < k; i++)
					{
						in.nextInt();
					}
					
					break;
				}
				else
				{
					int[] counter = new int[m + 1];
					
					for(int a = 0; a < currentNumbers.size(); a++)
					{
						if(currentNumbers.get(a) == 3 || currentNumbers.get(a) == 5 || currentNumbers.get(a) == 7)
						{
							out.print(currentNumbers.get(a));
							used[currentNumbers.get(a)]++;
							numsLeft--;
						}
						
						counter[currentNumbers.get(a)]++;
					}
					
					if(counter[2] == 1 && counter[8] == 0)
					{
						out.print("2");
						used[2]++;
						numsLeft--;
					}
				}
				
				currentNumbers.clear();
			}
			
			for(int b = 0; b < numsLeft; b++)
			{
				out.print("2");
			}
			
			out.println();
		}
		
		out.close();
	}
}
