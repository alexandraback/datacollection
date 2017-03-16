import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B_CloseMatch {
	
	private static long DIFF = Integer.MAX_VALUE;
	private static String ANSWER_C;
	private static String ANSWER_J;
	
	public static void main(String[] args) {
		Reader.init();
		
		int T = Reader.nextInt();
		for(int main=0; main<T; main++) {
			DIFF = Integer.MAX_VALUE;
			
			String C = Reader.next();
			String J = Reader.next();
			
			calculateDiff(C, J, 0, 0);
			System.out.println("Case #" + (main+1) + ": " + ANSWER_C + " " + ANSWER_J);
		}
	}
	
	private static void calculateDiff(String C, String J, int idx, long currentDiff) {
		if(idx == C.length()) {
			if(Math.abs(currentDiff) < DIFF) {
				DIFF = Math.abs(currentDiff);
				ANSWER_C = C;
				ANSWER_J = J;
			}
			return;
		}
		
		currentDiff *= 10;
		
		char c = C.charAt(idx);
		char j = J.charAt(idx);
		
		if(c == '?' && j == '?') {
			// Both are not visible
			// 0 0
			calculateDiff(replace(C, idx, '0'), replace(J, idx, '0'), idx + 1, currentDiff + 0);
			// 0 1
			calculateDiff(replace(C, idx, '0'), replace(J, idx, '1'), idx + 1, currentDiff - 1);
			// 0 9
			calculateDiff(replace(C, idx, '0'), replace(J, idx, '9'), idx + 1, currentDiff - 9);
			// 1 0
			calculateDiff(replace(C, idx, '1'), replace(J, idx, '0'), idx + 1, currentDiff + 1);
			// 9 0
			calculateDiff(replace(C, idx, '9'), replace(J, idx, '0'), idx + 1, currentDiff + 9);
		} else if(c == '?' && j != '?') {
			// C is not visible
			calculateDiff(replace(C, idx, '0'), J, idx + 1, currentDiff + ('0'-j));
			
			// -1
			if(j!='0') calculateDiff(replace(C, idx, (char)(j-1)), J, idx + 1, currentDiff - 1);
			// 0
			calculateDiff(replace(C, idx, j), J, idx + 1, currentDiff);
			// +1
			if(j!='9') calculateDiff(replace(C, idx, (char)(j+1)), J, idx + 1, currentDiff + 1);

			calculateDiff(replace(C, idx, '9'), J, idx + 1, currentDiff + ('9'-j));
		} else if(c != '?' && j == '?') {
			// J is not visible
			calculateDiff(C, replace(J, idx, '0'), idx + 1, currentDiff + (c-'0'));
			
			// -1
			if(c!='0') calculateDiff(C, replace(J, idx, (char)(c-1)), idx + 1, currentDiff + 1);
			
			// 0
			calculateDiff(C, replace(J, idx, c), idx + 1, currentDiff);
			// +1
			if(c!='9') calculateDiff(C, replace(J, idx, (char)(c+1)), idx + 1, currentDiff - 1);
			
			calculateDiff(C, replace(J, idx, '9'), idx + 1, currentDiff + (c-'9'));
		} else {
			// Both are visible
			calculateDiff(C, J, idx + 1, currentDiff + (c-j));
		}
	}
	
	private static String replace(String src, int idx, char newChar) {
		StringBuilder builder = new StringBuilder(src);
		builder.setCharAt(idx, newChar);
		return builder.toString();
	}
	
	static class Reader {
		private static BufferedReader in;
		private static StringTokenizer tokenizer;
		
		public static void init() {
			in = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = new StringTokenizer("");
		}
		
		public static String next() {
			while(!tokenizer.hasMoreTokens())
				try {
					tokenizer = new StringTokenizer(in.readLine());
				} catch (IOException e) {
				}
			return tokenizer.nextToken();
		}
		
		public static int nextInt() {
			return Integer.parseInt(next());
		}
		
		public static long nextLong() {
			return Long.parseLong(next());
		}
	}
}
