import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class FairAndSquare {
	public static void main(String[] args) throws IOException {
		
		int n = 14;
		BigInteger bigI = BigInteger.ONE;
		BigInteger bigMax = BigInteger.valueOf(10).pow(n/2);
		BigInteger big1 = BigInteger.ONE;
		
		ArrayList<BigInteger> list = new ArrayList<BigInteger>();
		
		while (!bigI.equals(bigMax)) {
			
			if (palindrome(bigI)) {
				BigInteger bigSqr = bigI.multiply(bigI);
				if (palindrome(bigSqr)) {
					System.out.println(bigSqr.toString());
					list.add(bigSqr);
				}
			}
			
			bigI = bigI.add(big1);
		}

		String name = "C-large-1";
		String path = "C:\\Users\\dbu\\Downloads\\";
		
		String text = TextReader.read(path + name + ".in");
		
		PrintStream out = new PrintStream(new File(path + name + ".out"));
		
		StringTokenizer tokenizer = new StringTokenizer(text);
		
		int T = Integer.parseInt(tokenizer.nextToken());
		System.out.println(T);
		System.out.println("======");
		for (int t = 0; t < T; t += 1) {
		
			String A = tokenizer.nextToken();
			String B = tokenizer.nextToken();
			System.out.println(A + " " + B);
			
			BigInteger bigA = new BigInteger(A);
			BigInteger bigB = new BigInteger(B);
			
			int cnt = 0;
			for (BigInteger big : list) {
				int compA = big.compareTo(bigA);
				int compB = big.compareTo(bigB);
				if (compA == 0 || compB == 0 || compA == 1 && compB == -1) {
					cnt += 1;
				}
			}
			
			String result = "Case #"+(t+1)+": "+cnt;
			System.out.println(result);
			out.println(result);	
		}
		
		out.close();
	}
	
	static boolean palindrome(BigInteger big) {
		String str = big.toString();		
		int length = str.length();
		boolean ok = true;
		for (int i = 0; i < length/2; i++)
			ok = ok && (str.charAt(i) == str.charAt(length - i -1));
		return ok;
	}
}
