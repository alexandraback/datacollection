package codeJam2015;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

public class CA extends Cases {

	static int R;
	static int C;
	static int W;
	
	public static void operate(Case[] cases) throws IOException {
		for(Case ca : cases) {
		//for(int nn = 0; nn < 1; nn++) {
			//Case ca = cases[0];
			String[] ins = ca.input.get(0).split(" ");
			R = Integer.parseInt(ins[0]);
			C = Integer.parseInt(ins[1]);
			W = Integer.parseInt(ins[2]);
			
			//System.out.println(R + " " + C + " " + W);
			
			// code here
			int first = C / W;
			first = first * R;
			
			//System.out.println(first);
			
			int m = C % W;
			
			if(first == 1 && m == 0) {
				ca.output += (first + W - 1);
				continue;
			} else if(first > 1 && m == 0) {
				ca.output += (first + W - 1);
				continue;
			}
			
			ca.output += (first + W);
			//System.out.println(ca.id + ": " + ca.output);
		}
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = "A-large.in";
		//inputFile = "as.in";
		int caseSize = 1;	//	--------------------------------------- change the size here accordingly
		if(args.length > 0)
			inputFile = args[0];
		String outputFile = inputFile.substring(0, inputFile.length() - 3) + ".out";
		Case[] cases = readAllCases(inputFile, caseSize);
		operate(cases);
		writeOutput(outputFile, cases);
	}
}
