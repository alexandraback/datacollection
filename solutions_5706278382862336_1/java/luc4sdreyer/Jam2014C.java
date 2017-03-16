package gcj;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

import java.util.Iterator;

public class Jam2014C {
	//10^4 <  Short.MAX_VALUE (2^15)   < 10^5
	//10^9 <  Integer.MAX_VALUE (2^31) < 10^10
	//10^18 < Long.MAX_VALUE (2^63)    < 10^20


	public static void main(String[] args) throws NumberFormatException, IOException {		
		Scanner sc = new Scanner(new FileReader(filename+".in"));
		String output = null;
		String outputfile = filename + ".out";

		FileOutputStream Output = new FileOutputStream(outputfile);
		PrintStream file2 = new PrintStream(Output);

		boolean after25 = false;
		boolean after50 = false;
		boolean after75 = false;

		//int T = sc.nextInt();
		int T = Integer.parseInt(sc.nextLine());
		System.out.println(Calendar.getInstance().getTime()+" - Started writing to: "+outputfile);


		for (int i = 0; i < T; i++) {
			
//			int n = sc.nextInt();
//			ArrayList<String> words = new ArrayList<String>();
//			StringTokenizer st = new StringTokenizer(sc.nextLine());
//			for (int j = 0; j < n; j++) {
//				words.add(sc.next());
//			}
//			output = solve(n, words);
			
			String[] num = sc.nextLine().split("/");
			output = solve(Long.parseLong(num[0]), Long.parseLong(num[1]));

			file2.println("Case #" + (i+1) + ": "+output);
			if ((100*(i+1)/T >= 25) && (!after25)) {
				System.out.println(Calendar.getInstance().getTime()+" - 25% done");				after25 = true;
			} else if ((100*(i+1)/T >= 50) && (!after50)) {
				System.out.println(Calendar.getInstance().getTime()+" - 50% done");				after50 = true;
			} else if ((100*(i+1)/T >= 75) && (!after75)) {
				System.out.println(Calendar.getInstance().getTime()+" - 75% done");				after75 = true;
			}
		}
		sc.close();		System.out.println(Calendar.getInstance().getTime()+" - Finished writing to: "+outputfile);
	}


	private static String solve(long l, long m) {
		long firstElf = -1;
		boolean valid = false;
		for (long gen = 1; gen <= 40; gen++) {
			l = (l * 2);
			if (firstElf == -1 && l >= m) {
				firstElf = gen; 
			}
			l = l % m;
			if (l == 0) {
				valid = true;
				break;
			}
		}
		if (valid) {
			return Long.toString(firstElf);
		} else {
			return "impossible";
		}
	}


	private static String solve(int n, ArrayList<String> wordsOrig) {
		ArrayList<String> words = new ArrayList<String>(wordsOrig);
		long total = 1;
		for (char c = 'a'; c <= 'z'; c++) {
			ArrayList<Integer> currentWords = new ArrayList<Integer>();
			int numStart = 0;
			int numMid = 0;
			int numEnd = 0;
			String start = "";
			String end = "";
			for (int j = 0; j < words.size(); j++) {
				boolean starts = false;
				boolean ends = false;
				if (words.get(j).charAt(0) == c) {
					starts = true;
				}
				if (words.get(j).charAt(words.get(j).length()-1) == c) {
					ends = true;
				}
				int numMatching = 0;
				for (int k = 0; k < words.get(j).length(); k++) {
					if (words.get(j).charAt(k) == c) {
						numMatching++;
					}
				}
				if (numMatching == words.get(j).length()) {
					numMid++;
					currentWords.add(j);
				} else if (numMatching > 0) {
					if (ends) {
						numStart++;
						currentWords.add(j);
						start = words.get(j);
					} else if (starts) {
						numEnd++;
						currentWords.add(j);
						end = words.get(j);
					}
				}
			}
			if (numStart > 1 || numEnd > 1) {
				return "0";
			}
			total *= factorial(numMid).longValue() % 1000000007;
			
			Collections.sort(currentWords);
			for (int i = currentWords.size()-1; i >= 0; i--) {
				words.remove((int)currentWords.get(i));
			}
			if (numMid > 0) {
				words.add(start + c + end);
			} else if (start.length() > 0 || end.length() > 0) {
				words.add(start + end);
			}
		}
		for (char c = 'a'; c <= 'z'; c++) {
			int numWords = 0;
			for (int i = 0; i < words.size(); i++) {
				for (int j = 0; j < words.get(i).length(); j++) {
					if (words.get(i).charAt(j) == c) {
						numWords++;
						break;
					}
				}
			}
			if (numWords > 1) {
				return "0";
			} 
		}
		for (int i = 0; i < words.size(); i++) {
			ArrayList<Character> c = new ArrayList<Character>();
			for (int j = 0; j < words.get(i).length(); j++) {
				c.add(words.get(i).charAt(j));
			}
			for (int j = 1; j < c.size(); j++) {
				if (c.get(j) == c.get(j-1)) {
					c.remove((int)j);
					j--;
				}
			}
			int[] a = new int[26];
			for (int j = 0; j < c.size(); j++) {
				a[c.get(j)- 'a']++;
			}
			for (int j = 0; j < a.length; j++) {
				if (a[j] > 1) {
					return "0";
				}
			}
			
		}
		total *= factorial(words.size()).mod(BigInteger.valueOf(1000000007)).longValue();
		return Long.toString(total);
	}

	private static HashMap<Integer,BigInteger> fCache = new HashMap<Integer,BigInteger>();
	private static long fCacheSize = 1000000;
    
	private static BigInteger factorial(int n)
    {
        BigInteger ret;
        
        if (n < 0) return BigInteger.ZERO;
        if (n == 0) return BigInteger.ONE;
        
		if (null != (ret = fCache.get(n))) return ret;
        else ret = BigInteger.ONE;
        for (int i = n; i >= 1; i--) {
        	if (fCache.containsKey(n)) return ret.multiply(fCache.get(n));
        	ret = ret.multiply(BigInteger.valueOf(i));
        }
        
        if (fCache.size() < fCacheSize) {
        	fCache.put(n, ret);
        }
        return ret;
    }


	//static String size = "sample";
	//static String size = "small";
	//static String size = "large"=
	static String filename = "F:\\gcj\\2014\\1C\\A-large";
}