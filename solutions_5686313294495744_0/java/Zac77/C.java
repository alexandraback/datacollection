/**
 * Source code for Google Code Jam 2016 - Online Round 1: Sub-Round B - Problem C
 * Author: Zac ZHANG (zac771989@gmail.com)
 * Date: 04/30/2016
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	
	public static final String FILE_NAME = "C-small-attempt0";
	
	private BufferedReader in;
	
	public static void main(String[] args) throws IOException {
		C main = new C();
		main.start();
	}
	
	private void start() throws IOException {
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(FILE_NAME + ".out")));
		in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
		
		int numCases = Integer.parseInt(in.readLine());
		for (int iCase = 1; iCase <= numCases; iCase++)
			out.println("Case #" + iCase + ": " + solve());
		
		in.close();
		out.close();
	}
	
	private String solve() throws IOException {
		int N = Integer.parseInt(in.readLine());
		Word[] words = new Word[N];
		for (int i = 0; i < N; i++) {
			String[] line = in.readLine().split(" ");
			words[i] = new Word(line[0], line[1]);
		}
		
		Arrays.sort(words);
		int ans = 0;
		int i1 = 0;
		while (i1 < words.length) {
			String currentFirst = words[i1].getFirst();
			int i2 = i1 + 1;
			while (i2 < words.length && words[i2].getFirst().equals(currentFirst))
				i2++;
			if (i2 - i1 > 1) {
				int countForThisFirst = 0;
				for (int i = i1; i < i2; i++) {
					String searchSecond = words[i].getSecond();
					boolean found = false;
					for (int j = 0; j < words.length; j++)
						if (words[j].getSecond().equals(searchSecond) && j != i) {
							found = true;
							break;
						}
					if (found)
						countForThisFirst++;
				}
				
				if (countForThisFirst == i2 - i1)
					countForThisFirst--;
				ans += countForThisFirst;
			}
			i1 = i2;
		}
		
		return Integer.toString(ans);
	}
	
	private class Word implements Comparable<Word> {
		
		private final String first;
		private final String second;
		
		public Word(String first, String second) {
			this.first = first;
			this.second = second;
		}
		
		public String getFirst() {
			return first;
		}
		
		public String getSecond() {
			return second;
		}
		
		/* (non-Javadoc)
		 * @see java.lang.Comparable#compareTo(java.lang.Object)
		 */
		@Override
		public int compareTo(Word o) {
			return first.compareTo(o.first);
		}
		
	}
	
}
