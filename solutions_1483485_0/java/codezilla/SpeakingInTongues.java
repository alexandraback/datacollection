package codejam2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Hashtable;
import java.util.Scanner;

public class SpeakingInTongues {

	public static void main(String[] args) throws Exception {

		Scanner scanner = new Scanner(new BufferedReader(new FileReader(
				"A-large-practice.in.txt")));
		Output out = new Output("A.out");
		
		Hashtable<Character, Character> table = new Hashtable<Character, Character>();
		
		table.put(' ', ' ');
		table.put('a', 'y');
		table.put('b', 'h');
		table.put('c', 'e');
		table.put('d', 's');
		table.put('e', 'o');
		table.put('f', 'c');
		table.put('g', 'v');
		table.put('h', 'x');
		table.put('i', 'd');
		table.put('j', 'u');
		table.put('k', 'i');
		table.put('l', 'g');
		table.put('m', 'l');
		table.put('n', 'b');
		table.put('o', 'k');
		table.put('p', 'r');
		table.put('q', 'z');
		table.put('r', 't');
		table.put('s', 'n');
		table.put('t', 'w');
		table.put('u', 'j');
		table.put('v', 'p');
		table.put('w', 'f');
		table.put('x', 'm');
		table.put('y', 'a');
		table.put('z', 'q');

		int T = scanner.nextInt();scanner.nextLine();

		for (int t = 1; t <= T; t++) {

			char[] input = scanner.nextLine().toCharArray();
			
			for(int i = 0; i < input.length; i++){
				input[i] = table.get(input[i]);
			}
			
			out.format("Case #%d: %s\n", t, new String(input));
		}

		scanner.close();
		out.close();
	}

	static class Output {

		PrintWriter pw;

		public Output(String filename) throws IOException {
			pw = new PrintWriter(new BufferedWriter(new FileWriter(filename)));
		}

		public void print(String s) {
			pw.print(s);
			System.out.print(s);
		}

		public void println(String s) {
			pw.println(s);
			System.out.println(s);
		}
		
		public void format(String format, Object...args){
			pw.format(format, args);
			System.out.format(format, args);
		}

		public void close() {
			pw.close();
		}
	}

}
