/*
GCJ2013-QB
Problem B. Lawnmower
10/30
*/

import java.io.*;
import java.util.*;
import java.math.*;

public class GCJ2013QB {
	static BufferedReader fin;
    static PrintWriter fout;
    // change numefile
    static String file="B-large";
    static String infile=file+".in";
    static String outfile=file+".out";
    //
  	
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
		String ret="";
		// Parse input for test no. test
		String a=fin.readLine();	
		String[] as=a.split(" ");
		int N=Integer.parseInt(as[0]);
		int M=Integer.parseInt(as[1]);
		int[][] t=new int[N][M];
		for (int i=0; i<N; i++){
			a=fin.readLine();
			as=a.split(" ");
			for (int j=0; j<M; j++) t[i][j]=Integer.parseInt(as[j]);
		}
		
		for (int i=0; i<N; i++)
			for (int j=0; j<M; j++) {
				int crt=t[i][j];
				// verific pe linia i sa nu fie mai mici
				boolean okl=true;
				for (int jj=0; jj<M; jj++) okl=okl && t[i][jj]<=crt;
				// verific pe coloana j sa nu fie mai mici
				boolean okc=true;
				for (int ii=0; ii<N; ii++) okc=okc && t[ii][j]<=crt;
				if (!okl && !okc) return "NO";
			}
		
		return "YES";
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
