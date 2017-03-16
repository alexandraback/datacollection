import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class GCJ_1B_B {
		
	class TestCase {
		String C, J;
	}
	
	public TestCase readTestCase() throws Exception {
		TestCase tc = new TestCase();
		nextLine();
		tc.C = nextString();
		tc.J = nextString();
		return tc;
	}
	
	String padString(String s, int len) {
		while (s.length() < len)
			s = "0" + s;
		return s;
	}
	
	boolean stringMatch(String a, String b) {
		for (int i = 0; i < a.length(); i++) {
			if (b.charAt(i) != '?' && a.charAt(i) != b.charAt(i)) {
				return false;
			}
		}
		return true;
	}
	public void writeTestResult(TestCase tc) throws Exception {
		int minDelta = 1000;
		int minI = 1000;
		int minJ = 1000;
		int tcLen = tc.C.length();
		long max = Math.round(Math.pow(10, tcLen));;
		for (int i = 0; i < max; i++) {
			if (!stringMatch(padString(i+"", tcLen), padString(tc.C, tcLen))) {
				continue;
			}
			for (int j = 0; j < max; j++) {
				if (!stringMatch(padString(j+"", tcLen), padString(tc.J, tcLen))) {
					continue;
				}
				if (Math.abs(i - j) < minDelta) {
					minDelta = Math.abs(i - j);
					minI = i;
					minJ = j;
				}
			}
		}
		bw.write(padString(minI+"", tcLen) + " " + padString(minJ+"", tcLen));
	}

	//=======================================================
	//=======================================================
	//=======================================================

	static final String path = ".";
	BufferedReader br;
	BufferedWriter bw;
	
	String currentLine;
	String[] currentPieces;
	int currentIndex = 0;
	
	String nextLine() throws IOException {
		currentLine = br.readLine();
		currentIndex = 0;
		currentPieces = currentLine.split(" ");
		return currentLine;
	}
	
	String[] pieces() {
		return currentPieces;
	}
	
	String nextString() {
		return currentPieces[currentIndex++];
	}
	
	Long nextLong() {
		return Long.valueOf(currentPieces[currentIndex++]);
	}
	
	Double nextDouble() {
		return Double.valueOf(currentPieces[currentIndex++]);
	}
	
	
	public void solve() throws Exception {
		br = new BufferedReader(new FileReader(path+"/input"));
		bw = new BufferedWriter(new FileWriter(path+"/output"));
		int testCases = Integer.valueOf(br.readLine()).intValue();
		for (int i = 0; i < testCases; i++) {
			System.out.print("Test case " + (i + 1) + ": ");
			long time = System.nanoTime();
			TestCase testCase = readTestCase();
			System.out.print(" read in " + (System.nanoTime() - time) / 1E3 + " ms, ");
			time = System.nanoTime();
			bw.write("Case #" + (i + 1) + ": ");
			writeTestResult(testCase);
			bw.write("\n");
			System.out.println("solved in "+(System.nanoTime()-time)/1E3+" ms");
		}
		bw.flush();
		bw.close();
		br.close();
	}
	
	public static void main(String[] args) throws Exception  {
		GCJ_1B_B jam = new GCJ_1B_B();
		jam.solve();
	}
}
