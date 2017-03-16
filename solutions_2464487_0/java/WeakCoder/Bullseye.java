package Round_1_A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Bullseye {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = null;
		PrintWriter out = null;
		try {
			in = new Scanner(new File("test.in"));
			out = new PrintWriter(new File("a_small.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int cases = in.nextInt();
		for (int i=1; i<=cases; i++) {
			long r = in.nextLong();
			long t = in.nextLong();
			int n = 0;
			for (long j=r; t>=0; j+=2) {
				long need = 2*j + 1;
				//if (i == 3) System.out.println(need);
				if (t>=need) {
					n++;
					t -= need;
				} else
					break;
			}
			out.println("Case #"+i+": " + n);
			out.flush();
		}
	}

}
