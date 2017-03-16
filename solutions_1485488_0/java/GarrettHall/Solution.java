import java.io.PrintWriter;
import java.util.Scanner;

public class Solution {
	Solution() throws Exception {
	}

	private int[][] ceilings;
	private int[][] floors;
	private double[][] bestTimes;
	private int water;

	Object solve() throws Exception {
		water = in.nextInt();
		int N = in.nextInt();
		int M = in.nextInt();
		bestTimes = new double[N][M];
		ceilings = new int[N][M];
		floors = new int[N][M];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				bestTimes[i][j] = Double.MAX_VALUE;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				ceilings[i][j] = in.nextInt();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				floors[i][j] = in.nextInt();
		tryMove(0, 0, 0);
		return bestTimes[N - 1][M - 1];
	}

	public void tryMove(int x1, int y1, double time) {
		if (canMove(x1, y1, x1 + 1, y1, time))
			tryMove(x1 + 1, y1, bestTimes[x1 + 1][y1]);
		if (canMove(x1, y1, x1, y1 + 1, time))
			tryMove(x1, y1 + 1, bestTimes[x1][y1 + 1]);
		if (canMove(x1, y1, x1 - 1, y1, time))
			tryMove(x1 - 1, y1, bestTimes[x1 - 1][y1]);
		if (canMove(x1, y1, x1, y1 - 1, time))
			tryMove(x1, y1 - 1, bestTimes[x1 ][y1 - 1]);
	}

	public boolean canMove(int x1, int y1, int x2, int y2, double time) {
		try {
			double absWater = water - (10 * time);
			double currentFloor = floors[x1][y1];
			double currentCeiling = ceilings[x1][y1];
			double nextFloor = floors[x2][y2];
			double nextCeiling = ceilings[x2][y2];
			double timeSpent = 0;
			double currentWater = absWater;
			double absFloor = Math.max(currentFloor, nextFloor);
			
			if (bestTimes[x2][y2] == 0)
				return false;
			if (currentCeiling < (nextFloor + 50))
				return false;
			if (absFloor > (nextCeiling - 50))
				return false;
			if (absWater > (nextCeiling - 50)) {
				timeSpent = (double)((absWater + 50) - nextCeiling) / 10;
				currentWater = absWater - (10 * timeSpent);
				time += timeSpent;
//				System.out.println(timeSpent);
			}
			if (time == 0)
				time += 0;
			else if ((currentWater - currentFloor) < 20)
				time += 10;
			else
				time += 1;
			
			if (time < bestTimes[x2][y2]) {
				bestTimes[x2][y2] = time;
				return true;
			} else
				return false;
		} catch (ArrayIndexOutOfBoundsException e) {
			return false;
		}
	}

	void solveAll() throws Exception {
		int cases = in.nextInt();
		in.nextLine();
		for (int i = 1; i <= cases; i++) {
			String solution = "Case #" + i + ": " + solve();
			System.out.println(solution);
			out.println(solution);
		}
		out.flush();
	}

	// -----------------------------------------------------------------------

	static Scanner in = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) throws Exception {
		new Solution().solveAll();
	}
}
