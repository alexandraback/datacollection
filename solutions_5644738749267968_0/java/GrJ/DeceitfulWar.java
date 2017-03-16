package eu.grzegorzjankowski;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Locale;
import java.util.StringTokenizer;

public class DeceitfulWar {

	public static void main(String[] args) {
		BufferedReader br = null;
		File file;

		Locale.setDefault(Locale.US);

		try {

			file = new File("c:\\CodeJam\\DeceitfulWar\\result.txt");
			if (file.exists())
				file.delete();
			file.createNewFile();

			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);

			br = new BufferedReader(new FileReader(
					"c:\\CodeJam\\DeceitfulWar\\D-small-attempt0.in"));

			int t = Integer.parseInt(br.readLine());
			for (int i = 0; i < t; i++) {
				int size = Integer.parseInt(br.readLine());
				StringTokenizer a = new StringTokenizer(br.readLine());
				StringTokenizer b = new StringTokenizer(br.readLine());
				ArrayList<Double> playerA = new ArrayList<>(size);
				ArrayList<Double> playerB = new ArrayList<>(size);
				for (int j = 0; j < size; j++) {
					playerA.add(Double.parseDouble(a.nextToken()));
					playerB.add(Double.parseDouble(b.nextToken()));
				}

				bw.write("Case #" + (i + 1) + ": " + solveIt(playerA, playerB));
				bw.newLine();
				System.out.println(i + 1 + " -> " + (i + 1.0) * 100 / t + "%");
			}
			bw.close();
			System.out.println("done");

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}

	}

	private static String solveIt(ArrayList<Double> playerA,
			ArrayList<Double> playerB) {
		Collections.sort(playerA);
		Collections.sort(playerB);

		ArrayList<Double> fairA = (ArrayList<Double>) playerA.clone();
		ArrayList<Double> fairB = (ArrayList<Double>) playerB.clone();
		ArrayList<Double> notFairA = playerA;
		ArrayList<Double> notFairB = playerB;

		return (solveItNotFair(notFairA, notFairB) + " " + solveItFair(fairA,
				fairB));

	}

	private static String solveItNotFair(ArrayList<Double> listA,
			ArrayList<Double> listB) {
		int playerA = 0;

		for (Double element : listA) {
			if (element > listB.get(0)) {
				playerA++;
				listB.remove((int)0);
			} else  {
				listB.remove((int)(listB.size()-1));
			} 
		}
		return Integer.toString(playerA);
	}

	private static String solveItFair(ArrayList<Double> fairA,
			ArrayList<Double> fairB) {
		int playerA = 0;
		int playerB = 0;

		for (Double element : fairA) {
			Integer i = findBigger(fairB, element);
			if (i != null) {
				playerB++;
				fairB.remove(fairB.get(i));
			} else {
				playerA++;
				fairB.remove(fairB.get(0));
			}
		}
		return Integer.toString(playerA);
	}

	private static Integer findBigger(ArrayList<Double> fairB, Double element) {
		int size = fairB.size();

		for (int i = 0; i < fairB.size(); i++) {
			if (fairB.get(i) > element)
				return i;
		}
		return null;

	}
}
