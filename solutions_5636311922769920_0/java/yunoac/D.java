package QR;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {

	private static Scanner reader;
	private static PrintWriter writer;
	
	public static void main(String[] args) throws IOException {
		reader = new Scanner(new FileReader("input.in"));
		writer = new PrintWriter(new FileWriter("output.out"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			int K = reader.nextInt();
			int C = reader.nextInt();
			int S = reader.nextInt();
			writer.printf("Case #%d: ", tc);
			for(int i = 1; i <= S; i++) {
				writer.print(i);
				if(i < S) {
					writer.print(" ");
				}
			}
			writer.println();
		}
		reader.close();
		writer.close();
	}
	
}
