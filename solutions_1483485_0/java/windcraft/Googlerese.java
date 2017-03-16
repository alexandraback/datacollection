package qualification;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class Googlerese {
	private static char[] mapping = new char[26];
	
	public static void main(String[] args) throws IOException {
		buildMapping();
		Scanner input = new Scanner(new FileInputStream("A-small-attempt1.in"));

		FileOutputStream out = new FileOutputStream("A-small-attempt1.in.out", false);
		slove(input, out);
		out.close();
	}
	
	private static void buildMapping()
	{
		String[] input = new String[] {
				"ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",	
				"de kr kd eoya kw aej tysr re ujdr lkgc jv"
		};
		
		String[] out = new String[] {
				"our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up",
		};
		
		mapping['y' - 'a'] = 'a';
		mapping['e' - 'a'] = 'o';
		mapping['q' - 'a'] = 'z';
				
		int n = 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < input[i].length(); j++) {
				char a = input[i].charAt(j);
				char b = out[i].charAt(j);
				if (a >= 'a' && a <= 'z') {
					int k = a - 'a';
					if (mapping[k] == 0) {
						mapping[k] = b;
						System.out.printf("mapping %d %c to %c\n", n, a, b);
						n++;
					} else if (mapping[k] != b) {
						throw new RuntimeException("sample error");
					}
				}
			}
		}
		
		int s1 = 0;
		int s2 = 0;
		int missing = 0;
		for (int i = 0; i < 26; i++) {
			s1 += i;
			if (mapping[i] == 0) {
				missing = i;
			} else {
				s2 += mapping[i] - 'a';
			}
		}
		mapping[missing] = (char) ((s1 - s2) + 'a');
	}
	
	private static void slove(Scanner input, FileOutputStream out) throws IOException
	{
		input.useDelimiter("\n");
		int n = input.nextInt();
		for (int i = 0; i < n; i++) {
			String s = input.next();
			StringBuilder r = new StringBuilder();
			for (int j = 0; j < s.length(); j++) {
				char c = s.charAt(j);
				if (c >= 'a' && c <= 'z') {
					r.append(mapping[c - 'a']);					
				} else if (c == ' ') {
					r.append(c);
				}
			}
			s = String.format("Case #%d: %s\r\n", i + 1, r.toString());
			out.write(s.getBytes());
		}
	}
}
