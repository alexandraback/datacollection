package spikemf.googlecodejam.rounds;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;


public class QD {
	static String infilename = "D-large.in";
	static String outfilename = "qd.out";
	static BufferedWriter out;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(infilename));
		int cases = Integer.parseInt(br.readLine());
		for (int i=0;i<cases;i++) {
			String line1 = br.readLine();
			String line2 = br.readLine();
			String line3 = br.readLine();
			handleLines(line1, line2, line3);
		}
		br.close();
		if (out != null) out.close();
	}
	static int caseNumber = 1;
	public static void writeLine(String line) throws IOException {
		if (out == null) {
			out = new BufferedWriter(new FileWriter(outfilename));
		}
		if (line == null) return;
		line = line.trim();
		if (line == "") return;
		out.write("Case #" + (caseNumber++) + ": ");
		out.write(line);
		out.write("\n");
	}
	public static void handleLines(String line1, String line2, String line3) throws IOException {
		int maxScore = Integer.parseInt(line1);
		String[] a1 = line2.split(" ");
		String[] a2 = line3.split(" ");
		if (maxScore != a1.length || a1.length != a2.length) {
			throw new Error("Unexpected array length!: expected: " + maxScore + " == " + a1.length + " == " + a2.length);
		}
		ArrayList<Double> naomi = new ArrayList<Double>(maxScore);
		ArrayList<Double> ken = new ArrayList<Double>(maxScore);
		
		for (String s : a1) {
			naomi.add(Double.parseDouble(s));
		}
		for (String s : a2) {
			ken.add(Double.parseDouble(s));
		}
		Collections.sort(naomi);
		Collections.reverse(naomi);
		
		Collections.sort(ken);
		Collections.reverse(ken);
		
		ArrayList<Double> kencopy = new ArrayList<Double>(ken);
		ArrayList<Double> naomicopy = new ArrayList<Double>(naomi);


		int normalScore = maxScore - getDeceitScore(ken, naomi, 0);
		int deceitScore = getDeceitScore(naomicopy, kencopy, 0);
		writeLine("" + deceitScore + " " + normalScore);
		
		/* both lists are in descending order */
		
	}
	
	static int getDeceitScore(ArrayList<Double> naomi, ArrayList<Double> ken, int score) {
		if (naomi.size() != ken.size()) {
			throw new Error("Expected same size");
		}
		if (naomi.size() == 0) return score;
		if (naomi.get(0) > ken.get(0)) {
			score ++;
			ken.remove(0);
			naomi.remove(0);
		} else {
			ken.remove(0);
			naomi.remove(naomi.size() - 1);
		}
		return getDeceitScore(naomi, ken, score);
	}
	
	/** assumes both inputs are scorted in descending order */
	static int getNormalScore(ArrayList<Double> naomi, ArrayList<Double> ken) {
		if (naomi.size() != ken.size()) {
			throw new Error("Expected same size");
		}
		int score = 0;
		for (int i=0;i<ken.size();i++) {
			if (naomi.get(i) > ken.get(i)) {
				System.out.println(naomi.get(i) + "   " + ken.get(i));
				score ++;
			}
		}
		System.out.println();
		
		return score;
	}
}
