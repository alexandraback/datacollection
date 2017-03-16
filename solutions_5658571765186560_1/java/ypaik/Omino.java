package ProblemD;

import java.io.*;
import java.util.*;

public class Omino {

	public static void main(String[] args) throws Exception {
		//BufferedReader br = new BufferedReader(new FileReader("D-sample.in"));
		//BufferedReader br = new BufferedReader(new FileReader("D-small-attempt1.in"));
		BufferedReader br = new BufferedReader(new FileReader("D-large.in"));
		
		//File file = new File("D-sample.out");
		//File file = new File("D-small.out");
		File file = new File("D-large.out");
		
		if(!file.exists()) file.createNewFile();
		FileWriter fw = new FileWriter(file.getAbsolutePath());
		BufferedWriter bw = new BufferedWriter(fw);
		
		int numberOfCases = Integer.parseInt(br.readLine());
		for(int caseNum = 1; caseNum <= numberOfCases; caseNum++) {
			
			String winner = "GABRIEL";
			String[] setup = br.readLine().split(" ");
			int x = Integer.parseInt(setup[0]);
			int r = Integer.parseInt(setup[1]);
			int c = Integer.parseInt(setup[2]);

			int minDim = Math.min(r, c);
			int maxDim = Math.max(r, c);
			
			if(x >= 7) winner = "RICHARD";
			if((r*c)%x != 0) winner = "RICHARD";
			if(maxDim < x) winner = "RICHARD";
			if(x > 2 && minDim < Math.sqrt(x)) winner = "RICHARD";
			if(x == 4 && minDim == 2) winner = "RICHARD";
			if(x == 5 && minDim == 2) winner = "RICHARD";
			if(x == 5 && minDim == 3 && (maxDim == 5 || maxDim % 5 != 0)) winner = "RICHARD";
			if(x == 6 && minDim == 2) winner = "RICHARD";
			if(x == 6 && minDim <= 3) winner = "RICHARD";
			
			String output = "Case #" + caseNum + ": " + winner + "\n";
			bw.write(output);
		}
		
		bw.close();
	}

}
