package codejam.y2014.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.HashSet;

public class ProblemB {
	
	private static final DecimalFormat df = new DecimalFormat("#.0000000");

	public double calcu(double C, double F, double X) {
		
		if (F <= 0) {
			return X / 2;
		}
		int k = 0;
		double noBuyingTime = X / (F * k + 2);
		double nextByingOppTime = C / (F * k + 2);
		double buyingTime = nextByingOppTime + X / (F* (k+1) + 2);
		double seconds = 0;
		while(noBuyingTime > buyingTime) {
			seconds += nextByingOppTime;
			k++;
			noBuyingTime = X / (F * k + 2);
			nextByingOppTime = C / (F * k + 2);
			buyingTime = nextByingOppTime + X / (F* (k+1) + 2);
		}
		seconds += X / (F* k + 2);
		
		return seconds;
	}
	
	
	public ProblemB() {
	}
	
	
	                 
	String process( String line) {
		String[] sp = line.split(" ");
		double C = Double.parseDouble(sp[0]);
		double F = Double.parseDouble(sp[1]);
		double X= Double.parseDouble(sp[2]);
		double time = this.calcu(C, F, X);
		return df.format(time);
		
	}
	
	

	
	
	String readBlock(BufferedReader br) throws IOException {
	
		String line = br.readLine();
		return this.process(line);		
	}
	
	
	public ArrayList<String> read(BufferedReader br) throws NumberFormatException, IOException {
		ProblemB problemA = new ProblemB();
		 ArrayList<String> results = new  ArrayList<String>();
		int cases = Integer.parseInt(br.readLine());
		for (int i=1; i<=cases; i++) {
			String result = problemA.readBlock(br);
			results.add("Case #" + i + ": " + result);
		}
		return results;
	}
	
	
	public ArrayList<String> read(String file) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new FileReader(file));
		ArrayList<String> results = this.read(br);
		br.close();
		return results;
	}
	
	
	
	public void writeResult(ArrayList<String> results, String output) throws IOException {
		BufferedWriter bw = new BufferedWriter(new FileWriter(output));
		for (int i=0; i<results.size(); i++) {
			
			bw.write(results.get(i));
			bw.newLine();
		}
		bw.close();
	}
	
	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
	
		
		//String file_name = "b-test";
		//String file_name = "B-small-attempt0.in";
		String file_name = "B-large.in";
		///String file_name = "A-test";
		String test = "src/input/" + file_name;
			
		String output = "src/output/" + file_name;
		System.out.println(output);
		ProblemB problemA = new ProblemB();
		ArrayList<String> results = problemA.read(test);
		for (String result : results) {
			System.out.println(result);
		}
		problemA.writeResult(results, output);
	}
	

}
