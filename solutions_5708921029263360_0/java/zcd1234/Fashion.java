package codejam2016;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

import tools.TT;

public class Fashion {
	int J,P,S,K;
	String sl;
	public static void main(String[] args) throws IOException {
		new Fashion().solve();
	}
	public void solve() throws IOException{
		String inputFile = TT.chooseFile();
		long startTime = System.currentTimeMillis();
		String outputFile = TT.getOutputName(inputFile);
		BufferedReader in = new BufferedReader(new FileReader(inputFile));
		PrintWriter out = new PrintWriter(outputFile);
		int T = Integer.parseInt(in.readLine());//first line
		for(int caseN=1; caseN<=T;caseN++){
			int[] line = TT.intArray(in.readLine(), " ");
			J = line[0];
			P = line[1];
			S = line[2];
			K = line[3];
			sl = "";
			String output = "Case #"+caseN + ": "+getMax();
			output += sl;
			System.out.println(output);
			out.println(output);
		}
		in.close();
		out.close();
		long timeUsed = System.currentTimeMillis()-startTime;
		TT.println("total execution time is "+timeUsed);
	}
	long getMax(){
		int[][] jp = new int[S+1][S+1];
		int[][] js = new int[S+1][S+1];
		int[][] ps = new int[S+1][S+1];
		long count = 0;
		for(int j=1;j<=J;j++){
			for(int p=1;p<=P;p++){
				for(int s=1;s<=S;s++){
					if(jp[j][p]>=K || js[j][s]>=K ||ps[p][s]>=K){
						continue;
					}else{
						count++;
						sl = sl + "\n" + j + " " + p + " " + s;
						jp[j][p] = jp[j][p]+1;
						js[j][s] = js[j][s]+1;
						ps[p][s] = ps[p][s]+1;
						//TT.println(j + " " + p + " " + s);
					}
				}
			}
		}
		return count;
	}
}
