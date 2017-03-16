/*
GCJ2013-QA
Problem A. Tic-Tac-Toe-Tomek
10/20
*/

import java.io.*;
import java.util.*;
import java.math.*;

public class GCJ2013QA {
	static BufferedReader fin;
    static PrintWriter fout;
    
    // change numefisier
    static String file="A-large";
    static String infile=file+".in";
    static String outfile=file+".out";
     	
	// write result to output file
	private static void writetestresult(int test, String ret){
		fout.println("Case #"+test+": "+ret);
	}
	
	// open files
	private static void openfiles() throws IOException{
		fin = new BufferedReader(new FileReader(infile));
	    fout = new PrintWriter(new BufferedWriter(new FileWriter(outfile)));
	}
	
	// close files
	private static void closefiles() throws IOException{
		fin.close();
		fout.close();
	}
	
	 // solve test no. "test"
	private static String solvetest(int test) throws IOException{
		String sx="X won"; 					// (the game is over, and X won)
		String so="O won"; 					// (the game is over, and O won)
		String sd="Draw"; 					// (the game is over, and it ended in a draw)
		String sg="Game has not completed"; // (the game is not over yet)
		String ret="";
		// Parse input for test no. test
		int n=4;
		char[][] a=new char[n][n];
		
		for (int i=0; i<n; i++) {
			String s=fin.readLine();	
			for (int j=0; j<n; j++) {
				a[i][j]=s.charAt(j);
			}
		}
		
		// blank line separator
		String s=fin.readLine();
		
		boolean xwon=false;
		boolean owon=false;
		boolean full=true;
		
		for (int i=0; i<n; i++) 
			for (int j=0; j<n; j++) full=full && (a[i][j]!='.');
		
		// X sau T pe linii?
		for (int i=0; i<n; i++) {
			boolean xw=true;
			for (int j=0; j<n; j++) xw=xw && (a[i][j]=='X' || a[i][j]=='T');
			if (xw) xwon=true;
		}
		// X sau T pe coloane?
		for (int j=0; j<n; j++) {
			boolean xw=true;
			for (int i=0; i<n; i++) xw=xw && (a[i][j]=='X' || a[i][j]=='T');
			if (xw) xwon=true;
		}
		
		// X sau T pe prima diagonala?
		boolean xw=true;
		for (int i=0; i<n; i++) xw=xw && (a[i][i]=='X' || a[i][i]=='T'); 
		if (xw) xwon=true;
		
		// X sau T pe diagonala secundara?
		xw=true;
		for (int i=0; i<n; i++) xw=xw && (a[i][n-1-i]=='X' || a[i][n-1-i]=='T');
		if (xw) xwon=true;
		
		if (xwon) return sx;
		
		// O sau T pe linii?
		for (int i=0; i<n; i++) {
			boolean ow=true;
			for (int j=0; j<n; j++) ow=ow && (a[i][j]=='O' || a[i][j]=='T');
			if (ow) owon=true;
		}
		// O sau T pe coloane?
		for (int j=0; j<n; j++) {
			boolean ow=true;
			for (int i=0; i<n; i++) ow=ow && (a[i][j]=='O' || a[i][j]=='T');
			if (ow) owon=true;
		}
		
		// O sau T pe prima diagonala?
		boolean ow=true;
		for (int i=0; i<n; i++) ow=ow && (a[i][i]=='O' || a[i][i]=='T'); 
		if (ow) owon=true;
		
		// O sau T pe diagonala secundara?
		ow=true;
		for (int i=0; i<n; i++) ow=ow && (a[i][n-1-i]=='O' || a[i][n-1-i]=='T');
		if (ow) owon=true;
		
		if (owon) return so;
		
		// nici X, nici O, full;
		
		if (full) return sd;	//draw
		
		// nici X, nici O, not full
		return sg;				//game not completed
	}
	
	// main here
	public static void main(String[] args) throws IOException{
		// open files
		openfiles();
		
		// read first line
		String line=fin.readLine();
		int T=Integer.parseInt(line);    
		
		// solve T tests
		for (int test=1; test<=T; test++) {	    	
			//long stime=System.currentTimeMillis();
			
			String ret=solvetest(test);
			writetestresult(test, ret);
			
			//long etime=System.currentTimeMillis();
	    	//long dtime=(etime-stime);
	    	//System.out.println("Test "+test+": "+dtime+"ms");
		}	    
		// close files
		closefiles();
	}
}
