package com.spawn.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.concurrent.atomic.AtomicInteger;

// https://github.com/google/guava/
import com.google.common.collect.*;

class Case {

	public int caseNumber;
	public String result;

	public Case(int i, Scanner s) {
		caseNumber = i;
		parse(s);
	}

	public String getResult() {
		return "Case #" + caseNumber + ": " + result + "\n";
	}

	long c, d, v;
	ArrayList<Integer> denoms;

	public void parse(Scanner s) {
		c = s.nextLong();
		d = s.nextLong();
		v = s.nextLong();
		denoms = new ArrayList<Integer>((int) d);
		for (int i = 0; i < d; i++)
			denoms.add(s.nextInt());
	}

	private static long gcd(long a, long b) {
		while (b > 0) {
			long temp = b;
			b = a % b; // % is remainder
			a = temp;
		}
		return a;
	}

	private static long gcd(long[] input) {
		long result = input[0];
		for (int i = 1; i < input.length; i++)
			result = gcd(result, input[i]);
		return result;
	}

	private static long lcm(long a, long b) {
		return a * (b / gcd(a, b));
	}

	private static long lcm(long[] input) {
		long result = input[0];
		for (int i = 1; i < input.length; i++)
			result = lcm(result, input[i]);
		return result;
	}

	public void solve() {
		int count = 0;
		//ignoring C
		boolean flag = true;
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j < 1 << denoms.size(); j++) {
				long sum = 0;
				for (int k = 0; k < denoms.size(); k++)
					if (((j >> k) & 1) != 0)
						sum += denoms.get(k);
				if (sum == i) {
					flag = false;
					break;
				}
			}
			if (flag) {
				denoms.add(i);
				count++;
			}
			flag = true;
		}
		result = Integer.toString(count);
		System.out.println("#" + caseNumber + " done; "
				+ Main.casesRemaining.decrementAndGet() + " remaining");
	}
}

public class Main {

	public static AtomicInteger casesRemaining = new AtomicInteger();

	public static void main(String[] args) {
		try {
			String name = readLine();
			Scanner s = new Scanner(new File("../" + name + ".in"));

			int t = s.nextInt();
			casesRemaining.set(t);
			ArrayList<Case> cases = new ArrayList<Case>(t);
			File f = new File("../" + name + ".out");
			FileWriter output = new FileWriter(f);
			for (int i = 0; i < t; i++) {
				cases.add(i, new Case(i + 1, s));
			}
			if (name.equals("test"))
				cases.stream().forEach(Case::solve);
			else
				cases.parallelStream().forEach(Case::solve);

			for (int i = 0; i < t; i++) {
				output.write(cases.get(i).getResult());
			}
			output.close();
			s.close();

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static String readLine() throws IOException {
		if (System.console() != null) {
			return System.console().readLine();
		}
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		return reader.readLine();
	}

}
