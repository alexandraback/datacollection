package com.whitecrow.codejam2012.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		String filename = "A-small-attempt0";

		FileReader input;
		FileWriter output;
		try {
			input = new FileReader(filename + ".in");
			output = new FileWriter(filename + ".out");

			BufferedReader reader = new BufferedReader(input);
			BufferedWriter writer = new BufferedWriter(output);

			// String in = "";
			String out = "";

			int T = Integer.parseInt(reader.readLine());
			for (int i = 0; i < T; i++) {
				String result = "";
				String line = reader.readLine();
				for(int j = 0; j < line.length(); j++) {
					result += mapping(line.charAt(j));
				}
				
				
				out = "Case #" + (i + 1) + ": " + result;
				System.out.println(out);
				writer.write(out+"\n");
			}

			reader.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(0);
		}
	}
	
	public static char mapping(char c) {
		if(c == 'y') {
			return 'a';
		} else if(c == 'n') {
			return 'b';
		} else if(c == 'f') {
			return 'c';
		} else if(c == 'i') {
			return 'd';
		} else if(c == 'c') {
			return 'e';
		} else if(c == 'w') {
			return 'f';
		} else if(c == 'l') {
			return 'g';
		} else if(c == 'b') {
			return 'h';
		} else if(c == 'k') {
			return 'i';
		} else if(c == 'u') {
			return 'j';
		} else if(c == 'o') {
			return 'k';
		} else if(c == 'm') {
			return 'l';
		} else if(c == 'x') {
			return 'm';
		} else if(c == 's') {
			return 'n';
		} else if(c == 'e') {
			return 'o';
		} else if(c == 'v') {
			return 'p';
		} else if(c == 'z') {
			return 'q';
		} else if(c == 'p') {
			return 'r';
		} else if(c == 'd') {
			return 's';
		} else if(c == 'r') {
			return 't';
		} else if(c == 'j') {
			return 'u';
		} else if(c == 'g') {
			return 'v';
		} else if(c == 't') {
			return 'w';
		} else if(c == 'h') {
			return 'x';
		} else if(c == 'a') {
			return 'y';
		} else if(c == 'q') {
			return 'z';
		} else {
			return ' ';
		}
	}
}
