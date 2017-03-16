package cz.phx.gcj2016.round1C;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Created by PHX on 08.05.2016.
 */
public class Task1CC {

	private static int YEAR = 2016;
	private static String ROUND = "round1C";

	private final int t;

	public static void main(String[] args) throws IOException {
//		new Task1CC("C-test");
//		new Task1CC("C-small-attempt0");
		new Task1CC("C-small-attempt1");
//		new Task1CC("C-large");
	}

	public Task1CC(String inFile) throws IOException {

		String folder = "resources/" + YEAR + "/" + ROUND + "/";

		Scanner scanner = new Scanner(new File(folder + inFile + ".in"));

		FileWriter fw = new FileWriter(folder + inFile + ".out");
		BufferedWriter writer = new BufferedWriter(fw);

		t = scanner.nextInt();

		for (int i = 0; i < t; i++) {
			processOne(i, scanner, writer);
		}

		scanner.close();
		writer.close();
	}

	private void processOne(int t, Scanner scanner, BufferedWriter writer) throws IOException {
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		int c = scanner.nextInt();
		int m = scanner.nextInt();

		Map<String, Integer> map12 = new HashMap<>();
		Map<String, Integer> map23 = new HashMap<>();
		Map<String, Integer> map13 = new HashMap<>();

		int rows = 0;
		StringBuffer sb = new StringBuffer();
		for (int ai = 1; ai <= a; ai++) {
			for (int bi = 1; bi <= b; bi++) {
				for (int ci = 1; ci <= c; ci++) {
					String key12 = ai + " " + bi;
					String key23 = bi + " " + ci;
					String key13 = ai + " " + ci;

					System.out.println(ai + " " + bi + " " + ci + "   -   " + can(map12, key12, m) + " " + can(map13, key13, m) + " " + can(map23, key23, m));
					if (can(map12, key12, m) && can(map13, key13, m) && can(map23, key23, m)) {
						rows++;
						sb.append(ai + " " + bi + " " + ci + "\n");

						increment(map12, key12);
						increment(map13, key13);
						increment(map23, key23);
					}
				}
			}
		}


		String result = rows + "\n" + sb.toString();

		String row = "Case #" + (t + 1) + ": " + result;
		writer.write(row);
		System.out.println(row);
	}

	private boolean can(Map<String, Integer> map, String key, int m) {
		Integer r = map.get(key);
		if (r == null || r < m) return true;
		return false;
	}

	private void increment(Map<String, Integer> map, String key) {
		Integer r = map.get(key);
		if (r == null) r = 1;
		else r++;
		map.put(key, r);
	}

}
