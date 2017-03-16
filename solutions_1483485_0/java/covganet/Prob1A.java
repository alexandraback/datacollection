import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class Prob1A {
	static String sIn = "zqejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
	static String sOut = "qzour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int t = Integer.parseInt(br.readLine());
		for(int x = 1; x <= t; x++) {
			String s = br.readLine();
			char[] out = new char[s.length()];
			for(int i = 0; i < out.length; i++) {
				boolean found = false;
				for(int j = 0; j < sIn.length(); j++) {
					if(sIn.charAt(j) == s.charAt(i)) {
						out[i] = sOut.charAt(j);
						found = true;
						break;
					}
				}
				if(!found) {
					System.out.println(s.charAt(i) + " not found");
					boolean[] vb = new boolean[26];
					for(int k = 0; k < sIn.length(); k++) {
						if(sOut.charAt(k) != ' ') {
							vb[sOut.charAt(k) - 'a'] = true;
						}
					}
					for(int j = 0; j < vb.length; j++) {
						if(!vb[j]) {
							System.out.println((char)('a' + j));
							out[i] = (char)('a' + j);
						}
					}
				}
			}
			
			pw.println("Case #" + x + ": " + new String(out));
		}
		
		br.close();
		pw.close();
	}
}
