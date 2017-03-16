package codejam.year2014.round1C;

import java.util.*;
import java.io.*;
import java.math.*;

public class B {

	private static Scanner sc;

	private static long MOD = 1000000007L;
	private static int N;
	private static long sum;
	private static String[] cars;
	public static void main(final String[] args) {
//		 setStreams("C:\\Users\\ybandiel\\Desktop\\testB");
		 setStreams("C:\\Users\\ybandiel\\Desktop\\B-small-attempt2");
		// setStreams("C:\\Users\\ybandiel\\Desktop\\B-large");
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
		N = sc.nextInt();
		cars = new String[N];
		sum = 0;
		Set<Integer> nums = new HashSet<>();
		for(int i = 0 ; i < N ; i++) {
			nums.add(i);
			cars[i] = sc.next();
		}

		checkPerms(nums, new int[N]);
		System.out.println("Case #" + caseNumber + ": " + sum);
	}

	private static void checkPerms(Set<Integer> numsLeft, int[] perm) {
		
		if(!checkPerm(perm, N - numsLeft.size())) {
			return;
		}
		else if(numsLeft.isEmpty()) {
				sum++;
				if(sum == MOD) {
					sum = 0;
				}
			return;
 		}
		for(int num : numsLeft) {
			perm[N - numsLeft.size()] = num;
			Set<Integer> newNumsLeft = new HashSet<>(numsLeft);
			newNumsLeft.remove(num);
			checkPerms(newNumsLeft, perm);
		}
	}

	private static boolean checkPerm(int[] perm, int len) {
		String str = "";
		for(int i = 0 ; i < len ; i++) {
			str += cars[perm[i]];
		}
		
		Set<Character> chars = new HashSet<>();
		Character last = null;
		for(int i = 0 ; i < str.length() ; i++) {
			if(last == null) {
				last = str.charAt(i);
				chars.add(last);
			}
			else {
				if(str.charAt(i) != last) {
					if(chars.contains(str.charAt(i))) {
						return false;
					}
					else {
						chars.add(str.charAt(i));
						last = str.charAt(i);
					}
				}
			}
		}
		
		return true;
	}

	private static void log(final String message) {
		System.out.println(message);
	}
}
