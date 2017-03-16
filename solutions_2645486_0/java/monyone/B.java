import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;


public class B {
	
	public static long dfs(final int E, final int R, final int N, int cur_ene, int deep, int[] array){
		if(deep >= N){
			return 0L;
		}
		
		long max = Long.MIN_VALUE;
		for(int use = cur_ene; use >= 0; use--){
			long ret = dfs(E, R, N, Math.min(E, cur_ene - use + R), deep + 1, array) + array[deep] * use;
			
			max = Math.max(max, ret);
		}
		
		return max;
	}
	
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		
		final int T = sc.nextInt();
		
		for(int tt = 1; tt <= T; tt++){
			final int E = sc.nextInt();
			final int R = sc.nextInt();
			final int N = sc.nextInt();
			
			int[] jams = new int[N];
			for(int i = 0; i < N; i++){
				jams[i] = sc.nextInt();
			}
			
			long amount = 0;
			int cur_energy = E;
			
			for(int i = 0; i < N; i++){
				amount += cur_energy * jams[i];
				cur_energy = Math.min(E, R);
			}
			
			System.out.println("Case #" + tt + ": " + dfs(E, R, N, E, 0, jams));
		}
		
		
	}
	
	public static class Scanner {
		
		private BufferedReader br;
		private StringTokenizer tok;
		
		public Scanner(InputStream is) throws IOException{
			br = new BufferedReader(new InputStreamReader(is));
			getLine();
		}
		
		private void getLine() throws IOException{
			while(tok == null || !tok.hasMoreTokens()){
				tok = new StringTokenizer(br.readLine());
			}
		}
		
		private boolean hasNext(){
			return tok.hasMoreTokens();
		}
		
		public String next() throws IOException{
			if(hasNext()){
				return tok.nextToken();
			}else{
				getLine();
				return tok.nextToken();
			}
		}
		
		public int nextInt() throws IOException{
			if(hasNext()){
				return Integer.parseInt(tok.nextToken());
			}else{
				getLine();
				return Integer.parseInt(tok.nextToken());
			}
		}
		
		public long nextLong() throws IOException{
			if(hasNext()){
				return Long.parseLong(tok.nextToken());
			}else{
				getLine();
				return Long.parseLong(tok.nextToken());
			}
		}
		
		public double nextDouble() throws IOException{
			if(hasNext()){
				return Double.parseDouble(tok.nextToken());
			}else{
				getLine();
				return Double.parseDouble(tok.nextToken());
			}
		}
	}
}
