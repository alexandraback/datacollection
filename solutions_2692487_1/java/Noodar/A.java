package com.google.round1b.a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws Exception {
		// Scanner scanner = new Scanner(new File("input/A-sample.in"));
		// BufferedWriter bw = new BufferedWriter(new FileWriter(
		// "output/A-sample.output"), 32768);

//		Scanner scanner = new Scanner(new File("input/A-small-attempt1.in"));
//		BufferedWriter bw = new BufferedWriter(new FileWriter(
//				"output/A-small-attempt1.output"), 32768);

		 Scanner scanner = new Scanner(new File("input/A-large.in"));
		 BufferedWriter bw = new BufferedWriter(new
		 FileWriter("output/A-large.output"), 32768);

		long totalCase = Integer.valueOf(scanner.nextLine());
		for (int i = 1; i <= totalCase; i++) {
			String[] range = scanner.nextLine().split(" ");
			int headMote = Integer.valueOf(range[0]);
			int numberOfMote = Integer.valueOf(range[1]);

			String[] otherMotes = scanner.nextLine().split(" ");

			List<Integer> motes = new ArrayList<>();
			for (String s : otherMotes) {
				motes.add(Integer.valueOf(s));
			}
			Collections.sort(motes);
			int num = getOperationNum(headMote, motes);
			bw.write("Case #" + i + ": " + num);
			System.out.println("Case #" + i);
			if (i != totalCase) {
				bw.newLine();
			}
		}
		scanner.close();
		bw.close();
	}

	public static int getOperationNum(int headMote, List<Integer> otherMotes) {
		if (headMote <= 1) {
			return otherMotes.size();
		}

		int num = 0;
		for (int i = 0; i < otherMotes.size(); i++) {
			int m = otherMotes.get(i);
			if (num >= otherMotes.size()) {
				return otherMotes.size();
			}

			if (headMote > m) {
				headMote += m;
			} else if (i == otherMotes.size() - 1) {
				num++;
			} else if (m <= 1) {
				num++;
			} else {
				headMote += headMote - 1;
				num++;
				--i;
			}
		}

		return num;
	}
}