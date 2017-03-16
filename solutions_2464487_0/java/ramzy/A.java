package codejam.y2013.round1A;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader("inputs/1A/A.in"));
		PrintWriter output = new PrintWriter("inputs/1A/A.out");

		String out;
		int N = input.nextInt();
		for(int c = 1; c <= N; c++) {
			long r = input.nextLong();
			long t = input.nextLong();

			int rings = 0;
			long i = 0;
			while(true) {
				i = (long) Math.pow(i, 2);
				// sum i = 0,r  (2r)^2-(2r-1)^2
				t = t-paint(r);
				if(t>=0)
					rings++;
				else
					break;
				r += 2;
			}
			
			out = "Case #" + c + ": " + rings;
			output.println(out);
			System.out.println(out);
		}
		input.close();
		output.close();
	}
	
	private static long paint(long r) {
		return (long) (Math.pow(r+1, 2) - Math.pow(r, 2));
	}
	
}

