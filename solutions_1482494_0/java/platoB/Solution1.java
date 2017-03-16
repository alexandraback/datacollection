import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Solution1 {
	static final boolean DBG = true;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int i = 1; i <= T; i++) {
			Task one = new Task(sc);
			System.out.println(one.getResult(i));

		}

	}

	static class Task {
		ArrayList<Level> levels = new ArrayList<Solution1.Level>();
		int result = -1;
		int N;
		int startsIHave = 0;

		public Task(Scanner sc) {
			N = Integer.parseInt(sc.nextLine());

			for (int i = 0; i < N; i++) {
				String[] vals = sc.nextLine().split(" ");
				levels.add(new Level(Integer.parseInt(vals[0]), Integer
						.parseInt(vals[1])));
			}

			result = calcLevelsHeMustComplete();
		}

		int calcLevelsHeMustComplete() {
			int okWithTwo = 0;
			int totalCompeted = 0;

			while (okWithTwo < N) {
				boolean completedAnyWithTwo = false;
				for (int i = 0; i < levels.size(); i++) {
					Level level = levels.get(i);
					if (level.completedWithTwo)
						continue;

					if (level.b <= startsIHave) {
						level.completedWithTwo = true;// complete with two
						if (level.completedWithOne) {
							startsIHave += 1;
						} else {
							startsIHave += 2;
						}
						completedAnyWithTwo = true;
						totalCompeted++;
						okWithTwo++;
					}
				}

				if (completedAnyWithTwo)
					continue;

				Collections.sort(levels);
				
				boolean completedAnyWithOne = false;
				for (int i = 0; i < levels.size(); i++) {
					Level level = levels.get(i);
					if (level.completedWithTwo || level.completedWithOne)
						continue;

					if (level.a <= startsIHave) {
						level.completedWithOne = true;// complete with two
						startsIHave += 1;
						completedAnyWithOne = true;
						totalCompeted++;
						break;
					}
				}

				if (!completedAnyWithOne)
					break;

			}

			if (okWithTwo == N) {
				return totalCompeted;
			}
			return -1;
		}

		String getResult(int caseNo) {
			String res;
			if (result == -1) {
				res = "Too Bad";
			} else {
				res = String.valueOf(result);
			}
			return "Case #" + String.valueOf(caseNo) + ": " + res;
		}
	}

	static class Level implements Comparable<Level> {
		Integer a = 0;
		Integer b = 0;
		boolean completedWithOne = false;
		boolean completedWithTwo = false;

		public Level(int a, int b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Level o) {
			return o.b.compareTo(this.b);
		}

	}

}
