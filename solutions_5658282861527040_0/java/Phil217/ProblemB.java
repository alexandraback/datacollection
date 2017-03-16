package Round1B;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemB {

	static BufferedWriter out;

	public static void solve(Scanner sc) throws IOException {
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		int pairs = 0;
		for (int a = 0; a < A; a++) {
			for (int b = 0; b < B; b++) {
				if ((a & b) < K) {
					pairs++;
				}
			}
		}
		System.out.println(pairs);
		out.write(pairs + "\n");
	}

	public static void main(String[] args) throws IOException {
//		String name = "B-practice";
		String name = "B-small-attempt0";
//		String name = "B-large";
		Scanner sc = new Scanner(new File(name + ".in")); 
		sc.useLocale(Locale.US);
		 
		FileWriter fstream = new FileWriter(name + ".out");
		out = new BufferedWriter(fstream);
		
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			out.write("Case #" + i + ": ");
			solve(sc);
		}
		sc.close();
		out.close();
	}
}
