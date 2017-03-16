import java.io.*;
import java.util.*;

public class Prob1 {
	public static final String vowels = "aeiou";
	
	public static void main(String[] args) throws Exception {
		PrintWriter pw = new PrintWriter(new FileWriter("out1.txt"));
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		
		int nrTests = Integer.parseInt(br.readLine());
		for(int testNr = 1; testNr <= nrTests; testNr++) {
			String[] strs = br.readLine().split(" ");
			int res = 0;
			int n = Integer.parseInt(strs[1]);
			char[] chr = strs[0].toCharArray();
			int lastJ = -1;
			for(int i = 0; i < chr.length; i++) {
				if(i > 0 && i <= lastJ - n + 1) {
					res += chr.length - lastJ;
					continue;
				}
				int nrC = i == 0 ? 0 : lastJ - i + 1;
				boolean isOk = false;
				for(int j = lastJ + 1; j < chr.length; j++) {
					if(vowels.indexOf(chr[j]) == -1) {
						nrC++;
						if(nrC >= n) {
							isOk = true;
						}
					} else {
						nrC = 0;
					}
					if(isOk) {
						res += chr.length - j;
						lastJ = j;
						break;
					}
				}
				if(!isOk) {
					break;
				}
			}
			
			pw.println("Case #" + testNr + ": " + res);
		}
		
		br.close();
		pw.close();
	}
}
