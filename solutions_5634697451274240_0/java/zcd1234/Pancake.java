package codejam2016;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class Pancake {
	public static void main(String[] args) throws IOException {
		Pancake t = new Pancake();
		t.solve();
	}
	public void solve() throws IOException{
		String inputFile = Tools.chooseFile();
		long startTime = System.currentTimeMillis();
		String outputFile = Tools.getOutputName(inputFile);
		BufferedReader in = new BufferedReader(new FileReader(inputFile));
		PrintWriter out = new PrintWriter(outputFile);
		int T = Integer.parseInt(in.readLine());//first line
		for(int caseN=1; caseN<=T;caseN++){
			String s = in.readLine();
			s = s+"+";
			
			
			String output = "Case #"+caseN + ": "+getCount(s);
			System.out.println(output);
			out.println(output);
		}
		in.close();
		out.close();
		long timeUsed = System.currentTimeMillis()-startTime;
		Tools.println("total execution time is "+timeUsed);
	}
	int getCount(String s){
		int count = 0;
		int L = s.length();
		char c0 = s.charAt(0);
		for(int i=1;i<L;i++){
			char c1 = s.charAt(i);
			if(c1!=c0)
				count++;
			c0 = c1;
		}
		return count;
	}
}
