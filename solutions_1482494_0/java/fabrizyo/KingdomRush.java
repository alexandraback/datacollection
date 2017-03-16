package googlejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class KingdomRush {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("inputB.txt"));
		int T = sc.nextInt();
		PrintWriter pw = new PrintWriter("outputB.txt");
		for (int t = 1; t <= T; t++) {

			int n = sc.nextInt();
			Level[] levelsFirst = new Level[n];
			Level[] levelsSecond = new Level[n];

			for (int i = 0; i < n; i++) {
				levelsFirst[i] = new Level(sc.nextInt(), sc.nextInt());
				levelsSecond[i] = levelsFirst[i];
			}
			Arrays.sort(levelsFirst, new Comparator<Level>() {

				public int compare(Level o1, Level o2) {
					return o1.first - o2.first;
				}
			});
			Arrays.sort(levelsSecond, new Comparator<Level>() {

				public int compare(Level o1, Level o2) {
					return o1.second - o2.second;
				}
			});

			int times = 0;
			int stars = 0;
			int completed = n;
			int indexFirst = 0;
			int indexSecond = 0;

			while (true) {

				if (completed == 0)
					break;

				while (indexFirst < n && levelsFirst[indexFirst].firstCompleted) {
					indexFirst++;
				}
				while (levelsSecond[indexSecond].secondCompleted) {
					indexSecond++;
				}

				Level levelS = levelsSecond[indexSecond];
				Level levelF = indexFirst < n ? levelsFirst[indexFirst] : null;

				if (levelS.second <= stars) {
					++times;
					completed--;
					stars += levelS.firstCompleted ? 1 : 2;
					levelS.secondCompleted = true;
					levelS.firstCompleted = true;
				} else if (levelF != null && levelF.first <= stars) {
					++times;
					stars += 1;
					levelF.firstCompleted = true;
				} else {
					break;
				}
			}

			pw.println("Case #" + t + ": " + (completed == 0 ? "" + times : "Too Bad"));
		}
		pw.flush();
		pw.close();
	}

	static class Level {
		int first;
		int second;
		boolean firstCompleted;
		boolean secondCompleted;

		public Level(int first, int second) {
			this.first = first;
			this.second = second;
		}

	}
}
