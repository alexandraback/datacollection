import java.util.*;
import java.io.*;

public class ProblemA {

	private static final String IN_DIR = "inputs";
	private static final String OUT_DIR = "outputs";

	private static final String IN_FILE = "A-small-attempt0.in";
	private static final String OUT_FILE = "output_a.txt";
	
	private static final int VOWEL = 0;
	private static final int CONSN = 1;
	
	public static void main(String[] args) {
		Scanner sc = null;
		BufferedWriter out = null;

		try {
			sc = new Scanner(new File(IN_DIR + "/" + IN_FILE));
			out = new BufferedWriter(new FileWriter(OUT_DIR + "/" + OUT_FILE));
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		int numTests = sc.nextInt();
		sc.nextLine();
		try {
			for (int i = 0; i < numTests; i++) {
				handleTest(sc, out, i+1);
			}

			// clean up
			sc.close();
			out.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static void handleTest(Scanner sc, BufferedWriter out, int caseNum) throws IOException {
		String str = sc.next();
		int totlen = str.length();
		int sublen = sc.nextInt();
		
		int[] repr = new int[totlen];
		for (int i = 0; i < totlen; i++) {
			char ch = str.charAt(i);
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
				repr[i] = VOWEL;
			} else {
				repr[i] = CONSN;
			}
		}
		
		int counter = 0;
		for (int start = 0; start < totlen; start++) {
			boolean found = false;
			int curCount = 0;
			for (int end = start; end < totlen; end++) {
				if (repr[end] == CONSN) {
					curCount++;
				} else {
					curCount = 0;
				}			
				if (curCount >= sublen) {
					found = true;
				}
				
				if (found) {
					counter++;
				}
			}
		}
		
		out.write("Case #" + caseNum + ": " + counter + '\n');
	}
	
}
