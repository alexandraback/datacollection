package round1A;

import java.util.*;
import java.io.*;

public class Bullseye {

	public static void main(String[] args) throws IOException {
		Scanner infile = new Scanner(new File("sample.in"));
		PrintWriter out = new PrintWriter(new File("out.txt"));
		int dataSets = infile.nextInt();
		infile.nextLine();
		
		for(int dataSet = 1; dataSet <= dataSets; dataSet++) {
			long r = infile.nextLong();
			long t = infile.nextLong();
			System.out.printf("Case #%d: %d\n", dataSet, maximumRings(r, t));
			out.printf("Case #%d: %d\n", dataSet, maximumRings(r, t));
		}
		out.close();
	}
	
	public static int maximumRings(long radius, long t) {
		int rings = 0;
		double paint = (double) t;
		long r = radius; // r holds the inner radius 
		
		boolean enoughPaint = true;		
		while(enoughPaint) {
			double needed = area(r);
			paint -= needed;
			if(paint < 0)
				enoughPaint = false;
			else
				rings++;
			r += 2;
		}
		return rings;
	}
	
	private static double area(long r) {
		return (2*r + 1.0);
	}
	
}
