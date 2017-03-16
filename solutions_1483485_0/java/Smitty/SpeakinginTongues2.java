import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.io.*;

public final class SpeakinginTongues2 {

	private final static String FILE_IN = SpeakinginTongues2.class.getSimpleName() + ".in";			
	private final static String FILE_OUT = SpeakinginTongues2.class.getSimpleName() + ".out";			
	
	public static final void main(final String[] args) throws Exception {
		final Scanner in = new Scanner(new File(FILE_IN));
		final PrintWriter out = new PrintWriter(FILE_OUT);
		final int n = in.nextInt();
		
		final Map<Character, Character> code = new TreeMap<Character, Character>();
		code.put('y', 'a');
		code.put('e', 'o');
		code.put('q', 'z');

		final String [] sources = new String[n];
		final String [] targets = new String[n];
		
		for (int i = 0; i < n; ++ i){
			sources[i] = in.nextLine();
		}
		for (int i = 0; i < n; ++ i){
			targets[i] = in.nextLine();
		}

		for (int i = 0; i < n; ++ i){
			for (int q = 0; q < sources[i].length(); ++ q){
				final char from = sources[i].charAt(q);
				final char to = targets[i].charAt(q);
			
				if (code.containsKey(from)){
					if (code.get(from) != to){
						int bad = 1;
					}
				}
				else {
					code.put(from, to);
				}
			}
		}

		for (Map.Entry<Character, Character> entry : code.entrySet()){
			if (entry.getKey() == ' '){
				continue;
			}
			out.println(entry.getKey() + " " + entry.getValue());
		}
		
		in.close();
		out.close();
	}

}
