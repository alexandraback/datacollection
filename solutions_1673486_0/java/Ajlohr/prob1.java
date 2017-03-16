package round1;

import java.util.Scanner;

public class prob1 {
public static void main(String[] args)
{
	Scanner sc = new Scanner(System.in);
	int cases = sc.nextInt();
	sc.nextLine();
	for(int curcase = 1;curcase<=cases;curcase++)
	{
		int A = sc.nextInt();
		int B = sc.nextInt();
		float[] probs = new float[A];
		float[] runningprod = new float[A+1];
		probs[0] = sc.nextFloat();
		runningprod[0] = 1;
		for(int i=1;i<A;i++)
		{
			probs[i] = sc.nextFloat();
			runningprod[i] = probs[i-1]*runningprod[i-1];
		}
		runningprod[A] = runningprod[A-1]*probs[A-1];
		//probability that first i are correct
		float min = B+2;
		for(int i=1;i<=A;i++)
		{
			float temp =(B+A-2*i+1)*runningprod[i] + (2*B+A-2*i+2)*(1-runningprod[i]);
			if (temp < min)
				min  = temp;
		}
		sc.nextLine();
		System.out.println("Case #"+curcase+": "+min);
	}
}
}
