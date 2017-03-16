import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;


public class C {
	
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
	
	
	static class Topic {
		String a, b;
		public Topic(String aa, String bb) {
			a = aa;
			b = bb; 
		}
	}
	
	static int N;
	static Topic[] array;
	static Integer[] dp;
	
	
	static int dp(int mask) {
		if (dp[mask] != null)
			return dp[mask];
		HashSet<String> first = new HashSet<String>();
		HashSet<String> second = new HashSet<String>();
		for(int i = 0; i < N; i++) {
			int tmp = mask >> i;
			if ((tmp & 1) == 1) {
				first.add(array[i].a);
				second.add(array[i].b);
			}
		}
		int max = 0;
		for(int i = 0; i < N; i++) {
			int tmp = mask >> i;
			if ((tmp & 1) == 0) {
				int current = 0;
				boolean a = first.contains(array[i].a) && second.contains(array[i].b);
				if (a)
					current++;
				int nmask = mask | (1<<i);
				max = Math.max(max, current + dp(nmask));
			}
		}
		dp[mask] = max;
		return max;
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++) {
			N = sc.nextInt();
			array = new Topic[N];
			for(int i = 0; i < N; i++)
				array[i] = new Topic(sc.next(), sc.next());
			dp = new Integer[1<<N];
			System.out.printf("Case #%d: %d\n", c, dp(0));
		}
	}

}
