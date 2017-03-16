package codejam2016;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import tools.Tools;

public class CountingSheep {
	boolean[] encountered;
	int count;
	public static void main(String[] args) throws IOException {
		CountingSheep t = new CountingSheep();
		t.solve();
	}
	void test(){
		for(int i=0;i<1000000;i++){
			Tools.println(getCount(i));
		}
	}
	public void solve() throws IOException{
		String inputFile = Tools.chooseFile();
		long startTime = System.currentTimeMillis();
		String outputFile = Tools.getOutputName(inputFile);
		BufferedReader in = new BufferedReader(new FileReader(inputFile));
		PrintWriter out = new PrintWriter(outputFile);
		int T = Integer.parseInt(in.readLine());//first line
		for(int caseN=1; caseN<=T;caseN++){

			long N = Long.parseLong(in.readLine());
			long n = getCount(N);
			String s = "";
			if(n==0)
				s = "INSOMNIA";
			else
				s = n + "";
			String output = "Case #"+caseN + ": "+s;
			System.out.println(output);
			out.println(output);
		}
		in.close();
		out.close();
		long timeUsed = System.currentTimeMillis()-startTime;
		Tools.println("total execution time is "+timeUsed);
	}
	long getCount(long N){
		if(N==0)
			return 0;
		encountered = new boolean[10];
		count = 0;
		long n = N;
		while(count < 10){
			String s = n + "";
			int L = s.length();
			for(int l=0;l<L;l++){
				int cl = s.charAt(l) - '0';
				if(!encountered[cl]){
					encountered[cl] = true;
					count++;
				}
			}
			n = n+N;
		}
		return n-N;
	}
}
