import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class Blarge {
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens()) {
				String cad = br.readLine();
				if (cad == null)
					return null;
				tk=new StringTokenizer(cad);
			}
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public long nextLong() throws NumberFormatException, IOException{
			return Long.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	
	static class Pair implements Comparable<Pair>{
		long x, y;
		String a, b;
		public Pair(String aa, String bb) {
			a = aa;
			b = bb;
			x = Long.parseLong(a, 10);
			y = Long.parseLong(b, 10);
		}
		@Override
		public int compareTo(Pair o) {
			if (Math.abs(x - y) == Math.abs(o.x - o.y) ) {
				if (x == o.x)
					return (y < o.y)?-1:1;
				return (x < o.x)?-1:1;
			}
			long a = Math.abs(o.x - o.y);
			long b = Math.abs(x - y);
			return (b < a)?-1:1;
		}
	}
	
	static Pair best_so_far;
	
	
	static Pair fill_with(int idx, char[] aa, char[] bb, int digit1, int digit2) {
		char[] a = aa.clone();
		char[] b = bb.clone();
		for(int i = idx; i < a.length; i++) {
			if (a[i] == '?')
				a[i] = (char)(digit1 + '0');
			if (b[i] == '?')
				b[i] = (char)(digit2 + '0');
		}
		return new Pair(new String(a), new String(b));
	}
	
	
	static void smart_brute_force(int idx, char[] a, char[] b) {
		if (idx == a.length) {
			Pair c = fill_with(idx, a, b, 0, 0);
			if (best_so_far == null || c.compareTo(best_so_far) < 0)
				best_so_far = c;
			return;
		}
		if (a[idx] != '?' && b[idx] != '?') {
			if (a[idx] == b[idx])
				smart_brute_force(idx + 1, a, b);
			else {
				Pair c;
				if (a[idx] > b[idx])
					c = fill_with(idx, a, b, 0, 9);
				else
					c = fill_with(idx, a, b, 9, 0);
				if (best_so_far == null || c.compareTo(best_so_far) < 0)
					best_so_far = c;
			}
			return;
		}
		if (a[idx] == '?' && b[idx] == '?') {
			a[idx] = '0';
			b[idx] = '1';
			smart_brute_force(idx, a, b);
			a[idx] = '1';
			b[idx] = '0';
			smart_brute_force(idx, a, b);
			a[idx] = '0';
			b[idx] = '0';
			smart_brute_force(idx, a, b);
		}
		else {
			if (a[idx] == '?') {
				if (b[idx] > '0') {
					a[idx] = (char)(b[idx] - 1);
					smart_brute_force(idx, a, b);
				}
				if (b[idx] < '9') {
					a[idx] = (char)(b[idx] + 1);
					smart_brute_force(idx, a, b);
				}
				a[idx] = b[idx];
				smart_brute_force(idx, a, b);
			}
			else {
				if (a[idx] > '0') {
					b[idx] = (char)(a[idx] - 1);
					smart_brute_force(idx, a, b);
				}
				if (a[idx] < '9') {
					b[idx] = (char)(a[idx] + 1);
					smart_brute_force(idx, a, b);
				}
				b[idx] = a[idx];
				smart_brute_force(idx, a, b);
			}
		}
	}
	
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++) {
			String a = sc.next();
			String b = sc.next();
			best_so_far = null;
			smart_brute_force(0, a.toCharArray(), b.toCharArray());
			System.out.printf("Case #%d: %s %s\n", c, best_so_far.a, best_so_far.b);
		}
	}

}
