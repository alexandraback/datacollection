package codejam2016;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Fractiles {
	public static void main(String[] args) throws IOException {
		Fractiles t = new Fractiles();
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
			int[] kcs = Tools.intArray(in.readLine()," ");
			int K = kcs[0];
			int C = kcs[1];
			int S = kcs[2];
			String output = "Case #"+caseN + ": "+getResult(K,C,S);
			System.out.println(output);
			out.println(output);
		}
		in.close();
		out.close();
		long timeUsed = System.currentTimeMillis()-startTime;
		Tools.println("total execution time is "+timeUsed);
	}
	String getResult(int K,int C, int S){
		String re = "";
		int min = K / C;
		if(K%C!=0)
			min++;
		if(min > S)
			return "IMPOSSIBLE";
		int[] pos = new int[C];
		for(int i=0;i<C;i++){
			if(i<K)
				pos[i] = i+1;
			else
				pos[i] = K;
		}
		re = re + getLastIndex(pos,K);
		while(pos[C-1] < K){
			for(int i=0;i<C;i++){
				pos[i] = pos[i] + C;
				if(pos[i] > K)
					pos[i] = K;
			}
			re = re + " " + getLastIndex(pos,K);
		}
		return re;
	}
	long getLastIndex(int[] pos,int K){
		long index = pos[0];
		int C = pos.length;
		for(int i=1;i<C;i++){
			index = (index-1)*K + pos[i];
		}
		return index;
	}
}
