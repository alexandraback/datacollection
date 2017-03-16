import java.util.*;

public class Main{
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cc = 1; cc<= T; cc++)
		{
			int A = in.nextInt();
			int B = in.nextInt();
			double[] proba = new double[A+1];
			proba[0] = 1;
			for(int i = 1; i<A+1; i++)
			{
				proba[i] = in.nextDouble();
			}
			
			double[] keep = new double[A+1];
			keep[0] = B+1;
			keep[1] = proba[1]*B + (1-proba[1])*(B+B+1);
			double probaC = proba[1];
			for(int i = 2; i<=A; i++)
			{
				probaC *= proba[i];
				keep[i] = probaC * (B-i+1) + (1-probaC)*(B-i+1+B+1);
			}
			double min = B+2;
			for(int i = 0; i<= A; i++)
			{
				if(keep[i]+ (A-i) < min)
					min = keep[i]+(A-i);
			}
			System.out.print("Case #"+cc+": ");
			System.out.format("%06f%n", min);
		}
		
	}
}