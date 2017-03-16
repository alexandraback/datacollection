import java.io.*;
import java.util.*;

public class template {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		HashMap<Character, Character> map = new HashMap<Character, Character>();
		
		map.put('a', 'y');
		map.put('b', 'h');
		map.put('c', 'e');
		map.put('d', 's');
		map.put('e', 'o');
		map.put('f', 'c');
		map.put('g', 'v');
		map.put('h', 'x');
		map.put('i', 'd');
		map.put('j', 'u');
		map.put('k', 'i');
		map.put('l', 'g');
		map.put('m', 'l');
		map.put('n', 'b');
		map.put('o', 'k');
		map.put('p', 'r');
		map.put('q', 'z');
		map.put('r', 't');
		map.put('s', 'n');
		map.put('t', 'w');
		map.put('u', 'j');
		map.put('v', 'p');
		map.put('w', 'f');
		map.put('x', 'm');
		map.put('y', 'a');
		map.put('z', 'q');
		map.put(' ', ' ');

		int count = in.nextInt();
		in.nextLine();
		
		for(int i = 0 ; i < count ; i++) {
			out.print("Case #" + (i+1) + ": ");
			String s = in.nextLine();
			for(int j = 0 ; j < s.length() ; j++) {
				out.print(map.get(s.charAt(j)));
			}
			
			out.println();
		}
		
		out.flush();
	}
}