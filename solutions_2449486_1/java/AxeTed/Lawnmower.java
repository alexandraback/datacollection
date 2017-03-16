package com.cbs.trials.cj13;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

public class Lawnmower {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//System.out.println("Test");
		
		//input
		String[] in=null;
		try{
			BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\Admin\\Downloads\\B-large.in"));
			//BufferedReader br = new BufferedReader(new FileReader("F:\\ECLIPSEWS\\codejam13\\small.in"));
			String line=null;
			ArrayList<String> ins 	= new ArrayList<>(); 
			while((line=br.readLine())!=null){
				ins.add(line);
			}
			in=ins.toArray(new String[]{});
		}catch(Exception e){
			System.out.println("Error finding/reading file.");
		}

		int numcases = Integer.parseInt(in[0]);
		int lastread=0;
		for(int i=0;i<numcases;i++){
			lastread++;
			String defrow = in[lastread];
			int rows = Integer.parseInt(defrow.split(" ")[0]);
			int cols = Integer.parseInt(defrow.split(" ")[1]);
			
			int[][] board= new int[rows][cols];
			String[] rowpieces = null;
			for(int j=0;j<rows;j++){
				lastread++;
				rowpieces = in[lastread].split(" ");
				for(int jj=0; jj<cols; jj++){
					board[j][jj]=Integer.parseInt(rowpieces[jj]);
				}
			}
			
			boolean poss = isPossible(board, rows, cols);
			System.out.println(String.format("Case #%d: %s", i+1, poss?"YES":"NO"));
		}
	}
	
	static boolean[] rowpass=null;
	static boolean[] colpass=null;
	static int curnum=-1;
	private static boolean isPossible(int[][] board, int rows, int cols){
	
		rowpass=new boolean[rows];
		colpass=new boolean[cols];
		
		
		int thisrow=-1;
		int thiscol=-1;
		while(true){
			//find lowest from notpassed places
			boolean foundnewcur=false;
		
			curnum=999;
			//outer: //Find smalles available unpassed number
			for(int i=0;i<rows;i++){
				if(rowpass[i]) continue;
				for(int j=0;j<cols;j++){
					if(colpass[j]) continue;
					if(board[i][j]<curnum){
						curnum=board[i][j];
						foundnewcur=true;
						thisrow=i;
						thiscol=j;
					}
				}
			}
			
			if(!foundnewcur) return true;
			
			boolean thisrowok = true;
			boolean thiscolok = true;
			//thisrow all cols check
			for(int j=0;j<cols;j++){
				if(board[thisrow][j]>curnum){
					thisrowok=false;
					break;
				}					
			}
			//thisrow all cols check
			for(int i=0;i<rows;i++){
				if(board[i][thiscol]>curnum){
					thiscolok=false;
					break;
				}					
			}
			
			if(thisrowok || thiscolok){
				//ok
				if(thisrowok) rowpass[thisrow]=true;
				if(thiscolok) colpass[thiscol]=true;
			}else{
				return false; //not possible
			}
		}
	}
}
