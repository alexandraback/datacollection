import java.util.*;

class A
{
	public static void main(String [] args)
	{
		int t;
		Scanner in = new Scanner(System.in);
		t = in.nextInt();
		for(int casen = 1; casen <= t;++casen)
		{
			int numTyped, total;
			numTyped = in.nextInt();
			total = in.nextInt();
			double probs [] = new double[numTyped];
			double cumprob [] = new double[numTyped];
			for(int i=0;i<numTyped;++i)
			{
				probs[i] = in.nextDouble();
				cumprob[i] = probs[i];
				if(i-1 >= 0)
					cumprob[i] *= cumprob[i-1];
			}
			
			double min = 1 + total + 1;
			for(int i=0;i<numTyped;++i)
			{
				int backspaceamt = i;
				int letterstyped = (total - numTyped) + backspaceamt*2 + 1; //counts enter;
				int ifwrong = letterstyped + total + 1;
				double currex = letterstyped*cumprob[numTyped-1-i]+ifwrong*(1-cumprob[numTyped-1-i]);
				//System.out.println("numBK: " + i + " , currex : " + currex + ", R/W " + letterstyped+ " / " + ifwrong);
				if(currex < min)
					min = currex;
			}
			double eraseall = numTyped + total + 1; //full backspace
			if(min > eraseall)
				min = eraseall;
			
			System.out.printf("Case #%d: %.6f\n",casen,min);
			
		}
		
		
	}
}
