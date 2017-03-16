package com.google.Brattleship;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Brattleship {

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));

		int numCases = Integer.parseInt(br.readLine());

		for (int i = 0; i < numCases; i++) {
			solve(br, i + 1);
		}

	}

	private static void solve(BufferedReader br, int i) throws IOException {

		String[] RCW = br.readLine().split(" ");
		
		int R = Integer.parseInt(RCW[0]);
		int C = Integer.parseInt(RCW[1]);
		int W = Integer.parseInt(RCW[2]);
		
		int timeTakenToFindTheShip = ((R * (C / W)) - (C % W == 0 ? 1 : 0)) + W;
		
		System.out.println("Case #" + i + ": " + timeTakenToFindTheShip);

		return;
	}

}
