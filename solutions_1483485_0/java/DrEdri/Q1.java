import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Q1 {
	public static Problem[] probs;
	public static HashMap<String, String> mapping = new HashMap<String, String>();

	static class Problem {
		String text;
	}
			
	public static void staticInit() {
		mapping.put("a", "y");
		mapping.put("b", "h");
		mapping.put("c", "e");
		mapping.put("d", "s");
		mapping.put("e", "o");
		mapping.put("f", "c");
		mapping.put("g", "v");
		mapping.put("h", "x");
		mapping.put("i", "d");
		mapping.put("j", "u");
		mapping.put("k", "i");
		mapping.put("l", "g");
		mapping.put("m", "l");
		mapping.put("n", "b");
		mapping.put("o", "k");
		mapping.put("p", "r");
		mapping.put("q", "z");
		mapping.put("r", "t");
		mapping.put("s", "n");
		mapping.put("t", "w");
		mapping.put("u", "j");
		mapping.put("v", "p");
		mapping.put("w", "f");
		mapping.put("x", "m");
		mapping.put("y", "a");
		mapping.put("z", "q");
	}
	
	public static void main(String[] args) {
		String inputFile = args[0];
		staticInit();
		parseFile(inputFile);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(inputFile + ".out"));
			for (int i=0; i<probs.length; i++) {
				String output = solveProblem(probs[i]);
				bw.write("Case #" + (i+1) + ": " + output + "\n");
			}
			bw.flush();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
			
	private static String solveProblem(Problem p) {
		StringBuffer result = new StringBuffer();
		for (int i=0; i<p.text.length(); i++) {
			result.append(" ");
		}
		for (String key: mapping.keySet()) {
			for (int i=0; i<p.text.length(); i++) {
				if (p.text.substring(i, i+1).equals(key)) {
					result.replace(i, i+1, mapping.get(key));
				}
			}
		}
		return result.toString();
	}

	public static void parseFile(String inputFile) {
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFile));
			String line = br.readLine();
			probs = new Problem[Integer.parseInt(line)];
			line = br.readLine();
			for (int i=0; i<probs.length; i++) {
				probs[i] = new Problem();
				probs[i].text = line;
				line = br.readLine();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
