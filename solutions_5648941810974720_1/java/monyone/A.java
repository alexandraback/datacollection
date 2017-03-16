import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class A {
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		final int alphabets = 26;
		
		final int T = sc.nextInt();
		for(int tt = 1; tt <= T; tt++){
			final char[] inputs = sc.next().toCharArray();
			
			int[] counts = new int[alphabets];
			for(final char c : inputs){
				counts[c - 'A']++;
			}
			
			int[] numbers = new int[10];
			numbers[0] = counts['Z' - 'A'];
			numbers[2] = counts['W' - 'A'];
			numbers[4] = counts['U' - 'A'];
			numbers[6] = counts['X' - 'A'];
			numbers[8] = counts['G' - 'A'];
			numbers[1] = counts['O' - 'A'] - numbers[0] - numbers[2] - numbers[4];
			numbers[3] = counts['H' - 'A'] - numbers[8];
			numbers[5] = counts['F' - 'A'] - numbers[4];
			numbers[7] = counts['V' - 'A'] - numbers[5];
			numbers[9] = (counts['N' - 'A'] - numbers[1] - numbers[7]) / 2;
			
			System.out.print("Case #" + tt + ": ");
			for(int i = 0; i < 10; i++){
				for(int j = 0; j < numbers[i]; j++){
					System.out.print(i);
				}
			}
			System.out.println();
		}
	}
	
	public static class Scanner implements Closeable {
		private BufferedReader br;
		private StringTokenizer tok;
 
		public Scanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}
 
		private void getLine() {
			try {
				while (!hasNext()) {
					tok = new StringTokenizer(br.readLine());
				}
			} catch (IOException e) { /* ignore */
			}
		}
 
		private boolean hasNext() {
			return tok != null && tok.hasMoreTokens();
		}
 
		public String next() {
			getLine();
			return tok.nextToken();
		}
 
		public int nextInt() {
			return Integer.parseInt(next());
		}
 
		public long nextLong() {
			return Long.parseLong(next());
		}
 
		public double nextDouble() {
			return Double.parseDouble(next());
		}
 
		public void close() {
			try {
				br.close();
			} catch (IOException e) { /* ignore */
			}
		}
	}
}
