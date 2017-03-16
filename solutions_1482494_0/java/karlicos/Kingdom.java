import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;


public class Kingdom {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		new Kingdom().run();
	}

	private int solve(int[] a, int[] b) {
		int n = a.length;
		boolean[] adone = new boolean[n], bdone = new boolean[n];
		ArrayList<String> schedule = new ArrayList<String>();
		int curStars = 0;
		boolean changed = true;
		while (changed) {
			changed = false;
			int mIndex = -1;
			for (int j = 0; j < n; j++) {
				if (!bdone[j]) {
					if (b[j] <= curStars) {
						if (mIndex == -1 || !adone[j]) {
							mIndex = j;
						}
					}
				}
			}
			if (mIndex != -1) {
				schedule.add("b" + mIndex);
				changed = true;
				curStars += (adone[mIndex] ? 1 : 2);
				bdone[mIndex] = true;
				adone[mIndex] = true;
			} else {
				for (int j = 0; j < n; j++) {
					if (!adone[j]) {
						if (a[j] <= curStars) {
							if (mIndex == -1 || (b[mIndex] < b[j]))
							mIndex = j;
						}
					}
				}
				if (mIndex != -1) {
					schedule.add("a" + mIndex);
					changed = true;
					curStars += 1;
					adone[mIndex] = true;
				}
			}
			
		}
			
		boolean allDone = true;
		for (int i = 0; i < n; i++) {
			if (!adone[i] || !bdone[i]) {
				allDone = false;
			}
		}
		if (!allDone) {
			return - 1;
		} else {
			return schedule.size();
		}
	}
	
	private void run() throws IOException {
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		//Scanner in = new Scanner("A-small-attempt0.in");
		//PrintWriter out = new PrintWriter("A-small-attempt0.out");
		
		
		int t = in.nextInt();
		for (int test = 0; test < t; test++) {
			int n = in.nextInt();
			int[] a = new int[n], b = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
				b[i] = in.nextInt();
			}
			int ans = solve(a, b);
			out.println("Case #" + (test + 1) + ": " + (ans == -1 ? "Too Bad" : ans));
		}
		
		out.close();
	}
}
