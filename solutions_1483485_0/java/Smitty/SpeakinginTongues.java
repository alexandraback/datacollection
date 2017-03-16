import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.io.*;

import javax.swing.event.TreeExpansionEvent;

public final class SpeakinginTongues {

	private final static String FILE_IN = SpeakinginTongues.class.getSimpleName() + ".in";			
	private final static String FILE_OUT = SpeakinginTongues.class.getSimpleName() + ".out";			
	
	public static final void main(final String[] args) throws Exception {

		final Map<Character, Character> code = new TreeMap<Character, Character>();
		final Scanner inputCode = new Scanner(new File("SpeakinginTongues2.out"));
		String line = null;
		while (inputCode.hasNextLine() && (line = inputCode.nextLine()) != null){
			final String parts [] = line.split("\\s");
			code.put(parts[0].charAt(0), parts[1].charAt(0));
		}
		inputCode.close();
		
		final Scanner in = new Scanner(new File(FILE_IN));
		final PrintWriter out = new PrintWriter(FILE_OUT);
		final int testCnt = in.nextInt();
		in.nextLine();
		for (int caseNum = 1; caseNum <= testCnt; ++ caseNum){
			
			final String source = in.nextLine();
			final char [] target = source.toCharArray();
			for (int i = 0; i < source.length(); ++ i){
				if (target[i] == ' '){
					continue;
				}
				if (code.containsKey(target[i])){
					target[i] = code.get(target[i]);
				}
				else {
					target[i] = '*';
				}
			}
			// out.println(String.format("Case #%d: %s", caseNum, new String(source)));			
			out.println(String.format("Case #%d: %s", caseNum, new String(target)));			
		}
		in.close();
		out.close();
	}

}
