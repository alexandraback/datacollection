import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class GCJ_1B_A {
		
	class TestCase {
		String S;
	}
	
	public TestCase readTestCase() throws Exception {
		TestCase tc = new TestCase();
		tc.S = nextLine();
		return tc;
	}
	
	
	String[] helper = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
	
	public Map<Character, List<Integer>> prepareMap() {
		Map<Character, List<Integer>> m = new HashMap<Character, List<Integer>>();
		for (char c = 'A'; c <= 'Z'; c++) {
			for (int i = 0; i < helper.length; i++) {
				String s = helper[i];
				if (s.contains("" + c)) {
					List<Integer> l = m.get(c);
					if (l == null) {
						m.put(c, l = new ArrayList<Integer>());
					}
					l.add(i);
				}
			}
		}
		return m;
	}
	
	
	private int[] toIndexArray(String s) {
		int[] result = new int[26];
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			result[c - 'A']++;
		}
		return result;
	}
	
	public void writeTestResult(TestCase tc) throws Exception {
		List<Integer> result = new ArrayList<Integer>();
		Map<Character, List<Integer>> m = prepareMap();
		int unresolvedChars = tc.S.length();
		int[] indexArray = toIndexArray(tc.S);
		while (unresolvedChars > 0) {
			for (Map.Entry<Character, List<Integer>> e : m.entrySet()) {
				if (e.getValue().size() != 1) {
					continue;
				}
				Integer phoneDigit = e.getValue().get(0);
				int charCount = indexArray[e.getKey().charValue() - 'A'];
				for (int cc = 0; cc < charCount; cc++) {
					result.add(phoneDigit);
					String stringDigit = helper[phoneDigit];
					for (int i = 0; i < stringDigit.length(); i++) {
						char letter = stringDigit.charAt(i);
						indexArray[letter - 'A'] -= 1;
						unresolvedChars -= 1;
					}
				}
				//Update resolve map
				for (Map.Entry<Character, List<Integer>> ne : m.entrySet()) {
					ne.getValue().remove(phoneDigit);
				}
			}
		}
		Collections.sort(result);
		String phoneNumber = result.toString().replaceAll("[^0-9]*", "");
		System.out.println(phoneNumber);
		bw.write(phoneNumber);
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
		GCJ_1B_A jam = new GCJ_1B_A();
		jam.solve();
	}
}
