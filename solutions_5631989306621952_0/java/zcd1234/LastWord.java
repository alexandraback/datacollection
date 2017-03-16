package codejam2016;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

import tools.Tools;



public class LastWord {
	public static void main(String[] args) throws IOException {
		LastWord t = new LastWord();
		t.solve();
	}
	void test(){
		Tools.println('M'>'J');
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
			
			
			String output = "Case #"+caseN + ": "+getMin(s);
			System.out.println(output);
			out.println(output);
		}
		in.close();
		out.close();
		long timeUsed = System.currentTimeMillis()-startTime;
		Tools.println("total execution time is "+timeUsed);
	}
	String getMin(String s){
		String ms = ""+s.charAt(0);
		int N = s.length();
		for(int n=1;n<N;n++){
			char cn = s.charAt(n);
			char c0 = ms.charAt(0);
			if(cn - c0 > 0){
				ms = cn + ms;
			}else if(cn - c0 < 0){
				ms = ms + cn;
			}else{
				String ms1 = ms + cn;
				String ms2 = cn + ms;
				if(Tools.largerThan(ms1,ms2)>=0){
					ms = ms1;
				}else
					ms = ms2;
			}
		}
		return ms;
	}
}
