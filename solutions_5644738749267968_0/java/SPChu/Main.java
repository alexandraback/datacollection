package com.codejam.problemd;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner;
		try {
			scanner = new Scanner(new File("D:/CodeJam/D-small-attempt2.in"));
			// scanner = new Scanner(new File("D:/CodeJam/input.txt"));
			File file = new File("D:/CodeJam/D-small-attempt2.txt");

			// if file doesnt exists, then create it
			if (!file.exists()) {
				file.createNewFile();
			}

			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);

			int n = scanner.nextInt();
			int m;
			LinkedList<Double> massNaomi;
			LinkedList<Double> massKen;
			LinkedList<Double> massKen2;
			int y, z;
			for (int i = 1; i <= n; i++) {
				y = 0;
				z = 0;
				massNaomi = new LinkedList<>();
				massKen = new LinkedList<>();
				massKen2 = new LinkedList<>();
				m = scanner.nextInt();
				for (int j = 0; j < m; j++) {
					massNaomi.add(scanner.nextDouble());
				}
				for (int j = 0; j < m; j++) {
					massKen.add(scanner.nextDouble());
				}

				Collections.sort(massNaomi, Collections.reverseOrder());
				Collections.sort(massKen);
				Double maxKen;
				Double minKen;
				massKen2.addAll(massKen);
				// System.out.println(massNaomi);
				// System.out.println(massKen);

				// If Naomi playing War
				for (Double d : massNaomi) {
					maxKen = massKen.getLast();
					if (d > maxKen) {
						z++;
						massKen.removeFirst();
					} else {
						// remove next closest number to d from massKen
						for (Double d2 : massKen) {
							if (d2 > d) {
								massKen.remove(d2);
								break;
							}
						}
					}
				}

				Collections.sort(massNaomi);
				// System.out.println(massNaomi);
				// System.out.println(massKen2);
				// if Maomi playing Deceitful War
				for (Double d : massKen2) {
					for (Double d2 : massNaomi) {
						if (d2 > d) {
							y++;
							massNaomi.remove(d2);
							break;
						}
					}
				}

				// System.out.println("Case #" + i + ": " + y + " " + z + "\n");
				bw.write("Case #" + i + ": " + y + " " + z + "\n");
			}
			bw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
