import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class ProblemA {
	
	static Map<Character, Character> substitutes = new HashMap<>();
	
	public static void main(String[] args) {
		List<String> testInputs = Arrays.asList(
				"a zoo q",
				"ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv");
		List<String> testOutputs = Arrays.asList(
				"y qee z",
				"our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up");
		
		for(int idx = 0; idx < Math.min(testInputs.size(), testOutputs.size()); idx++) {
			String input 	= testInputs.get(idx);
			String output	= testOutputs.get(idx);
			
			for(int pos = 0; pos < Math.min(input.length(), output.length()); pos++) {
				char ch = input.charAt(pos);
				if(ch >= 'a' && ch <= 'z') 	substitutes.put(ch, output.charAt(pos));
			}
		}
		
		try (BufferedReader reader = new BufferedReader(new FileReader("A-small.in"))) {
			try (BufferedWriter writer = new BufferedWriter(new FileWriter("A-small.out"))) {
				String line = reader.readLine();
				int numCases = Integer.parseInt(line);
						
				StringBuilder builder = new StringBuilder();
				for(int caseIdx = 0; caseIdx < numCases; caseIdx++) {
					builder.setLength(0);
	
					line = reader.readLine();
					for(char ch : line.toCharArray()) {
						char subst = substitutes.containsKey(ch) ? substitutes.get(ch) : ch;
						builder.append(subst);
					}
					
					String caseOutput = String.format("Case #%d: %s", caseIdx + 1, builder.toString());
					
					System.out.println(caseOutput);
					writer.append(caseOutput);
					writer.newLine();
				}
			}
		} catch(IOException readerEx) {
			readerEx.printStackTrace();
		}
	}

}
