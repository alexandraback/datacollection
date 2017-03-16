import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class CodeJamB
{
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		int cases = in.nextInt();
		for(int casenum = 1;casenum <= cases;casenum++)
		{
			int N = in.nextInt();
			int S = in.nextInt();
			int P = in.nextInt();
			int count = 0;
			
			for(int i=0;i<N;i++)
			{
				int curr = in.nextInt();
				if(curr==0 && P==0)
				{
					count++;
					continue;
				}
				if(curr%3 == 0 && curr!=0)
				{
					if(curr/3 >= P)
					{
						count++;
						continue;
					}
					if(curr/3+1 >= P && S>0)
					{
						S--;
						count++;
						continue;
					}
				}
				else if(curr%3 == 1)
				{
					if((curr+2)/3 >= P)
					{
						count++;
						continue;
					}
				}
				else if(curr%3 == 2)
				{
					if((curr+1)/3 >= P)
					{
						count++;
						continue;
					}
					if((curr+1)/3+1 >= P && S>0)
					{
						S--;
						count++;
						continue;
					}
				}
			}
			
			out.write("Case #" + casenum + ": "+count+"\n");
		}
		in.close();
		out.close();
	}
}