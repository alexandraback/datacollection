
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Stack;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader fileIn = new BufferedReader(new FileReader("A-small-attempt2.in"));
		PrintWriter fileOut = new PrintWriter(new FileWriter("result"));
		int caseNum = Integer.parseInt(fileIn.readLine());
		for (int i = 1; i <= caseNum; i++) {
			String[] parts = fileIn.readLine().split("/");
			long up = Long.parseLong(parts[0]);
			long down = Long.parseLong(parts[1]);
			fileOut.println("Case #" + i + ": " + solve(up, down));
		}
		fileIn.close();
		fileOut.close();
	}
	
	public static long findGCD(long a, long b)
	{
	   if (b==0) return a;
	   return findGCD(b,a%b);
	}
	
	public static String solve(long up, long down) {
		long gcd = findGCD(up, down);
		up /= gcd;
		down /= gcd;
		long i = 1;
		while (i < down) {
			i <<= 1;
		}
		if (i != down) {
			return "impossible";
		} else {
			int result = 0;
			while (up < down) {
				up <<= 1;
				result++;
			}
			return String.valueOf(result);
		}
 		
	}

}
