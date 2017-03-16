package andresrcb.codejam14.qual.solutions;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.TreeSet;

public class ProblemD {

	public static void main(String[] args) {
		try {
		String fileName;
		String outputName;
		int runType = 1;
		switch(runType) {
		case 0:
			fileName = "/Users/andrescontreras/Development/codeJamIO/qualification/4/D-sample.in";
			outputName = "/Users/andrescontreras/Development/codeJamIO/qualification/4/D-sample.out";
			break;
		case 1:
			fileName = "/Users/andrescontreras/Development/codeJamIO/qualification/4/D-small-attempt0.in";
			outputName = "/Users/andrescontreras/Development/codeJamIO/qualification/4/D-small-attempt0.out";
			break;
		default:
			fileName = "/Users/andrescontreras/Development/codeJamIO/qualification/4/D-large.in";
			outputName = "/Users/andrescontreras/Development/codeJamIO/qualification/4/D-large.out";
		}

		
			BufferedReader r = new BufferedReader(new FileReader(fileName));
			Scanner s = new Scanner(r);
			
			int cases = s.nextInt();
			int blocks;
			int y, z;
			String[] results = new String[cases];
			double blockWeight;
			TreeSet<Double> naomiBlocks, kenBlocks,naomiWarBlocks,kenWarBlocks;
			Double naomi, ken;
			for (int t = 1; t <= cases; ++t) {
				blocks = s.nextInt();
				y = 0;
				z = 0;
				naomiBlocks = new TreeSet<Double>();
				kenBlocks = new TreeSet<Double>();
				naomiWarBlocks = new TreeSet<Double>();
				kenWarBlocks = new TreeSet<Double>();
				for (int i = 0; i<blocks;++i) {
					blockWeight = s.nextDouble();
					naomiBlocks.add(blockWeight);
					naomiWarBlocks.add(blockWeight);
				}
				for (int i = 0; i<blocks;++i) {
					blockWeight = s.nextDouble();
					kenBlocks.add(blockWeight);
					kenWarBlocks.add(blockWeight);
				}
				for (int i = 0; i<blocks;++i) {
				//war
					naomi = naomiWarBlocks.pollFirst();
					ken = kenWarBlocks.ceiling(naomi);
					if(ken!=null){
						kenWarBlocks.remove(ken);
					}
					else {
						++z;
						kenWarBlocks.pollFirst();
					}
					
					//deceitful war
					if(naomiBlocks.first() < kenBlocks.first() ||
							naomiBlocks.last() < kenBlocks.last()) {
						naomiBlocks.pollFirst();
						kenBlocks.pollLast();
					}
					else {
						naomi = naomiBlocks.ceiling(kenBlocks.pollFirst());
						naomiBlocks.remove(naomi);
						++y;
					}
				}
				
				results[t-1] ="Case #" + t + ": " + y + " " + z;
				
				
				
			}
			
			s.close();
			r.close();
		



			// TODO Write Output
			
			File outputFile = new File(outputName);

			if (!outputFile.exists()) {
				System.out.println(outputFile.getName());
				outputFile.createNewFile();
			}

			FileWriter fw = new FileWriter(outputFile.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			
			for (int i = 0; i<cases;++i) {
				bw.write(results[i] + "\n");				
			}			
			bw.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
