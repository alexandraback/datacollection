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
			out.println("Case #" + caseIndex + ": " + solveSmall(line, n));
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
		int start = -1;
		int current = 0;
		int length = line.length();
		
		long result = f(length, n);
		
		for (;current < length; current++) {
			switch(line.charAt(current)) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				if (start == -1) {
					continue;
				} else {
					long t = f (current - start - 1, n);
					result -= t;
				}
				break;
			default:
				if (start == -1) {
					start = current;
				}
				break;
			}
			
			if (start != -1) {
				long t = f(length - start - 1, n);
				result -= t;
			}
		}
		return result;
	}
	
	public static long f(long length, long n) {
		return (length - n + 1) * (length - n + 2) / 2;
	}
}
