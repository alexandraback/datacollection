/*
 * GCJ 2013
 * Problem - Bullseye

Maria has been hired by the Ghastly Chemicals Junkies (GCJ) company to help them manufacture bullseyes. A bullseye consists of a number of concentric rings (rings that are centered at the same point), and it usually represents an archery target. GCJ is interested in manufacturing black-and-white bullseyes. 

  

Maria starts with t millilitres of black paint, which she will use to draw rings of thickness 1cm (one centimetre). A ring of thickness 1cm is the space between two concentric circles whose radii differ by 1cm.

Maria draws the first black ring around a white circle of radius r cm. Then she repeats the following process for as long as she has enough paint to do so:

Maria imagines a white ring of thickness 1cm around the last black ring.
Then she draws a new black ring of thickness 1cm around that white ring.
Note that each "white ring" is simply the space between two black rings.
The area of a disk with radius 1cm is π cm2. One millilitre of paint is required to cover area π cm2. What is the maximum number of black rings that Maria can draw? Please note that:

Maria only draws complete rings. If the remaining paint is not enough to draw a complete black ring, she stops painting immediately.
There will always be enough paint to draw at least one black ring.
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of a line containing two space separated integers: r and t.

Output

For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the maximum number of black rings that Maria can draw.

Limits

Small dataset

1 ≤ T ≤ 1000.
1 ≤ r, t ≤ 1000.

Large dataset

1 ≤ T ≤ 6000.
1 ≤ r ≤ 1018.
1 ≤ t ≤ 2 × 1018.

Sample


Input 
 	
5
1 9
1 10
3 40
1 1000000000000000000
10000000000000000 1000000000000000000
 * 
 */

//package round1a;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Bullseye {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileInputStream("/home/meha/Downloads/A-small-attempt0.in"));
        FileWriter out = new FileWriter("/home/meha/Desktop/output.out");
        int c = 1;
        for(int T = in.nextInt(); T > 0; T--, c++)
        {
            long r = in.nextLong();
            long t = in.nextLong();
         
            String print = String.format("Case #%d: %d\n", c, bullseye(r, t));
            out.write(print);
            System.out.print(print);
            out.flush();
        }
	}

	private static int bullseye(long r, long t) {
		
		int count = 0;
		double inc = (double) t;
		for(int i=0; inc > 0; i+=2)
		{
			double a = area(r+i, r+i+1);
			if(a > inc) return count;
			else
			{
				inc -= a;
				count++;
				
			}
		}
		
		return (count>1?count:1);
	}

	private static double area(long r1, long r2) {
		return (2*r1+1);//(r2*r2-r1*r1);
	}

}
