package test.bolpor.topcoding.google.jam.cjbv.y2013.r1b;

import java.util.Arrays;

import test.bolpor.topcoding.google.jam.base.ProblemSolver;

public class A extends ProblemSolver
{
	public static void main(String[] args) throws java.io.IOException
	{
		A processor;

		processor = new A();
		processor.setFilePrefix("A-large");
		processor.start();
	}
	
	@Override
	public String processCase(int caseNumber) throws java.io.IOException
	{
		int A = nextInteger();
		int N = nextInteger();
		int[] motes = nextIntegers(N);
		Arrays.sort(motes);
		
		return Integer.toString(process(A, 0, motes));
	}
	
	public int process(long size, int i, int[] motes)
	{
		if ( i >= motes.length ) return 0;
		if ( motes[i] >= size )
		{
			int ins = 0;
			int rem = process(size, i + 1, motes) + 1;
			if ( 1 == size )
			{
				ins = rem;
			}
			else
			{
				while ( size <= motes[i] )
				{
					size += size - 1;
					ins++;
				}
				ins = process(size + motes[i], i + 1, motes) + ins;
			}
			return ( rem < ins ) ? rem : ins; 
		}
		else
		{
			return process(size + motes[i], i + 1, motes);
		}
	}
}
