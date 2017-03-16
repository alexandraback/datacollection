package GCJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class GCJ2B {

	static int T;
	static BufferedReader br;
	static FileWriter fstream;
	static BufferedWriter out ;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		T = readT();
		for (int t = 0; t < T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			String ans = "";
			for (int i = 0; i < Math.abs(x); i++) {
				if(x<0)
					ans += "EW";
				else
					ans += "WE";
			}
			for (int i = 0; i < Math.abs(y); i++) {
				if(y<0)
					ans+="NS";
				else
					ans+="SN";
			}
			printAns("Case #"+(t+1)+": "+ans);
		}
		out.close();
	}

	private static int readT() throws IOException {
		br = new BufferedReader(new FileReader("inB.txt"));
		return Integer.parseInt(br.readLine());
	}

	private static void printAns(String ans) throws IOException {
		if (fstream == null) {
			fstream = new FileWriter("out.txt");
			out = new BufferedWriter(fstream);
		}
		out.write(ans + "\n");
	}
}
