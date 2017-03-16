package codeJam2015;

import java.io.IOException;

public class OminousOmino extends Cases {

	static int N;
	static int R;
	static int C;
	
	public static void operate(Case[] cases) {
		for(Case ca : cases) {
		//for(int nn = 0; nn < 1; nn++) {
			//Case ca = cases[55];
			String[] tmp = ca.input.get(0).split(" ");
			N = Integer.parseInt(tmp[0]);
			R = Integer.parseInt(tmp[1]);
			C = Integer.parseInt(tmp[2]);
			
			if(check())
				ca.output = "GABRIEL";
			else
				ca.output = "RICHARD";
			System.out.println(N + " " + R + " " + C + " " + ca.output);
		}
	}
	
	private static boolean check() {
		int maxOfMin = N / 2;
		int longer = R > C ? R : C;
		int shorter = R > C ? C : R;
		if(N > longer)
			return false;
		int area = R * C;
		int remains = area - N;
		if(remains < 0)
			return false;
		if(remains % N != 0)
			return false;
		if(N == 2)
			return true;
		remains = N - shorter;
		System.out.println(longer + " " + shorter + " " + remains);
		if(remains > shorter)
			return false;
		if(remains == shorter && shorter > 1)
			return false;
		return true;
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = "D-small-attempt2.in";
		int caseSize = 1;	/////////////////////////////////////// remember to set caseSize here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(args.length > 0)
			inputFile = args[0];
		String outputFile = inputFile.substring(0, inputFile.length() - 3) + ".out";
		Case[] cases = readAllCases(inputFile, caseSize);
		operate(cases);
		writeOutput(outputFile, cases);
	}
}
