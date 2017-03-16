package com.google.code.jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {
	public static int Case,M,N;
	public static int[][] lawn = new int[102][102];
	public static String[] Judge = {"YES","NO"};

//	public static final String inputfileName = "B-small-attempt1.in";
//	public static final String outputfileName = "B-small-attempt1.out";
//	public static final String inputfileName = "B-practice.in";
//	public static final String outputfileName = "B-practice.out";
//	public static final String inputfileName = "B-small-attempt0.in";
//	public static final String outputfileName = "B-small-attempt0.out";
	public static final String inputfileName = "B-large.in";
	public static final String outputfileName = "B-large.out";
	
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
				N = s.nextInt();
				M = s.nextInt(); 
				//populate the lawn
				for(int j=0;j<N;j++){
					for(int k=0;k<M;k++){
						lawn[j][k] = s.nextInt();
						//System.out.format("%d ", lawn[j][k]);
					}
					//System.out.println();
				}
				//System.out.println();
				int rst = solve();
				System.out.format("Case #%d: %s\n" , i+1, Judge[rst]);
				outputStream.format("Case #%d: %s\n" , i+1, Judge[rst]);	
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
		boolean row_ok,col_ok;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				row_ok = true;
				for(int k=1;k<M;k++){
					if(lawn[i][j]<lawn[i][(j+k)%M]){
						row_ok = false;
					}
				}
				col_ok = true;
				for(int k=1;k<N;k++){
					if(lawn[i][j]<lawn[(i+k)%N][j]){
						col_ok = false;
					}
				}
				if( !row_ok && !col_ok ){
					return 1;
				}
			}
		}
		return 0;
	}
}
