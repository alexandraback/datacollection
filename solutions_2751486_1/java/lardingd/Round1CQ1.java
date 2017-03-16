package qualifierFun;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;


public class Round1CQ1 {

	private static Set<Character> vowels;
	
	static {
		vowels = new HashSet<Character>();
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			PrintWriter out = new PrintWriter(new FileWriter("output1c1.txt")); 
			BufferedReader in  = new BufferedReader(new FileReader("C:\\Users\\leetname\\Downloads\\large.in"));
			int answer =1;
			String strLine = in.readLine();
			int totalCases = Integer.parseInt(strLine);
			for(int i = 0; i < totalCases; i++) {
				strLine = in.readLine();
				String inputs[] = strLine.split(" ");
				String name = inputs[0];
				int n = Integer.parseInt(inputs[1]);
				long score = getScore(name, n);
				System.out.print(String.format("Case #%s: %s\n", answer, score));
				out.write(String.format("Case #%s: %s\n", answer, score));
				answer++;
			}
			out.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("I'd want to know");
		} catch (IOException e) {
			System.out.println("I'd want to know io");
		}
		System.out.println("done");
	}

	private static long getScore(String name, int n) {
		long score = 0;
		int streakSize = 0;
		int lastStreakIndex = -1;
		for(int i = 0; i < name.length(); i++) {
			if (isVowel(name.charAt(i))) {
				streakSize = 0;
			} else {
				streakSize++;
			}
			if (streakSize >= n) {
				int behind = 1 + (i-lastStreakIndex - n);
				int ahead = name.length() - i;
				score += behind * ahead;
				lastStreakIndex = i - n + 1;
			} 
		}
		return score;
	}

	private static boolean isVowel(char test) {
		return vowels.contains(test);
	}

}
