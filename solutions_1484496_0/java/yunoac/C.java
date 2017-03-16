package R1B_2012;

import java.io.*;
import java.util.*;

public class C {

	static BufferedWriter writer;

	public static void main(String[] args) throws IOException {
		writer = new BufferedWriter(new FileWriter("output.out"));
		Scanner reader = new Scanner(new FileReader("input.in"));
		int nt = reader.nextInt();
		reader.nextLine();
		for (int tc = 1; tc <= nt; tc++) {
			writer.write("Case #" + tc + ": ");
			//TODO: code here
			
			writer.newLine();
		}
		writer.close();
		System.out.println("Done.");
	}
}
