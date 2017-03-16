package codejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;

public class ProblemA
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("in.txt"));
		PrintStream out = new PrintStream("out.txt");
//		out = System.out;
		
		int T = Integer.parseInt(in.readLine());
		
		for (int t = 0; t < T; t++)
		{
			String[] tok = in.readLine().split(" ");
			int A = Integer.parseInt(tok[0]);
			int B = Integer.parseInt(tok[1]);
			tok = in.readLine().split(" ");
			double[] p = new double[A];
			for (int i = 0; i < p.length; i++) p[i] = Double.parseDouble(tok[i]);
			double ans = B + 2;
			double pRight = 1;
			for(int i = 0; i < A; i++)
			{
				pRight *= p[i];
				double strokesRight = ((A-i-1)+(B-i-1)+1)*pRight;
				double strokesWrong = ((A-i-1)+(B-i-1)+1+B+1)*(1-pRight);
				if (strokesRight + strokesWrong < ans)
				{
					ans = strokesRight + strokesWrong;
				}
			}
			out.printf("Case #%d: %.6f\n", t+1, ans);
		}
		out.close();
	}
}
