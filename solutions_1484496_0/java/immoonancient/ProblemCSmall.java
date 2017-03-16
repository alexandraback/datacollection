import java.util.*;
import java.io.*;

public class ProblemCSmall {

	static void printSet(int s, int[] a, PrintStream cout)
	{
		boolean first = true;
		for (int i=0; i<a.length; i++)
			if ((s & (1<<i)) != 0)
			{
				if (!first)
					cout.print(" ");
				cout.print(a[i]);
				first = false;
			}
		cout.println();
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner cin = new Scanner(new File("C.in"));
		PrintStream cout = new PrintStream("C.out");
		int caseN = cin.nextInt();
		for (int caseI=1; caseI<=caseN; caseI++)
		{
			int n = cin.nextInt();
			int[] a = new int[n];
			for (int i=0; i<n; i++)
				a[i] = cin.nextInt();
			cout.println("Case #" + caseI + ": ");
			Map<Integer, Set<Integer>> table = new HashMap<Integer, Set<Integer> >();
			boolean ans = false;
			for (int s=1; s<(1 << n); s++)
			{
				int sum = 0;
				for (int i=0; i<n; i++)
					if ((s & (1<<i)) != 0)
						sum += a[i];
				if (!table.containsKey(sum))
					table.put(sum, new HashSet<Integer>());
				Set<Integer> sets = table.get(sum);
				sets.add(s);
				for (Integer s1 : sets)
				{
					for (Integer s2 : sets)
						if ((s1 & s2) == 0)
						{
							printSet(s1, a, cout);
							printSet(s2, a, cout);
							ans = true;
							break;
						}
					if (ans)
						break;
				}
				if (ans)
					break;
			}
			if (!ans) cout.println("Impossible");
		}
	}

}
