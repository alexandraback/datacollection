package com.google.code.jam;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class First {
    private static final String dir = "C:\\Users\\Sasidharan\\Downloads\\Code\\A\\";

    public static int mins = 0;
	
	public static void main(String[] args) throws Exception {
		First o = new First();
		Scanner sc = new Scanner(new FileReader(dir + "A-large.in"));

		PrintWriter pw = new PrintWriter(new FileWriter(dir + "output.txt"));
		int caseCnt = sc.nextInt();
		sc.nextLine();
		for(int n = 0; n < caseCnt; n++) {
			//sc.nextLine();
			//System.out.println("Test cases " + (n + 1));
			pw.print("Case #" + (n+1) + ": ");
			//mins = 0;
			o.solve(sc, pw);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	private void solve(Scanner sc, PrintWriter pw) {
		String text = sc.nextLine();
		System.out.println(text);
		char[] c = text.toCharArray();
		char temp = c[0];
		StringBuilder s = new StringBuilder();
		for(char a : c) {
			if(a >= temp) {
				s = new StringBuilder().append(a).append(s.toString());
				temp = a;
			} else {
				s.append(a);
			}
			
		}
		System.out.println(s.toString());
		pw.println(s.toString());
	}

}
