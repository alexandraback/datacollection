package cz.phx.gcj2015.round1C;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

/**
 * Created by PHX on 10. 5. 2015.
 */
public class TaskCSmallOnly {

	private final int t;

	public TaskCSmallOnly(String inFile, String outFile) throws IOException {
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
		int C = scanner.nextInt();
		int D = scanner.nextInt();
		int V = scanner.nextInt();

		TreeSet<Integer> coins = new TreeSet<>(Integer::compare);
		for (int i = 0; i < D; i++)
			coins.add(scanner.nextInt());

		System.out.println(coins);

		for (int v = 1; v <= V; v++) {
			int rest = v;
			TreeSet<Integer> tempCoins = new TreeSet<>(coins);
			do {
				Integer coin = tempCoins.floor(rest);
				if (coin == null) {
					if (coins.contains(rest)) {
						coins.add(v);
					}
					else {
						coins.add(rest);
					}
					break;
				} else {
					rest -= coin;
					tempCoins.remove(coin);
				}
			} while (rest > 0);
		}

		System.out.println(coins);

		System.out.println("Case #" + T + ": " + (coins.size() - D));
		writer.write("Case #" + T + ": " + (coins.size() - D) +"\n");

	}

	public static void main(String[] args) throws IOException{
//		String fileName = "resources/2015/round1C/C-test.in";
		String fileName = "resources/2015/round1C/C-small-attempt0.in";
//		String fileName = "resources/2015/round1C/A-small-attempt1.in";
//		String fileName = "resources/2015/round1C/A-small-attempt2.in";
//		String fileName = "resources/2015/round1C/A-large.in";
		new TaskCSmallOnly(fileName, fileName + ".out");
	}


}
