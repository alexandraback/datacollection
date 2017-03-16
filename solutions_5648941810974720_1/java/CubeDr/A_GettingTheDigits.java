import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A_GettingTheDigits {

	private static final String[] DIGITS_STR = new String[] {
		"ZERO",
		"ONE",
		"TWO",
		"THREE",
		"FOUR",
		"FIVE",
		"SIX",
		"SEVEN",
		"EIGHT",
		"NINE"
	};
	private static final String	ALPHABETS = "ZERONTWHFUIVSXG";
	private static int[] alphabetCount = new int[ALPHABETS.length()];
	private static int[] digitCount = new int[10];
	
	public static void main(String[] args) {
		Reader.init();
		int T = Reader.nextInt();
		
		for(int main=0; main<T; main++) {
			init();
			countAlphabets(Reader.next().toCharArray());
			
			// count zero
			while(alphabetCount[ALPHABETS.indexOf('Z')] > 0)
				countDigit(0);

			// count two
			while(alphabetCount[ALPHABETS.indexOf('W')] > 0)
				countDigit(2);
			
			// count four
			while(alphabetCount[ALPHABETS.indexOf('U')] > 0)
				countDigit(4);

			// count three
			while(alphabetCount[ALPHABETS.indexOf('R')] > 0)
				countDigit(3);
			
			// count five
			while(alphabetCount[ALPHABETS.indexOf('F')] > 0)
				countDigit(5);
			
			// count six
			while(alphabetCount[ALPHABETS.indexOf('X')] > 0)
				countDigit(6);
			
			// count seven
			while(alphabetCount[ALPHABETS.indexOf('S')] > 0)
				countDigit(7);
			
			// count eight
			while(alphabetCount[ALPHABETS.indexOf('G')] > 0)
				countDigit(8);
			
			// count one
			while(alphabetCount[ALPHABETS.indexOf('O')] > 0)
				countDigit(1);
			
			// count nine
			while(alphabetCount[ALPHABETS.indexOf('N')] > 0)
				countDigit(9);
			
			System.out.println("Case #" + (main+1) + ": " + getAnswer());
		}
	}
	
	private static void init() {
		Arrays.fill(alphabetCount, 0);
		Arrays.fill(digitCount, 0);
	}
	
	private static void countAlphabets(char[] str) {
		for(char c : str)
			alphabetCount[ALPHABETS.indexOf(c)]++;
	}
	
	private static void countDigit(int digit) {
		digitCount[digit]++;
		reduceAlphabets(DIGITS_STR[digit]);
	}
	
	private static void reduceAlphabets(String alphabets) {
		char[] str = alphabets.toCharArray();
		
		for(char c : str)
			alphabetCount[ALPHABETS.indexOf(c)]--;
	}
	
	private static String getAnswer() {
		StringBuilder str = new StringBuilder();
		
		for(int i=0; i<10; i++)
			for(int j=0; j<digitCount[i]; j++)
				str.append(i);
		
		return str.toString();
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
