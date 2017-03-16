package com.google.codejam;

import java.util.Scanner;

public class KingdomRushSolver {

	private int[] lv1Stars;
	private int[] lv2Stars;
	
	public KingdomRushSolver(int numOfLevel) {
		this.lv1Stars = new int[numOfLevel];
		this.lv2Stars = new int[numOfLevel];
	}
	
	public void addLevel(int level, int lv1, int lv2) {
		this.lv1Stars[level] = lv1;
		this.lv2Stars[level] = lv2;
	}
	
	public int getMinRound() {
		int round = 0;
		int numOfStar = 0;
		int prevRound = 0;
		boolean[] lv1Complete = new boolean[this.lv1Stars.length];
		boolean[] lv2Complete = new boolean[this.lv2Stars.length];
		
		do {
			prevRound = round;
			//complete all the available lv2
			for (int i = 0; i < this.lv2Stars.length; i++) {
				if (lv2Complete[i] == false) {
					if (this.lv2Stars[i] <= numOfStar) {
						if (lv1Complete[i] == true) {
							numOfStar += 1;
						} else {
							numOfStar += 2;
						}
						lv1Complete[i] = true;
						lv2Complete[i] = true;
						round++;
						//System.err.printf("Level %d lv2 Complete%n", i);
					}
				}
			}
			//complete one lv1 if still have unsolved lv2
			if (round == prevRound) {
				for (int i = 0; i < this.lv1Stars.length; i++) {
					if (lv1Complete[i] == false) {
						if (this.lv1Stars[i] <= numOfStar) {
							numOfStar += 1;
							lv1Complete[i] = true;
							round++;
							break;
						}
					}
				}
			}
			
		} while (round > prevRound);
		
		if (numOfStar < this.lv1Stars.length * 2) {
			return -1;
		} else {
			return round;
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		final int totalNum = Integer.parseInt(scanner.nextLine());
		for (int i = 0; i < totalNum; i++) {
			int numOfLevel = Integer.parseInt(scanner.nextLine());
			KingdomRushSolver solver = new KingdomRushSolver(numOfLevel);
			for (int j = 0; j < numOfLevel; j++) {
				int lv1 = scanner.nextInt();
				int lv2 = scanner.nextInt();
				solver.addLevel(j, lv1, lv2);
				scanner.nextLine();
			}
			int answer = solver.getMinRound();
			System.out.printf("Case #%d: %s%n", i+1, (answer > 0 ? String.valueOf(answer) : "Too Bad"));
		}
	}

}
