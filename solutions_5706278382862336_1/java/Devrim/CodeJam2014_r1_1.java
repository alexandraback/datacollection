package org.devrimtuncer.round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

public class CodeJam2014_r1_1 {
	
	private static final String SAMPLE_FILE = "sample";
	private static final String SMALL_FILE = "small-practice";
	private static final String LARGE_FILE = "large-practice";

	private static final String PATH = "/Users/devrimtuncer/CodeJam/2014/r1c/1/";

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			String caseFileName = SMALL_FILE; // Do not add '.in' type, it'll be auto added

			List<Case> caseList = getCaseList(caseFileName);
			
			for (Case caseItem : caseList) {
				caseItem.solve();
			}
			
			writeToFile(caseFileName, caseList);// Do not add '.out' type, it'll be auto added

		} catch (Throwable t) {
			t.printStackTrace();
		}
	}

	private static class Case {
		private int id;
		private String status;

		// TODO: add other fields for case specific
		
		private String currentValue;
		private int count = 0;
		
		public Case(int id) {
			this.id = id;
		}

		public void solve() {
			// TODO: write your case solution logic here and set status
			String[] splitted = currentValue.split("/");
			double up = Long.parseLong(splitted[0]);
			double down = Long.parseLong(splitted[1]);
			
			double v = (up / down);
			solveP(v);
			
			
			this.status = "impossible";
		}
		
		private void solveP(double value) {
			count ++;
			double parent = value * 2;
			if(parent > 1) {
				
				double fractionalPart = parent % 1;
				double pow = Math.pow(2, 40 - count);
				double fixedFractionalPart = fractionalPart * pow;
				
				double afterFixFractionalPart = fixedFractionalPart % 1;
				if(afterFixFractionalPart == 0) {
					// finish
				} else {
					count = -1;
				}				
			}else if(parent == 1) {
				//finish
			} else {
				
				solveP(parent);
			}
		}

		@Override
		public String toString() {
			if(count != -1) {
				status = String.valueOf(count);			
			} else if(count > 40) {
				
			}
			return "Case #" + id + ": " + status;
		}
	}

	private static List<Case> getCaseList(String fileName) throws IOException {
		BufferedReader br = null;

		br = new BufferedReader(new FileReader(PATH + fileName + ".in"));

		int caseCount = Integer.parseInt(br.readLine());
		List<Case> caseList = new ArrayList<Case>(caseCount);

		int caseId = 1;

		String sCurrentLine = null;
		while ((sCurrentLine = br.readLine()) != null) {
			Case caseItem = new Case(caseId);

			caseItem.currentValue = sCurrentLine;
			
			caseList.add(caseItem);
			caseId ++;
		}

		try {
			if (br != null)
				br.close();
		} catch (IOException ex) {
			// Ignore
		}

		return caseList;
	}

	public static void writeToFile(String fileName, List<Case> caseList)
			throws IOException {
		File file = new File(PATH + fileName + ".out");

		// if file doesnt exists, then create it
		if (!file.exists()) {
			file.createNewFile();
		}

		FileWriter fw = new FileWriter(file.getAbsoluteFile());
		BufferedWriter bw = new BufferedWriter(fw);

		for (Case caseItem : caseList) {
			bw.write(caseItem + "\n");
			System.out.println(caseItem);
		}

		try {
			if (bw != null)
				bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
}
