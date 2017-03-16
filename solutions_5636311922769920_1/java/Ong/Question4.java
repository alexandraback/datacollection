package code.jam;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Question4 {
	private static String path = "C:\\Users\\Ong Keng Chai\\Documents\\property\\codeJam\\src\\code\\jam\\";
	
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File(path + "input.txt"));
		PrintWriter out = new PrintWriter(new File(path + "output.txt"));
		
		int caseCount = in.nextInt();
		in.nextLine();
		for (int caseInstance = 1; caseInstance <= caseCount; caseInstance++) {
			System.out.println("======== case " + caseInstance);
			String line = in.nextLine();
			Scanner lineScanner = new Scanner(line);
			
			int k = lineScanner.nextInt();
			int c = lineScanner.nextInt();
			int s = lineScanner.nextInt();
			
			int times = (int) Math.ceil((double) k / (double) c);
			if (times > s) {
				out.println("Case #" + caseInstance + ": IMPOSSIBLE");
				continue;
			}
			
			out.print("Case #" + caseInstance + ":");
			int pos = 0;
			while (pos < k) {
				BigInteger tile = BigInteger.valueOf(0);
				for (int i = 0; i < c; i++) {
					if (pos < k) {
						BigInteger startPos = BigInteger.valueOf(k);
						startPos = startPos.pow(i);
						startPos = startPos.multiply(BigInteger.valueOf(pos));
						tile = tile.add(startPos);
					}
					pos++;
				}
				tile = tile.add(BigInteger.valueOf(1));
				out.print(" " + tile.toString());
			}
			out.println();
			
			lineScanner.close();
		}
		in.close();
		out.close();
	}
}
