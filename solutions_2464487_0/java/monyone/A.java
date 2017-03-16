import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;


public class A {
	
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		
		final int T = sc.nextInt();
		
		for(int tt = 1; tt <= T; tt++){
			final long r = sc.nextLong();
			final long t = sc.nextLong();
			
			long limit = t;
			long cur_r = r;
			
			long count = 0;
			
			//System.out.println(2 * cur_r + 1 + " " + limit);
			while((2 * cur_r + 1) <= limit){
				limit -= (2 * cur_r + 1);
				cur_r += 2;
				count++;
			}
			
			System.out.println("Case #" + tt + ": " + count);
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
