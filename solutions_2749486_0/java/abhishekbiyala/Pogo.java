package abhi;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Pogo {
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileInputStream("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("B-small-attempt0.out"));
		
		int totalCases = sc.nextInt();
		
		int x, y;
		
		//For each case
		for(int i = 1; i <= totalCases; i++) {
			x = sc.nextInt();
			y = sc.nextInt();
			
			out.println("Case #"+i+": "+getMoves(x, y));

		}
		
		out.close();
	}

	private static String getMoves(int x, int y) {
		return solveX(x) + solveY(y);
	}

	private static String solveX(int x) {
		String solution = "";
		int jNum = 1;
		int currX = 0;
		boolean positive = x>=0?false:true;
		
		while (x != currX) {
			if(positive) {
				solution = solution + "E";
				currX = currX + jNum;
				positive = false;
			} else {
				solution = solution + "W";
				currX = currX -jNum;
				positive = true;
			}
		
			jNum++;
		}
		
		return solution;
	}

	private static String solveY(int y) {
		String solution = "";
		int jNum = 1;
		int currY = 0;
		boolean positive = y>=0?false:true;
		
		while (y != currY) {
			if(positive) {
				solution = solution + "N";
				currY = currY + jNum;
				positive = false;
			} else {
				solution = solution + "S";
				currY = currY - jNum;
				positive = true;
			}
		
			jNum++;
		}
		
		return solution;
	}
}
