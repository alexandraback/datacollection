package gcj_2014_pr;
import java.util.*;
import java.io.*;

public class FairAndSquare {
	public boolean palindrome(long x){
		String str = Long.toString(x);
		for(int i = 0; i <= str.length()/2; i++){
			if( str.charAt(i) != str.charAt(str.length()-1-i) ){
				return false;
			}
		}
		return true;
	}
	public void solve() throws IOException {
		int t = nextInt();
		for(int i = 0; i < t; i++){
			int a = nextInt();
			int b = nextInt();
			long c = 0;
			for(int j = (int)Math.ceil(Math.sqrt(a)); j <= Math.sqrt(b); j++){
				if( palindrome(j) && palindrome((long)j*j) ){
					c++;
			//		writer.println(j + " " + (long)j*j);
				}
			}
			writer.println("Case #" + (i+1) + ": " + c);
		}
		
	}

	public static void main(String[] args) throws IOException {
		new FairAndSquare().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() throws IOException {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
}
