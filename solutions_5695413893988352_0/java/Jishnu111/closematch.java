package cdejam;

import java.io.*;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class closematch {

	public static void main(String args[]) throws Exception {

		BufferedReader bf = new BufferedReader(
				new FileReader("D:\\Tax_Forms\\formsprocessing\\java_project\\src\\cdejam\\input.txt"));

		BufferedWriter bw = new BufferedWriter(
				new FileWriter("D:\\Tax_Forms\\formsprocessing\\java_project\\src\\cdejam\\output.txt"));
		

		int N = Integer.parseInt(bf.readLine());
		

		for (int i = 1; i <= N; i++) {
			String input = bf.readLine();
			String inpstr[] = input.split(" ");
			String coders = inpstr[0];
			String jammers = inpstr[1];
			ArrayList<String> allposcoders = findAllPos(coders);
			ArrayList<String> allposjammers = findAllPos(jammers);
			String[] result = findBestMatch(allposcoders, allposjammers);

			bw.write("Case #" + i + ": " + result[0] + " " + result[1] + System.lineSeparator());

		}
		bw.close();

	}

	private static String[] findBestMatch(ArrayList<String> allposcoders, ArrayList<String> allposjammers) {
		ArrayList<Score> allscore = new ArrayList<>();
		for (String coder : allposcoders) {
			for (String jammer : allposjammers) {
				Score s = new Score();
				s.coder = coder;
				s.jammer = jammer;
				int value =Integer.parseInt(coder) - Integer.parseInt(jammer);
				if (value < 0)
					s.value = -1 * value;
				else
					s.value = value;
				allscore.add(s);
			}
		}
		int min = Integer.MAX_VALUE;
		Score minScore = null;
		ArrayList<Score> minscores = new ArrayList<>();
		for (Score score : allscore) {
			if (score.value < min) {
				minscores = new ArrayList<>();
				minscores.add(score);
				min=score.value;
			} else if (score.value == min) {
				minscores.add(score);
			}

		}
		String[] result = new String[2];

		int minCoder = Integer.MAX_VALUE;
		minScore = null;
		ArrayList<Score> mincoderList = new ArrayList<Score>();

		for (Score score : minscores) {
			if (Integer.parseInt(score.coder) < minCoder) {
				mincoderList = new ArrayList<>();
				mincoderList.add(score);
				minCoder=Integer.parseInt(score.coder);
			} else if (Integer.parseInt(score.coder) == minCoder) {
				mincoderList.add(score);
			}

		}

		int minJammer = Integer.MAX_VALUE;
		Score minjamscore = new Score();
		for (Score score : mincoderList) {
			if (Integer.parseInt(score.jammer)< minJammer) {
				minJammer = Integer.parseInt(score.jammer);
				minjamscore = score;
			}
		}

		result[0] = minjamscore.coder;
		result[1] = minjamscore.jammer;

		return result;
	}

	private static ArrayList<String> findAllPos(String coders) {
		ArrayList<String> allpos = new ArrayList<>();
		int change = coders.length() - coders.replace("?", "").length();
		int changepow = (int) Math.pow(10, change);
		for (int i = 0; i < changepow; i++) {
			String temp = new String(coders);
			for (int j = 0; j < change; j++) {
				String hj=String.format("%0"+change+"d", i);
				System.out.println(hj);
				temp=temp.replaceFirst("\\?", hj.charAt(j) + "");
			}
			allpos.add(temp);
		}
		return allpos;
	}

}

class Score {
	String coder;
	String jammer;
	int value;
}
