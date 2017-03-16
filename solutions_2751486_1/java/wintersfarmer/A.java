import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class A {
	public static void run() throws IOException {
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
		BufferedReader in = new BufferedReader(new FileReader("in.txt"));
		
		int caseN = Integer.parseInt(in.readLine());
		for (int caseIndex = 1; caseIndex <= caseN; caseIndex++) {
			String tokens[] = in.readLine().split(" ");
			String line = tokens[0];
			int n = Integer.parseInt(tokens[1]);
			out.println("Case #" + caseIndex + ": " + solve(line, n));
		}
		in.close();
		out.close();
	}
	
	public static long solveSmall(String line, int n) {
		char[] data = line.toCharArray();
		int length = line.length();
		long result = 0;
		
		for (int start = 0; start < length; start++) {
			for (int end = start + n; end <= length; end++) {
				int counter = 0;
				for (int i = start; i < end; i++) {
					switch (data[i]) {
						case 'a':
						case 'e':
						case 'i':
						case 'o':
						case 'u':
							counter = 0;
							break;
						default:
							counter++;
					}
					if (counter >= n) {
						result++;
						break;
					}
				}
			}
		}
		return result;
	}
	
	public static long solve(String line, int n) {
		int length = line.length();
		
		long result = 0;
		long nearest = -1;
		long counter = 0;
		
		for (int i = 0; i < length; i++) {
			switch(line.charAt(i)) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				counter = 0;
				if (nearest >= 0) {
					result += (nearest + 1);
				}
				break;
			default:
				counter++;
				if (counter >= n) {
					nearest = i - n + 1;
				}
				result += (nearest + 1);
			}
		}
		return result;
	}
	
	public static long f(long length, long n) {
		return (length - n + 1) * (length - n + 2) / 2;
	}
}
