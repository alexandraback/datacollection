import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 * Good luck, Wash!
 * @author Wangshu
 *
 */
public class SpeakingInTongues {

	static Map<Character, Character> alphabet = new HashMap<Character, Character>();
	
	static final String input_path = "data/problem.a.txt";
	
	static String[] input_sentence = {
			"ejp mysljylc kd kxveddknmc re jsicpdrysi",
			"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
			"de kr kd eoya kw aej tysr re ujdr lkgc jv"
	};
	
	static String[] output_sentence = {
			"our language is impossible to understand", 
			"there are twenty six factorial possibilities",
			"so it is okay if you want to just give up"
	}; 
	
	
	private static void init() {
		int N = input_sentence.length;
		for (int i = 0; i < N; i ++) {
			String input = input_sentence[i];
			String output = output_sentence[i];
			assert(input.length() == output.length());
			for (int j = 0; j < input.length(); j ++)
				if (input.charAt(j) != ' ') 
					alphabet.put(input.charAt(j), output.charAt(j));
		}
		
		alphabet.put('z', 'q');
		alphabet.put('q', 'z');
	}
	
	private static void doing(String inputStr) {
		int len = inputStr.length();
		for (int i = 0; i < len; i++) {
			char ch = inputStr.charAt(i);
			if (ch == ' ')
				System.out.print(' ');
			else
				System.out.print(alphabet.get(ch));
		}
	}
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		init();
		BufferedReader in = new BufferedReader(new FileReader(input_path)); 
		String intext = in.readLine();
		int N = Integer.parseInt(intext);
		for (int caseIter = 0; caseIter < N; caseIter ++) {
			intext = in.readLine();
			System.out.print(String.format("Case #%d: ", caseIter + 1));
			doing(intext);
			System.out.println();
		}
		in.close();
	}

}
