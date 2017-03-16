import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {

	public static void main(String[] args) {
		
		char[] map = new char[26];
		map[ord('a')] = 'y';
		map[ord('b')] = 'h';
		map[ord('c')] = 'e';
		map[ord('d')] = 's';
		map[ord('e')] = 'o';
		map[ord('f')] = 'c';
		map[ord('g')] = 'v';
		map[ord('h')] = 'x';
		map[ord('i')] = 'd';
		map[ord('j')] = 'u';
		map[ord('k')] = 'i';
		map[ord('l')] = 'g';
		map[ord('m')] = 'l';
		map[ord('n')] = 'b';
		map[ord('o')] = 'k';
		map[ord('p')] = 'r';
		map[ord('q')] = 'z';
		map[ord('r')] = 't';
		map[ord('s')] = 'n';
		map[ord('t')] = 'w';
		map[ord('u')] = 'j';
		map[ord('v')] = 'p';
		map[ord('w')] = 'f';
		map[ord('x')] = 'm';
		map[ord('y')] = 'a';
		map[ord('z')] = 'q';
		
		try {
			Scanner in = new Scanner(new File("inputA.in"));
			BufferedWriter writer = new BufferedWriter(new FileWriter(new File("outputA.out")));
			
			int N = in.nextInt();
			in.nextLine();
			
			for (int i=0; i<N; i++) {
				String line = in.nextLine();
				
				char[] newLine = new char[line.length()];
				
				for (int j=0; j<newLine.length; j++) {
					if (line.charAt(j) == ' ') 
						newLine[j] = ' ';
					else
						newLine[j] = map[ord(line.charAt(j))];
				}
				
				String newLineS = new String(newLine);
				System.out.println(newLineS);
				
				writer.append("Case #" + (i+1) + ": " + newLineS + "\n");
			}
			
			
			writer.close();
			
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static int ord(char c) {
		return c - 'a';
	}
}
