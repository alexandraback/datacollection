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
			int A = in.nextInt();
			int B = in.nextInt();
			
			double currentbest = B+2; //case 3
			double p[] = new double[A];
			double mult = 1;
			
			for(int n=0;n<A;n++)
			{
				p[n] = in.nextDouble();
				mult *= p[n];
			}
			
			if(mult*(B - A + 1) + (1-mult)*(B - A + 1 + B+1) < currentbest)
			{
				currentbest = mult*(B - A + 1) + (1-mult)*(B - A + 1 + B+1);
			}
			
			int backs = 0;
			for(int n=A-1;n>=0;n--)
			{
				backs++;
				mult/=p[n];
				if(mult*(backs + backs + B - A + 1) + (1-mult)*(backs + backs + B - A + 1 + B+1) < currentbest)
				{
					currentbest = mult*(backs + backs + B - A + 1) + (1-mult)*(backs + backs + B - A + 1 + B+1);
				}
			}
			System.out.println(currentbest);
			out.write("Case #" + casenum + ": " + currentbest + "\n");
		}
		in.close();
		out.close();
	}
}