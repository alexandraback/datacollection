package com.google.code.jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class C {
	public static int Case,rst;
	public static BigInteger A,B;
	public static List<BigInteger> hint = new ArrayList<BigInteger>();

//	public static final String inputfileName = "C-small-attempt1.in";
//	public static final String outputfileName = "C-small-attempt1.out";
//	public static final String inputfileName = "C-practice.in";
//	public static final String outputfileName = "C-practice.out";
//	public static final String inputfileName = "C-small-attempt0.in";
//	public static final String outputfileName = "C-small-attempt0.out";
	public static final String inputfileName = "C-large-1.in";
	public static final String outputfileName = "C-large-1.out";
	
//	public static final String outputfileName2 = "hints.out";
	public static final String inputfileName2 = "hints.out";
	
	public static String wordReverse(String str){
	    int n = str.length();  
	    char[] chars = new char[n];  
	    str.getChars(0, n, chars, 0);
	      
	    int length=chars.length;  
	    StringBuffer sbStr = new StringBuffer();  
	    for(int i=0;i<length;i++){  
	        sbStr.append(chars[length-1-i]+"");
	    }  
	    return sbStr.toString();
	}
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner s = null;
		Scanner s_hint = null;
		PrintWriter outputStream = null;
		PrintWriter outputStream2 = null;
		try{
			s = new Scanner(new BufferedReader(
					new FileReader(inputfileName)));
			
			s_hint = new Scanner(new BufferedReader(
					new FileReader(inputfileName2)));
			
			outputStream = new PrintWriter(
    				new BufferedWriter(new FileWriter(outputfileName)));
			
			/*outputStream2 = new PrintWriter(
    				new BufferedWriter(new FileWriter(outputfileName2)));
			*/
			// solution 
			while(s_hint.hasNextBigInteger()){
				hint.add(s_hint.nextBigInteger());
			}
			/*for(int i=0;i<hint.size();i++){
				System.out.format("%d \n",hint.get(i));				
			}*/
			Case = s.nextInt();
			for(int i=0;i<Case;i++){
				A = s.nextBigInteger(); B = s.nextBigInteger();
				rst = 0;
				for(int j=0;j<hint.size();j++){
					if(hint.get(j).compareTo(B)>0){
						break;
					}
					if(hint.get(j).compareTo(A)>=0 && hint.get(j).compareTo(B)<=0){
						rst++;
					}
				}
				System.out.format("Case #%d: %d\n", i+1, rst);
				outputStream.format("Case #%d: %d\n", i+1, rst);
			}
			
			/*//Generate the hints data
			Case = s.nextInt();
			for(int i=0;i<Case;i++){
				A = s.nextBigInteger();B = s.nextBigInteger();
				BigInteger tmp = A;
				BigInteger tmp_sqr;
				while(true){
					if(pal_jdg(tmp)){
						tmp_sqr = tmp.pow(2);
						if(pal_jdg(tmp_sqr)){
							System.out.format("%d\n",tmp_sqr);
//							outputStream2.format("%d\n", tmp_sqr);
						}
					}
					tmp = tmp.add(BigInteger.ONE);
					if(tmp.compareTo(B)>0){
						break;
					}
				}		
			}*/
		}finally{
			if (s != null) {
                s.close();
            }
			if (s_hint != null) {
                s_hint.close();
            }
            if (outputStream != null) {
            	outputStream.close();
            }
            if (outputStream2 != null) {
            	outputStream2.close();
            }
		}
	}

	private static boolean pal_jdg(BigInteger tmp_sqr) {
		// TODO Auto-generated method stub
		String str1 = tmp_sqr.toString();
		String str2 = wordReverse(str1);
		if(str1.compareTo(str2)==0){
			return true;
		}
		return false;
	}
}
