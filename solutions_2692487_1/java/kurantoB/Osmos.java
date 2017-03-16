package Round_1B;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Osmos {
	
	static int thisCase;
	
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new FileReader(args[0]));
		PrintWriter out = new PrintWriter(new FileWriter( "out.txt"));
		int cases = in.nextInt();
		for (thisCase = 1; thisCase <= cases; thisCase++) {
			String display = "Case #" + thisCase + ": " + go_crazy(in);
			out.println(display);
			System.out.println(display);
		}
		out.close();
	}

	private static int go_crazy(Scanner in) {
		int A = in.nextInt();
		int N = in.nextInt();
		in.nextLine();
		String line = in.nextLine();
		String[] lineSeg = line.split(" ");
		int[] motes = new int[lineSeg.length];
		for (int i = 0; i < lineSeg.length; i++) {
			motes[i] = Integer.parseInt(lineSeg[i]);
		}
		Arrays.sort(motes);
		int rVal = getMinOps(A, motes, 0, 0);
		return rVal;
	}

	private static int getMinOps(int a, int[] motes, int start, int rVal) {
		if (a == 1) {
			return motes.length;
		}
		int i;
		for (i = start; i < motes.length; i++) {
			if (a > motes[i]) {
				a += motes[i];
			} else {
				break;
			}
			if (i == motes.length - 1) {
				return rVal;
			}
		}
		return rVal + Math.min(motes.length - i, getMinOps(a + a - 1, motes, i, 1));
	}

}
