import java.util.*;
import java.io.*;

public class CoinJam {
	public static void main(String[] args) throws IOException{
		Scanner kb = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter("coinjam.out"));
		//PrintStream out = System.out;
		int len = 16;
		int cases = 50;
		out.println("Case #1:");
		for(int i=-1; i <= cases-2; i++) {
			int a = i / 7;
			int b = i % 7;
			out.print('1');
			for(int k=0; k < 14; k++) {
				if ((k == a * 2 || k == b*2 + 1) && i != -1)
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
