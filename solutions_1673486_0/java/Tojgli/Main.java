package szarfos;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {
	private static List<String[]> input;
	private static List<String[]> prob;
	
	
	public static void main(String[] args) throws IOException {
		readFile();
		BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
		for (int i = 0; i < input.size(); i++) {
			int A = Integer.parseInt(input.get(i)[0]);
			int B = Integer.parseInt(input.get(i)[1]);
			double result = 0.0;
			if (A == 1) {
				double p1 = Double.parseDouble(prob.get(i)[0]);
				double first = p1 * (B - A + 1) + (1 - p1) * (2 * B - A + 2);
				double second = B+2;
				result = first;
				if (second < result)
					result = second;
			} else if (A == 2) {
				double p1 = Double.parseDouble(prob.get(i)[0]);
				double p2 = Double.parseDouble(prob.get(i)[1]);
				double first = p1 * p2 * (B - A + 1) + p1 * (1 - p2) * (2 * B - A + 2) + (1-p1) * p2 * (2 * B - A + 2) + (1-p1) * (1-p2) * (2 * B - A + 2);
				double second = p1 * p2 * (B - A + 3) + p1 * (1 - p2) * (B - A + 3) + (1-p1) * p2 * (2 * B - A + 4) + (1-p1) * (1-p2) * (2 * B - A + 4);
				double third = p1 * p2 * (B + 2) + p1 * (1 - p2) * (B + 2) + (1-p1) * p2 * (B + 2) + (1-p1) * (1-p2) * (B + 2);
				result = first;
				if (second < result)
					result = second;
				if (third < result)
					result = third;
				
			} else {
				double p1 = Double.parseDouble(prob.get(i)[0]);
				double p2 = Double.parseDouble(prob.get(i)[1]);
				double p3 = Double.parseDouble(prob.get(i)[2]);
				double first = p1 * p2 * p3 * (B - A + 1) + (1 - p1) * p2 * p3 * (2 * B - A + 2) + p1 * (1-p2) * p3 * (2 * B - A + 2) + p1 * p2 * (1-p3) * (2 * B - A + 2);
				first += p1 * (1-p2) * (1-p3) * (2 * B - A + 2) + (1-p1) * p2 * (1-p3) * (2 * B - A + 2) + (1-p1) * (1-p2) * p3 * (2 * B - A + 2);
				first += (1-p1) * (1-p2) * (1-p3) * (2 * B - A + 2);
				
				double second = p1 * p2 * p3 * (B - A + 3) + (1 - p1) * p2 * p3 * (2 * B - A + 4) + p1 * (1-p2) * p3 * (2 * B - A + 4) + p1 * p2 * (1-p3) * (B - A + 3);
				second += p1 * (1-p2) * (1-p3) * (2 * B - A + 4) + (1-p1) * p2 * (1-p3) * (2 * B - A + 4) + (1-p1) * (1-p2) * p3 * (2 * B - A + 4);
				second += (1-p1) * (1-p2) * (1-p3) * (2 * B - A + 4);
				
				double third = p1 * p2 * p3 * (B - A + 5) + (1 - p1) * p2 * p3 * (2 * B - A + 6) + p1 * (1-p2) * p3 * (B - A + 5) + p1 * p2 * (1-p3) * (B - A + 5);
				third += p1 * (1-p2) * (1-p3) * (B - A + 5) + (1-p1) * p2 * (1-p3) * (2 * B - A + 6) + (1-p1) * (1-p2) * p3 * (2 * B - A + 6);
				third += (1-p1) * (1-p2) * (1-p3) * (2 * B - A + 6);
				
				double fourth = B+2;
				result = first;
				if (second < result)
					result = second;
				if (third < result)
					result = third;
				if (fourth < result)
					result = fourth;
			}
			
			System.out.println("Number : " + result);
			int caseNum = i+1;
		    out.write("Case #" + caseNum + ": " + result);		
		    out.newLine();
		}	
		out.close();
	}		
	
	
	
	public static void readFile() {
		try {
			input = new ArrayList<String[]>();
			prob = new ArrayList<String[]>();
		    BufferedReader in = new BufferedReader(new FileReader("input.txt"));
		    String str;
		    in.readLine();
		    while ((str = in.readLine()) != null) {
		    	String[] n = str.split(" ");
		    	input.add(n);
		    	
		    	str = in.readLine();
		    	n = str.split(" ");
		    	prob.add(n);
		    }
		    in.close();
		} catch (IOException e) {
		}
	}
	

	

}
