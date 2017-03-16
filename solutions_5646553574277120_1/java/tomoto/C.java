import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;

public class C {
	public static void main(String[] args) throws FileNotFoundException {
		new C().run();
	}
	
	// private static final String FILE = "../sample";
	// private static final String FILE = "../C-small-attempt0";
	private static final String FILE = "../C-large";
	
	private Scanner scanner;
	private PrintWriter out;
	
	void run() throws FileNotFoundException {
		scanner = new Scanner(new File(FILE + ".in"));
		out = new PrintWriter(new File(FILE + ".out"));
		
		int n = scanner.nextInt();
		for (int i = 1; i <= n; i++) {
			solve(i);
		}
		
		scanner.close();
		out.close();
	}
	
	void solve(int index) {
		String result = "result";
		out.println("Case #" + index + ": " + solve1());
	}

	private int solve1() {
		long c = scanner.nextInt();
		long d = scanner.nextInt();
		long v = scanner.nextInt();
		
		TreeSet<Long> originalDenomis = new TreeSet<>();
		for (int i = 0; i < d; i++) {
			originalDenomis.add(scanner.nextLong());
		}
		
		TreeSet<Long> workDenomis = new TreeSet<>(originalDenomis);
		
		TreeSet<Long> additionalDenomis = new TreeSet<>();
		long k = 1;
		while (k <= v) {
			if (workDenomis.size() > 0 && workDenomis.first() < k) {
				k += workDenomis.pollFirst() * c;
			} else if (workDenomis.size() > 0 && workDenomis.first() == k) {
				workDenomis.remove(k);
				k += k * c;
			} else {
				additionalDenomis.add(k);
				k += k * c;
			}
		}
		
		System.err.println(originalDenomis.toString() + " -> " + additionalDenomis.toString());
		return additionalDenomis.size();
	}
}

