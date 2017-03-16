import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Square {

	public static boolean isPalindrome(String s){
		for(int i=0; i<(s.length()+1)/2; i++){
			if(s.charAt(i)!=s.charAt(s.length()-i-1)){
				return false;
			}
		}
		return true;
	}
	
	public static boolean isSquare(long x){
		return Math.abs(Math.round(Math.sqrt(x)) - Math.sqrt(x))<1e-10;
	}
	
	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);

		ArrayList<Long> p = new ArrayList<Long>();
		
		for(long i=1;; i++){
			long sq = i*i;
			if (sq>100000000000000L)break;
			if(isPalindrome(""+i) && isPalindrome(""+sq)){
				p.add(sq);
			}
		}
		
		int cases = sc.nextInt();
		
		for(int c = 0; c<cases; c++){
			

			
			long a = sc.nextLong();
			long b = sc.nextLong();
			
			int count = 0;
			
			for(int i=0; i<p.size(); i++){
				if(p.get(i)>=a && p.get(i)<=b){
					count++;
				}
			}
					
			System.out.printf("Case #%d: %d\n", c+1,count);
		}
		
	}

	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
		
		double nextDouble(){
			return Double.parseDouble(next());
		}
	}
}
