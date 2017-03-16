package com.nastya.code_jam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Cookie {

	public static void main(String args[]) {
		try {
			BufferedReader in = new BufferedReader(new FileReader("data/in/cookie.in"));
			PrintWriter out = new PrintWriter("data/out/cookie.out");

			int amount = Integer.parseInt(in.readLine());
			
			for (int k = 0; k < amount; k++) {
				String row = in.readLine();
				String[] arrRow = row.split(" ");
				double mC = Double.parseDouble(arrRow[0]);
				double mF = Double.parseDouble(arrRow[1]);
				double mX = Double.parseDouble(arrRow[2]);
				double time = play(mC, mF, mX);

				out.printf("Case #" + (k + 1) + ": %.7f\n", time); 
			}
			
			in.close();
			out.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("Конец!");
	}
	
	static double play(double C, double F, double X) {
		double resTime = 0;
		
		double v = 2;
		while (true) {
			if (X / v > C / v  + X / (v + F)) {
				resTime = resTime + C / v;
				v = v + F;
			}
			else {
				resTime = resTime + X / v;
				break;
			}
		}
		
		return resTime;
	}
}
