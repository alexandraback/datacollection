package codejam.y2013.r1a;
import java.io.IOException;
import java.util.ArrayList;

import codejam.base.ProblemSolver;

public class B extends ProblemSolver {

	public static void main(String[] args) throws java.io.IOException
	{
		B processor;

		processor = new B();
		processor.setFilePrefix("B-small");
		processor.start();
	}
	
	@Override
	public String processCase(int caseNumber) throws IOException {
		int e = nextInteger();
		int r = nextInteger();
		int n = nextInteger();
		int[] c = nextIntegers(n);
		
		int[] sorted = c.clone();
		java.util.Arrays.sort(sorted);
		ArrayList<Integer> t = new ArrayList<Integer>();
		long prev = -1;
		for ( int i = sorted.length - 1; i >= 0; i-- )
			if ( sorted[i] != prev )
			{
				t.add(sorted[i]);
				prev = sorted[i];
			}
		
		int[] ranks = new int[100000000];
		for ( int i = 0; i < t.size(); i++ )
			ranks[t.get(i)] = i + 1;
		
		int[] ranked = new int[n];
		
		for ( int i = 0; i < ranked.length; i++ )
			ranked[i] = ranks[c[i]];
		
		int[] spent = new int[n];
		for ( int i = 0; i < spent.length; i++ )
			spent[i] = -1;
		
		for ( int i = 1; i <= t.size(); i++ )
		{
			for ( int j = 0; j < spent.length; j++ )
			{
				if ( ranked[j] == i && spent[j] == -1 )
					spent[j] = maxSpent(spent, j, e, r);
			}
		}
		
		dumper.dump(spent);
		int ans = 0;
		for ( int i = 0; i < spent.length; i++ )
			ans += c[i] * spent[i];
		return Integer.toString(ans);
	}
	
	int maxSpent(int[] spent, int x, int e, int r)
	{
		int e1 = e;
		int togo = 0;
		for ( int i = 0; i < x; i++ )
			if ( spent[i] > -1 )
			{
				e1 = e1 - spent[i];
				e1 = e1 + r;
				e1 = Math.min(e1, e);
			}
		int togain = 0;
		int gainable = r;
		for ( int i = x + 1; i < spent.length; i++ )
		{
			if ( spent[i] > -1 )
			{
				gainable = gainable + togo * r;
				togain = spent[i] - e1;
				
				e1 = gainable - togain;
				break;
			}
			else
				togo += 1;
		}
		e1 = Math.min(e1, e);
		return Math.max(e1, 0);
	}
}
