import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
	
	static FileReader fr;
	static Scanner sc;
	static FileWriter fw;
	
	public static void openFiles(String inFile, String outFile) throws IOException {	
		fr = new FileReader(inFile);
		fw = new FileWriter(outFile);
		sc = new Scanner(fr);
	}
	public static void closeFiles() throws IOException {
		sc.close();
		fw.close();
		fr.close();
	}
	public static void writeLine(String line) throws IOException {
		write(line + "\n");
	}
	public static void write(String str) throws IOException {
		System.out.print(str);
		fw.write(str);
	}
	
	public static String reverse(String s) {
		return new StringBuilder(s).reverse().toString();
	}
	
	public static String flip(String s) {
		return reverse(s).replace('+', 'x').replace('-', '+').replace('x', '-');
	}
	
	public static void main(String[] args) throws IOException {
		
		openFiles("B-large.in", "output.txt");
		
		int t = sc.nextInt();
		sc.nextLine();
		
		for (int i=1; i<=t; i++) {
			String stack = sc.nextLine();
			
			int steps = 0;
			int length = stack.length();
			
			while(true) {
				
				int happies = 0;
				int sads = 0;
				
				for (happies=0; happies<length && stack.charAt(happies)=='+'; happies++);
				if (happies == length) break;

				for (sads=0; sads<length && stack.charAt(sads)=='-'; sads++);

				if (happies != 0) {
					stack = flip(stack.substring(0, happies)) + stack.substring(happies);
				}
				else {
					stack = flip(stack.substring(0, sads)) + stack.substring(sads);
				}
				
				steps++;
			}
			

			writeLine("Case #"+i+": "+steps);
		}
		
		closeFiles();
	}
}
