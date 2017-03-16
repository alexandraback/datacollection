package test.bolpor.topcoding.google.jam.cjbv.y2013.r1c;

import java.util.HashMap;

import test.bolpor.topcoding.google.jam.base.ProblemSolver;

public class C extends ProblemSolver
{
	public static void main(String[] args) throws java.io.IOException
	{
		C processor;

		processor = new C();
		processor.setFilePrefix("C-small-attempt0");
		processor.start();
	}
	
	@Override
	public String processCase(int caseNumber) throws java.io.IOException
	{
		int N = nextInteger();
		Tribe[] tribes = new Tribe[N];
		for ( int i = 0; i < N; i++ )
			tribes[i] = new Tribe(i); 

		long succ = 0;
		HashMap<Double, Integer> heights = new HashMap<Double, Integer>();
		for ( int day = 0; ; day++ )
		{
			HashMap<Double, Integer> attacks = new HashMap<Double, Integer>();
			boolean done = true;
			for ( Tribe tribe : tribes )
			{
				if ( tribe.n <= 0 )
					continue;
				done = false;
				if ( day < tribe.nextAttack )
					continue;
				boolean attacked = false;
				for ( double i = tribe.w; i <= tribe.e; i+= 0.5 )
				{
					Integer height = heights.get(i);
					if ( null == height )
						height = 0;
					if ( height < tribe.s )
					{
						Integer prev = attacks.get(i);
						if ( (null == prev) || (prev < tribe.s) )
						{
							prev = tribe.s;
						}
						attacks.put(i, prev);
						attacked = true;
						//System.err.printf("\nAttack by %d at %s in attack %d (height = %d)", tribe.i, i, tribe.n, prev);
					}
					else
					{
						//System.err.printf("\nFail by %d at %s in attack %d (height = %d)", tribe.i, i, tribe.n, height);
					}
				}

				if ( attacked ) succ++;
				tribe.n--;
				tribe.w += tribe.deltaP;
				tribe.e += tribe.deltaP;
				tribe.s += tribe.deltaS;
				tribe.nextAttack += tribe.deltaD;
			}

			if ( done )
				break;
			
			for ( Double key : attacks.keySet() )
			{
				Integer height = heights.get(key);
				Integer attack = attacks.get(key);
				if ( (null == height) || (height < attack) )
					heights.put(key, attack);
			}
		}

		return Long.toString(succ);
	}
	
	class Tribe
	{
		Tribe(int i)
		{
			this.i = i;
			d = nextInteger();
			n = nextInteger();
			w = nextInteger();
			e = nextInteger();
			s = nextInteger();
			deltaD = nextInteger();
			deltaP = nextInteger();
			deltaS = nextInteger();
			nextAttack = d;
		}
		int i;
		int d;
		int n;
		int w;
		int e;
		int s;
		int deltaD;
		int deltaP;
		int deltaS;
		int nextAttack;
	}
}
