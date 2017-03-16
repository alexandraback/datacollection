package net.seungchul.googlecodejam.qual;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class C_MinesweeperMaster {
	public static void main(String[] args) {
		try {
			Scanner scan = new Scanner(new File("C-small-attempt4.in"));
			int nTests = Integer.parseInt(scan.nextLine());
			for (int i=1; i<=nTests; i++) {
				String[] line = scan.nextLine().split(" ");
				int nRows = Integer.parseInt(line[0]);
				int nCols = Integer.parseInt(line[1]);
				int nMine = Integer.parseInt(line[2]);

				String rslt = "";
				if (nRows == 1 && nCols > nMine) {
					for (int j=1; j<=nCols; j++) {
						if (j==1) rslt += "c";
						else if (j <= nCols-nMine) rslt += ".";
						else rslt += "*";
					}
				} else if (nRows > nMine && nCols == 1) {
					for (int j=1; j<=nRows; j++) {
						if (j==1) rslt += "c";
						else if (j <= nRows-nMine) rslt += "\n.";
						else rslt += "\n*";
					}
				} else if (nRows * nCols - nMine == 1) {
					for (int j=1; j<=nRows; j++) {
						for (int k=1; k<=nCols; k++) {
							if (j==1 && k==1) rslt +="c";
							else rslt += "*";
						}
						if (j < nRows) rslt += "\n";
					}
				} else if (nRows * nCols - nMine >= 4) {
					int remain = nRows * nCols - nMine;
					int[] eachRow = new int[nRows+1];
					for (int j=1; j<=nRows; j++) {
						eachRow[j] = 0;
					}
					
					boolean found = false;
					for (int j=remain/2; j>=2; j--) {
						if (j > nCols) continue;
						int myRemain = remain;
						eachRow[1] = j;
						eachRow[2] = j;
						myRemain -= 2*j;
						if (myRemain == 0) {
							found = true;
							break;
						}
						for (int k=3; k<=nRows; k++) {
							if (myRemain >= j+2) {
								eachRow[k] = j;
								myRemain -= j;
							} else if (myRemain == j+1 && j>=3) {
								eachRow[k] = j-1;
								myRemain -= j-1;
							} else if (myRemain >= 2 && j>=myRemain) {
									eachRow[k] = myRemain;
									myRemain = 0;
									found = true;
									break;
							} else if (myRemain == 0) {
								found = true;
								break;
							}
						}
						if (found) break;
					}
					
					if (found) {
						for (int j=1; j<=nRows; j++) {
							for (int k=1; k<=nCols; k++) {
								if (j == 1 && k == 1) rslt += "c";
								else if (k<=eachRow[j]) rslt += ".";
								else rslt += "*";
							}
							if (j < nRows) rslt += "\n";
						}
					} else {
						rslt = "Impossible";
					}
					/*
					eachRow[1] = 2;
					eachRow[2] = 2;
					remain -= 4;
					int nJoinRows = 2;
					int rowTurn = 3;
					while (remain != 0) {
						if (remain == 1) {
							if (rowTurn > nJoinRows) {
								rslt = "Impossible";
								break;
							} else {
								if (eachRow[rowTurn] < nCols) {
									eachRow[rowTurn]++;
									remain--;
								} else {
									rowTurn++;
								}
							}
						} else if (remain >= 2) {
							if (eachRow[1] < nCols) {
								eachRow[1] += 1;
								eachRow[2] += 1;
								remain -= 2;
							} else {
								if (nJoinRows < nRows) {
									eachRow[nJoinRows+1] = 2;
									nJoinRows++;
									remain-=2;
								} else {
									if (rowTurn > nJoinRows) {
										rslt = "Impossible";
										break;
									} else {
										if (eachRow[rowTurn] < nCols) {
											eachRow[rowTurn]++;
											remain--;
										} else {
											rowTurn++;
										}
									}
								}
							}
						}
					}
					if (remain == 0) {
						for (int j=1; j<=nRows; j++) {
							for (int k=1; k<=nCols; k++) {
								if (j == 1 && k == 1) rslt += "c";
								else if (k <= eachRow[j]) rslt += ".";
								else rslt += "*";
							}
							if (j < nRows) rslt += "\n";
						}
					}
					*/
				} else {
					rslt = "Impossible";
				}
				System.out.printf("Case #%d:\n%s\n", i, rslt);
			}
			scan.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}
