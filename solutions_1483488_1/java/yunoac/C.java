package QR_2012;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.TreeSet;

public class C {

	static BufferedWriter writer;

	public static void main(String[] args) throws IOException {
		writer = new BufferedWriter(new FileWriter("output.out"));
		Scanner reader = new Scanner(new FileReader("input.in"));
		int nt = reader.nextInt();
		reader.nextLine();
		for(int tc = 1; tc <= nt; tc++) {
			writer.write("Case #" + tc + ": ");
			int a = reader.nextInt();
			int b = reader.nextInt();
			int total = 0;
			for(int n = a; n < b; n++) {
				int count = count(n, b);
				total += count;
			}
			writer.write(Integer.toString(total));
			writer.newLine();
		}
		writer.close();
	}

	static int count(int n, int b) {
		int count = 0;
		String s = Integer.toString(n);
		int l = s.length();
		TreeSet<String> T = new TreeSet<String>();
		for(int i = 1; i < l; i++) {
			s = s.substring(1) + s.charAt(0);
			if(!T.contains(s)) {
				T.add(s);
				int m = Integer.parseInt(s);
				if(n < m && m <= b) {
					count++;
				}
			}
		}
		return count;
	}


}
