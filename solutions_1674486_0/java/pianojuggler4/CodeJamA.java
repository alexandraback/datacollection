import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class CodeJamA
{
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		int cases = in.nextInt();

		for(int casenum = 1;casenum <= cases;casenum++)
		{
			int N = in.nextInt();
			HashMap<Integer,ArrayList<Integer>> map = new HashMap<Integer,ArrayList<Integer>>();
			HashMap<Integer,ArrayList<Integer>> map2 = new HashMap<Integer,ArrayList<Integer>>();
			for(int n = 1;n < N + 1;n++)
			{
				int M = in.nextInt();
				if(M != 0)
				{
					map.put(n,new ArrayList<Integer>());
					map2.put(n,new ArrayList<Integer>());
				}
				for(int m = 0;m < M;m++)
				{
					int X = in.nextInt();
					map.get(n).add(X);
					map2.get(n).add(X);
				}
			}

			boolean yes = false;
			
			loop: for(int n = 1;n < N + 1;n++)
			{
				if(map.containsKey(n))
				{
					ArrayList<Integer> ll = (ArrayList<Integer>)(map.get(n).clone());
					for(int m:ll)
					{
						ArrayList<Integer> list = new ArrayList<Integer>();
						list = recur(list,map,n,m);
						for(int i:list)
						{
							if(map2.get(n).contains(i))
							{
								System.out.println(n+" "+i);
								yes = true;
								//break loop;
							}
							map2.get(n).add(i);
						}
					}
				}
			}

			for(int n = 1;n <= N;n++)
			{
				System.out.println(n + ": ");
				if(map.containsKey(n))
				{
					for(int m:map.get(n))
					{
						System.out.print(m + " ");
					}
					System.out.print("\n");
				}
			}

			if(yes)
				out.write("Case #" + casenum + ": " + "Yes" + "\n");
			else
				out.write("Case #" + casenum + ": " + "No" + "\n");
		}
		in.close();
		out.close();
	}

	public static ArrayList<Integer> recur(ArrayList<Integer> list,HashMap<Integer,ArrayList<Integer>> map,int M,int X)
	{
		if(!map.containsKey(X))
		{
			return list;
		}
		list.addAll(map.get(X));
		for(int n:map.get(X))
		{
			//list.add(n);
			list = recur(list,map,M,n);
		}
		return list;
	}
}