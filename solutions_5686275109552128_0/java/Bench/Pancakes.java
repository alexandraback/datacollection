import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Pancakes {

	public static void main(String[] args) {
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			System.out.println("Couldn't open input file.\n" + e.getMessage());
			e.printStackTrace();
		}
		FileWriter writer = null;
		try {
			writer = new FileWriter(new File("output.txt"));
		} catch (IOException e) {
			System.out.println("Couldn't open/make output file."
					+ e.getMessage());
			e.printStackTrace();
		}

		int numTrials = scanner.nextInt();
		for (int trial = 1; trial <= numTrials; trial++) {
			System.out.println("Trial: " + trial);
			try {
				writer.write("Case #" + trial + ": ");
				solveTrial(scanner, writer);
				writer.write("\n");
			} catch (IOException e) {
				System.out.println("Error on trial #" + trial + "\n"
						+ e.getMessage());
				e.printStackTrace();
			}
		}
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		scanner.close();
	}

	static void solveTrial(Scanner scanner, FileWriter writer)
			throws IOException {
		float[] num_plates = new float[1001];
		int d = scanner.nextInt();
		for (int i = 0; i < d; i++)
			num_plates[scanner.nextInt()]++;

		int high = 1000;
		while (high > 0 && num_plates[high] == 0)
			high--;
		float minSteps = high;
		for (float m = 2; m < high; m++){
			float steps = m;
			for (int i = (int)m+1; i <= high; i++){
				if (num_plates[i] != 0)
					steps +=  num_plates[i]*(Math.ceil(i/m)-1);
			}
			minSteps = Math.min(minSteps, steps);
		}
		writer.write((int)minSteps + "");
	}
}
