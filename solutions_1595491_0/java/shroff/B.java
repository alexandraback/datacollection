package qualifier;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;


public class B {
	public static void main(String args[]) throws IOException {
		Scanner in = new Scanner(new File("B-small.in"));
		PrintStream out = new PrintStream(new File("B-small.out"));
		int tc = in.nextInt();
		
		for(int c=1; c<=tc; c++) {
			int n = in.nextInt();
			int s = in.nextInt();
			int p = in.nextInt();
			int ct = 0;
			
			int d;
			for(int i=0; i<n; i++) {
				d = in.nextInt();
				if(d < 2) {
					if(p <= d)
						ct++;
				} else if(d >= (p*3)-2) {
					ct++;
				} else if(d >= (p*3)-4 && s > 0) {
					s--;
					ct++;
				}
			}
				
			out.printf("Case #%d: %d\n", c, ct);
		}
	}
}
