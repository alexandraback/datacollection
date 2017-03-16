package gcj14;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class PartElf {

	private String getAnswer(long nom, long denom) {
		long gc = gcd(nom, denom);
		nom /= gc;
		denom /= gc;
		
		long tempImp = denom;
		while (tempImp % 2 == 0) {
			tempImp /= 2;
		}
		if (tempImp != 1) return "impossible";
		
		int res = 1;
		long tempDenom = denom / 2;
		while (nom - tempDenom < 0) {
			tempDenom /= 2;
			res++;
		}
		
		return String.valueOf(res);
	}

	static long gcd(long x, long y) {
		return y == 0 ? x : gcd(y, x % y);
	}
	
	public static final String INPUT_FILE_PATH = "C://DiskD//CodeJamInput.txt";
	public static final String OUTPUT_FILE_PATH = "C://DiskD//CodeJamOutput.txt";

	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter writer = null;
		try {
			System.out.println("start");

			in = new Scanner(new File(INPUT_FILE_PATH));
			writer = new PrintWriter(new FileWriter(OUTPUT_FILE_PATH));
			int testCount = in.nextInt();

			for (int i = 0; i < testCount; i++) {
				String num = in.next();
				long nom = Long.valueOf(num.split("/")[0]);
				long denom = Long.valueOf(num.split("/")[1]);

				System.out.println(i);
				writer.println("Case #" + (i + 1) + ": " + new PartElf().getAnswer(nom, denom));
			}
			writer.flush();

			System.out.println("end");
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			if (in != null) in.close();
			if (writer != null) writer.close();
		}
	}

}
