import java.util.*;
import java.io.*;

public class CoinJam {
	public static void main(String[] args) throws IOException{
		Scanner kb = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter("coinjam.out"));
		//PrintStream out = System.out;
		int len = 32;
		int cases = 500;
		out.println("Case #1:");
		for(int i=0; i < cases; i++) {
			int a = i / 56;
			int c = a / 7;
			int d = a % 7 + 8;
			int b = i % 56;
			int e = b / 7;
			int f = b % 7 + 8;
			out.print('1');
			for(int k=0; k < len-2; k++) {
				if ((k == c * 2 || k == d * 2 || k == e*2 + 1 || k == f*2 + 1))
					out.print('1');
				else
					out.print('0');
			}
			out.print('1');
			for (int k=3; k <= 11; k++) {
				out.print(" " + k);
			}
			out.println("");
		}
		out.close();
	}
}
