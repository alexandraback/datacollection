package com.theblind.problem;

import java.util.HashMap;
import java.util.Scanner;

import com.theblind.utility.FileUtility;

public class SpeakingInTongues {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		String inputFileName = in.next();
		String inputData = FileUtility.readFromFile(inputFileName);
		
		SpeakingInTongues problem = new SpeakingInTongues();
		String content = problem.solve(inputData);
		
		FileUtility.writeToFile("output.txt", content);
	}

	private String solve(String inputData) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(inputData);
		StringBuilder sb = new StringBuilder();
		
		int testCases = in.nextInt();
		in.nextLine();
		for (int i = 1; i <= testCases; ++i) {
			sb.append("Case #" + i + ": ");
			
			String line = in.nextLine();
			sb.append(mapping(line));
			sb.append("\n");
		}
		return sb.toString();
	}
	
	HashMap<Character, Character> letters = new HashMap<Character, Character>();
	{
		letters.put('a', 'y');letters.put('b', 'h');letters.put('c', 'e');letters.put('d', 's');
		letters.put('e', 'o');letters.put('f', 'c');letters.put('g', 'v');letters.put('h', 'x');
		letters.put('i', 'd');letters.put('j', 'u');letters.put('k', 'i');letters.put('l', 'g');
		letters.put('m', 'l');letters.put('n', 'b');letters.put('o', 'k');letters.put('p', 'r');
		letters.put('q', 'z');letters.put('r', 't');letters.put('s', 'n');letters.put('t', 'w');
		letters.put('u', 'j');letters.put('v', 'p');letters.put('w', 'f');letters.put('x', 'm');
		letters.put('y', 'a');letters.put('z', 'q');
	}
	
	private Object mapping(String line) {
		// TODO Auto-generated method stub
		StringBuilder sb = new StringBuilder(line);
		for (int i = 0; i < line.length(); ++i) {
			if (line.charAt(i) == ' ') {
				continue;
			}
			sb.setCharAt(i, letters.get(line.charAt(i)));
		}
		return sb.toString();
	}

}
