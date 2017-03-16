package com.nastya.code_jam.round_1с;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Random;

public class Blank {

	public static void main(String args[]) {
		try {
			BufferedReader in = new BufferedReader(new FileReader("data/in/elv.in"));
			PrintWriter out = new PrintWriter("data/out/elv.out");

			int amount = Integer.parseInt(in.readLine());
			
			for (int k = 0; k < amount; k++) {
				String row = in.readLine();
				String[] arrRow = row.split("/");
				int up = Integer.parseInt(arrRow[0]);
				int down = Integer.parseInt(arrRow[1]);
				//double time = play(mC, mF, mX);
				int del = gcd(up, down);
				up = up / del;
				down = down / del;
				int d = degree(down) - 1;
				int c = clear(up, d - 1);
				if (d == -2 || up == 0)
					out.println("Case #" + (k + 1) + ": " + "impossible");
				else
					out.println("Case #" + (k + 1) + ": " + (d - c)); 
			}
			
			in.close();
			out.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("Конец!");
	}

    private static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
    
    private static int degree(double a) {
    	if (a == 1)
    		return 1;
    	if (Math.round(a) != a)
    		return -1;
    	
    	int ret = degree(a/2);
    	if (ret == -1)
    		return -1;
    	else
    		return ret + 1;
    }
    
    private static int clear(int a, int de) {
    	if (a >= Math.pow(2, de))
    		return de;
        return clear(a, de-1);
    }
}
