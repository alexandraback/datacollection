import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class A {
	
	int n;
	int[] ms;
	Map<Pair, Integer> mem;
	
	private class Pair {
		public final Integer a;
		public final Integer i;
		
		public Pair(Integer a, Integer i) {
			super();
			this.a = a;
			this.i = i;
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + ((a == null) ? 0 : a.hashCode());
			result = prime * result + ((i == null) ? 0 : i.hashCode());
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (a == null) {
				if (other.a != null)
					return false;
			} else if (!a.equals(other.a))
				return false;
			if (i == null) {
				if (other.i != null)
					return false;
			} else if (!i.equals(other.i))
				return false;
			return true;
		}
		private A getOuterType() {
			return A.this;
		}
		
		
	}
	
	public int solve(Scanner sc) {
		

		int a =  sc.nextInt();
		n = sc.nextInt();
		ms = new int[n];
		for (int i = 0; i < n; i++) {
			ms[i] = sc.nextInt();
		}
		Arrays.sort(ms);
		mem = new HashMap<Pair, Integer>();		
		return sol(a, 0);
	}
	
	public int sol(int a, int i) {
		if (i == n-1) {
			if (a > ms[i]) {
				return 0;
			} else {
				return 1;
			}
		}
		Pair p = new Pair(a, i);
		if (mem.containsKey(p)) {
			return mem.get(p);
		}
		if (a > ms[i]) {			
			int tmp = sol(a + ms[i], i+1);
			mem.put(p, tmp);
			return tmp;
		}
		// remove the current mote
		int ret = 1 + sol(a, i+1);
		// or add a new one, largest we can eat (if we are > 1)
		if (a > 1) {
			ret = Math.min(ret, 1 + sol(a + a - 1, i));
		}
		mem.put(p, ret);
		return ret;		
	}
	 

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int iT = 1; iT <= T; iT++) {
			int res = new A().solve(sc);
			System.out.println("Case #" + iT + ": " + res);
		}
		
	}
}
