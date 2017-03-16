import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class ProblemA {

	static BufferedWriter out;

	public static void solve(Scanner sc) throws IOException {
		int A = sc.nextInt();
		int N = sc.nextInt();
		int[] motes = new int[N];
		for (int i = 0; i < motes.length; i++) {
			motes[i] = sc.nextInt();
		}
		
		if (A == 1) {
			System.out.println(N);
			out.write(N + "\n");
			out.flush();
			return;
		}
		
		Arrays.sort(motes);
		int[] generated = new int[N];
		
		int pos = 0;
		while (pos < N) {
			if (motes[pos] < A) {
				//eat
				A += motes[pos];
				pos++;
				continue;
			} else {
				generated[pos]++;
				A = 2*A-1;
			}
		}
		
		int bestDiff = 0;
		
		for (int i = 1; i < N; i++) {
			generated[N - 1 - i] += generated[N - i];
			if (generated[N - i] - i > bestDiff) {
				bestDiff = generated[N - i] - i;
			}
		}
		if (generated[0] - N > bestDiff) {
			bestDiff = generated[0] - N;
		}
		int sol = generated[0] - bestDiff;
		System.out.println(sol);
		
//		System.out.println("blub");
		out.write(sol + "\n");
		out.flush();
	}
	

	public static void main(String[] args) throws IOException {
//		String name = "A-practice";
		String name = "A-small-attempt2";
//		String name = "A-large";
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
	}
}
