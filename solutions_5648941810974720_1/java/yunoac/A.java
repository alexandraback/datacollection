package R1B;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class A {
		
	private static Scanner reader;
	private static PrintWriter writer;
	
	static String[] A = new String[] {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	
	public static void main(String[] args) throws IOException {
		reader = new Scanner(new FileReader("input.in"));
		writer = new PrintWriter(new FileWriter("output.out"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			writer.printf("Case #%d: ", tc);
			String S = reader.next();
			
			CountMap H = new CountMap();
			for(char c : S.toCharArray()) {
				H.add(c);
			}
			
			LinkedList<Integer> digits = new LinkedList<>();
			

			while(H.contains('Z')) {
				digits.add(0);
				for(char c : "ZERO".toCharArray()) {
					H.remove(c);
				}
			}
			
			while(H.contains('W')) {
				digits.add(2);
				for(char c : "TWO".toCharArray()) {
					H.remove(c);
				}
			}
			
			while(H.contains('X')) {
				digits.add(6);
				for(char c : "SIX".toCharArray()) {
					H.remove(c);
				}
			}
			
			while(H.contains('G')) {
				digits.add(8);
				for(char c : "EIGHT".toCharArray()) {
					H.remove(c);
				}
			}
			
			while(H.contains('H')) {
				digits.add(3);
				for(char c : "THREE".toCharArray()) {
					H.remove(c);
				}
			}
			
			while(H.contains('R')) {
				digits.add(4);
				for(char c : "FOUR".toCharArray()) {
					H.remove(c);
				}
			}
			
			while(H.contains('F')) {
				digits.add(5);
				for(char c : "FIVE".toCharArray()) {
					H.remove(c);
				}
			}
			
			while(H.contains('S')) {
				digits.add(7);
				for(char c : "SEVEN".toCharArray()) {
					H.remove(c);
				}
			}

			
			while(H.contains('O')) {
				digits.add(1);
				for(char c : "ONE".toCharArray()) {
					H.remove(c);
				}
			}
			
			while(H.contains('N')) {
				digits.add(9);
				for(char c : "NINE".toCharArray()) {
					H.remove(c);
				}
			}
			
			Collections.sort(digits);
			for(int x : digits) {
				writer.print(x);
			}
			writer.println();
			
		}
		reader.close();
		writer.close();
	}
	
	static class CountMap {
		
		HashMap<Character, Integer> H;
		
		public CountMap() {
			H = new HashMap<>();
		}
		
		public void add(char c) {
			Integer cnt = H.get(c);
			if(cnt == null) {
				H.put(c, 1);
			} else {
				H.put(c, cnt + 1);
			}
		}
		
		public boolean contains(char c) {
			return H.containsKey(c);
		}
		
		public void remove(char c) {
			Integer cnt = H.get(c);
			if(cnt == 1) H.remove(c);
			else H.put(c, cnt - 1);				
		}
		
		public String toString() {
			return H.toString();
		}
		
	}
}
