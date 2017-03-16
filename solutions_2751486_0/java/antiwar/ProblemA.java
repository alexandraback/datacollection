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
public class ProblemA {
	char[] a;
	int b;
	
	public static void main(String args[]) throws Exception {
		new ProblemA().run();
	}
	
	public void run() throws Exception{
		Scanner sc = new Scanner(new FileInputStream(new File("C:\\codejam\\A-small-attempt0.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream("C:\\codejam\\a1_out.txt"));
		int cases = sc.nextInt();
		int size = cases;
		
		 while(cases-- > 0) {
			 a = sc.next().toCharArray();
			 b = sc.nextInt();
			 
			 //System.out.println(Answer());
			 out.println("Case #" + String.valueOf(size -cases)+ ": " + Answer());
			 out.flush();
		 }
		 System.out.println("===end==");
	}
	
	public int Answer()
	{
		int result = 0;
		for(int i =0; i < a.length; i++){
			for(int j= i; j < a.length; j++){
				if(isCase(i, j)){
					result++;
				}
			}
		}
		
		return result;
	}
	
	public Boolean isCase(int startIdx, int endIdx){
		int length = 0;
		boolean result = false;
		
		for(int i= startIdx; i <= endIdx; i++){
			if(!isVowel(a[i])){
				length++;
			}else{
				length = 0;
			}
			
			if(length >= b){
				result = true;
				break;
			}
		}
		return result;
	}
	
	public boolean isVowel(char elem){
		char[] vowel = { 'a', 'e', 'i', 'o', 'u' };
		
		boolean result = false;
		for(int i =0; i < vowel.length; i++){
			if(elem == vowel[i]){
				result = true;
				break;
			}
		}
		
		return result;
	}
}
