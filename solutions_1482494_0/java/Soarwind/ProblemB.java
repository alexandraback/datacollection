package roundone;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemB {

	/**
	 * @param args
	 */
	public static String input = "B-small-attempt0.in";

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new FileReader(input));
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new FileWriter(input + ".out"));
		int t = in.nextInt();
		for (int test = 0; test < t; test++) {
			int n = in.nextInt();
			int[] oneStarRest = new int[n];
			int[] twoStarRest = new int[n];
			int[] oneStarNeed = new int[n];
			int[] twoStarNeed = new int[n];

			for (int i = 0; i < n; i++) {
				oneStarRest[i] = 1;
				twoStarRest[i] = 2;
			}
			for (int i = 0; i < n; i++) {
				oneStarNeed[i] = in.nextInt();
				twoStarNeed[i] = in.nextInt();
			}
			int currentStar = 0;
			int oldStar = 0;
			int count = 0;
			while (true) {
				oldStar = currentStar;
				boolean roundDone = false;
				// 先找2星能打并且有2星
				for (int i = 0; i < n; i++) {
					if (twoStarNeed[i] <= currentStar && twoStarRest[i] == 2) {
						currentStar += 2;
						twoStarRest[i] = 0;
						oneStarRest[i] = 0;
						count++;
						roundDone = true;
						break;

					}
				}
				if (roundDone) {
					continue;
				}
				// 再找2星能打但是只有一星的
				for (int i = 0; i < n; i++) {
					if (twoStarNeed[i] <= currentStar && twoStarRest[i] == 1) {
						currentStar += 1;
						twoStarRest[i] = 0;
						count++;
						roundDone = true;

						break;
					}
				}
				if (roundDone) {
					continue;
				}
				// 再找1星能打并且有1星的,并且1星所对应的2星需要更多星
				int max = -1;
				int maxId = -1;
				for (int i = 0; i < n; i++) {
					if (oneStarNeed[i] <= currentStar && oneStarRest[i] == 1) {
						if (twoStarNeed[i] > max) {
							max = twoStarNeed[i];
							maxId = i;
						}
					}
				}
				if (max != -1) {
					currentStar += 1;
					count++;
					if (twoStarRest[maxId] == 2) {
						twoStarRest[maxId] = 1;
					}
					oneStarRest[maxId] = 0;
					roundDone = true;
				}
				if (roundDone) {
					continue;
				}
				if (oldStar == currentStar) {
					break;
				}
			}
			boolean done = true;
			for (int i = 0; i < n; i++) {
				if (twoStarRest[i] != 0) {
					done = false;
				}
			}
			if (done) {
				out.println("Case #" + (test + 1) + ": " + count);
			} else {
				out.println("Case #" + (test + 1) + ": Too Bad");
			}
		}
		out.close();
	}

}
