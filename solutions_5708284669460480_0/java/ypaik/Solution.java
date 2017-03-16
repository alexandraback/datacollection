package ProblemB;

import java.io.*;
import java.util.*;

public class Solution {

	public static void main(String[] args) throws Exception {
		//BufferedReader br = new BufferedReader(new FileReader("B-sample.in"));
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt1.in"));
		//BufferedReader br = new BufferedReader(new FileReader("B-large-practice.in"));
		
		//File file = new File("B-sample.out");
		File file = new File("B-small.out");
		//File file = new File("B-large.out");
		
		if(!file.exists()) file.createNewFile();
		FileWriter fw = new FileWriter(file.getAbsolutePath());
		BufferedWriter bw = new BufferedWriter(fw);
		
		int numberOfCases = Integer.parseInt(br.readLine());
		for(int caseNum = 1; caseNum <= numberOfCases; caseNum++) {
			
			String[] setup = br.readLine().split(" ");
			int k = Integer.parseInt(setup[0]);
			int l = Integer.parseInt(setup[1]);
			int s = Integer.parseInt(setup[2]);
			
			HashMap <Character, Double> kMap = new HashMap <Character, Double> ();
			String kString = br.readLine();
			for(int i = 0; i < k; i++) {
				char current = kString.charAt(i);
				if(kMap.containsKey(current)) kMap.put(current, kMap.get(current) + (1.0 / k));
				else kMap.put(current, 1.0 / k);
			}
			
			String target = br.readLine();
			int repetition = 0;
			for(int i = 1; i < l; i++) {
				if(target.substring(i, l).equals(target.substring(0, l - i))) repetition++;
			}
			
			int maximum = (s - l)/(l-repetition) + 1;
			double possibilities = 1.0;
			
			for(int i = 0; i < l; i++) {
				char current = target.charAt(i);
				if(!kMap.containsKey(current)) maximum = 0;
				else possibilities *= kMap.get(current);
			}
  
			double pay = 0.0;
			for(int i = maximum; i > 0; i--) {
				pay += i * Math.pow(possibilities, i);
			}
			
			double remaining = maximum > pay ? maximum - pay : 0.0;
			
			String output = "Case #" + caseNum + ": " + remaining + "\n";
			System.out.println(output);
			bw.write(output);
		}
		
		bw.close();
	}
	
}
