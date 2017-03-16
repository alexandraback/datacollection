/*
 * @(#)FreeCell.java $version 2013. 4. 26.
 *
 * Copyright 2011 NHN Corp. All rights Reserved. 
 * NHN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

package topcoder.example.codejam.real3;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author : 쇼핑관리개발팀 정용균
 * @version $Rev$, $Date$ 
 */
public class ProblemB {
	int X;
	int Y;
	int[] xV = {1, 0, -1, 0};
	int[] yV = {0, 1, 0, -1};
	String[] pathV = { "E", "N", "W", "S"}; 
	String result;
	
	public static void main(String args[]) throws Exception {
		new ProblemB().run();
	}
	
	public void run() throws Exception{
		Scanner sc = new Scanner(new FileInputStream(new File("C:\\codejam\\B-small-attempt1.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream("C:\\codejam\\b1_out.txt"));
		int cases = sc.nextInt();
		int size = cases;
		
		 while(cases-- > 0) {
			X = sc.nextInt();
			Y = sc.nextInt();
			
//			System.out.println(Answer());
//			result = "";
			 out.println("Case #" + String.valueOf(size -cases)+ ": " + Answer());
			 out.flush();
		 }
		 System.out.println("===end==");
	}
	
	public String Answer(){		
		String result = "";
		
		if(X > 0){
			String add = "WE";
			for(int i = 0; i < Math.abs(X); i++){
				result = result + add;
			}
		}else{
			String add = "EW";
			for(int i = 0; i < Math.abs(X); i++){
				result = result + add;
			}
		}
		
		if(Y > 0){
			String add = "SN";
			for(int i = 0; i < Math.abs(Y); i++){
				result = result + add;
			}
		}else{
			String add = "NS";
			for(int i = 0; i < Math.abs(Y); i++){
				result = result + add;
			}
		}
		
		return result;
	}
}
