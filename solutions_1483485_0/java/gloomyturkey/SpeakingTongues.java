package com.google.cj12;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;

public class SpeakingTongues {
	private HashMap<Character, Character> map;
	private HashMap<Character, Character> reverse;
	
	public static void main(String[] args) {
		SpeakingTongues st = new SpeakingTongues();
		st.init();
		st.run();
	}
	
	private void init() {
		map = new HashMap<Character, Character>();
		reverse = new HashMap<Character, Character>();
		map.put('a', 'y');
		map.put('o', 'e');
		map.put('z', 'q');
		
		try {
			BufferedReader fi = new BufferedReader(new FileReader("resources/input.0"));
			BufferedReader fo = new BufferedReader(new FileReader("resources/output.0"));
			int N = 3; 
			fi.readLine();
			
			for (int i=0; i<N; i++) {
				String in = fi.readLine();
				String out = fo.readLine().substring(9);
				for (int j=0; j<in.length(); j++) {
					char ci = in.charAt(j);
					char co = out.charAt(j);
					if (ci == ' ') continue;
					if (map.containsKey(co) && map.get(co)!=ci) {
						System.out.println("error to translate!");
					}
					else {
						map.put(co, ci);
					}
				}
			}
			
			fi.close();
			fo.close();
		} catch (IOException e) {}
		
		int total = 0;
		for (char c='a'; c<='z'; c++) total += c;
		int inMiss = total;
		int outMiss = total;
		for (char c : map.keySet()) {
			inMiss -= c;
			outMiss -= map.get(c);
		}
		map.put((char)inMiss, (char)outMiss);
		
		for (char c : map.keySet()) {
//			System.out.println(c + " -> " + map.get(c));
			reverse.put(map.get(c), c);
		}
	}
	
	private void run() {
		try {
			BufferedReader fi = new BufferedReader(new FileReader("resources/input"));
			int N = Integer.parseInt(fi.readLine()); 
			
			for (int i=0; i<N; i++) {
				String in = fi.readLine();
				StringBuffer out = new StringBuffer();
				for (char c : in.toCharArray()) {
					if (c == ' ') {
						out.append(c);
					}
					else {
						out.append(reverse.get(c));
					}
				}
				System.out.println("Case #" + (i+1) + ": " + out.toString());
			}
			
			fi.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
