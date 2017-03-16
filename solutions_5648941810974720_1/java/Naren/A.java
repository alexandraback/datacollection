import java.lang.*;
import java.util.*;
import java.io.*;

public class A {
	private static final String prefix = "C:\\Users\\sivasub\\Downloads\\".replace("\\", "/");
	private static final String fileName = prefix + "A-large";
	
	static String[] numbers = new String[] {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	
	
	static Map<Character, Integer> getMap(String number, Map<Character, Set<Integer>> overallMap, int n) {
		Map<Character, Integer> numMap = new HashMap<>();
		for(int i = 0; i< number.length(); i++) { 
			numMap.put(number.charAt(i), 1 + numMap.getOrDefault(number.charAt(i), 0));
			Set<Integer> st = overallMap.getOrDefault(number.charAt(i), new HashSet<>());
			st.add(n);
			overallMap.put(number.charAt(i), st);
		}
		return numMap;
	}
	
	static boolean exists(Map<Character, Integer> numMap, Map<Character, Integer> map) {
		for(Character c : numMap.keySet()) {
			if(map.getOrDefault(c, 0) < numMap.get(c)) {
				return false;
			}
		}
		
		return true;
	}
	
	static void remove(Map<Character, Integer> numMap, Map<Character, Integer> map) {
		for(Character c : numMap.keySet()) {
			map.put(c, map.get(c) - numMap.get(c));
		}
	}

	public static void main(String args[]) throws Exception {
	
		 
		
		try(InputStream input = new FileInputStream(fileName + ".in");
			Scanner sc = new Scanner(input);
			PrintStream output = new PrintStream(fileName + ".out")) {
			
			Map<Integer, Map<Character, Integer>> numMap = new HashMap<>();
			Map<Character, Set<Integer>> overallSet = new HashMap<>();
			
			for(int i = 0; i< 10; i++) {
				numMap.put(i, getMap(numbers[i], overallSet, i));
				
			}
			
			System.out.println(overallSet);
			int T = sc.nextInt();
			int[] seq = new int[]{0, 6,2,4,8,5,7,3,1,9};
			for(int t = 1; t <= T; t++) {
				//Input
				String s = sc.next();
				
				Map<Character, Integer> map = new HashMap<>();
				for(int i = 0; i< s.length(); i++) {
					map.put(s.charAt(i), 1 + map.getOrDefault(s.charAt(i), 0));
				}
				
				StringBuilder sb = new StringBuilder();
				for(int i = 0; i < 10; i++) {
					while(exists(numMap.get(seq[i]), map)) {
						sb.append(seq[i]);
						remove(numMap.get(seq[i]), map);
					}
				}
				char[] ar = sb.toString().toCharArray();
				Arrays.sort(ar);
				//Output
				output.println("Case #" + t + ": " + String.valueOf(ar));
			}
		}
	}
}
