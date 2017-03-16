import java.util.Locale;
import java.util.Scanner;

public class B {
	static {
		Locale.setDefault(Locale.US);
	}

	private double heightH;
	private int rowsN;
	private int colsM;
	private int[][] ceilingHeight;
	private int[][] floorHeight;
	private double[][] bestTime;

	public B(Scanner scanner) {
		this.heightH = scanner.nextInt();
		this.rowsN = scanner.nextInt();
		this.colsM = scanner.nextInt();
		scanner.nextLine();
		this.ceilingHeight = new int[rowsN][];
		for (int i = 0; i < rowsN; i++) {
			ceilingHeight[i] = new int[colsM];
			for (int j = 0; j < colsM; j++)
				ceilingHeight[i][j] = scanner.nextInt();
		}
		this.floorHeight = new int[rowsN][];
		for (int i = 0; i < rowsN; i++) {
			floorHeight[i] = new int[colsM];
			for (int j = 0; j < colsM; j++)
				floorHeight[i][j] = scanner.nextInt();
		}
		this.bestTime = new double[rowsN][];
		for (int i = 0; i < rowsN; i++) {
			bestTime[i] = new double[colsM];
			for (int j = 0; j < colsM; j++)
				bestTime[i][j] = Double.MAX_VALUE;
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nrOfTestCases = scanner.nextInt();
		for (int caseNr = 1; caseNr <= nrOfTestCases; caseNr++) {
			System.out.println("Case #" + caseNr + ": " + solveCase(scanner));
		}
	}

	// String
	static double solveCase(Scanner scanner) {
		return new B(scanner).solve();
	}

	private double solve() {
		solve(0, 0, 0.0);
		return best();
	}

	private void solve(int i, int j, double curTime) {
		if (curTime >= bestTime[i][j])
			return;
		bestTime[i][j] = curTime;

		double timeToMove = canMove(i, j, i - 1, j, curTime);
		if (timeToMove < best())
			solve(i - 1, j, timeToMove);
		timeToMove = canMove(i, j, i + 1, j, curTime);
		if (timeToMove < best())
			solve(i + 1, j, timeToMove);
		timeToMove = canMove(i, j, i, j - 1, curTime);
		if (timeToMove < best())
			solve(i, j - 1, timeToMove);
		timeToMove = canMove(i, j, i, j + 1, curTime);
		if (timeToMove < best())
			solve(i, j + 1, timeToMove);
	}

	private double canMove(int i1, int j1, int i2, int j2, double curTime) {
		if (i2 < 0)
			return Double.MAX_VALUE;
		if (j2 < 0)
			return Double.MAX_VALUE;
		if (i2 >= rowsN)
			return Double.MAX_VALUE;
		if (j2 >= colsM)
			return Double.MAX_VALUE;
		double floorHeightNext = floorHeight[i2][j2];
		double ceilingHeightNext = ceilingHeight[i2][j2];
		if (floorHeightNext + 50 > ceilingHeightNext)
			return Double.MAX_VALUE;
		double floorHeightThis = floorHeight[i1][j1];
		if (floorHeightThis + 50 > ceilingHeightNext)
			return Double.MAX_VALUE;
		double ceilingHeightThis = ceilingHeight[i1][j1];
		if (floorHeightNext + 50 > ceilingHeightThis)
			return Double.MAX_VALUE;
		double waterLevel = heightH - 10.0 * curTime;
		if (waterLevel + 50 <= ceilingHeightNext)
			return curTime == 0.0 ? 0 : waterLevel >= floorHeightThis + 20 ? curTime + 1.0
					: curTime + 10.0;
		double timeToMove = (heightH - ceilingHeightNext + 50.0) / 10.0;
		waterLevel = heightH - 10.0 * timeToMove;
		if (waterLevel + 50 <= ceilingHeightNext)
			return waterLevel >= floorHeightThis + 20 ? timeToMove + 1.0 : timeToMove + 10.0;
		return timeToMove;
	}

	private final double best() {
		return bestTime[rowsN - 1][colsM - 1];
	}
}
