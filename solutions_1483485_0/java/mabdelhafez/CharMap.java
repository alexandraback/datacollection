import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class CharMap {
	HashMap<Character,Character> dict = new HashMap<Character,Character>();
	
	public void initDict(String[] code, String[] decode) {
		dict.put('y', 'a');
		dict.put('e', 'o');
		dict.put('q', 'z');
		for(int i = 0; i < code.length; i++) {
			for(int j = 0; j < code[i].length(); j++) {
				if(dict.containsKey(code[i].charAt(j)) && dict.get(code[i].charAt(j)) != decode[i].charAt(j)) {
					System.out.println("Error found! Charachter '" + code[i].charAt(j) + "' maps to '" +
							decode[i].charAt(j) + ", and '" + dict.get(code[i].charAt(j)) + "'");
					System.out.append("i = " + i + ", j = " + j);
				}
				dict.put(code[i].charAt(j),  decode[i].charAt(j));
			}
		}
		char missingKey = ' ';
		char missingValue = ' ';
		//find missing character
		for(char c = 'a'; c <= 'z'; c++) {
			if(!dict.keySet().contains(c)) missingKey = c;
			if(!dict.values().contains(c)) missingValue = c;
		}
		//System.out.println("Missing key = " + missingKey + ", missingValue = " + missingValue);
		dict.put(missingKey, missingValue);
		//System.out.println(dict.size());
	}
	
	
	public String decode(String input){
		StringBuffer buf = new StringBuffer();
		for(int i = 0; i < input.length(); i++) {
			buf.append(dict.get(input.charAt(i)));
		}
		return buf.toString();
	}
	
	
	
	public static void main(String args[]) {
		CharMap c = new CharMap();
		String result[] = null;
		c.initDict(new String[] {"ejp mysljylc kd kxveddknmc re jsicpdrysi", 
								 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
								 "de kr kd eoya kw aej tysr re ujdr lkgc jv"}, new String[] {
								 "our language is impossible to understand",
								 "there are twenty six factorial possibilities",
								 "so it is okay if you want to just give up"});
		try {
			Scanner sc = new Scanner(new FileInputStream("C:/Users/Administrator/Downloads/A-small-attempt1.in"));
			String line = sc.nextLine().trim();
			int cases = Integer.parseInt(line);
			result = new String[cases];
			for(int i = 0; i < cases; i++) {
				line = sc.nextLine().trim();
				result[i] = "Case #" + (i+1) + ": " + c.decode(line);
			}
			
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		try {
			 FileWriter fstream = new FileWriter("C:/out.txt");
			 PrintWriter out = new PrintWriter(fstream);
			 
			 for(int i = 0; i < result.length; i++) {
				 out.println(result[i]);
			 }
			 out.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
}
