import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class B {
	
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
		int x, y;
		String a, b;
		public Pair(int xx, int yy) {
			x = xx;
			y = yy;
		}
		@Override
		public int compareTo(Pair o) {
			if (Math.abs(x - y) == Math.abs(o.x - o.y) ) {
				if (x == o.x)
					return y - o.y;
				return x - o.x;
			}
			return Math.abs(x - y) - Math.abs(o.x - o.y);
		}
	}
	
	
	static void generate(char[] a, int idx, LinkedList<String> ans) {
		if (idx == a.length) {
			ans.add(new String(a));
			return;
		}
		if (a[idx] != '?') {
			generate(a, idx + 1, ans);
			return;
		}
		for(int i = 0; i < 10; i++) {
			a[idx] = (char)(i + '0');
			generate(a, idx + 1, ans);
		}
		a[idx] = '?';
		return;
	}
	
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++) {
			String a = sc.next();
			String b = sc.next();
			LinkedList<String> f = new LinkedList<String>();
			LinkedList<String> s = new LinkedList<String>();
			generate(a.toCharArray(), 0, f);
			generate(b.toCharArray(), 0, s);
			//System.out.println(f.size());
			//System.out.println(s.size());
			LinkedList<Pair> ans = new LinkedList<Pair>();
			for(String uno: f) {
				for(String dos: s) {
					Pair n = new Pair(Integer.valueOf(uno), Integer.valueOf(dos));
					n.a = uno;
					n.b = dos;
					ans.add(n);
				}
			}
			Collections.sort(ans);
			System.out.printf("Case #%d: %s %s\n", c, ans.get(0).a, ans.get(0).b);
		}
	}

}
