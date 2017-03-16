package round1c;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class ProblemB {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int cases = sc.nextInt();

		for (int cs = 1; cs <= cases; cs++) {
			
			int n = sc.nextInt();
			
			String []str = new String[n];
			
			for(int i = 0; i < n; i++) {
				str[i] = sc.next();
			}
			
			int [][] perms = getPermutations(n);
			
			int count = 0;
			
			for(int []perm : perms) {
				StringBuffer buff = new StringBuffer();
				
				for(int idx : perm) {
					buff.append(str[idx]);
				}
				
			 if(check(buff.toString())) {
				 count++;
			 }
			}
			

			System.out.println("Case #" + cs + ":" + count);
		}
	}
	
	private static boolean check(String string) {
		char []ch = string.toCharArray();
		
		Map<Character, Boolean> map = new HashMap<Character,Boolean>();
		
		boolean ret = true;
		
		for(int i = 1; i < ch.length; i++) {
			if(ch[i] != ch[i - 1]) {
				if(map.get(ch[i - 1]) != null) {
					ret = false;
					break;
				}
				map.put(ch[i - 1], true);
			}
		}

		if(map.get(ch[ch.length - 1]) != null) {
			ret = false;
		}
		
		return ret;
		
	}

	public static int[][] getPermutations(int k) {

		int[][] perms = new int[(int) factorial(k)][k];

		List<Integer> initialOptions = new ArrayList<Integer>();

		for (int i = 0; i < k; i++) {
			initialOptions.add(Integer.valueOf(i));
		}

		List<List<Integer>> permutations = computePermutations(initialOptions);

		int listidx = 0;
		for (List<Integer> list : permutations) {
			int idx = 0;
			for (Integer igr : list) {
				perms[listidx][idx++] = igr.intValue();
			}
			listidx++;
		}

		return perms;
	}
	
	/*
	 * Computes all the distinct permutations from 0 upto given integer - 1. For
	 * exmple if k = 2 permutations would be 0,1 and 1,0 etc.
	 * 
	 * input = list of numbers (0...k-1) output = list of list of integers of
	 * permutations
	 */

	public static List<List<Integer>> computePermutations(List<Integer> options) {
		List<List<Integer>> result = new ArrayList<List<Integer>>();

		if (options.size() == 1) {
			result.add(new ArrayList<Integer>(options));
			return result;
		}

		for (Integer i : options) {
			List<Integer> newOptions = new ArrayList<Integer>(options);
			newOptions.remove(i);
			List<List<Integer>> results = computePermutations(newOptions);
			for (List<Integer> r : results) {
				r.add(0, i);
				result.add(r);
			}
		}
		return result;
	}

	/*
	 * Computes the factorial of given number
	 * 
	 * input = given number output = factorial of given number
	 */
	public static long factorial(long m) {
		long result = 1;
		while (m != 1) {
			result = result * m--;
		}
		return result;
	}

}
