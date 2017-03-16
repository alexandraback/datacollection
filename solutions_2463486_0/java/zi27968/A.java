import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	long A,B;

	
	public A(BufferedReader reader) throws IOException {
		String line = reader.readLine();
		StringTokenizer token = new StringTokenizer(line, " ");
		A = Long.parseLong(token.nextToken());
		B = Long.parseLong(token.nextToken());
	}
	
	public boolean isPalindrome(long x) {
		String strX = "" + x;
		int len = strX.length();
		for (int i = 0; i<=len/2.0; i++) {
			if (strX.charAt(i) != strX.charAt(len-i - 1)) {
				return false;
			}
		}
		return true;
	
	}
	
	public String solve() {
		long A2 = (long)Math.ceil(Math.pow(A, 1.0/2f));
		long B2 = (long)Math.floor(Math.pow(B, 1.0/2f));
		
		long count = 0;
		for (long i = A2; i<=B2; i++) {
			if (isPalindrome(i)){
				if (isPalindrome(i * i)) {
					count ++;
				}
			}
		}
		
		return "" + count;
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = args[0];
		BufferedReader reader = new BufferedReader(new FileReader(inputFile
				+ ".in"));
		FileWriter outFile = new FileWriter(inputFile + ".out");
		PrintWriter out = new PrintWriter(outFile);
		String strNrLines = reader.readLine();
		int nrLines = Integer.parseInt(strNrLines);
		for (int i = 1; i <= nrLines; i++) {
			A b = new A(reader);
			out.println("Case #" + i + ": " + b.solve());
		}
		reader.close();
		out.close();
	}
	
}
