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

public class Crecycled {

	static final String fileIn = "/home/wwu/Desktop/C-small-attempt0.in";
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
			int A = testCase[0];
			int B = testCase[1];
			String str = "Case #" + (caseNum + 1) + ": " + solve(A, B);
			w.write(str + "\n");
			System.out.println(str);
		}
		r.close();
		w.close();
	}

	private static String solve(int a, int b) {
		int numRecyled = 0;
		for (int outerCompare=a; outerCompare<=b; outerCompare++) {
			numRecyled += getRecycledPairNum(outerCompare, a, b);
//			for (int innerCompare=a; innerCompare<=b; innerCompare++) {
//				if (isRecycledPair(outerCompare, innerCompare)) {
//					numRecyled++;
//				}
//			}
		}
		return String.valueOf(numRecyled/2);
	}

	private static int getRecycledPairNum(int outerCompare, int a, int b) {
		int retVal = 0;
		int lenOfOuter = String.valueOf(outerCompare).length();
		int nextRecycledNum = (int) Math.pow(10, lenOfOuter-1)*(outerCompare % 10) + outerCompare/10;
		for (int i=0; i<=lenOfOuter; i++) {
			if (outerCompare == nextRecycledNum) {
				continue;
			} else if (nextRecycledNum >= a && nextRecycledNum <= b) {
				retVal++;
			}
			nextRecycledNum = (int) Math.pow(10, lenOfOuter-1)*(nextRecycledNum % 10) + nextRecycledNum/10;
		}
		return retVal;
	}

//	private static boolean isRecycledPair(int outerCompare, int innerCompare) {
//		// 123 -> 312
//		int lenOfOuter = String.valueOf(outerCompare).length();
//		int nextRecycledNum = (int) Math.pow(10, lenOfOuter-1)*(outerCompare % 10) + outerCompare/10;
//		for (int i=0; i<=lenOfOuter; i++) {
//			if (outerCompare == innerCompare) {
//				continue;
//			} else if (nextRecycledNum == innerCompare) {
//				return true;
//			}
//			nextRecycledNum = (int) Math.pow(10, lenOfOuter-1)*(nextRecycledNum % 10) + nextRecycledNum/10;
//		}
//		return false;
//	}
//	

}
