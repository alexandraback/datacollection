package com.greggc.codejam;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;

import com.greggc.codejam.utils.FileUtils;

public class Problem4 {
	private static final String FILE_NAME = "D-large";
	
	public void solve() {
		StringBuilder builder = new StringBuilder();
		File input = new File(FILE_NAME + ".in");
		if (input.exists()) {
			String[] strings = FileUtils.getFileAsString(input);
			int nbTestCases = Integer.parseInt(strings[0]);
			
			for (int i = 0; i < nbTestCases; i++){
				// Algo
				// Init vars
				int nbBlocks = Integer.parseInt(strings[1 + (i * 3)]);
				String[] naomiStrings = strings[2 + (i * 3)].split(" ");
				String[] kenStrings = strings[3 + (i * 3)].split(" ");
				double[] ken = new double[nbBlocks];
				double[] naomi = new double[nbBlocks];
				for (int j = 0; j < nbBlocks; j++) {
					naomi[j] = Double.parseDouble(naomiStrings[j]);
					ken[j] = Double.parseDouble(kenStrings[j]);
				}
				Arrays.sort(ken);
				Arrays.sort(naomi);
				if (i == 5) {
					int erihgoe = 0;
					erihgoe++;
				}
				int s1 = this.findS1(ken, naomi);
				int s2 = this.findS2(ken, naomi);
				
				builder.append(String.format(
						"Case #%s: %s %s\n",
						i + 1,
						s1,
						s2));
			}
			
			FileUtils.stringToFile(builder.toString(), FILE_NAME + ".out");
		}
	}
	
	public int findS1(double[] ken, double[] naomi) {
		int result = 0;
		
		ArrayList<Double> aKen = new ArrayList<Double>(ken.length);
		ArrayList<Double> aNaomi = new ArrayList<Double>(naomi.length);
		
		for (int i = 0; i < naomi.length; i++) {
			aNaomi.add(naomi[i]);
			aKen.add(ken[i]);
		}
		
		ArrayList<Double> kenPlus = new ArrayList<Double>();
		
		for (int i = 0; i < ken.length; i++) {
			if (ken[i] > naomi[naomi.length - 1]) {
				kenPlus.add(ken[i]);
			}
		}
		
		for (double i : kenPlus) {
			aKen.remove(i);
			aNaomi.remove(0);
		}
		
		for (int i = 0; i < aNaomi.size(); i++) {
			boolean oneInferior = false;
			int inferiorIndex = 0;
			for (int j = 0; j < aKen.size(); j++) {
				if (aKen.get(j) < aNaomi.get(i)) {
					oneInferior = true;
					inferiorIndex = j;
					break;
				}
			}
			
			if (oneInferior) {
				result++;
				aKen.remove(inferiorIndex);
			} else {
				aKen.remove(aKen.size() - 1);
			}
		}
		
		
		return result;
	}
	
	public int findS2(double[] ken, double[] naomi) {
		int result = naomi.length;
		ArrayList<Double> naomiUsed = new ArrayList<Double>();
		ArrayList<Double> kenUsed = new ArrayList<Double>();
		
		double maxKen = 0;
		for (int i = 0; i < ken.length; i++) {
			if (maxKen < ken[i]) {
				maxKen = ken[i];
			}
		}
		for (int i = 0; i < naomi.length; i++) {
			boolean found = false;
			double minSuperior = maxKen;
			for (int j = 0; j < ken.length; j++) {
				if (!kenUsed.contains(ken[j]) && ken[j] > naomi[i] && ken[j] <= minSuperior) {
					minSuperior = ken[j];
					found = true;
					break;
				}
			}
			if (found) {
				result--;
			}
			kenUsed.add(minSuperior);
		}
		
		return result;
	}
}
