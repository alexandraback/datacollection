import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
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
			int arr[]=new int[N];
			int sum = 0;
			for(int n=0;n<N;n++)
			{
				arr[n] = in.nextInt();
				sum += arr[n];
			}
			
			double fin = (sum*1.0/N)*2;
			
			int a = N;
			
			int sum2=0;
			for(int n=0;n<N;n++)
			{
				if(arr[n] > fin)
				{
					a--;
					continue;
				}
				sum2 += arr[n];
			}
			fin = (sum*1.0/a)*(1+sum2*1.0/sum);
			
			out.write("Case #" + casenum + ": ");
			
			for(int n=0;n<N;n++)
			{
				if(fin < arr[n])
					out.write(0.0 + " ");
				else
					out.write(((fin-arr[n])*1.0/sum)*100 + " ");
			}
			out.write("\n");
		}
		in.close();
		out.close();
	}
}