import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class OminousOmino {

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
		System.out.println("Completed Trials!");
	}

	static void solveTrial(Scanner scanner, FileWriter writer)
			throws IOException {
		int x = scanner.nextInt();
		int rows = scanner.nextInt();
		int cols = scanner.nextInt();

		if (x > 6) {
			writer.write("RICHARD");
			return;
		}
		if ((rows * cols) % x != 0 || (rows < x && cols < x)) {
			writer.write("RICHARD");
			return;
		}
		if (x <= 2) {
			writer.write("GABRIEL");
		} else if (x == 3) {
			if (rows > 1 && cols > 1)
				writer.write("GABRIEL");
			else
				writer.write("RICHARD");
		} else if (x == 4) {
			if (rows >= 3 && cols >= 3)
				writer.write("GABRIEL");
			else
				writer.write("RICHARD");
		} else {
			System.out.println("NOT SUPPOSED TO HAPPEN");
			System.exit(1);
		}
	}
}
