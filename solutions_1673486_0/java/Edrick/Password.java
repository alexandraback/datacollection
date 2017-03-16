import java.util.*;

class Password
{

	static int typed;
	static int length;
	static double[] chance;

	public static double solve()
	{
		double minimum;
		double dummy;
		double real;
		double wrong = length+1;
		double result;
		int i;
		int j;
		dummy=1;
		for (i=0; i<typed; i++)
			dummy=dummy*chance[i];
		real = length-typed+1;
		minimum = dummy*(real) + (1-dummy) * (real+wrong);

		j = typed-1;
		for (i=1; i<=typed; i++)
		{
			dummy=dummy/chance[j];
			real = 2*i+length-typed+1;
			result = dummy*real+(1-dummy)*(real+wrong);
			minimum = Math.min(minimum,result);
			j--;
		}

		minimum = Math.min(minimum, length+2);

		return minimum;
	}


	public static void main(String[] args)
	{
		Scanner myInput = new Scanner(System.in);
		int caseNumber;
		int caseCurrent;
		caseNumber = myInput.nextInt();
		for (caseCurrent=1; caseCurrent<=caseNumber; caseCurrent++)
		{
			int i;
			chance = new double [99999];
			typed=myInput.nextInt();
			length=myInput.nextInt();
			for (i=0; i<typed; i++)
			{
				chance[i] = myInput.nextDouble();
			}
			System.out.printf("Case #%d: %.6f\n",caseCurrent,solve());
		}
	}

}
