package com.noxoin.codejam2014;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

class DeceitfulWar {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		PrintWriter writer;
		try {
			writer = new PrintWriter("out.txt", "UTF-8");
		
			int t = Integer.parseInt(s.nextLine());
			
			for (int i = 1; i <= t; ++i){
				// solve
				int n = Integer.parseInt(s.nextLine());
			
				String[] x = s.nextLine().split(" ");
				String[] y = s.nextLine().split(" ");
				
				double[] a = new double[n];
				double[] b = new double[n];
				for(int j = 0; j < n; ++j) {
					a[j] = Double.parseDouble(x[j]);
					b[j] = Double.parseDouble(y[j]);
				}
				
				Arrays.sort(a);
				Arrays.sort(b);

				ArrayList<Double> ai = new ArrayList<Double>();
				ArrayList<Double> bi = new ArrayList<Double>();

				for(int j = 0; j < n; ++j){
					ai.add(a[j]);
					bi.add(b[j]);
				}

				ArrayList<Double> ax = (ArrayList<Double>) ai.clone();
				ArrayList<Double> bx = (ArrayList<Double>) bi.clone();

				int c1 = 0;
				for(int j = 0; j < n; ++j){
					if(ax.get(0) < bx.get(0)){
						ax.remove(0);
						bx.remove(bx.size()-1);
					} else {
						c1++;
						ax.remove(0);
						bx.remove(0);
					}
				}
				
				// normal war
				int c2 = 0;
				for(int j = n; j > 0; --j){
					if(ai.get(j-1) > bi.get(j-1)) {
						c2++;
						ai.remove(j-1);
						bi.remove(0);
					} else {
						ai.remove(j-1);
						bi.remove(j-1);
					}
				}
				
				System.out.println("Case #" + i + ": " + c1 + " " + c2);
				writer.println("Case #" + i + ": " + c1 + " " + c2);
			}
			
			s.close();
			writer.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}
	}

}