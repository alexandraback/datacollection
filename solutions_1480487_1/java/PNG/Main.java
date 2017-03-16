import java.io.*;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("input"));
		BufferedWriter w = new BufferedWriter(new FileWriter(new File("output")));
		int cases = s.nextInt();
		s.nextLine();

		for (int i = 1; i <= cases; i++) {
			w.write("Case #");
			w.write(String.valueOf(i));
			w.write(": ");

			solve(s, w);

			w.write("\n");
		}
		w.close();
	}

	private static Object solve(Scanner s, BufferedWriter w) throws Exception {
		int contestant = s.nextInt();
		int sum = 0;
		int[] judges = new int[contestant];
		int max = 0;
		int min = 100;
		for (int i = 0; i < contestant; i++) {
			int val = (int) s.nextInt();
			sum += judges[i] = val;
			max = Math.max(max, val);
			min = Math.min(min, val);
		}
		double avg = ((double) sum) / contestant;
		int sum2 = 0;

		int count = 0;
		for (int score : judges) {
			if (score <= 2 * avg) {
				sum2 += score;
				count++;
			}
		}

		double target =  ((double) sum + sum2) / count;

		for (int score : judges) {
			double ans;
			if (score > target) {
				ans = 0;
			} else {
				ans = (target - score) / sum * 100;
			}

			w.write(String.valueOf(ans));
			w.write(' ');
		}

		return sum;
	}

}
