package net.seungchul.googlecodejam.qual;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class D_DeceitfulWar {
	public static void main(String[] args) {
		try {
			Scanner scan = new Scanner(new File("D-large.in"));
			int nTests = Integer.parseInt(scan.nextLine());
			for (int i=1; i<=nTests; i++) {
				int nBlocks = Integer.parseInt(scan.nextLine());
				double[] blockNaomi = new double[nBlocks];
				double[] blockKen = new double[nBlocks];
				String[] blockStr = scan.nextLine().split(" ");
				for (int j=0; j<nBlocks; j++) {
					blockNaomi[j] = Double.parseDouble(blockStr[j]);
				}
				blockStr = scan.nextLine().split(" ");
				for (int j=0; j<nBlocks; j++) {
					blockKen[j] = Double.parseDouble(blockStr[j]);
				}
				
				Arrays.sort(blockNaomi);
				Arrays.sort(blockKen);
				// Deceitful
				int deceitful = 0;
				for (int j=0; j<nBlocks; j++) {
					boolean check = true;
					for (int k=j; k<nBlocks; k++) {
						if (blockNaomi[k] < blockKen[k-j]) {
							check = false;
							break;
						}
					}
					if (check) {
						deceitful = nBlocks-j;
						break;
					}
				}
				
				// Normal
				int normal = nBlocks;
				for (int j=0; j<nBlocks; j++) {
					boolean check = true;
					for (int k=j; k<nBlocks; k++) {
						if (blockKen[k] < blockNaomi[k-j]) {
							check = false;
							break;
						}
					}
					if (check) {
						normal = j;
						break;
					}
				}
				System.out.printf("Case #%d: %d %d\n", i, deceitful, normal);
			}
			scan.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}
