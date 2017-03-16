package qualifier;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;


public class C {
	static boolean done[] = new boolean[2222222];

	public static void main(String args[]) throws IOException {
		Scanner in = new Scanner(new File("C-large.in"));
		System.setOut(new PrintStream(new File("C-large.out")));
		int tc = in.nextInt();
		
		for(int c=1; c<=tc; c++) {
			int a = in.nextInt();
			int b = in.nextInt();
			int d = 0;
			int t = a;
			int m = 1;
			int ct  = 0;
			int n;
			while(t > 0) {
				t /= 10;
				d++;
				m *= 10;
			}
			d--;
			m /= 10;
			
			Arrays.fill(done, false);
			
			for(int i=a; i<=b; i++) {
				if (done[i])
					continue;
				done[i] = true;
				n = i;
				t = 0;
				for(int j=d; j>0; j--) {
					n = (n/10)+((n%10)*m);
					if(n > m && n >= a && n <= b && !done[n]) {
						t++;
						done[n] = true;
					}
				}
				ct += (t*(t+1))/2;
			}
			System.out.printf("Case #%d: %d\n", c, ct);
		}
	}
}
