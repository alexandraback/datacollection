import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Formatter;
import java.util.Scanner;

public class Dancing {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Path path = Paths.get(args[0]);
		Path file = Paths.get("dancers.txt");
		int numberOfCases;
		try (Scanner scanner = new Scanner(Files.newInputStream(path), "UTF-8");
				OutputStreamWriter output = new OutputStreamWriter(Files.newOutputStream(file), "UTF-8")) {
			Formatter f = new Formatter(output);
			numberOfCases = scanner.nextInt();
			for (int i = 1; i <= numberOfCases; i++) {
				int[] googlersScores = new int[scanner.nextInt()];
				int specialScores = scanner.nextInt();
				int scoreAtLeast = scanner.nextInt();
				for (int j = 0; j < googlersScores.length; j++) {
					googlersScores[j] = scanner.nextInt();
				}
				int result = solve(googlersScores, specialScores, scoreAtLeast);
				f.format("Case #%d: %d\n", i, result);
			}
			f.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static int solve(int[] googlersScores, int specialCases, int scoreAtLeast) {
		int numberOfGooglers = 0;
		for (int googleScore : googlersScores) {
			int firstScore = (int) Math.floor(googleScore / 3.);
			int secondScore = (int) Math.floor((googleScore - firstScore) / 2.);
			int thirdScore = googleScore - firstScore - secondScore;
			if (thirdScore >= scoreAtLeast) {
				numberOfGooglers++;
			} else if (thirdScore > 0 && thirdScore == scoreAtLeast - 1 && secondScore == thirdScore && specialCases > 0) {
				numberOfGooglers++;
				specialCases--;
			}
		}
		return numberOfGooglers;
	}
}
