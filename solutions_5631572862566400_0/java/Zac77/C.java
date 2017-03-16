/**
 * Source code for Google Code Jam 2016 - Online Round 1: Sub-Round A - Problem C
 * Author: Zac ZHANG (zac771989@gmail.com)
 * Date: 04/15/2016
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class C {
	
	public static final String FILE_NAME = "C-small-attempt1";
	
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
		int[] F = new int[N];
		String[] numbers = in.readLine().split(" ");
		for (int j = 0; j < numbers.length; j++)
			F[j] = Integer.parseInt(numbers[j]) - 1;
		
		List<BFFLink> possibleLinks = new ArrayList<BFFLink>();
		List<boolean[]> possibleCircles = new ArrayList<boolean[]>();
		int ans = 0;
		for (int testStart = 0; testStart < N; testStart++) {
			boolean[] usedKids = new boolean[N];
			usedKids[testStart] = true;
			int[] circle = new int[N];
			circle[0] = testStart;
			int testCircleLength = 1;
			while (true) {
				int nextKid = F[circle[testCircleLength - 1]];
				if (!usedKids[nextKid]) {
					circle[testCircleLength] = nextKid;
					usedKids[nextKid] = true;
					testCircleLength++;
					continue;
				}
				if (nextKid == circle[testCircleLength - 2]) {
					possibleLinks.add(new BFFLink(usedKids, circle, testCircleLength));
					if (testCircleLength > ans)
						ans = testCircleLength;
				}
				if (nextKid == testStart) {
					possibleCircles.add(usedKids);
					if (testCircleLength > ans)
						ans = testCircleLength;
				}
				break;
			}
		}
		
		for (int i = 0; i < possibleLinks.size() - 1; i++)
			for (int j = i + 1; j < possibleLinks.size(); j++) {
				BFFLink a = possibleLinks.get(i);
				BFFLink b = possibleLinks.get(j);
				int k = 0;
				for (; k < b.numUsedKids; k++) {
					if (a.usedKids[b.circle[k]])
						break;
				}
				if (k == b.numUsedKids && a.numUsedKids + b.numUsedKids > ans) {
					ans = a.numUsedKids + b.numUsedKids;
					continue;
				}
				if (b.circle[k] == a.circle[a.numUsedKids - 1]) {
					if (a.numUsedKids + k > ans)
						ans = a.numUsedKids + k;
				}
				/*
				if (a.lastKid == b.lastKid) {
					boolean canConnect = true;
					for (int k = 0; k < N; k++) {
						if (k != a.lastKid && a.usedKids[k] && b.usedKids[k]) {
							canConnect = false;
							break;
						}
					}
					if (canConnect && a.numUsedKids + b.numUsedKids - 1 > ans)
						ans = a.numUsedKids + b.numUsedKids - 1;
				}*/
			}
		for (int i = 0; i < possibleCircles.size() - 1; i++)
			for (int j = i + 1; j < possibleCircles.size(); j++) {
				boolean[] a = possibleCircles.get(i);
				boolean[] b = possibleCircles.get(j);
				boolean can = true;
				int counter = 0;
				for (int k = 0; k < a.length; k++)
					if (a[k] && b[k]) {
						can = false;
						break;
					} else if (a[k] || b[k])
						counter++;
				if (can && counter > ans)
					ans = counter;
			}
		return Integer.toString(ans);
	}
	
	private class BFFLink {
		
		private final boolean[] usedKids;
		private final int[] circle;
		private final int numUsedKids;
		
		public BFFLink(boolean[] usedKids, int[] circle, int numUsedKids) {
			this.usedKids = usedKids;
			this.circle = circle;
			this.numUsedKids = numUsedKids;
		}
		
	}
	
}
