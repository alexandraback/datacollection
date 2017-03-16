package cz.phx.gcj2015.round1C;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by PHX on 10. 5. 2015.
 */
public class TaskA {

	private final int t;

	public TaskA(String inFile, String outFile) throws IOException {
		Scanner scanner = new Scanner(new File(inFile));

		FileWriter fw = new FileWriter(outFile);
		BufferedWriter writer = new BufferedWriter(fw);

		t = scanner.nextInt();

		for (int i = 0; i < t; i++) {
			processOne(i + 1, scanner, writer);
		}

		scanner.close();
		writer.close();
	}

	private void processOne(int T, Scanner scanner, BufferedWriter writer) throws IOException {
		int R = scanner.nextInt();
		int C = scanner.nextInt();
		int W = scanner.nextInt();

		int score = W;

		if (W < C) {
			score++;
			score += (C - W - 1) / W;
		}

		score += (C / W) * (R - 1);

		System.out.println("Case #" + T + ": " + score);
		writer.write("Case #" + T + ": " + score +"\n");

	}

	public static void main(String[] args) throws IOException{
//		String fileName = "resources/2015/round1C/A-test.in";
//		String fileName = "resources/2015/round1C/A-small-attempt0.in";
//		String fileName = "resources/2015/round1C/A-small-attempt1.in";
//		String fileName = "resources/2015/round1C/A-small-attempt2.in";
		String fileName = "resources/2015/round1C/A-large.in";
		new TaskA(fileName, fileName + ".out");
	}


}
