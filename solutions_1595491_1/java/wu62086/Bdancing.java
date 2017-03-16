package wwu.quals2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

import lib.tuple.Pair;
import lib.tuple.Tuple;
import lib.util.StringUtil;

public class Bdancing {

	static final String fileIn = "/home/wwu/Desktop/B-large.in";
//	static final String fileIn = "data/A-large-practice.in";
	static final String fileOut = "/home/wwu/Desktop/out.txt";
	
	public static Map<String, String> charMap;

	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new FileReader(fileIn));
		BufferedWriter w = new BufferedWriter(new FileWriter(fileOut));
		String line = r.readLine();
		int T = Integer.parseInt(line);
		for (int caseNum = 0; caseNum < T; caseNum++) {
			int[] testCase = StringUtil.getIntArray(r.readLine());
			int nGooglers = testCase[0];
			int surprises = testCase[1];
			int pBestResultScore = testCase[2];
			List<Integer> totalScores = new ArrayList<Integer>();
			for (int i=0; i<nGooglers; i++) {
				totalScores.add(testCase[i+3]);
			}
			String str = "Case #" + (caseNum + 1) + ": " + solve(nGooglers, surprises, pBestResultScore, totalScores);
			w.write(str + "\n");
			System.out.println(str);
		}
		r.close();
		w.close();
	}

	private static String solve(int nGooglers, int surprises,
			int pBestResultScore, List<Integer> totalScores) {
		int maxPossibleGooglers = 0;
		Collections.sort(totalScores);
		Collections.reverse(totalScores);
		//int highestNoSurprise = Math.min(3*pBestResultScore+2, 30);
		//int highestWithSurprise = Math.min(3*pBestResultScore+4, 30);
		int lowestNoSurprise = Math.max(3*pBestResultScore-2, pBestResultScore);
		int lowestWithSurprise = Math.max(3*pBestResultScore-4, pBestResultScore);
		for (Integer score : totalScores) {
			if (score >= lowestNoSurprise /*&& score <= highestNoSurprise*/) {
				maxPossibleGooglers++;
			} else if (score >= lowestWithSurprise /*&& score <= highestWithSurprise*/ && surprises > 0) {
				maxPossibleGooglers++;
				surprises--;
			}
		}
		return String.valueOf(maxPossibleGooglers);
	}

}
