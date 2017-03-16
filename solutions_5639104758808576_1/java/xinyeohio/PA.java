package codeJam2015;

import java.io.IOException;
import java.util.Arrays;

public class PA extends Cases {

	public static void operate(Case[] cases) {
		for(Case ca : cases) {
			String[] tmp = ca.input.get(0).split(" ");
			int maxlevel = Integer.parseInt(tmp[0]);
			//char[] audisChar = tmp[1].toCharArray();
			int len = maxlevel + 1;
			int[] audis = new int[len];
			for(int i = 0; i < len; i++)
				audis[i] = Integer.parseInt(tmp[1].substring(i, i + 1));
			System.out.println(maxlevel + " " + Arrays.toString(audis));
			if(maxlevel == 0) {
				ca.output += 0;
				continue;
			}
			int people = 0;
			int prefixSum = audis[0];
			for(int i = 1; i < len; i++) {
				if(audis[i] > 0 && prefixSum < i) {
					people += i - prefixSum;
					prefixSum = i + audis[i];
				} else {
					prefixSum += audis[i];
				}
			}
			ca.output += people;
		}
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = "A-large.in";
		int caseSize = 1;	/////////////////////////////////////// remember to set caseSize here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(args.length > 0)
			inputFile = args[0];
		String outputFile = inputFile.substring(0, inputFile.length() - 3) + ".out";
		Case[] cases = readAllCases(inputFile, caseSize);
		operate(cases);
		writeOutput(outputFile, cases);
	}
}
