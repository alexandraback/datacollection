package qualification;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class DancingWithTheGoogler {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new FileInputStream("B-small-attempt0.in"));

		FileOutputStream out = new FileOutputStream("B-small-attempt0.out", false);
		slove(input, out);
		out.close();
	}
	
	private static void slove(Scanner input, FileOutputStream out) throws IOException
	{
		int cases = input.nextInt();
		for (int caseOrder = 1; caseOrder <= cases; caseOrder++) {
			int n = input.nextInt();
			int s = input.nextInt();
			int p = input.nextInt();
			
			int[] a = new int[n];
			
			for (int i = 0; i < n; i++) {
				a[i] = input.nextInt();			
			}
			
			int r = 0;
			for (int i = 0; i < n; i++) {
				int d = p * 3 - a[i];
				if (d <= 2) {
					r++;
				} else if (d <= 4) {
					if (s > 0 && a[i] >= p) {
						s--;
						r++;
					}
				}
			}
			
			String outline = String.format("Case #%d: %d\r\n",  caseOrder, r);
			out.write(outline.getBytes());
		}
	}
}
