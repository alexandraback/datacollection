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
		
		openFiles("A-large.in", "output.txt");
		
		int t = sc.nextInt();
		sc.nextLine();
		
		for (int i=1; i<=t; i++) {
			int n = sc.nextInt();
			int rem = 10;
			boolean did[] = new boolean[10];
			
			if (n == 0) {
				writeLine("Case #"+i+": INSOMNIA");
			}
			else {
				int mult;
				for (mult=1; rem>0; mult++) {
					int res = n*mult;
					while (res >= 1) {
						int mod = res % 10;
						if (!did[mod]) {
							did[mod] = true;
							rem--;
						}
						res /= 10;
					}
				}
				writeLine("Case #"+i+": "+(n * (mult-1)));
			}

		}
		
		closeFiles();
	}
}
