import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
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
			int N = in.nextInt();
			int arr[] = new int[N];

			for(int n = 0;n < N;n++)
			{
				arr[n] = in.nextInt();
			}

			HashMap<Integer,String> map = new HashMap<Integer,String>();

			int s = 0;
			String ss = "";
			boolean imp = true;
			
			for(int a = 1;;a++)
			{
				s = 0;
				ss = "";
				for(int n = 0;n<N;n++)
				{
					if(((1<<n) & a) != 0)
					{
						s += arr[n];
						ss += arr[n] + " ";
					}
				}
				if(map.containsKey(s))
				{
					imp = false;
					break;
				}
				map.put(s,ss);

			}

			if(!imp)
			{
				out.write("Case #" + casenum + ":\n" + map.get(s) + "\n" + ss + "\n");
			}
			else
			{
				out.write("Case #" + casenum + ":\n" + "Impossible\n");
			}
		}
		in.close();
		out.close();
	}
}