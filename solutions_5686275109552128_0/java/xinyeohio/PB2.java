package codeJam2015;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class PB2 extends Cases {

static int D;
	
	public static void operate(Case[] cases) {
		for(Case ca : cases) {
		//for(int nn = 0; nn < 1; nn++) {
			//Case ca = cases[4];
			
			D = Integer.parseInt(ca.input.get(0));
			String[] tmp = ca.input.get(1).split(" ");
			ArrayList<Integer> plates = new ArrayList<>();
			for(int i = 0; i < D; i++)
				plates.add(Integer.parseInt(tmp[i]));
			ca.output += check(plates);
			System.out.println(ca.id + " " + ca.output);
		}
	}
	
	private static int check(ArrayList<Integer> list) {
		Collections.sort(list);
		int maxi = list.get(list.size() - 1);
		if(maxi < 4)
			return maxi;
		ArrayList<Integer> list1 = new ArrayList<>();
		for(int i : list)
			list1.add(i - 1);
		int case1 = check(list1) + 1;
		
		int min = case1;
		
		int max1 = list.remove(list.size() - 1);
		int half = max1 / 2;
		
		for(int i = 2; i <= half; i++) {
			ArrayList<Integer> list2 = new ArrayList<>(list);
			int rest = max1 - i;
			list2.add(i);
			list2.add(rest);
			int case2 = check(list2) + 1;
			if(case2 < min)
				min = case2;
		}
		return min;
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = "B-small-attempt4.in";
		int caseSize = 2;	/////////////////////////////////////// remember to set caseSize here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(args.length > 0)
			inputFile = args[0];
		String outputFile = inputFile.substring(0, inputFile.length() - 3) + ".out";
		Case[] cases = readAllCases(inputFile, caseSize);
		operate(cases);
		writeOutput(outputFile, cases);
	}
}
