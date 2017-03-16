import java.io.*;
import java.util.*;

public class Qual1 {
	private static char[] matching = new char[26];
	private static String[] original = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv" };
	private static String[] converted = {"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"};
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Arrays.fill(matching, '.');
		for(int i = 0; i < original.length; i++) {
			for(int j = 0; j < original[i].length(); j++) {
				char c = original[i].charAt(j);
				if(c != ' ') {
					//if(matching[c-'a'] != 0 && matching[c-'a'] != converted[i].charAt(j)) throw new Exception();
					matching[c-'a'] = converted[i].charAt(j);
				}
			}
		}
		matching['q' - 'a'] = 'z';
		matching['z' - 'a'] = 'q';
		/*int count = 0;
		for(int i = 0; i < 26; i++) {
			if(matching[i] != '.') count++;
			else System.out.println((char)(i + 'a'));
		}
		System.out.println(count);*/
		FileReader fr = new FileReader("A-small-attempt0.in");
		BufferedReader br = new BufferedReader(fr);
		FileWriter fw = new FileWriter("output.txt");
		int total = Integer.parseInt(br.readLine());
		for(int i = 1; i <= total; i++) {
			String line = br.readLine();
			//System.out.println(line);
			fw.write("Case #" + i + ": " + convert(line) + "\n");
		}
		fw.close();
	}
	
	private static String convert(String input) {
		char[] arr = new char[input.length()];
		for(int i = 0; i < input.length(); i++) {
			char c = input.charAt(i);
			arr[i] = c == ' ' ? ' ' : matching[input.charAt(i)-'a'];
		}
		return new String(arr);
	}

}
