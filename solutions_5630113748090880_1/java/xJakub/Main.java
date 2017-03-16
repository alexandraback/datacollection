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
		openFiles("B-large.in", "output.txt");

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
		int n = sc.nextInt();
		int heights[] = new int[2501];
		
		for (int l=0; l<2*n-1; l++) {
			for (int i=0; i<n; i++) {
				int height = sc.nextInt();
				heights[height]++;
			}
		}
		
		boolean first = true;
		for (int height=0; height<heights.length; height++) {
			if (heights[height] % 2 != 0) {
				if (!first) {
					write(" ");
				}
				write(height+"");
				first = false;
			}
		}
	}
}
