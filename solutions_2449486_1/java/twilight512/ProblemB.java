package com.yapark.codejam2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ProblemB {

	private int[][] lawn;
	private int N;
	private int M;

	public ProblemB(int n, int m) {
		N = n;
		M = m;
		lawn = new int[N][M];
	}
	
	public void readLine(String input, int lineNum) {
		String[] heights = input.split(" ");
		for(int i=0; i<M; i++) {
			lawn[lineNum][i] = Integer.decode(heights[i]);
		}
	}
	
	public int getMinIndex() {
		int minVal = 101;
		int minRow = 0;
		int minCol = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(lawn[i][j]<minVal) {
					minVal = lawn[i][j];
					minRow = i;
					minCol = j;
				}
			}
		}
		return minRow*M+minCol;
	}
	
	public int getRow(int index) {
		return index/M;
	}
	
	public int getCol(int index) {
		return index%M;
	}
	
	public int getVal(int index) {
		return lawn[getRow(index)][getCol(index)];
	}
	
	public boolean checkRow(int row, int minVal) {
		for(int i=0; i<M; i++) {
			if(lawn[row][i]!=minVal && lawn[row][i]!=101) {
				return false;
			}
		}
		return true;
	}
	
	public boolean checkCol(int col, int minVal) {
		for(int i=0; i<N; i++) {
			if(lawn[i][col]!=minVal && lawn[i][col]!=101) {
				return false;
			}
		}
		return true;
	}

	public void changeRow(int row) {
		for(int i=0; i<M; i++) {
			lawn[row][i]=101;
		}
	}
	
	public void changeCol(int col) {
		for(int i=0; i<N; i++) {
			lawn[i][col]=101;
		}
	}
	
	public boolean checkPossible() {
		int minIndex;
		int minVal;
		int minRow;
		int minCol;
		minIndex = getMinIndex();
		minRow = getRow(minIndex);
		minCol = getCol(minIndex);
		minVal = getVal(minIndex);
		while(minVal!=101) {
			if(checkRow(minRow, minVal)) {
				changeRow(minRow);
			}
			else if(checkCol(minCol, minVal)) {
				changeCol(minCol);
			}
			else {
				return false;
			}
			minIndex = getMinIndex();
			minRow = getRow(minIndex);
			minCol = getCol(minIndex);
			minVal = getVal(minIndex);
		}
		return true;
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
			FileWriter fw = new FileWriter("outputBlarge.txt");
			BufferedWriter bw = new BufferedWriter(fw);

			String line;
			int numOfGames;
			line = br.readLine();
			numOfGames = Integer.decode(line);
			for(int i = 1; i<=numOfGames; i++) {
				int rows, cols; 
				line = br.readLine();
				String[] dims = line.split(" ");
				rows = Integer.decode(dims[0]);
				cols = Integer.decode(dims[1]);
				ProblemB prob = new ProblemB(rows,cols);
				for(int j=0; j<rows; j++) {
					line = br.readLine();
					prob.readLine(line, j);
				}
				if(prob.checkPossible()) {
					bw.write("Case #"+i+": YES\n");
				}
				else {
					bw.write("Case #"+i+": NO\n");
				}
			}
			br.close();
			bw.flush();
			bw.close();
		}
		catch (FileNotFoundException e) {
			System.out.println("ERROR: Cannot find file.");
			return;
		}
		catch (IOException e) {
			
		}
	}

}
