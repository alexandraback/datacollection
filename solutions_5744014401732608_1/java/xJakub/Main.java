import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
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


	public static void main(String[] args) throws Exception {
		openFiles("B-large.in", "output.txt");

		int t = sc.nextInt();
		sc.nextLine();

		// launch processCase(i) for every test case
		for (int i=1; i<=t; i++) {
			write("Case #"+i+": ");
			processCase(i);
			write("");
		}

		closeFiles();
	}

	public static void processCase(int caseNumber) throws Exception { 
		int b = sc.nextInt();
		long m = sc.nextLong();

		boolean mat[][] = new boolean[b][b]; 

		if (false) { 
			writeLine("IMPOSSIBLE");
		} else {
			
			for (int i=0; i<b-1; i++) {
				for (int j=i+1; j<b-1; j++) {
					mat[i][j] = true;
				}
			}


			long m2 = m;
			
			if (b <= 30 && pow(2L, b-2) == m) {
				mat[0][b-1] = true;
				m2--;
			}
			
			for (int i=1; i<b-1; i++) {
				if (m2 % 2 != 0) {
					mat[i][b-1] = true;
				}
				m2 /= 2;
			}

			if (m2 == 0) {
			
			writeLine("POSSIBLE");
			for (int i=0; i<b; i++) {
				for (int j=0; j<b; j++) {
					write("" + (mat[i][j] ? '1' : '0'));
				}
				writeLine("");
			}
			}
			else {

				writeLine("IMPOSSIBLE");
			}
		}
	}

	public static long pow(long a, long b) {
		long result = 1;
		
		while (b >= 1) {
			b--;
			result *= a;
		}
		return result;
	}


}
