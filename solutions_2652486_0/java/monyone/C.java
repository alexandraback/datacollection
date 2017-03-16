import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;


public class C {
	
	public static int[] dfs(final int N, final int M, int deep, int[] product, int[] array){
		if(deep < N){
			for(int i = 2; i <= M; i++){
				array[deep] = i;
				
				int[] ret = dfs(N, M, deep + 1, product, array);
				if(ret != null){
					return ret;
				}
			}
		}else{
			int count = 0;
			boolean[] check = new boolean[product.length];
			
			for(int time = 0; time < 100000; time++){
				int pro = 1;
				
				
				for(int i = 0; i < N; i++){
					if(Math.random() >= 0.5){
						pro *= array[i];
					}
				}
				
				for(int i = 0; i < product.length; i++){
					
					//System.out.println(pro + " " + product[i]);
					if(!check[i] && product[i] == pro){
						count++;
						check[i] = true;
					}
				}
			}
			
			//System.out.println(Arrays.toString(array));
			
			if(count >= product.length){
				return array;
			}else{
				return null;
			}
		}
		
		return null;
	}
	
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		
		final int T = sc.nextInt();
		
		for(int tt = 1; tt <= T; tt++){
			final int R = sc.nextInt();
			final int N = sc.nextInt();
			final int M = sc.nextInt();
			final int K = sc.nextInt();
			
			System.out.println("Case #" + tt + ":");
			
			for(int r = 0; r < R; r++){
				int[] array = new int[K];
				
				for(int i = 0; i < K; i++){
					array[i] = sc.nextInt();
				}
				
				int[] input = new int[N];
				
				input = dfs(N, M, 0, array, input);
				for(int i = 0; i < input.length; i++){
					System.out.print(input[i]);
				}
				System.out.println();
			}
			
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
