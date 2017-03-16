import java.util.*;
import java.io.*;

public class ProblemA2 {

	private static final String IN_DIR = "inputs";
	private static final String OUT_DIR = "outputs";

	private static final String IN_FILE = "A-large.in";
	private static final String OUT_FILE = "output_a_2.txt";
	
	private static final int VOWEL = 0;
	private static final int CONSN = 1;
	
	public static class ConsnSub {
		public int pos;
		public int len;
		
		public ConsnSub (int poss, int lenn) {
			this.pos = poss;
			this.len = lenn;
		}
	}
	
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
		
		List<ConsnSub> subs = new ArrayList<ConsnSub>();
		int curPos = -1;
		int curLen = 0;
		for (int i = 0; i < totlen; i++) {
			if (repr[i] == CONSN) {
				if (curPos == -1) {
					curPos = i;
					curLen = 0;
				}
				curLen++;				
			} else {
				if (curPos != -1) {
					if (curLen >= sublen) {
						subs.add(new ConsnSub(curPos, curLen));
					}
					curPos = -1;
				}
			}
		}
		if (curPos != -1) {
			if (curLen >= sublen) {
				subs.add(new ConsnSub(curPos, curLen));
			}
			curPos = -1;
		}
		
		//System.out.println("subs size: " + subs.size());
		
		
		long result = 0;
		int numSubs = subs.size();
		if (numSubs > 0) {
			int nextSub = 0;
			for (long start = 0; start < totlen; start++) {
				int nextPos = subs.get(nextSub).pos;
				int nextLen = subs.get(nextSub).len;
				if (nextPos + nextLen - start < sublen) {
					nextSub++;
					if (nextSub == numSubs) {
						break;
					}
				}
				//System.out.println("next sub: " + nextSub);
				nextPos = subs.get(nextSub).pos;
				nextLen = subs.get(nextSub).len;
				
				//System.out.println("next pos: " + nextPos);
				//System.out.println("next len: " + nextLen);
				
				if (start >= nextPos) {
					//System.out.println("case 1");
					result += (totlen - (start + sublen) + 1);
				} else {
					//System.out.println("case 2");
					result += (totlen - (nextPos + sublen) + 1);
				}
			}
		}
		
		out.write("Case #" + caseNum + ": " + result + '\n');
	}
	
}
