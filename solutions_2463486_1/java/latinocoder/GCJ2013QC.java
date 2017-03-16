/*
GCJ2013-QC
Problem C. Fair and Square
10/35/55
*/

import java.io.*;
import java.util.*;
import java.math.*;

public class GCJ2013QC {
	static BufferedReader fin;
    static PrintWriter fout;
    // change numefile
    static String file="C-large-1";
    static String infile=file+".in";
    static String outfile=file+".out";
    //
    
    static int N=10000001;
    static int[] t=new int[N];
  	
    
    
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
	
	private static boolean ispal(long i){
		long ri=0;
		long si=i;
		while (si>0) {
			ri=ri*10+si%10;
			si/=10;
		}
		if (i==ri) return true;
		return false;
	}
	
	private static String solvetest(int test) throws IOException{
		String ret="";
		int iret=-1;
		// Parse input for test no. test
		String sta=fin.readLine();	
		String[] as=sta.split(" ");
		long A=Long.parseLong(as[0]);
		long B=Long.parseLong(as[1]);
		long la=(long)Math.sqrt(A);
		long lb=(long)Math.sqrt(B);
		boolean app=false;
		if (la*la==A) app=true;
		int a=(int)la; 
		int b=(int)lb;
		if (app) iret=t[b]-t[a-1]; else iret=t[b]-t[a];
		return ""+iret;
	}
	
	// main here
	public static void main(String[] args) throws IOException{
		t[0]=1;
		for (int i=1; i<N; i++) {
			long li=1L;
			li*=i;
			long lip=li*li;
			if (ispal(li) && ispal(lip)) t[i]=t[i-1]+1; else t[i]=t[i-1];		
		}
		
		
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
