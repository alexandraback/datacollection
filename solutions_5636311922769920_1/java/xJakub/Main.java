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
		
		openFiles("D-large.in", "output.txt");
		
		int t = sc.nextInt();
		sc.nextLine();
		
		for (int i=1; i<=t; i++) {
			long k = sc.nextInt();
			long c = sc.nextInt();
			long s = sc.nextInt();
			
			if (c * s < k) {
				writeLine("Case #"+i+": IMPOSSIBLE");				
			}
			else {
				s = (k+c-1) / c;
				
				write("Case #"+i+": ");
				
				for (int j=0; j<s; j++) {
					long pos = 1;
					long mult = 1;
					
					long offStart = (c * j);
					long offEnd = Math.min(offStart + c - 1, k - 1);
					
					for (long l=offStart; l<=offEnd; l++) {
						pos += l * mult;
						mult *= k;
					}
					
					write(pos+"");
					
					if (j == s-1) {
						writeLine("");
					}
					else {
						write(" ");
					}
				}
			}
		}
		
		closeFiles();
	}
}
