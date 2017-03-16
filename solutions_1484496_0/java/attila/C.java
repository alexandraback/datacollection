package at.jaki.codejam.y2012.r1B.C;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class C {

	private static final String NAME = "C";
	private static final String IN = ".in";
	private static final String OUT = ".out";
	// private static final String TYPE = "-small-attempt0";
	// private static final String TYPE = "-large";
	private static final String TYPE = "";
	private static final String TEMPLATE = "Case #%d: %s";

	private static Scanner sc;
	private static PrintWriter pw;
	private static int totalTests;

	private static List<Integer> numbers;
	private static Map<Long, Long> map = new HashMap<Long, Long>();
	private static long max;

	private static void init() {
		try {
			sc = new Scanner(new File(NAME.concat(TYPE.concat(IN))));
			pw = new PrintWriter(new File(NAME.concat(TYPE.concat(OUT))));
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static void start() {
		totalTests = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= totalTests; i++) {
			doStuff(i);
		}
	}

	private static void close() {
		pw.flush();
		pw.close();
	}

	public static void main(String[] args) {
		init();
		start();
		close();
	}

	private static void doStuff(int test) {
		int n = sc.nextInt();
		numbers = new ArrayList<Integer>(n);
		long sum = 0;
		for (int i = 0; i < n; i++) {
			int x = sc.nextInt();
			numbers.add(x);
			sum += x;
		}
		max = sum / 2;

		StringBuilder sb1 = new StringBuilder();
		StringBuilder sb2 = new StringBuilder();

		try {
			do2(new ArrayList<Integer>(n), 1L, 0, 0L);
		} catch (RuntimeException e) {
			String[] x = e.getMessage().split(" ");
			char[] ch1 = x[0].toCharArray();
			char[] ch2 = x[1].toCharArray();
			for (int i = 0; i < ch1.length; i++) {
				if (ch1[i] == '1') {
					sb1.append(numbers.get(i));
					sb1.append(" ");
				}
			}
			System.out.println();
			for (int i = 0; i < ch2.length; i++) {
				if (ch2[i] == '1') {
					sb2.append(numbers.get(i));
					sb2.append(" ");
				}
			}
		} finally {
			map.clear();
			if (sb1.length()==0){
				pw.println(String.format(TEMPLATE, test,"Impossible"));
			} else {
				pw.println(String.format(TEMPLATE, test," "));
				pw.println(sb1);
				pw.println(sb2);
			}
		}

	}

	private static void do2(List<Integer> left, long hash, int index,
			Long currSum) {
		if (currSum > max) {
			return;
		}
		if (currSum != 0 && hash % 2 != 0) {
			Long prev = map.put(currSum, hash);
			if (prev != null) {
				String s1 = Long.toString(hash, 2).substring(1);
				String s2 = Long.toString(prev, 2).substring(1);
				throw new RuntimeException(s1 + " " + s2);
			}
		}
		if (index == numbers.size()) {
			return;
		}
		do2(left, hash << 1, index + 1, currSum);
		Integer x = numbers.get(index);
		left.add(x);
		do2(left, (hash << 1) + 1, index + 1, currSum + x);
		left.remove(x);
	}
}
