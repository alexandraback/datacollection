package round1C;

import java.util.*;
import java.io.*;
import java.math.*;

public class B {

	private static Scanner sc;
	private static boolean[][] res;
	static int B, total;
	static long M;
	static Map<Integer, Long> cache = new HashMap<>();

	public static void main(final String[] args) {
		setStreams("/Users/yariv/Downloads/B-small-attempt0");
//		setStreams("/Users/yariv/Downloads/B-large");
//		setStreams("/Users/yariv/Downloads/test");
		sc = new Scanner(System.in);
		final int numCases = sc.nextInt();
		handleCases(numCases);
	}

	private static void setStreams(final String baseFileName) {
		try {
			System.setIn(new FileInputStream(baseFileName + ".in"));
			System.setOut(new PrintStream(baseFileName + ".out"));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void handleCases(final long numCases) {
		for (int i = 1; i <= numCases; i++) {
			handleCase(i);
		}
	}

	private static void handleCase(final int caseNumber) {
		 B = sc.nextInt();
		 M = sc.nextLong();
		
		if(M > Math.pow(2, (B - 2))) {
			
			System.out.println("Case #" + caseNumber + ": IMPOSSIBLE");
		}
		else {
			res = new boolean[B][B];
			
			 total = 0;
			for(int i = 1 ; i < B ; i++) {
				total += i;
			}
			
			permAll(0);
			
			System.out.println("Case #" + caseNumber + ": POSSIBLE");
			for(int i = 0 ; i < B ; i++) {
				for(int j = 0 ; j < B ; j++) {
					if(res[i][j]) {
						System.out.print("1");	
					}
					else {
					System.out.print("0");
					}
				}
				System.out.println("");
			}
		}
	}
	
	private static boolean permAll(int index) {
		int row = 0;
		int col = 0;
		int temp = index;
		
		if(index == total) {
			cache = new HashMap<Integer, Long>();
			long res = check(0);
			if(res == M) {
				return true;
			}
			
			return false;
		}
		
		for(int i = 1 ; i < B ; i++) {
			if(temp >= B - i) {
				temp -= B - i;
				row++;
			}
			else {
				col = temp + i;
				break;
			}
		}

		res[row][col] = true;
		if(permAll(index + 1)) {
			return true;
		}
		res[row][col] = false;
		if(permAll(index + 1)) {
			return true;
		}
		
		return false;
	}
	
	private static long check(int start) {
		if(start == B - 1) {
			return 1;
		}
		
		if(cache.get(start) != null) {
			return cache.get(start);
		}
		
		long sum = 0;
		for(int i = start + 1 ; i < B ; i++) {
			if(res[start][i]) {
				sum += check(i);
			}
		}
		
		cache.put(start, sum);
		return sum;
	}
	
	private static void log(final String message) {
//		System.out.println(message);
	}
}
