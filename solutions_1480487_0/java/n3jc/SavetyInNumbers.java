import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Formatter;
import java.util.Scanner;


public class SavetyInNumbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Path path = Paths.get(args[0]);
		Path file = Paths.get("savety.txt");
		int numberOfCases;
		try (Scanner scanner = new Scanner(Files.newInputStream(path), "UTF-8");
				OutputStreamWriter output = new OutputStreamWriter(Files.newOutputStream(file), "UTF-8")) {
			Formatter f = new Formatter(output);
			numberOfCases = scanner.nextInt();
			for (int i = 1; i <= numberOfCases; i++) {
				int[] contestansScores = new int[scanner.nextInt()];
				for (int j = 0; j < contestansScores.length; j++) {
					contestansScores[j] = scanner.nextInt();
				}
				
				double[] result = solve(contestansScores);
				f.format("Case #%d:", i);
				for (double res : result) {
					f.format(" %f", res);
				}
				f.format("\n");
			}
			f.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static double[] solve(int[] scores) {
		int sum = 0;
		for (int i : scores) {
			sum+=i;
		}
		double averageValue = sum*2/(double)scores.length;
		double[] result = new double[scores.length];
		for (int i = 0; i < scores.length; i++) {
			double remaining = averageValue - scores[i];
			result[i] = remaining/sum*100;
			if (result[i] < 0) {
				result[i] = 0;
			}
		}
		return result;
	}

}
