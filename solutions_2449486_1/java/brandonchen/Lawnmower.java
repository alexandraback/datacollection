package br.src.codejam;
/*
 * CodeJam

 * Author: Brandon Chen
 * Date: 2013/4/13
 * Question: Lawnmower
 */

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

class Lawnmower {
	static final String mInput = "B-large.in";
	static final String mOutput = "B-large.out";

	
	StringBuilder mSb = new StringBuilder();
	
	static void log (Object o) {
		if (o == null)
			return;
		///System.out.println(o.toString());
	}
	
	static void logArr (Object ...o) {
		if (o == null || o.length == 0)
			return;
		///System.out.println(Arrays.deepToString(o));
	}
	
	

	void ioReadAndRun() {
		log("start ioReadAndRun");
		try {
			Vector vec = new Vector();
			StringTokenizer st;
			File fp = new File(mInput);
			Scanner scanner = new Scanner(fp);
			int caseCnt = 0;
			if (scanner.hasNext())
				caseCnt = scanner.nextInt();
			for (int i = 0; i < caseCnt; i++) {
				log (i);
				int[][]  sm = new int[101][101];
				int row = Integer.parseInt(scanner.next());
				int column = Integer.parseInt(scanner.next());
				
				for (int j = 0; j < row; j++) {
					for (int k = 0; k < column; k++) {
						sm[j][k] = scanner.nextInt();
						
					}
				}
				//logArr(sm);
				String str = String.valueOf(functor(sm, row, column));
				System.out.println("Case #"+(i+1)+": "+ str);
				mSb.append("Case #"+(i+1)+": "+ str);
				mSb.append("\n");
			}
		
		} catch (IOException e) {
			System.err.println(e.getMessage() + " case:" + e.getCause());
		}
	}

	void ioWrite() {
		log("start ioWrite");
	    try {	
	    	PrintStream out = new PrintStream(new File(mOutput));
	    	out.println(mSb.toString());
	    	out.close();
	    } catch(IOException e) {
	    	System.err.println(e.getMessage() + " case:" + e.getCause());
	    }
	}
	
	void logMatrix(int[][] m , int r, int c)
	{
		for (int i = 0; i < r; i++) {
			for (int j  =0; j < c; j++) {
				System.out.print(m[i][j] +" ");
			}
			System.out.println();
		}
		
	}
	void logMatrix(boolean[][] m , int r, int c)
	{
		for (int i = 0; i < r; i++) {
			for (int j  =0; j < c; j++) {
				System.out.print(m[i][j] +" ");
			}
			System.out.println();
		}
		
	}
	//row
	boolean IsLargest(int value, int[] array)
	{
		for (int i =0; i < array.length; i++) {
			if (array[i] == -1)
				return true;
			if (value < array[i])
				return false;
		}
		return true;
	}
	
	//column
	boolean IsLargest(int value, int[][] sc, int c)
	{
		//check
		for (int j = 0;j < 101; j++) {
			if (sc[j][c] == -1)
				return true;
			if (value < sc[j][c])	
				return false;
			
		}
			
		return true;
	}
	
	
	public String functor(int[][] m, int r, int c) {
		boolean[][] mapc = new boolean[101][101];
		boolean[][] mapr = new boolean[101][101];
		for (int i = 0; i < 101; i++) {
			Arrays.fill(mapc[i], false);
			Arrays.fill(mapr[i], false);
		}
		
		for (int i = 0 ; i < r; i++) {
			for (int j = 0 ; j < c; j++) {
				mapc[i][m[i][j]] = true;
				mapr[m[i][j]][j] = true;
			}
		}
	
		int[][] sr= new int[101][101];
		int[][] sc = new int[101][101];
		for (int i = 0; i < 101; i++) {
			Arrays.fill(sr[i], -1);
			Arrays.fill(sc[i], -1);
		}
		int idxr = 0;		
	
		for (int i = 0; i < 101; i++) {
			idxr = 0;
			for (int j = 0; j < 101; j++) {
				if (mapc[i][j]==true) {
					sr[i][idxr] = j ;
					idxr++;
				}
			}
		}
		///logMatrix(mapr,3,3);
		int idxc = 0;	
		for (int j = 0; j < 101; j++) {
			idxc = 0;
			for (int i = 0 ; i < 101; i++) {
				if(mapr[i][j]==true) {
					sc[idxc][j] = i;
					idxc++;
				}
			}
		}
		
		log("sr");
		///logMatrix(sr,r,c);
		log("sc");
		///logMatrix(sc,r,c);
		
		boolean br, bc;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				//compare rows
				br = IsLargest (m[i][j], sr[i]);
				//compare columns
				bc = IsLargest (m[i][j], sc, j);
				//log("("+i+","+j+") br=" +br+" bc="+bc);
				if (br == false && bc == false)
					return "NO";
			}
		}
		
		return "YES";
	}
	public static void main(String[] args) {
		
		Lawnmower fb= new Lawnmower();
		log("=== start testing == ");
		fb.ioReadAndRun();
		fb.ioWrite();
		log("=== end testing == ");
	}

}

