package test.bolpor.topcoding.google.jam.cjbv.y2013.r1c;

import test.bolpor.topcoding.google.jam.base.ProblemSolver;

public class A extends ProblemSolver
{
	public static void main(String[] args) throws java.io.IOException
	{
		A processor;

		processor = new A();
		processor.setFilePrefix("A-small-attempt0");
		processor.start();
	}
	
	@Override
	public String processCase(int caseNumber) throws java.io.IOException
	{
		String S = nextString();
		int n = nextInteger();
		char[] A = S.toCharArray();
		int cons = 0;
		int firstCons = -1;
		int nFact = 0;
		int matches = 0;
		for ( int i = 0; i < S.length(); i++ )
		{
			if ( isVowel(A[i]) )
			{
				cons = 0;
				firstCons = -1;
			}
			else
			{
				if ( -1 == firstCons )
					firstCons = i;
				cons++;
			}
			if ( n == cons )
			{
				nFact += firstCons + 1;
				nFact += A.length - firstCons - n;
				nFact -= matches;
				firstCons++;
				cons--;
				matches++;
			}
		}

		if ( n == cons )
		{
			nFact += firstCons + 1;
		}
		return Integer.toString(nFact);
	}
	
	boolean isVowel(char c)
	{
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
}
