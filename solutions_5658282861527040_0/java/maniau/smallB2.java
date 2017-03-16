package RB;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class smallB2 {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("B-small-attempt0(1).in"));
		PrintWriter pw = new PrintWriter(new File("outB_small"));
//		Scanner sc = new Scanner(System.in);
//		PrintWriter pw = new PrintWriter(System.out);
		
		int T = sc.nextInt();
		for(int t = 1; t <= T; t++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			int K = sc.nextInt();
			
			int ans = 0;
			for(int a = 0; a < A; a++)
				for(int b = 0; b < B; b++) {
					int z = a&b;
					if(z < K)
						ans++;
				}
			pw.println("Case #"+t+": "+ans);
		}
		pw.flush();
	}
}
