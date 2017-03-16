import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Battleship {

	public static void main(String[] args) throws Exception {
		Battleship object = new Battleship();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		Scanner scanner = new Scanner(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		int testCases = scanner.nextInt();

		for (int tc = 1; tc <= testCases; tc++) {

			int r = scanner.nextInt();
			int c = scanner.nextInt();
			int w = scanner.nextInt();

			System.out.println();
			int result = object.solve(r, c, w);

			wr.write("Case #" + tc + ": " + result + "\r\n");
		}

		scanner.close();
		wr.close();
	}

	private int solve(int R, int C, int W) throws Exception {

		int value1 = (R - 1) * getNeededForEliminateRow(C, W);
		int value2 = getNeededToGuessShipInRow(C, W);

		return value1 + value2;
	}

	private int getNeededToGuessShipInRow(int c, int w) {

		int result = 1000000000;

		for (int z = 0; (z < (1 << c)); z++) {

			int[] columnsGuessed = new int[c];
			Arrays.fill(columnsGuessed, 0);

			for (int i = 0; i < c; i++)
				if (((1 << i) & z) > 0) {
					columnsGuessed[i] = 1;
				}

			// are there multiple positions for the ship?
			int availablePositions = 0;
			for (int st = 0; st < c; st++)
				if (st + w <= c) {
					boolean ok = true;
					for (int j = st; j < st + w; j++)
						if (columnsGuessed[j] == 1)
							ok = false;

					if (ok) {
						availablePositions++;
					}
				}

			if (availablePositions == 1)
				result = Math.min(result, Integer.bitCount(z));

		}

		return result + w;

	}

	private int getNeededForEliminateRow(int c, int w) {
		int guesses = 0;

		while (c >= w) {
			guesses++;
			c -= w;
		}

		return guesses;
	}

}
