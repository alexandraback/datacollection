package Round1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class Pogo {
	public static void main(String[] args) {
		Scanner input = null;
		try {	input = new Scanner(new File("bin\\Round1C\\B-small-attempt0.in"));	} catch (FileNotFoundException e) {		e.printStackTrace();	}
		int T = input.nextInt();
		input.nextLine();
		for (int i = 1; i <= T; i++) {
			String[] s = input.nextLine().split(" ");
			int x = Integer.parseInt(s[0]);
			int y = Integer.parseInt(s[1]);
			System.out.print("Case #" + i + ": ");
			char xforw = x > 0 ? 'E' : 'W';
			char xback = x > 0 ? 'W' : 'E';
			char yforw = y > 0 ? 'N' : 'S';
			char yback = y > 0 ? 'S' : 'N';
			int X = 0, Y = 0, D = 1;
			String output = "";
			x = Math.abs(x);
			y = Math.abs(y);
			boolean xStrong = true, yStrong = true;
			while (x != X || y != Y){
				if (x == X){
					xStrong = false;
				} else if (X + D <= x){
					output += xforw;
					X += D;
					D++;
				} else {
					xStrong = false;
					if (!yStrong){
						output += xback;
						output += xforw;
						X++;
						D+=2;
					}
				}
				if (y == Y){
					yStrong = false;
				} else if (Y + D <= y){
					output += yforw;
					Y += D;
					D++;
				} else {
					yStrong = false;
					if (!xStrong){
						output += yback;
						output += yforw;
						Y++;
						D+=2;
					}
				}
			}
			System.out.println(output);
		}
	}
	
}
