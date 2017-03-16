import java.io.*;
import java.util.*;

public class ProblemC {

	static void log(String fs, Object... args) {
		System.err.println(String.format(fs, args));
	}

	public static void main(String[] args) throws FileNotFoundException {
		//String filename = "data/C-test.in";
		String filename = "data/C-small-attempt0.in";
		//String filename = "data/C-large.in";
		Scanner sc = 
				new Scanner(
						new FileInputStream(
								new File(filename)));
		PrintWriter pw = 
				new PrintWriter(
						new FileOutputStream(
								new File(filename + ".result")));

		int T = sc.nextInt();
		for (int task = 1; task <= T; task++) {
			
			pw.println(String.format("Case #%d:", task));
			log("Case #%d:", task);

			int N = sc.nextInt();
			
			int nums[] = new int[N];
			for (int i = 0; i < N; i++) {
				nums[i] = sc.nextInt();
				//log("%d", nums[i]);
			}

			int K = 100*1000*N;
			int sums[] = new int[K];
			for (int i = 0; i < K; i++) {
				sums[i] = -1;
			}

			boolean ok = false;
			for (int mask = 1; mask < (1<<N); mask++) {
				int sum = 0;
				for (int bit = 0; bit < N; bit++) {
					int m = ((1 << bit) & mask) >> bit;
					if (m == 1) {
						sum += nums[bit];
					}
				}
				//log("MASK %d, SUM %d", mask, sum);
				
				if (sums[sum] < 0) {
					sums[sum] = mask;
					continue;
				} else {
					int mask1 = sums[sum];
					for (int bit = 0; bit < N; bit++) {
						int m = ((1 << bit) & mask1) >> bit;
						if (m == 1) {
							pw.printf("%d ", nums[bit]);
							log("%d", nums[bit]);
						}
					}
					pw.println();
					log("---");
					
					int mask2 = mask;
					for (int bit = 0; bit < N; bit++) {
						int m = ((1 << bit) & mask2) >> bit;
						if (m == 1) {
							pw.printf("%d ", nums[bit]);
							log("%d", nums[bit]);
						}
					}
					pw.println();
					
					ok = true;
					break;
				}
				
			}
			
			if (!ok) {
				pw.println("Impossible");
				log("Impossible");
			}
		}
		pw.close();
	}
}
