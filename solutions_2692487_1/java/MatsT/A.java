package se.matst.codejam;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new File("C:\\dev\\codejam\\codejam\\src\\A-large.in"));

		PrintWriter out = new PrintWriter("C:\\dev\\codejam\\codejam\\src\\A-large.out");

		int testCases = scanner.nextInt();

		for (int i = 0; i < testCases; i++) {
			int operations = 0;
			int maxOp = Integer.MAX_VALUE;
			int arminMote = scanner.nextInt();
			int nrOfMotes = scanner.nextInt();
			Queue<Integer> motes = new PriorityQueue<Integer>();
			for (long j = 0; j < nrOfMotes; j++) {
				motes.add(scanner.nextInt());
			}
			if (arminMote == 1) {
				operations = nrOfMotes;
			} else {
				while (!motes.isEmpty()) {
					if (maxOp > operations + motes.size()) {
						maxOp = operations + motes.size();
					}
					Integer mote = motes.poll();
					while (arminMote <= mote) {
						arminMote += arminMote - 1;
						operations++;
					}
					arminMote += mote;
				}
				if (maxOp < operations) {
					operations = maxOp;
				}
			}

			out.println("Case #" + (i + 1) + ": " + operations);
			System.out.println(i + " done!");
		}

		out.close();
	}
}