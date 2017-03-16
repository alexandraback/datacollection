package qr2014B;

import java.util.*;
import java.io.*;

import static java.lang.System.*;
import static java.lang.Math.*;

public class Main {

//	Scanner sc = new Scanner(in);
	Scanner sc; 
	
	void run() {
		try {
			sc = new Scanner(new File("/Users/ryo/Documents/procon/B-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int t = sc.nextInt();
		for (int z = 1; z <= t; z++) {
			double c = sc.nextDouble(), f = sc.nextDouble(), x = sc.nextDouble();
			double res = 0, prev = Double.MAX_VALUE/2;
			double p = 2.0;
			while (true) {
				if (res + x/p < prev) {
					prev = res + x/p;
					res += c/p;
					p += f;
				} else {
					break;
				}
			}
			out.printf("Case #%d: %.7f\n", z, prev);
		}
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}