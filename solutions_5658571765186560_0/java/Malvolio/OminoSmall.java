package round0;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class OminoSmall {
	private static FileWriter writer;

	public static void main(String[] args) throws IOException {
		File file = new File("round0/D-small-attempt0.in");
		BufferedReader reader = new BufferedReader(new FileReader(file));
	
		File outputFile = new File("round0/output-omino.txt");
		writer = new FileWriter(outputFile);
		int numberOfTests = Integer.parseInt(reader.readLine());
		for (int test = 1; test <= numberOfTests; test++) {
			String[] split = reader.readLine().split(" ");
			int x = Integer.parseInt(split[0]);
			int r = Integer.parseInt(split[1]);
			int c = Integer.parseInt(split[2]);
			String answer = play(x,r,c) ? "RICHARD" : "GABRIEL";
			generateOutput("Case #" + test + ": " + answer);
		}
		
		
		reader.close();
		writer.close();
	}
	
	private static boolean play(int x, int r, int c) {
		if (r*c % x != 0) {
			return true;
		}
		if (x <= 2) {
			return false;
		}
		if (x == 3) {
			return (r == 1 || c == 1);
		}
		return (r <= 2 || c <= 2);
		
	}

	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}

}
