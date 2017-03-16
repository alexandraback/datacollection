import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;


public class DacingScore {

	public static String SMALL_IN_FILE_NAME = "./B-large.txt";
	static PrintStream out = null;
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File smallIn = new File(SMALL_IN_FILE_NAME);
		BufferedReader br = new BufferedReader(new FileReader(smallIn));
		String s = br.readLine();
		int caseCount = Integer.parseInt(s);
		File smallOut = new File("./output.txt");
		smallOut.createNewFile();
		out = new PrintStream(smallOut);
//		out = System.out;
		
		for (int i = 0; i < caseCount; i ++) {
			out.printf("Case #%d: ", i+1);
			s = br.readLine();
			TestCase t = new TestCase(s);
			out.println(solveTestCase(t));
		}
		System.out.println("Done");
	}
	private static int solveTestCase(TestCase t) {
		int p = t.getpScore();
		int sCount = t.getSuprisingCount();
		ArrayList<Triplet> triplets = t.getTriplets();
		ArrayList<Triplet> normal = new ArrayList<Triplet>();
		ArrayList<Triplet> candidate = new ArrayList<Triplet>();
		ArrayList<Triplet> failed = new ArrayList<Triplet>();
		int sNormal = 0, sCandidate = 0, sFailed = 0;
		for (Triplet triplet : triplets) {
			if (triplet.getBest(false) >= p) {
				normal.add(triplet);
				if (triplet.isSuprisable()) {
					sNormal ++;
				}
			} else if (triplet.getBest(true) >= p) {
				candidate.add(triplet);
				sCandidate++;
			} else {
				failed.add(triplet);
				if (triplet.isSuprisable()) {
					sFailed++;
				}
			}
		}
		int result = -1;
		if (candidate.size() >= sCount) { 
			// plenty of candidates
			result = normal.size() + sCount;
		} else {
			result = normal.size() + candidate.size();
		}
		return result;
	}
}
