package net.seungchul.googlecodejam.qual;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class B_CookieClickerAlpha {
	public static void main(String[] args) {
		try {
			Scanner scan = new Scanner(new File("B-large.in"));
			int nTests = Integer.parseInt(scan.nextLine());
			for (int i=1; i<=nTests; i++) {
				String[] line = scan.nextLine().split(" ");
				double C = Double.parseDouble(line[0]);
				double F = Double.parseDouble(line[1]);
				double X = Double.parseDouble(line[2]);

				double cps = 2.0;
				double totalTime = 0;
				while(true) {
					double timeToXWithoutBuy = X / cps;
					double timeToXWithBuy = (C / cps) + (X / (cps+F));
					if (timeToXWithoutBuy < timeToXWithBuy) {
						totalTime += timeToXWithoutBuy;
						break;
					} else {
						totalTime += C / cps;
						cps += F;
					}
				}
				
				System.out.printf("Case #%d: %.7f\n", i, totalTime);
			}
			scan.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}
