package wwu.quals2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

import lib.tuple.Pair;
import lib.tuple.Tuple;
import lib.util.StringUtil;

public class Atongues {

	static final String fileIn = "/home/wwu/Desktop/A-small-attempt0.in";
	static final String fileOut = "data/out2.txt";
	
	public static Map<String, String> charMap;

	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new FileReader(fileIn));
		BufferedWriter w = new BufferedWriter(new FileWriter(fileOut));
		String line = r.readLine();
		int T = Integer.parseInt(line);
		charMap = new HashMap<String, String>();
		trainCharMap();
		for (int caseNum = 0; caseNum < T; caseNum++) {
			String googlese = r.readLine();
			String str = "Case #" + (caseNum + 1) + ": " + solve(googlese);
			w.write(str + "\n");
			System.out.println(str);
		}
		r.close();
		w.close();
	}

	private static String solve(String googlese) {
		StringBuilder sb = new StringBuilder();
		for (int i=0; i<googlese.length(); i++) {
			sb.append(charMap.get(String.valueOf(googlese.charAt(i))));
		}
		return sb.toString();
	}

	private static void trainCharMap() {
		String s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		String a1 = "our language is impossible to understand";
		String s2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		String a2 = "there are twenty six factorial possibilities";
		String s3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv"; 
		String a3 = "so it is okay if you want to just give up";
		charMap.put("a", "y");
		charMap.put("o", "e");
		charMap.put("z", "q");
		charMap.put("q", "z");
		for (int i=0; i<s1.length(); i++) {
			charMap.put(String.valueOf(s1.charAt(i)), String.valueOf(a1.charAt(i)));
		}
		for (int i=0; i<s1.length(); i++) {
			charMap.put(String.valueOf(s2.charAt(i)), String.valueOf(a2.charAt(i)));
		}
		for (int i=0; i<s1.length(); i++) {
			charMap.put(String.valueOf(s3.charAt(i)), String.valueOf(a3.charAt(i)));
		}
		List<String> allCharsOut = new ArrayList<String>();
		List<String> allCharsIn = new ArrayList<String>();
		for (Map.Entry<String, String> entry : charMap.entrySet()) {
//			System.out.println("key " + entry.getKey() + " value " + entry.getValue());
			allCharsIn.add(entry.getKey());
			allCharsOut.add(entry.getValue());
		}
		Collections.sort(allCharsIn); // missing q
		Collections.sort(allCharsOut); // missing z
//		System.out.println(allCharsIn);
	}

}
