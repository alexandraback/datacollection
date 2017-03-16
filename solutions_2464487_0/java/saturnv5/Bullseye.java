package round_1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Bullseye {

	private static final File input = new File("round_1a/A-small.in");
	private static final File output = new File("round_1a/A-small.out");

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(input);
		PrintStream out = new PrintStream(output);
		
		int cases = scan.nextInt();
		
		for(int cs = 1; cs <= cases; cs++){
			long r = scan.nextLong();
			long t = scan.nextLong();
			
			out.println("Case #" + cs + ": " + countRings(r, t));
		}

		scan.close();
		out.close();
	}
	
	static long countRings(long r, long t){
		double paintUsed = 0;
		for(long ring = 0; ; ring++){
			double radius = r + ring*2 + 1;
			paintUsed += radius*radius - (radius-1) * (radius-1);
			if(paintUsed > t)
				return ring;
		}
	}
}
