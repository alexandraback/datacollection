package one_a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Bullseye {

	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new BufferedReader(new FileReader("A-small-attempt0.in")));
		BufferedWriter bw = new BufferedWriter(new FileWriter("output"));
		int cases = s.nextInt();
		for (int i = 0; i != cases; i++) {
			int y = foo(s.nextInt(), s.nextInt());
			String str = "Case #" + (i+1) + ": " + y;
			System.out.println(str);
			bw.write(str+'\n');
		}
		bw.close();
		s.close();
	}

	private static int foo(int r, int t) {
		int y = 1;
		t = t - (r+1)*(r+1) + r*r;
		r += 2;
		while (t - (r+1)*(r+1) + r*r >= 0) {
			y++;
			t = t - (r+1)*(r+1) + r*r;
			r += 2;
		}
		return y;
	}

}
