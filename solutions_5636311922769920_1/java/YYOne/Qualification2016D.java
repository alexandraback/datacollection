package GCJ;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Qualification2016D {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new FileInputStream("D-large.in"));
		PrintWriter out = new PrintWriter(new FileOutputStream("D-large.out"));
		
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
		
		if(s * c < k) out.println(" IMPOSSIBLE");
		else {
			for(int i=0; i<k; i+=c) {
				long x = 0;
				for(int j=i; j<i+c; ++j) {
					int tmp = j;
					if(j >= k) tmp = 0;
					x = x * k + tmp;
				}
				out.print(" " + (x + 1));
			}
			out.println();
		}
	}

}
