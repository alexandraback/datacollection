

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class A {

	static final String filein = "A-in.txt";
	static final String fileout = "A-out.txt";
	static int nTest;
	static long r, t, count;
	
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File(filein));
		PrintStream ps = new PrintStream(new File(fileout));
		PrintStream stdout = System.out;
		System.setOut(ps);
		nTest = scanner.nextInt();
		for (int test=1;test<=nTest;++test) {
			r = scanner.nextLong();
			t = scanner.nextLong();
			count = 0;
			long i = r;
			while (true) {
				long area = (i+1)*(i+1) - i*i;
				if (t >= area) {
					t -= ((i+1)*(i+1) - i*i);
					count++;
					i += 2;
				}
				else {
					break;
				}
			}
			
//			long delta = r*r - 2*r + 1 + 8*t;
//			double top = (double)(-r-1 + Math.sqrt(delta)) / (double)2 ;
			
			System.out.println("Case #" + test + ": " + count);
		}

	}

}
