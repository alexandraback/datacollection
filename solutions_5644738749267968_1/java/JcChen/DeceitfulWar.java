package com.google.jam2014.QR;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class DeceitfulWar implements Comparable<DeceitfulWar> {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		FileInputStream fis = new FileInputStream(args[0]);
		PrintWriter pw = new PrintWriter(new File(args[1]));
		Scanner scanner = new Scanner(fis);
		int T = scanner.nextInt();
		for (int t = 0; t < T; t++) {
			int N = scanner.nextInt();
			DeceitfulWar[] list = new DeceitfulWar[N * 2];
			
			for (int i = 0; i < N; i++) {
				list[i] = new DeceitfulWar(scanner.nextDouble(), 1);
			}
			
			for (int i = 0; i < N; i++) {
				list[i + N] = new DeceitfulWar(scanner.nextDouble(), 2);
			}
			
			Arrays.sort(list);
			
			int deceitWin = 0;
			int player1Counter = 0;
			for (int i = 0; i < 2 * N; i++) {
				if (list[i].player == 1) {
					player1Counter++;
				} else {
					if (player1Counter > 0) {
						deceitWin++;
						player1Counter--;
					}
				}
			}
			
			int normalWin = N;
			int player2Counter = 0;
			for (int i = 0; i < 2 * N; i++) {
				if (list[i].player == 2) {
					player2Counter++;
				} else {
					if (player2Counter > 0) {
						normalWin--;
						player2Counter--;
					}
				}
			}
			
			pw.println("Case #" + (t+1) + ": " + deceitWin + " " + normalWin);
		}
		pw.close();
	}

	double value;
	int player;
	DeceitfulWar(double value, int player) {
		this.player = player;
		this.value = value;
	}
	
	@Override
	public int compareTo(DeceitfulWar that) {
		// TODO Auto-generated method stub
		return this.value > that.value ? -1 : 1;
	}
	
	
}
