package com.nolmecolindor.gcj2012.round1b;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Problem_A_0 {

	private String solve(final Scanner input) {
		final short N = input.nextShort();
		final short[] j = new short[N];
		int X = 0;
		for (int i = 0; i < N; i++) {
			j[i] = input.nextShort();
			X += j[i];
		}

		
		final short[] points = Arrays.copyOf(j, N);
		Arrays.sort(points);

		final StringBuilder result = new StringBuilder();
		for (int i = 0; i < N; i++) {
			final short myLevel = j[i];
			short los = 0;
			short eq = 0;
			int adv = 0;
			for (final short p: points) {
				if (p < myLevel) {
					los++;
					adv += myLevel - p;
				} else if (p == myLevel) {
					eq++;
				} else {
					break;
				}
			}

			if (X <= adv) {	// they can not all catch up, no matter what
				result.append("0.0");
			} else {
				int rem = X - adv;	// remaining votes to share, if all loosers cought up
				double level = myLevel;
				short g = (short) (los + eq);
				
				for (short p: points) {
					if (rem == 0) break;
					if (p <= myLevel) continue;
					final short target = p;
					if ((target - level) * g <= rem) {
						rem -= (target - level) * g;
						level = target;
					} else {
						level += (double)rem / g;
						rem = 0;
					}
					g +=1;
					
				}
				if (rem != 0) level += (double)rem / g;
				result.append((level - myLevel) / X * 100);
			}
			result.append(" ");
		}
		return result.toString();
	}
	
	
	private void solveAll(final Scanner input) throws NumberFormatException, IOException {
		final int cases = input.nextInt();
		input.nextLine();
		for (int caseNum = 1; caseNum <= cases; caseNum++) {
			System.out.println("Case #" + caseNum + ": " + solve(input));
		}
	}
	
	public static void main(final String[] args) {
		try {
			final Scanner input = new Scanner(((args.length == 2) && args[0].equals("--input")) ? new FileInputStream(args[1]) : System.in);
			new Problem_A_0().solveAll(input);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
