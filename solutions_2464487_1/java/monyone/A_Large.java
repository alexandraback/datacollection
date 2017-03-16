import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;


public class A_Large {
	
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		
		final int T = sc.nextInt();
		
		for(int tt = 1; tt <= T; tt++){
			final long r = sc.nextLong();
			final long t = sc.nextLong();
			
			long count = (t + 4) / (2 * r + 5);
			
			long high = Integer.MAX_VALUE / 2;
			long low = 0;
			
			while(high - low != 1){
				long mid = (high + low) / 2;
				
				long limit = 2 * mid;
				
				//System.out.println(low + " " + high + " : " + mid + " " + limit + " " + t);
				
				if(limit > ((t / mid) - (2 * r - 1))){
					high = mid;
				}else if(limit < (t / mid) - (2 * r - 1)){
					low = mid;
				}else{
					low = mid;
					break;
				}
			}
			
			count = low;
			
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
