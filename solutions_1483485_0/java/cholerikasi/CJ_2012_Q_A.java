import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.TreeMap;

public class CJ_2012_Q_A {

	static TreeMap<Character, Character> map = new TreeMap<Character, Character>();
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("cj_files/in"));
		FileWriter w = new FileWriter(new File("cj_files/out"));
		
		fillMap();
		
		int count = s.nextInt();
		s.nextLine();
		
		for(int i = 0; i < count; i++) {
			String line = s.nextLine();
			StringBuffer res = new StringBuffer();
			res.append("Case #" + (i+1) + ": ");
			for(int j = 0; j < line.length(); j++) {
				res.append(map.get(line.charAt(j)));
			}
			res.append("\n");
			w.write(res.toString());
		}
		
		w.close();
	}
	
	private static void fillMap() {
		String inStr  = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
		String outStr = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
		
		inStr = inStr.replaceAll(" ", "");
		outStr = outStr.replaceAll(" ", "");
		
		for(int i = 0; i < inStr.length(); i++) {
			map.put(inStr.charAt(i), outStr.charAt(i));
		}
		map.put(' ', ' ');
		map.put('q', 'z');
		map.put('z', 'q');
	}

}
