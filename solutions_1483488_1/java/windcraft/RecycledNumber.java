package qualification;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Collection;
import java.util.HashSet;
import java.util.Scanner;

public class RecycledNumber {
	public static void main(String[] args) throws IOException {
		String inputFile = "C-large.in";
		Scanner input = new Scanner(new FileInputStream(inputFile));

		FileOutputStream out = new FileOutputStream(inputFile + ".out", false);
		slove(input, out);
		out.close();
	}
	
	private static void slove(Scanner input, FileOutputStream out) throws IOException
	{
		int cases = input.nextInt();
		for (int caseOrder = 1; caseOrder <= cases; caseOrder++) {
			int a = input.nextInt();
			int b = input.nextInt();
			
			long r = 0;
			for (int i = a; i <= b; i++) {
				for (int x: getRecycled(i)) {
					if (x >= a && x <= b && i < x && x > 0) {
						// System.out.printf("(%d, %d)\n", i, x);
						r++;
					}
				}
			}
			
			String outline = String.format("Case #%d: %d\r\n",  caseOrder, r);
			System.out.print(outline);
			out.write(outline.getBytes());
		}
	}
	
	private static Collection<Integer> getRecycled(int a)
	{
		String s = Integer.toString(a);
		HashSet<Integer> ret = new HashSet<Integer>();
		for (int i = 1; i < s.length(); i++) {
			String s2 = s.substring(i) + s.substring(0, i);
			if (!s2.startsWith("0")) {
				ret.add(Integer.parseInt(s2));	
			}
		}
		return ret;
	}
}
