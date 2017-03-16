import java.util.*;

class Main
{
	public static void main(String[] arg)
	{
		Scanner in = new Scanner(System.in);
		int trials = in.nextInt();
		int tt=0;
		while(tt < trials)
		{
			int fin = in.nextInt();
			int tot = in.nextInt();
			double[] probs = new double[fin];
			
			for(int i=0; i<fin; ++i)
			{
				probs[i] = in.nextDouble();
			}
			
			double ret = tot + 2;
			double prob = 1;
			for(int i=0; i<fin; ++i)
			{
				prob = prob * probs[i];
				double success = fin-i + tot-i -1;
				double fail = success + tot + 1;
				double expV = success*prob + fail*(1.0-prob);
				ret = Math.min(ret,expV);
			}
			
			System.out.println("Case #" + ++tt + ": " + ret);
		}
	}
}