import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.List;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		List<String> lines = null;
		try {
			lines = Files.readAllLines(
					Paths.get("./input/input.txt"), 
					StandardCharsets.UTF_8);
		} catch (IOException e1) {
			e1.printStackTrace();
		}

		int cases = Integer.parseInt(lines.get(0));

		try {
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));

			for (int i=2; i<=2*cases; i+=2) {

				String[] ss = lines.get(i).split(" ");
				out.write(output(i/2, solve(ss)));
				out.newLine();
			}
			out.close();
		} catch (IOException e) {};
	}
	
	private static int solve(String[] ss) {
		for (int i=0; i<ss.length; i++)
			ss[i] = target(ss[i]);
		
		return permutation("", ss);
	}
	
	private static int permutation(String prefix, String[] ss) {
		int count = 0;
		if (ss.length == 0)
			return isValid(prefix);
		
		for (int i=0; i<ss.length; i++) {
			count += permutation(prefix + ss[i], sub(ss, i));
		}
		
		return count;
	}
	
	private static int isValid(String s) {
		int n = s.length();
		HashSet<Character> saw = new HashSet<Character>();
		saw.add(s.charAt(0));
		for (int i=1; i<n; i++) {
			if (s.charAt(i) != s.charAt(i-1) && saw.contains(s.charAt(i)))
				return 0;
			saw.add(s.charAt(i));
		}
		return 1;
	}
	
	private static String[] sub(String[] ss, int index) {
		String[] sub = new String[ss.length-1];
		for (int i=0, j=0; i<ss.length; i++) {
			if (i != index)
				sub[j++] = ss[i]; 
		}
		return sub;
	}
	
	private static String target(String s) {
		String target = "" + s.charAt(0);
		
		for (int i=1; i<s.length(); i++) {
			if (s.charAt(i) != target.charAt(target.length()-1))
				target += s.charAt(i);			
		}
		
		return target;
	}
	
	private static String output(int caseNum, int result) {
		return "Case #" + caseNum + ": " + result;
	}
}
