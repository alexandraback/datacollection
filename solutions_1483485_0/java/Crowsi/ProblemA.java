package qualification;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;

public class ProblemA {
	
	static Map<Character, Character> charMap;
	
	public static void main(String[] args) {

		
		String[] preparationG = new String[]{"ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
		
		String[] preparation = new String[]{"our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up"};

		charMap = new TreeMap<Character, Character>();
		
		charMap.put('y', 'a');
		charMap.put('e', 'o');
		charMap.put('q', 'z');
		
//		TreeSet<Character> values = new TreeSet<Character>();
		
		for ( int i = 0; i < preparation.length; i++ ) {
			
			for ( int j = 0; j < preparation[i].length(); j++ ) {
				if ( preparation[i].charAt(j) != ' ' ) {
					charMap.put(preparationG[i].charAt(j), preparation[i].charAt(j));
//					values.add(preparation[i].charAt(j));
				}
				
			}
			 
		}
		
		// Z is missing from keyset, Q is missing from valueset
		charMap.put('z', 'q');
		
//		System.out.println( charMap.size() );
//		System.out.println(charMap.keySet());
//		System.out.println(values);
		
		
		Scanner scan = new Scanner(System.in);
		
		int cases = Integer.parseInt(scan.nextLine());
		
		for ( int i = 1; i <= cases; i++) {
			String res = translate(scan.nextLine());
			System.out.println("Case #" + i + ": " + res);
		}
		
	}

	public static String translate(String s) {

		StringBuilder sb = new StringBuilder();
		
		for ( int i = 0; i < s.length(); i++ ) {
			
			Character ch = s.charAt(i);
			
			if ( ch != ' ' ) {
				sb.append(charMap.get(ch));
			} else {
				sb.append(' ');
			}
			
		}
	
		return sb.toString();
	}
	
}
