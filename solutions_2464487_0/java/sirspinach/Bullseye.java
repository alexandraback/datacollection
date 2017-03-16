import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
public class Bullseye {
	private static PrintWriter out;
	private static final Scanner s = new Scanner(System.in);
	
	private static void output(int t, long result) {
		out.println("Case #"+t+": "+result);
	}
	
	public static void main(String[] args) throws IOException {
		out = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Code Jam 2013\\output.txt")));
		int T = s.nextInt();
		for (int i = 1; i <= T; i++) {
			output(i, runTrial(s.nextLong(), s.nextLong()));
		}
		out.flush();
		System.exit(0);
	}
	
	private static long runTrial(long r, long t) {
		long sum = 0;
		long i = 0;
		r++;
		while (sum < t) {
			sum += getLength(r);
			r += 2;
			i++;
		}
		if (sum > t) return i-1;
		else return  i;
	}
	
	private static long getLength(long r) {
		return r * r - (r - 1) * (r - 1);
	}
}
