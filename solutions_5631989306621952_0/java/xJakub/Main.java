import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;
import java.util.Locale;
import java.util.Scanner;

public class Main {

	static FileReader fr;
	static Scanner sc;
	static FileWriter fw;

	public static void openFiles(String inFile, String outFile) throws IOException {	
		fr = new FileReader(inFile);
		fw = new FileWriter(outFile);
		sc = new Scanner(fr);
		sc.useLocale(Locale.US);
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


	public static void main(String[] args) throws IOException {
		openFiles("A-small-attempt0.in", "output.txt");

		int t = sc.nextInt();
		sc.nextLine();

		for (int i=1; i<=t; i++) {
			write("Case #"+i+": ");
			processCase(t);
			writeLine("");
		}

		closeFiles();
	}

	public static void processCase(int caseNumber) throws IOException {
		String s = sc.next();
		int length = s.length();
		
		char[] cs = s.toCharArray();
		String result = cs[0]+"";
		
		for (int i=1; i<length; i++) {
			char c = cs[i];
			if (c >= result.charAt(0)) {
				result = c + result;
			} else {
				result = result + c;
			}
		}
		
		write(result);
	}
}
