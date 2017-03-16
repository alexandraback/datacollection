import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class CodeJamC
{
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		int cases = in.nextInt();
		for(int casenum = 1;casenum <= cases;casenum++)
		{
			int a = in.nextInt();
			int b = in.nextInt();
			int count = 0;
			HashMap<Integer,ArrayList<Integer>> map = new HashMap<Integer,ArrayList<Integer>>();
			
			int len = ("" + a).length();

			for(int n = a;n <= b;n++)
			{
				int t = n;
				for(int i = 0;i<len-1;i++)
				{
					t = (t%10)*(int)(Math.pow(10,len-1)) + t/10;
					if(t > n && t <= b)
					{
						if(map.containsKey(n))
						{
							if(!map.get(n).contains(t))
							{
								count++;
								map.get(n).add(t);
							}
						}
						else
						{
							ArrayList<Integer> arr = new ArrayList<Integer>();
							arr.add(t);
							map.put(n,arr);
							count++;
						}
					}
				}
			}

			out.write("Case #" + casenum + ": " + count + "\n");
		}
		in.close();
		out.close();
	}
}