package GCJ;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Qualification2016D {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new FileInputStream("D-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileOutputStream("D-small-attempt0.out"));
		
		int T = in.nextInt();
		int cas = 0;
		while(T-- > 0) {
			out.print("Case #" + (++cas) + ":");
			gao(in, out);
		}
		
		in.close();
		out.close();
	}

	private static void gao(Scanner in, PrintWriter out) {
		int k = in.nextInt();
		int c = in.nextInt();
		int s = in.nextInt();
		for(int i=0; i<s; ++i) {
			out.print(" " + (i+1));
		}
		out.println();
	}

}
