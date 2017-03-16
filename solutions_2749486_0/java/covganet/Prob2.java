import java.io.*;
import java.util.*;

public class Prob2 {
	public static void main(String[] args) throws Exception {
		PrintWriter pw = new PrintWriter(new FileWriter("out2.txt"));
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
		
		int nrTests = Integer.parseInt(br.readLine());
		for(int testNr = 1; testNr <= nrTests; testNr++) {
			String[] strs = br.readLine().split(" ");
			int x = Integer.parseInt(strs[0]), y = Integer.parseInt(strs[1]);
			
			String res = "";
			if(x != 0) {
				char[] chr = new char[Math.abs(x) * 2 - 1];
				chr[0] = x > 0 ? 'E' : 'W';
				for(int i = 1; i < chr.length; i += 2) {
					chr[i] = x > 0 ? 'W' : 'E';
					chr[i + 1] = chr[0];
				}
				res = new String(chr);
			}
			if(y != 0) {
				char[] chr = new char[Math.abs(y) * 2];
				for(int i = 0; i < chr.length; i += 2) {
					chr[i] = y > 0 ? 'S' : 'N';
					chr[i + 1] = y > 0 ? 'N' : 'S';
				}
				res += new String(chr);
			}
			
			pw.println("Case #" + testNr + ": " + res);
		}
		
		br.close();
		pw.close();
	}
}
