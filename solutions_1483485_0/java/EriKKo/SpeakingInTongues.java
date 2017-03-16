import java.io.*;
import java.util.*;

public class SpeakingInTongues {

	static char[] mapping;
	
	static {
		mapping = new char['z'-'a'+1];
		mapping['q'-'a'] = 'z';
		mapping['z'-'a'] = 'q';
		map("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
		map("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
		map("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
	}
	
	public static void main(String[] args) throws IOException {
		for (int i = 0; i < mapping.length; i++) {
			System.out.println((char)(i+'a')+" : "+mapping[i]);
		}
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new FileWriter("speakingInTongues.txt"), true);
		int T = Integer.parseInt(in.readLine());
		for (int test = 1; test <= T; test++) {
			StringBuilder sb = new StringBuilder();
			String s = in.readLine();
			for (int i = 0; i < s.length(); i++) {
				char c = s.charAt(i);
				if (c != ' ') c = mapping[c-'a'];
				sb.append(c);
			}
			out.println("Case #"+test+": "+sb);
		}
		out.close();
	}
	
	static void map(String s1, String s2) {
		for (int i = 0; i < s1.length(); i++) {
			char c1 = s1.charAt(i);
			char c2 = s2.charAt(i);
			if (c1 == ' ') continue;
			mapping[c1-'a'] = c2;
		}
	}
}
