import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class GcjB {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output2.txt"));
		int nrT = Integer.parseInt(br.readLine());
		for(int tnr = 1; tnr <= nrT; tnr++) {
			String[] strs = br.readLine().split(" ");
			int k = Integer.parseInt(strs[0]);
			int l = Integer.parseInt(strs[1]);
			int s = Integer.parseInt(strs[2]);
			String kStr = br.readLine();
			lStr = br.readLine();
			
			kChrs = kStr.toCharArray();
			cComb = new char[s];
			maxOcc = totOcc = totNr = 0;
			
			process(0);
			
			double res = maxOcc - (double)totOcc / (double)totNr;

			pw.println("Case #" + tnr + ": " + res);
		}
		br.close();
		pw.close();
	}
	
	static char[] kChrs = null;
	static String lStr = null;
	static char[] cComb = null;
	static int maxOcc = 0, totOcc = 0, totNr = 0;
	
	static void process(int from) {
		if(from == cComb.length) {
			int nrOcc = 0;
			String str = new String(cComb);
			for(int i = 0; i + lStr.length() <= cComb.length; i++) {
				if(str.substring(i).startsWith(lStr)) {
					nrOcc++;
				}
			}
			maxOcc = Math.max(maxOcc, nrOcc);
			totOcc += nrOcc;
			totNr++;
			return;
		}
		
		for(int i = 0; i < kChrs.length; i++) {
			cComb[from] = kChrs[i];
			process(from + 1);
		}
	}
}
