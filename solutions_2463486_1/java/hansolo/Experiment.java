package partc;



public class Experiment {

	// INPUT
	public double A;
	public double B;
	
	// INTERNAL
	private long leftBound;
	private long rightBound;
	
	// OUTPUT
	public int result;
	
	public Experiment(int a, int b) {
		// TODO Auto-generated constructor stub
		A = a;
		B = b;
		leftBound = (int) Math.ceil(Math.sqrt(A));
		rightBound = (int) Math.floor(Math.sqrt(B));
		result = 0;
	}
	
	public Experiment(long a, long b) {
		// TODO Auto-generated constructor stub
		A = a;
		B = b;
		leftBound = (long) Math.ceil(Math.sqrt(A));
		rightBound = (long) Math.floor(Math.sqrt(B));
		result = 0;
	}

	public int Solve() {
		// TODO Auto-generated method stub
		
		long elm;
		for(elm = leftBound; elm <= rightBound; elm++)
		{
			if(checkPalindrome(elm))
				if(checkPalindrome(elm*elm))
					result++;
		}
		return result;
		
	}
	
	private boolean checkPalindrome(int elm)
	{
		String digitStr = "" + elm;
		
		int i;
		float cap = digitStr.length()/2f;
		for(i=0; i<cap; i++)
			if(digitStr.charAt(i) != digitStr.charAt(digitStr.length()-i-1))
				return false;
		return true;
	}
	
	private boolean checkPalindrome(long elm)
	{
		String digitStr = "" + elm;
		
		int i;
		float cap = digitStr.length()/2f;
		for(i=0; i<cap; i++)
			if(digitStr.charAt(i) != digitStr.charAt(digitStr.length()-i-1))
				return false;
		return true;
	}
	
	
}
