package round0;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class OminoLarge {
	private static FileWriter writer;

	public static void main(String[] args) throws IOException {
		File file = new File("round0/D-large.in");
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
		if (r < c) {
			return play(x, c, r);
		}
		if (r*c % x != 0) {
			return true;
		}
		if (x <= 2) {
			return false;
		}
		if (x == 3) {
			return (c == 1);
		}
		if (x == 4) {
			return (c <= 2);
		}
		if (x == 5) {
			if (c <= 2) {
				return true;
			}
			if (c == 3) {
				return r == 5;
			}
			return false;
		}
		if (x == 6) {
			return (c <= 3);
		}
		return true;
	}

	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}

}
