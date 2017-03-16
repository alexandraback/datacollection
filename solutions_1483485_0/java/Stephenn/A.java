package info.stephenn.codejam2012.qualify;

import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class A {
	static Map<Character, Character> map = new TreeMap<Character,Character>(); //goog -> english
	
	public static void main(String[] args){
		populate();
		
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		sc.nextLine();
		for (int caseX = 1; caseX <= cases; caseX++){
			String line = sc.nextLine();
			System.out.println("Case #"+caseX+": "+translateGtoE(line));
		}
	}
	
	public static String translateGtoE(String line){
		String output = "";
		for (Character c :line.toCharArray()){
//			if (map.containsKey(c) == false){
//				System.out.println("find c,"+c);
//			}
			output += map.get(c);
		}
		return output;
	}
	
	public static void populate(){
		map.put('y', 'a');
		map.put('e', 'o');
		map.put('q', 'z');
		map.put('j', 'u');
		map.put('p', 'r');
		map.put('m', 'l');
		map.put('s', 'n');
		map.put('l','g');
		map.put('c', 'e');
		map.put('k', 'i');
		map.put(' ', ' ');
		map.put('d', 's');
		map.put('n', 'b');
		map.put('r','t');
		map.put('i', 'd');
		map.put('x', 'm');
		map.put('v','p');
		map.put('t','w');
		map.put('h', 'x');
		map.put('f','c');
		map.put('a','y');
		map.put('b','h');
		map.put('w', 'f');
		map.put('o','k');
		map.put('g', 'v');
		map.put('u','j');
		map.put('z', 'q');
//		mysljylc kd kxveddknmc re jsicpdrysi
//		language is impossible to understand
//		
//		rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
//		there are twenty six factorial possibilities
//		
//		de kr kd eoya kw aej tysr re ujdr lkgc jv
//		so it is okay if you want to just give up
		
		
		
		
		
	}
}
