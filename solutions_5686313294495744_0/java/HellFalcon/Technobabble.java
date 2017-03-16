import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class Technobabble {
	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new BufferedReader(new FileReader(new File("C-small-attempt0.in")), 256 << 10));
			BufferedWriter out = new BufferedWriter(new FileWriter(new File("output.txt")), 256 << 10);

			int testsNumber = in.nextInt();
			for (int testId = 1; testId <= testsNumber; testId++) {
				int n = in.nextInt();
				String[] w1 = new String[n];
				String[] w2 = new String[n];
				for (int i = 0; i < n; i++) {
					w1[i] = in.next();
					w2[i] = in.next();
				}
				int best = 0;
				for (int comb = 1; comb < (1 << n); comb++) {
					if (best < Integer.bitCount(comb)) {
						boolean isOk = true;
						for (int i = 0; i < n; i++)
							if ((comb & (1 << i)) != 0) {
								
							boolean f1 = false;
							boolean f2 = false;
							for (int j = 0; j < n; j++)
								if ((comb & (1 << j)) == 0) {
									if (w1[i].equals(w1[j])) {
										f1 = true;
									}
									else if (w2[i].equals(w2[j])) {
										f2 = true;
									}
									if (f1 & f2) break;
								}
							
							if (!(f1 & f2)) {
								isOk = false;
								break;
							}
						}
						if (isOk)
							best = Integer.bitCount(comb);
					}
				}
				out.append("Case #" + testId + ": " + best);
				out.append("\n");
			}
			in.close();
			out.close();
		}
		catch (RuntimeException rte) {
			throw rte;
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}
