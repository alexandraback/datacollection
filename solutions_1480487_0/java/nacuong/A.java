import java.util.*;
import java.io.*;

public class A  {
	public static void main (String [] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("A-small-0.in"));
			PrintWriter pw = new PrintWriter("A-small-0.out");
			int inputNo;
			inputNo = Integer.parseInt(br.readLine());

			for (int i = 1; i <= inputNo; i++) {
				// get one input here
				String line = br.readLine();
				Scanner sc = new Scanner(line);
				int conNo = sc.nextInt();
				Integer[] score = new Integer[conNo];
				for (int j = 0; j < conNo; j++) {
					score[j] = sc.nextInt();
				}
				pw.println("Case #" + i + ": " + processInput(score));
			}

			br.close();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static String processInput(Integer[] score) {
		String out = "";
		int totalScore = 0;
		for (int s: score) {
			totalScore += s;
		}
		Double[] auds = new Double[score.length];
		boolean again = false;
		int newTotal = totalScore;
		int total = score.length;
		for (int i = 0; i < score.length; i++) {
			auds[i] = ((double)(2*totalScore-score.length*score[i]))*(double)(100)/((double)(score.length*totalScore)); 
			if (auds[i] < 0) {
				again = true;
				newTotal = newTotal - score[i];
				total--;
				auds[i] = 0.0;
			}
		}
		for (int i = 0; i < score.length; i++){
			if (again) 
				if (auds[i] > 0)
					auds[i] = ((double)(totalScore + newTotal-total*score[i]))*(double)(100)/((double)(total*totalScore)); 
			out += " " + auds[i];
		}

		return out;
	}
}
