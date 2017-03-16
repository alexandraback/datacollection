package codejam2013.round1C;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.SortedMap;
import java.util.TreeMap;
import java.util.Map.Entry;

public class ProblemC {

	public static class Attack {
		public int from;
		public int to;
		public int strength;
		public Attack(int from, int to, int strength) {
			this.from = from;
			this.to = to;
			this.strength = strength;
		}
		@Override
		public String toString() {
			return from + "-" + to + ": " + strength;
		}
	}

	private static final int FIRST_DAY = 0;
	private static final int ATTACKS = 1;
	private static final int FIRST_FROM = 2;
	private static final int FIRST_TO = 3;
	private static final int FIRST_STRENGTH = 4;
	private static final int INTERVAL = 5;
	private static final int SHIFT = 6;
	private static final int DELTA_STRENGTH = 7;

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "C-small-attempt1";
			File folder = new File(new File("files", "codejam2013"), "round1C");
			File inputFile = new File(folder, fileName + ".in");
			File outputFile = new File(folder, fileName + ".out");
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new PrintWriter(new FileWriter(outputFile));
			int count = Integer.parseInt(reader.readLine());
			for (int i = 0; i < count; i++) {
				int n = Integer.parseInt(reader.readLine());
				int[][] tribes = new int[n][8];
				for (int tribe = 0; tribe < n; tribe++) {
					String[] parameters = reader.readLine().split("\\s");
					for (int j = 0; j < parameters.length; j++) {
						tribes[tribe][j] = Integer.parseInt(parameters[j]);
					}
				}
				writer.printf("Case #%d: %s\n", i + 1, solveIt(tribes, n));
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			close(reader);
			close(writer);
		}
		System.out.println("Done.");
	}

	private static String solveIt(int[][] tribes, int n) {
		SortedMap<Integer, List<Attack>> schedule = new TreeMap<Integer, List<Attack>>();
		for (int tribe = 0; tribe < n; tribe++) {
			Integer day = tribes[tribe][FIRST_DAY];
			int strength = tribes[tribe][FIRST_STRENGTH];
			int from = tribes[tribe][FIRST_FROM];
			int to = tribes[tribe][FIRST_TO];
			for (int attack = 0; attack < tribes[tribe][ATTACKS]; attack++) {
				List<Attack> dailySchedule = schedule.get(day);
				if (dailySchedule == null) {
					dailySchedule = new ArrayList<Attack>();
					schedule.put(day, dailySchedule);
				}
				dailySchedule.add(new Attack(from, to, strength));
				day += tribes[tribe][INTERVAL];
				strength += tribes[tribe][DELTA_STRENGTH];
				from += tribes[tribe][SHIFT];
				to += tribes[tribe][SHIFT];
			}
		}
		int[] wall;
		int limit = 1000000/2;
		int[] nextWall = new int[limit*2+1];
		int successfulAttacks = 0;
		for (Entry<Integer, List<Attack>> dailySchedule : schedule.entrySet()) {
			wall = Arrays.copyOf(nextWall, nextWall.length);
//			Integer day = dailySchedule.getKey();
//			System.out.println(day + ":");
			for (Attack attack : dailySchedule.getValue()) {
				boolean succeeded = false;
//				System.out.println("   " + attack);
				for (int i = attack.from; i < attack.to; i++) {
//					System.out.print("      " + i + ": " + wall[i+limit]);
					if (wall[i+limit] < attack.strength) {
//						System.out.println(" X");
						succeeded = true;
						nextWall[i+limit] = Math.max(attack.strength, nextWall[i+limit]);
					} else {
//						System.out.println(" failed");
					}
				}
				if (succeeded) {
					successfulAttacks++;
				}
			}
		}
		return String.valueOf(successfulAttacks);
	}

	public static int[] parseIntegers(String line) {
		String[] strings = line.split("\\s");
		int[] numbers = new int[strings.length];
		for (int i = 0; i < strings.length; i++) {
			numbers[i] = Integer.parseInt(strings[i]);
		}
		return numbers;
	}

	private static void close(Closeable file) {
		if (file != null) {
			try {
				file.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
