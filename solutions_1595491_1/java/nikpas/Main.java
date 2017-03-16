import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		
		Scanner scanner = new Scanner(new File("input.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));

		int N = scanner.nextInt();

		for (int i = 1; i <= N; i++) {
			int n = scanner.nextInt();
			int s = scanner.nextInt();
			int p = scanner.nextInt();

			ArrayList<Integer> e = new ArrayList<Integer>();
			for (int j = 0; j < n; j++)
				e.add(scanner.nextInt());

			Solver solver = new Solver(s, p, e);

			writer.append("Case #" + i + ": " + solver.solve());
			writer.newLine();

		}

		writer.close();
		scanner.close();

	}

}
