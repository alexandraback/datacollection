package com.codejam.problemb;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Small {

	public static void main(String[] args) {
		Scanner scanner;
		try {
			scanner = new Scanner(new File("D:/CodeJam/B-large.in"));
			File file = new File("D:/CodeJam/B-large.txt");

			// if file doesnt exists, then create it
			if (!file.exists()) {
				file.createNewFile();
			}

			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);

			int n = scanner.nextInt();
			for (int i = 1; i <= n; i++) {
				double c = scanner.nextDouble();
				double f = scanner.nextDouble();
				double x = scanner.nextDouble();
				int nFarm = 0;
				double time = 0;
				while (true) {
					if (x / (2 + f * nFarm) <= (c / (2 + f * nFarm) + x
							/ (2 + f * (nFarm + 1)))) {
						time += x / (2 + f * nFarm);
						break;
					} else {
						time += c / (2 + f * nFarm);
						nFarm++;
					}
				}
				bw.write("Case #" + i + ": " + time + "\n");
			}
			bw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
