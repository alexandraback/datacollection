/**
 * 
 */
package codejam2012.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

/**
 * @author Jaffar Ramay
 *
 */
public class SpeakingInTongues {

	static HashMap<Character,Character> lettersMap = new HashMap<Character,Character>();
	
	static void initLettersMap(){
		String googlerese = "z q a y o e ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String english    = "q z y a e o our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
		
		for (int i = 0; i < googlerese.length(); i++) {
			lettersMap.put(googlerese.charAt(i), english.charAt(i));
		}
		
	}

	public static void solve() throws IOException {
		initLettersMap();
		
		BufferedReader reader = new BufferedReader(new FileReader(new File("/Users/jaffar_ramay/Workspaces/eclipseWorkspace/Revision/src/codejam2012/qualification/SpeakingInTongues.in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("/Users/jaffar_ramay/Workspaces/eclipseWorkspace/Revision/src/codejam2012/qualification/SpeakingInTongues.out")));
		StringBuffer output;
		String line = null;
		while((line=reader.readLine())!=null){
			int testCases = Integer.parseInt(line);
			for (int i = 1; i <= testCases; i++) {
				line = reader.readLine();
				output = new StringBuffer();
				output.append("Case #");
				output.append(i);
				output.append(": ");
				for (int j = 0; j < line.length(); j++) {
					output.append(lettersMap.get(line.charAt(j)));
					
				}
				writer.write(output.toString());
				if(i!=testCases)
					writer.newLine();
			}
		}
		reader.close();
		writer.close();
		
	}
	
	public static void main(String[] args) throws IOException {
		solve();
	}
}
