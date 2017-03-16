package QR_2012;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B {

	static BufferedWriter writer;

	public static void main(String[] args) throws IOException {
		writer = new BufferedWriter(new FileWriter("output.out"));
		Scanner reader = new Scanner(new FileReader("input.in"));
		int nt = reader.nextInt();
		reader.nextLine();
		for(int tc = 1; tc <= nt; tc++) {
			writer.write("Case #" + tc + ": ");
			int n = reader.nextInt();
			int s = reader.nextInt();
			int p = reader.nextInt();
			int count = 0;
			for(int i = 0; i < n; i++) {
				int t = reader.nextInt();
				if(canDoNormally(t, p)) {
					count++;
				} else if(s > 0 && canDoNormallyWith2(t, p)) {
					count++;
					s--;
				}
			}
			writer.write(Integer.toString(count));
			writer.newLine();
		}
		writer.close();
	}
	
	static boolean canDoNormallyWith2(int t, int p) {
		for(int i = 3; i <= 4; i++) {
			if((t + i) % 3 == 0 && (t + i) / 3 >= p && (t + i) / 3 - 2 >= 0) {
				return true;
			}
		}
		return false;
	}
	
	static boolean canDoNormally(int t, int p) {
		if(t % 3 == 0 && t / 3 >= p) {
			return true;
		}
		if((t + 1) % 3 == 0 && (t + 1) / 3 >= p &&  (t + 1) / 3 - 1 >= 0) {
			return true;
		}
		if((t + 2) % 3 == 0 && (t + 2) / 3 >= p &&  (t + 2) / 3 - 1 >= 0) {
			return true;
		}
		return false;
	}
	
}
