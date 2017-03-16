import java.util.*;
import java.io.*;

public class C
{

	private static class Pair {
		String f1, f2;

		public Pair(String af, String bf) {
			f1 = af;
			f2 = bf;
		}
	}

	public static void main(String[] args) throws Exception
	{

		//Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new File("C-small-attempt2.in"));
		PrintStream out = new PrintStream(new File("C-small-attempt2.out"));
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) 
		{
			int n = in.nextInt();

			Pair[] a = new Pair[n];
			HashMap<String, Integer> m1 = new HashMap<String, Integer>(); 
			HashMap<String, Integer> m2 = new HashMap<String, Integer>(); 

			for (int j = 0; j < n; j++) {
				String f = in.next();
				String s = in.next();
				int k1 = 1;
				if (m1.containsKey(f)) {
					k1 = m1.get(f);
					k1++;
				}
				m1.put(f, k1);

				int k2 = 1;
				if (m2.containsKey(s)) {
					k2 = m2.get(s);
					k2++;
				}
				m2.put(s, k2);
				a[j] = new Pair(f, s);
			}
			
			int ans = 0;
			for (int j = 0; j < n; j++) {

				if (m1.get(a[j].f1) > 1 && m2.get(a[j].f2) > 1 ) {
					int k1 = m1.get(a[j].f1);
					k1--;
					m1.put(a[j].f1, k1);
					
					int k2 = m2.get(a[j].f2);
					k2--;
					m2.put(a[j].f2, k2);

					ans++;
				}
			}


			out.println("Case #"+i+": "+ans);
		}
		


		
	}
}