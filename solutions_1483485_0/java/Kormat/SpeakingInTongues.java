import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;


public class SpeakingInTongues {
	public static void main(String[] args) {
		
		Map<Character, Character> languageMapping = new HashMap<Character, Character>();
		languageMapping.put('a','y');languageMapping.put('b','h');languageMapping.put('c','e');
		languageMapping.put('d','s');languageMapping.put('e','o');languageMapping.put('f','c');
		languageMapping.put('g','v');languageMapping.put('h','x');languageMapping.put('i','d');
		languageMapping.put('j','u');languageMapping.put('k','i');languageMapping.put('l','g');
		languageMapping.put('m','l');languageMapping.put('n','b');languageMapping.put('o','k');
		languageMapping.put('p','r');languageMapping.put('q','z');languageMapping.put('r','t');
		languageMapping.put('s','n');languageMapping.put('t','w');languageMapping.put('u','j');
		languageMapping.put('v','p');languageMapping.put('w','f');languageMapping.put('x','m');
		languageMapping.put('y','a');languageMapping.put('z','q');languageMapping.put(' ',' ');

		try {
			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
			BufferedReader inStream = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
			int testsNum = Integer.parseInt(inStream.readLine(), 10);
			
			String solution;
			for (int i=1; i<=testsNum; i++) {
				solution = solve(inStream, languageMapping);
				System.out.println("Case #"+i+": "+solution);
				System.err.println("Case #"+i+": "+solution);
			}
		} catch (Exception e) {e.printStackTrace();}
	}
	
	private static String solve(BufferedReader inStream, Map<Character, Character> mapping) throws IOException {
		String raw = inStream.readLine();
		StringBuilder ret = new StringBuilder();
		
		for (int i=0; i<raw.length(); i++) {
			ret.append(mapping.get(raw.charAt(i)));
		}
		return ret.toString();
	}
}
