package codejam;

import java.util.HashSet;

public class RecycledNumbers extends Solver {

	public static void main(String...args) {
		RecycledNumbers solver = new RecycledNumbers();
//		System.out.println(solver.solve("1 9"));
//		System.out.println(solver.solve("10 40"));
//		System.out.println(solver.solve("100 500"));
//		System.out.println(solver.solve("1111 2222"));
//		System.out.println(solver.solve("1000000 2000000"));
//		solver.solveSmallOf('C', 0);
		solver.solveLargeOf('C');
	}
	
	int a, b;
	
	@Override
	public String evaluate() {
		a = in.nextInt();
		b = in.nextInt();
		
		if(a<10) return "0";
		HashSet<Signed> set = new HashSet<Signed>();
		
		for(int i=a; i<=b; i++) {
			if(set.add(new Signed(i))) {
//				System.out.println(i + " added.");
			}
		}
		
		int c = 0;
		for(Signed s: set) {
			c+=s.getAvailablePairsCount();
		}
		
		return String.valueOf(c);
	}
	
	class Signed {
		final char[] ns;
		final int sign;
		
		Signed(int n) {
			ns = String.valueOf(n).toCharArray();
			int min = Integer.MAX_VALUE;
			for(int i=0; i<ns.length; i++) {
				if(ns[0]!='0') {
					int v = Integer.parseInt(String.valueOf(ns));
					if(v<min) min = v;
				}
				shift();
			}
			sign = min;
		}
		
		private void shift() {
			char temp = ns[0];
			int i;
			for(i=0; i<ns.length-1; i++) {
				ns[i] = ns[i+1];
			}
			ns[i] = temp;
		}
		
		public int getAvailablePairsCount() {
			int size = getSize();
			size = size * (size-1) / 2;
//			System.out.println(sign + " pairs " + size);
			return size;
		}
		
		private int getSize() {
			HashSet<Integer> cases = new HashSet<Integer>();
			for(int i=0; i<ns.length; i++) {
				if(ns[0]!='0') {
					Integer value = Integer.valueOf(String.valueOf(ns));
					if(value.intValue()>=a && value.intValue()<=b)
						cases.add(value);
				}
				shift();
			}
			return cases.size();
		}
		
		@Override
		public boolean equals(Object obj) {
			if(obj instanceof Signed) {
				return ((Signed) obj).sign==sign;
			}
			return super.equals(obj);
		}

		@Override
		public int hashCode() {
			return sign;
		}
		
	}
	
	class Pair {
		final int n, m;
		Pair(int n, int m) {
			if(n>m) {
				this.n = m;
				this.m = n;
			} else {
				this.n = n;
				this.m = m;
			}
		}
		
		@Override
		public boolean equals(Object obj) {
			if(obj instanceof Pair) {
				Pair p = (Pair) obj;
				return p.n == this.n && p.m == this.m;
			} else {
				return false;
			}
		}
		
		@Override
		public int hashCode() {
			return n*m+m;
		}
	}
}
