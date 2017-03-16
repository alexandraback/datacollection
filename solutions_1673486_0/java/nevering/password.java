import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class Solution {
	
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		int size = s.nextInt();
		s.nextLine();
		
		for (int count = 1; count <= size; count++){
		double result;
		int A = s.nextInt();
		int B = s.nextInt();
		
		double[] p = new double[A];
		double[] pAllCorrect = new double[A+1];
		for (int i = 0; i < A; i++)
		{
			p[i] = s.nextDouble();
			if (i == 0) pAllCorrect[i] = p[i];
			else        pAllCorrect[i] = pAllCorrect[i-1] * p[i];
			//pAllCorrect[i] *= p[i];
		}
		
	
		
//		for (int i = 0; i < A; i++)
//		{
//			System.out.println("all" + pAllCorrect[i]);
//		}
		
		//double expKeppTyping = pAllCorrect[A-1] * (B - A + 1) + (2*B - A + 1) * (1-pAllCorrect[A-1]);
		double expEnterNow = 2 + B;
		double[] expBackTyping = new double[A];
		double min  = Double.MAX_VALUE;
		for (int i = 0; i < A; i++)
		{
			expBackTyping[i] = i * 2 + pAllCorrect[A-1-i] * (B - A + 1 ) + (2 * B - A + 2) * (1 - pAllCorrect[A-1-i] );
			if (min > expBackTyping[i]) 
				{min = expBackTyping[i];
				}
			//System.out.println("back" + i+" min "+min);
		}
		
		double allBack = A+B+1;
		//System.out.println("back" + A+" min "+allBack);
		result = Math.min(expEnterNow, min);
		result = Math.min(allBack, result);
		

		System.out.println("Case #" + count+ ": " + result);	
		}
		
		
		
	}

}
