import java.util.Arrays;
import java.util.Scanner;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new A();
	}
	
	public A()
	{
		Scanner sc = new Scanner(System.in);
		
		int testCases = sc.nextInt();
		
		for(int testCase = 1; testCase <= testCases; ++testCase)
		{
			int participants = sc.nextInt();
			
			double[] scores = new double[participants];
			int[] sorted = new int[participants];
			
			double sum = 0;
			
			for(int i = 0; i < participants; ++i)
			{
				
				sorted[i] = sc.nextInt();
				scores[i] = sorted[i];
				
				sum += scores[i];
			}
			
			double average = (sum / participants) * 2;
			
			int part = participants;
			double sum2 = 0;
			for(int i = 0; i < participants; ++i)
			{
				if(average <= scores[i])
					part--;
				else
					sum2 += scores[i];
			}
			
			System.out.printf("Case #%d: ", testCase);
			//System.out.printf("\nAvg = %f Sum = %f\n", average, sum);
			
			if(part < participants)
				average = (sum2 + sum) / part;
			
			for(int i = 0; i < participants; ++i)
			{
				double pct = 0;
				
				if(average > scores[i])
				{
					double diff = average - scores[i];
					
					pct = (diff * 100 / sum);
				}
				
				/*
				long app = (long)(pct * 1000);
				
				if(scores[i] + app*sum/100000 < average)
				{
					System.out.print("Ouch ");
					pct += 0.000001;
				}
				*/
				
				//System.out.printf("%f ", scores[i]);
				System.out.printf("%f", pct);
				//System.out.printf(" %f\n", scores[i] + pct*sum/100);
				
				if(i + 1 < participants)
					System.out.print(" ");
			}
			
			System.out.println();
			
		}
			
	}

}
