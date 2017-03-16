/**
 * Recycled Numbers
 */
package com.google.jam.qualification;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class C {
	
	public static String moveFromEndToFront(String number, int n) {
		String begin = number.substring(0,number.length()-n);
		String end = number.substring(number.length()-n);
		return end+begin;
	}
	
	public static void main(String[] args) {
		try {
			FileOutputStream fos = new FileOutputStream("C-small-attempt0.out");
			System.setOut(new PrintStream(fos, true));
			
			FileInputStream fis=new FileInputStream(new File("C-small-attempt0.in"));
			InputStreamReader in=new InputStreamReader(fis);
			BufferedReader br=new BufferedReader(in);
			
			String line="";
			int nbTest = Integer.parseInt(br.readLine());
			
			for(int i=1; i<=nbTest; i++) {
				line = br.readLine();
				Scanner sc = new Scanner(line);
				int cpt = 0;
				int min = sc.nextInt();
				int max = sc.nextInt();
				
				for(int k=min; k<=max; k++) {
					String number = String.valueOf(k);
					HashMap<Integer,Integer> table = new HashMap<Integer,Integer>();
					
					for(int l=1; l<number.length(); l++) {
						String reverse = moveFromEndToFront(number,l);
						int numberVal = Integer.valueOf(number);
						int reverseVal = Integer.valueOf(reverse);
						if( (reverseVal <= max) && (numberVal < reverseVal) ) table.put(reverseVal, numberVal);
					}
					cpt += table.size();
				}
				
				
				System.out.println("Case #" + i + ": " + cpt);
			}
	
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println("File not found");
			e.printStackTrace();
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}

}
