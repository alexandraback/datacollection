package Round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class Bullseye {
	
	public static void main(String[] args) {
		Scanner input = null;
		try {	input = new Scanner(new File("bin\\Round1A\\A-small-attempt0.in"));	} catch (FileNotFoundException e) {		e.printStackTrace();	}
		int T = input.nextInt();
		input.nextLine();
		long d = 4;
		for (int i = 1; i <= T; i++) {
			String[] s = input.nextLine().split(" ");
			long r = Long.parseLong(s[0]) - 1;
			long t = Long.parseLong(s[1]);
			System.out.print("Case #" + i + ": ");
			long a = 3 + r + r;
//			System.out.print(" a=" + a + " ");
			a += a;
			long n = (long)(((4 - a) + Math.sqrt((a-4)*(a-4)+32*t))/8);
//			System.out.println(r + " " + t);
			System.out.println(n);
		}
	}
	
}
