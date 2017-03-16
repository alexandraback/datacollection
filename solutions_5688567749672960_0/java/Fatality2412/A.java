package round_one_B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("C:\\Users\\Valentin\\workspace_luna\\CodeJam\\src\\A-small-attempt1(1).in"));
		System.setOut(new PrintStream(new File("C:\\Users\\Valentin\\workspace_luna\\CodeJam\\src\\test.out")));

		int t = sc.nextInt();
		for (int k = 0; k < t; k++) {
			long goal = sc.nextLong();
			long cur = goal;
			long counter = 0;
			while (cur != 0) {
//				if (first(cur) == cur % 10 && reverseLong(cur) < cur) {
//					cur = reverseLong(cur);
//				}
				if (zeroInside(cur) && cur % 10 == 1 && reverseLong(cur) < cur) {
					cur = reverseLong(cur);
				}
				else cur--;
				counter++;
			}
			System.out.println("Case #" + (k+1) + ": " + counter);
		}
	}
	
	public static long reverseLong(long input)
	{
	    long reversedNum = 0;

	    long input_long = input;

	    while (input_long != 0)
	    {
	        reversedNum = reversedNum * 10 + input_long % 10;
	        input_long = input_long / 10;
	    }

	    if (reversedNum > Long.MAX_VALUE || reversedNum < Long.MIN_VALUE)
	    {
	        throw new IllegalArgumentException();
	    }
	    return (long)reversedNum;
	}
	
	public static long first(long input) {
		return Long.parseLong(Long.toString(input).substring(0, 1));
	}
	
	public static boolean zeroInside(long input) {
		//System.out.println(input);
		if (Long.toString(input).length() <= 3) {
			return true;
		}
		else return Long.parseLong(Long.toString(input).substring((int)(Math.ceil(Long.toString(input).length() / 2.0)), Long.toString(input).length() - 1)) == 0;
	}

}
