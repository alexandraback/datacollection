package com.google.code.jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {
	public static int Case;
	public static String[] status = {"X won","O won","Draw","Game has not completed"};
	public static String[] tmp = new String[4];
	

//	public static final String inputfileName = "A-small-attempt1.in";
//	public static final String outputfileName = "A-small-attempt1.out";
//	public static final String inputfileName = "A-practice.in";
//	public static final String outputfileName = "A-practice.out";
//	public static final String inputfileName = "A-small-attempt0.in";
//	public static final String outputfileName = "A-small-attempt0.out";
	public static final String inputfileName = "A-large.in";
	public static final String outputfileName = "A-large.out";
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner s = null;
		PrintWriter outputStream = null;
		try{
			s = new Scanner(new BufferedReader(
					new FileReader(inputfileName)));
			outputStream = new PrintWriter(
    				new BufferedWriter(new FileWriter(outputfileName)));
			
			Case = s.nextInt();
			for(int i=0;i<Case;i++){
				for(int j=0;j<4;j++){
					tmp[j] = s.next(); 
					//System.out.format("%s\n", tmp[j]);
				}
				//System.out.println();
				int rst = solve();
				System.out.format("Case #%d: %s\n" , i+1, status[rst]);
				outputStream.format("Case #%d: %s\n" , i+1, status[rst]);
			}		
		}finally{
			if (s != null) {
                s.close();
            }
            if (outputStream != null) {
            	outputStream.close();
            }	
		}
	}
private static int solve() {
	// TODO Auto-generated method stub
	int Xn,On,Tn;
	for(int i=0;i<4;i++){
		Xn = 0; Tn = 0; On = 0;
		for(int j=0;j<4;j++){
			if(tmp[i].charAt(j) == 'X'){
				Xn++;
			}
			else if(tmp[i].charAt(j) == 'O'){
				On++;
			}
			else if(tmp[i].charAt(j) == 'T'){
				Tn++;
			}
		}
		if( Xn==4 || (Xn==3&&Tn==1) ){
			return 0;
		}
		else if( On==4 || (On==3&&Tn==1) ){
			return 1;
		}
	}
	for(int i=0;i<4;i++){
		Xn = 0; Tn = 0; On = 0;
		for(int j=0;j<4;j++){
			if(tmp[j].charAt(i) == 'X'){
				Xn++;
			}
			else if(tmp[j].charAt(i) == 'O'){
				On++;
			}
			else if(tmp[j].charAt(i) == 'T'){
				Tn++;
			}
		}
		if( Xn==4 || (Xn==3&&Tn==1) ){
			return 0;
		}
		else if( On==4 || (On==3&&Tn==1) ){
			return 1;
		}
	}
	//check diagonal
	Xn = 0; Tn = 0; On = 0;
	for(int i=0;i<4;i++){
		if(tmp[i].charAt(i) == 'X'){
			Xn++;
		}
		else if(tmp[i].charAt(i) == 'O'){
			On++;
		}
		else if(tmp[i].charAt(i) == 'T'){
			Tn++;
		}
	}
	if( Xn==4 || (Xn==3&&Tn==1) ){
		return 0;
	}
	else if( On==4 || (On==3&&Tn==1) ){
		return 1;
	}
	
	//check diagonal
	Xn = 0; Tn = 0; On = 0;
	for(int i=0;i<4;i++){
		if(tmp[i].charAt(3-i) == 'X'){
			Xn++;
		}
		else if(tmp[i].charAt(3-i) == 'O'){
			On++;
		}
		else if(tmp[i].charAt(3-i) == 'T'){
			Tn++;
		}
	}
	if( Xn==4 || (Xn==3&&Tn==1) ){
		return 0;
	}
	else if( On==4 || (On==3&&Tn==1) ){
		return 1;
	}
	
	//check if not a draw
	for(int i = 0;i<4;i++){
		for(int j = 0;j<4;j++){
			if(tmp[i].charAt(j) =='.'){
				return 3;
			}
		}
	}
	
	return 2;
}
}
