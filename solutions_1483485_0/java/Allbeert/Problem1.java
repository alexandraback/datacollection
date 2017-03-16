import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Problem1 {
	public static void main (String[] args) throws IOException {
		File file = new File("input.txt");
		Scanner scan = null;
		try {
			scan = new Scanner(file);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		FileWriter fstream = null;
		try {
			fstream = new FileWriter("output.txt");
		} catch (IOException e) {
			e.printStackTrace();
		}
		BufferedWriter out = new BufferedWriter(fstream);
		
		int lineNumber;
		lineNumber = Integer.parseInt(scan.nextLine());
		for (int i = 0; i < lineNumber; i++) {
			Scanner lineScan = new Scanner(scan.nextLine());
			out.write("Case #" + (i + 1) + ": ");
			while (lineScan.hasNext()) {
				String currWord = lineScan.next();
				for (int j = 0; j < currWord.length(); j++) {
					char currChar = currWord.charAt(j);
					switch (currChar) {
					case 'y':
						out.write('a');
						break;
					case 'n':
						out.write('b');
						break;
					case 'f':
						out.write('c');
						break;
					case 'i':
						out.write('d');
						break;
					case 'c':	
						out.write('e');
						break;
					case 'w':
						out.write('f');
						break;
					case 'l':
						out.write('g');
						break;
					case 'b':
						out.write('h');
						break;
					case 'k':
						out.write('i');
						break;
					case 'u':
						out.write('j');
						break;
					case 'o':
						out.write('k');
						break;
					case 'm':
						out.write('l');
						break;
					case 'x':
						out.write('m');
						break;
					case 's':
						out.write('n');
						break;
					case 'e':
						out.write('o');
						break;
					case 'v':
						out.write('p');
						break;
					case 'z':
						out.write('q');
						break;
					case 'p':
						out.write('r');
						break;
					case 'd':
						out.write('s');
						break;
					case 'r':
						out.write('t');
						break;
					case 'j':
						out.write('u');
						break;
					case 'g':
						out.write('v');
						break;
					case 't':
						out.write('w');
						break;
					case 'h':
						out.write('x');
						break;
					case 'a':
						out.write('y');
						break;
					case 'q':
						out.write('z');
						break;
					default:
						break;
					}
					
				}
				out.write(' ');
			}
			out.write('\n');
		}
		out.close();
		
	}

}
