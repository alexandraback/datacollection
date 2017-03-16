package round1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Around1C {
	private static Writer writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round1/A-small-attempt0.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1/outputA.txt");
		writer = new FileWriter(outputFile);
		
		int numberOfExercises = Integer.parseInt(reader.readLine());
		for (int exercise = 1; exercise <= numberOfExercises; exercise++) {
			String[] split = reader.readLine().split(" ");
			int rows = Integer.parseInt(split[0]);
			int columns = Integer.parseInt(split[1]);
			int width = Integer.parseInt(split[2]);
			generateOutput("Case #" + exercise + ": " + doExercise(rows, columns, width));
		}
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
	
	private static int doExercise(int r, int c, int w) {
		if (c == w) {
			return w + otherRows(r,c,w);
		}
		int B = (c-1)/w;
		return w + otherRows(r, c, w) + B;
	}

	private static int otherRows(int r, int c, int w) {
		int B = 1 + (c - 1) / w;
		return (r-1) * B;
	}
}
