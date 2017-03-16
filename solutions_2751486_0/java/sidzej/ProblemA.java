package round13_a;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class ProblemA {

	//static String filePath = "src/round13_a/test.in"; 
	static String filePath = "src/round13_a/A-small-attempt0.in";
	//static String filePath = "src/round13_a/A-large.in";
	static StringBuffer fullResult = new StringBuffer();
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new FileReader(filePath));
		int noTestCases = s.nextInt();
		for (int i = 0; i < noTestCases; i++) {
			String result = "";			
			String name = s.next();
			char[] nameChar = new char[name.length()];
			for (int j = 0; j < name.length(); j++) {
				nameChar[j] = name.charAt(j);
			}
			int n = s.nextInt();
			int nValue = 0;
			for (int length = name.length(); length >= n; length--) {
				for (int start = 0; start <= name.length() - length; start++) {
					int consecutiveVovels = 0;
					for (int j = start; j < start + length; j++) {
						if (isVovel(nameChar[j])) {
							consecutiveVovels++;
						} else {
							consecutiveVovels = 0;
						}
						if (consecutiveVovels >= n) {
							nValue++;
							break;
						}
					}
				}
			}
			result = Integer.toString(nValue);
			fullResult.append("Case #" + (i + 1) + ": " + result + "\n");
		}
		writeFile();
	}

	private static boolean isVovel(int j) {
		if (j == 'b' || j == 'c' || j == 'd' || j == 'f' || j == 'g' || 
			j == 'h' || j == 'k' || j == 'l' || j == 'm' || j == 'n' || 
			j == 'p' || j == 'q' || j == 'r' || j == 's' || j == 't' ||
			j == 'v' || j == 'w' || j == 'x' || j == 'z' || j == 'j' ||
			j == 'y') {
			return true;
		} else {
			return false;
		}
	}

	static void writeFile() throws IOException {
		String path = filePath.replace(".in", ".out");
		BufferedWriter out = new BufferedWriter
			    (new OutputStreamWriter(new FileOutputStream(path),"UTF-8"));
		out.write(fullResult.toString());
		out.close();
		System.out.println(fullResult);
	}
}
