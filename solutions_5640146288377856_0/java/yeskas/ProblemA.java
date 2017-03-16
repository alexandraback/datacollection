import java.util.*;
import java.io.*;

public class ProblemA {

	private static final String IN_DIR = "inputs";
	private static final String OUT_DIR = "outputs";

	private static final String IN_FILE = "A-small-attempt0.in";
	private static final String OUT_FILE = "output_a.txt";
	
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
		for (int i = 0; i < numTests; i++) {
			try {
				handleTest(sc, out, i+1);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		try {
			sc.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void handleTest(Scanner sc, BufferedWriter out, int caseNum) throws Exception {
		String inrow = sc.nextLine();
		Scanner sc2 = new Scanner(inrow);
		int R = sc2.nextInt();
		int C = sc2.nextInt();
		int W = sc2.nextInt();

		// for small input
		if (C % W == 0) {
			writeCase(out, caseNum, (C/W + (W-1)) + "");
		} else {
			writeCase(out, caseNum, (C/W + W) + "");
		}
		
		//String nextRow = sc.nextLine();
		//writeCase(out, caseNum, "xxx");
	}

	private static void pr(String str) {
		System.out.println(str);
	}
	
	private static void prs(String str) {
		System.out.print(str);
	}

	private static void writeCase(BufferedWriter out, int caseNum, String res) throws Exception {
		out.write("Case #" + caseNum + ": " + res + "\n");
	}
	
}
