package pl.helman;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Pogo {


	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\cj\\pogo.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter f0 = new FileWriter("d:\\cj\\pogo.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		for (int c = 1; c <= t; c++) {
			System.out.println(c);

			line = br.readLine();
			String[] elems = line.split(" ");

			int x = Integer.parseInt(elems[0]);
			int y = Integer.parseInt(elems[1]);
			
			System.out.print("Case #" + c + ": ");
			f0.write("Case #" + c + ": ");
			
			while (x > 0) {
				System.out.print("WE");
				f0.write("WE");
				x--;
			}
			
			while (x < 0) {
				System.out.print("EW");
				f0.write("EW");
				x++;
			}
			
			while (y > 0) {
				System.out.print("SN");
				f0.write("SN");
				y--;
			}
			
			while (y < 0) {
				System.out.print("NS");
				f0.write("NS");
				y++;
			}
			
			System.out.println();
			f0.write("\r\n");
		}

		fr.close();
		f0.close();
	}
	
}
