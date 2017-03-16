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

	public static void main(String[] args) throws IOException {

		openFiles("C-small-attempt0.in", "output.txt");

		int t = sc.nextInt();
		sc.nextLine();

		for (int i=1; i<=t; i++) {
			int n = sc.nextInt();
			int j = sc.nextInt();

			if (n % 2 == 0) {
				writeLine("Case #"+t+":");
				
				for (int k=0; k<j; k++) {
					int chunkLength = n/2;
					
					long chunk = (1L << (chunkLength - 1)) + 2*k + 1;
					// long num = (chunk << (chunkLength)) + chunk;
					
					String chunkStr = "";

					while(chunk >= 1) {
						chunkStr = (chunk % 2) + chunkStr;
						chunk /= 2;
					}
					
					
					write(chunkStr + chunkStr);
					
					for (int b=2; b<=10; b++) {
						long divisor = 0;
						
						for (int o=0; o<chunkLength; o++) {
							divisor *= b;
							divisor += (long) (chunkStr.charAt(o) - '0');
						}
						
						write(" "+divisor);
					}
					
					writeLine("");
				}
			}
		}

		closeFiles();
	}
}
