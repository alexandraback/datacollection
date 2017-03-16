package minesweepermaster;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class MinesweeperMaster {

	static Scanner in=null;
	static PrintWriter out=null;
	
	public static void main(String[] args) {
		
		try {
		File file = new File("minesweepermasterin.txt");
		File file2=new File("minesweepermasterout.txt");
		in = new Scanner(file);
		out = new PrintWriter(file2);
		int testCases = in.nextInt();
		for (int i=0;i<testCases;i++) {
			solveCase(i+1);
		}
		out.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void solveCase(int caseNum) throws Exception {
		int r=in.nextInt();
		int c=in.nextInt();
		int m=in.nextInt();
		int[][] grid=new int[r][c]; //0 is click, 1 is dot, 2 is mine
		for (int i=0;i<r;i++) {
			for (int j=0;j<c;j++) {
				grid[i][j]=2;
			}
		}
		int n=r*c-m;
		
		if (n==1) {
			grid[0][0]=0;
			printCase(caseNum,grid);
			return;
		}
		if (r==1) {
			for (int i=0;i<n;i++) {
				grid[0][i]=1;
			}
			grid[0][0]=0;
			printCase(caseNum,grid);
			return;
		}
		if (c==1) {
			for (int i=0;i<n;i++) {
				grid[i][0]=1;
			}
			grid[0][0]=0;
			printCase(caseNum,grid);
			return;
		}
		if (n==2) {
			printImpossible(caseNum);
			return;
		}
		if (r==2) {
			if (n%2==1) {
				printImpossible(caseNum);
				return;
			}
			for (int i=0;i<n/2;i++) {
				grid[0][i]=1;
				grid[1][i]=1;
			}
			grid[0][0]=0;
			printCase(caseNum,grid);
			return;
		}
		if (c==2) {
			if (n%2==1) {
				printImpossible(caseNum);
				return;
			}
			for (int i=0;i<n/2;i++) {
				grid[i][0]=1;
				grid[i][1]=1;
			}
			grid[0][0]=0;
			printCase(caseNum,grid);
			return;
		}
		if (n==3 || n==5 || n==7) {
			printImpossible(caseNum);
			return;
		}
		
		for (int i=0;i<c;i++) {
			grid[0][i]=1;
			grid[1][i]=1;
			n-=2;
			if (n==3) {
				grid[2][0]=1;
				grid[2][1]=1;
				grid[2][2]=1;
				grid[0][0]=0;
				printCase(caseNum,grid);
				return;
			}
			if (n==0) {
				grid[0][0]=0;
				printCase(caseNum,grid);
				return;
			}
		}
		for (int i=2;i<r;i++) {
			grid[i][0]=1;
			grid[i][1]=1;
			n-=2;
			if (n==1) {
				grid[2][2]=1;
				grid[0][0]=0;
				printCase(caseNum,grid);
				return;
			}
			if (n==0) {
				grid[0][0]=0;
				printCase(caseNum,grid);
				return;
			}
		}
		for (int i=2;i<r;i++) {
			for (int j=2;j<c;j++) {
				grid[i][j]=1;
				n--;
				if (n==0) {
					grid[0][0]=0;
					printCase(caseNum,grid);
					return;
				}
			}
		}
	}
	
	public static void printCase(int caseNum,int[][] grid) {
		out.println("Case #"+caseNum+":");
		for (int i=0;i<grid.length;i++) {
			for (int j=0;j<grid[0].length;j++) {
				switch(grid[i][j]) {
				case 0: out.print("c");
				break;
				case 1: out.print(".");
				break;
				case 2: out.print("*");
				break;
				}
			}
			out.println();
		}
	}
	
	public static void printImpossible(int caseNum) {
		out.println("Case #"+caseNum+":\nImpossible");
	}
}