import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Map.Entry;

import javax.annotation.processing.SupportedSourceVersion;

import java.util.Scanner;
import java.util.Set;


public class BSol {


	public static void main(String[] args) {
		
		Date d1 = new Date();
		solveB("b.in", "b.out");
		//solveB("B-large.in", "B-large.out");		
		solveB("B-small-attempt0.in", "B-small-attempt0.out");
		
		Date d2 = new Date();
		System.out.println("time: " + (d2.getTime() - d1.getTime()));
		
		
		
		


	}


	private static void solveB(String in, String out) {
		
		

		
		try {
			
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);
			
			Scanner sc = new Scanner(new File(in));

			long t = sc.nextLong();
			sc.nextLine();
			
			
			
			//System.out.println(t);
			for (long i2 = 0; i2 < t; i2++) {

				
				String c= sc.next();
				String j= sc.next();
				
				
				
				String rez =  solve(c, j);
				//System.out.println("result: " + rez);
				
				bw.write("Case #" + (i2+1) + ": " +  rez + "\n");
				
			}
			
			
			bw.flush();
			bw.close();
			fw.close();
			sc.close();
		} catch (FileNotFoundException e) {
			
		} catch (IOException e) {
			
		} finally {
			
		}
	}


	private static String solve(String c, String j) {
		//System.out.println("{" + c + "} {" + j + "}");
		
		int n = c.length();
		
		
		int max = 10;
		if (n == 1) {
			max = 10;
		}
		
		if (n == 2) {
			max = 100;
		}
		
		if (n == 3) {
			max = 1000;
		}
	
		
		int minD = Integer.MAX_VALUE;
		String r = "";
		for (int i = 0; i < max; i++) {
			for (int k = 0; k < max; k++) {
				if (isValid(i, c) && isValid(k, j)) {
					int d = Math.abs(i-k);
					
					if (d < minD) {
						minD = d;
					    r = pad(i, n) + " " +pad(k, n);
					}
				}
			}
		}
		
		return r;
	}


	private static boolean isValid(int k, String j) {
		String kk = pad(k, j.length());
		boolean valid = true;
		for (int i = 0; i < j.length(); i++) {
			if(j.charAt(i) == '?') {
				
			} else {
				if (j.charAt(i) != kk.charAt(i)) {
					valid = false;
					break;
				}
			}
		}
		return valid;
	}


	private static String pad(int k, int n) {
		String  kk = ""+k;
		for (int i = 0; kk.length() < n; i++) {
			kk= "0" + kk;
		}
		return kk;
	}
	










	








}
