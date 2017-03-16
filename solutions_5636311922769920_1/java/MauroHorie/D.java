import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class D {
	public static void main(String[] args) {
		String filename = "src/D-large.in";
		String output = "output.txt";
		Scanner scanner = null;
		PrintWriter printer = null;

		try {
			scanner = new Scanner(new FileReader(filename));
			printer = new PrintWriter(new FileWriter(output));

			int tests = scanner.nextInt();
			for (int test = 1; test <= tests; test++) {

				int iniTileCount = scanner.nextInt();
				int complexity = scanner.nextInt();
				int students = scanner.nextInt();

				if (students < iniTileCount) {
					printer.println(String.format("Case #%d: IMPOSSIBLE", test));
				} else {
					printer.print(String.format("Case #%d:", test));
					for (int i = 0; i < iniTileCount; i++) {
						BigInteger tileToCheck = getFirstComplexTileForOriginalTile(i, iniTileCount, complexity);
						printer.print(" " + tileToCheck.toString());
					}
					printer.println();
				}
			}

		} catch (FileNotFoundException e) {
			System.out.println(filename + " not found.");
		} catch(IOException e) {
			System.out.println(e.getMessage());
		} finally {
			if (scanner != null) {
				scanner.close();
			}
			if (printer != null) {
				printer.flush();
				printer.close();
			}
		}
	}

	private static BigInteger getFirstComplexTileForOriginalTile(int original, int size, int complexity) {
		BigInteger timesBiggerThanOriginal = new BigInteger(String.valueOf(size)).pow(complexity - 1);
		return timesBiggerThanOriginal
				.multiply(new BigInteger(String.valueOf(original)))
				.add(new BigInteger("1"));
	}
}
