package jam1a15;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class C {
//	private static final String FILE = "C-sample";
	private static final String FILE = "C-small-attempt0";

	public static void main(String[] args) throws IOException {
		new C().start();
	}

	private void start() throws IOException {
		Scanner scanner = new Scanner(new File(FILE + ".in"));
		BufferedWriter writer = new BufferedWriter(
				new FileWriter(FILE + ".out"));
		int tests = scanner.nextInt();

		for (int i = 0; i < tests; i++) {
			String result = "Case #" + (i + 1) + ": " + runTest(scanner);
			System.out.println(result);
			writer.write(result + "\n");
		}

		writer.close();
		scanner.close();
	}

	private String runTest(Scanner scanner) {
		int c = scanner.nextInt();
		int d = scanner.nextInt();
		int v = scanner.nextInt();
		TreeSet<Integer> coins = new TreeSet<>();

		for (int i = 0; i < d; i++) {
			coins.add(scanner.nextInt());
		}

		int count = 0;
		List<Integer> remaining = new ArrayList<Integer>();
		for (int i = 1; i <= v; i++) {
			// check payable V with one coin
			if (coins.contains(i)) {
				continue;
			}
			
			//i is smaller than smallest coin, add it;
			if (i < coins.first()) {
				coins.add(i);
				count++;
				continue;
			}

			// check payable with current Ds
			int target = i;
			Integer coin = coins.last();
			while (null != coin && target != 0) {
				for (int j = 1; j <= c; j++) {
					if (target >= coin) {
						target -= coin;
					}
				}
				coin = coins.floor(coin - 1);
			}
			if (target == 0) {
				continue;
			}
			
			if (!coins.contains(target)) {
				//add remaining value to coins
				coins.add(target);
				count++;
				continue;
			}
			
			coins.add(i);
			count++;
		}

		return count + "";
	}
}
