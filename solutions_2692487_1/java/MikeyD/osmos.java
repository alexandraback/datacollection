import java.io.*;
import java.util.*;

public class osmos {

	public static int[][] grid;
	public static int[] motes;
	public static int sizeAfter;
	
	public static void main(String[] args) throws Exception{
		
		Scanner In = new Scanner(System.in);
		
		int numCases = In.nextInt();
		
		for(int currCase = 1;currCase <= numCases;currCase++){
			
			int ASize = In.nextInt(), numMotes = In.nextInt();
			
			motes = new int[numMotes];
			
			for(int i = 0;i < numMotes;i++)
				motes[i] = In.nextInt();
			
			Arrays.sort(motes);
			grid = new int[numMotes][numMotes];
			
			for(int i = 0;i < numMotes;i++)
				Arrays.fill(grid[i], -1);
			
			System.out.println("Case #"+currCase+": "+runOp(0, 0, 0, ASize));
			/*
			for(int i = 0;i < grid.length;i++){
				for(int j = 0;j < grid.length;j++){
					System.out.print(grid[i][j] + " ");
			
				}
				System.out.println();
			}*/
			
		}
		
	}
	
	public static int runOp(int adds, int subtracts, int currentMote, int currSize){
		
		if(currentMote == motes.length){
			return 0;
		}
		
		if(grid[adds][subtracts] != -1)
			return grid[adds][subtracts];
		
		int add = numAdditions(currSize, currentMote);
		//System.out.println()
		int newSize = sizeAfter;
		
		grid[adds][subtracts] = Math.min(add+runOp(adds+1, subtracts, currentMote+1, newSize+motes[currentMote]), 1+runOp(adds, subtracts+1, currentMote+1, currSize));
		
		return grid[adds][subtracts];
		
		
		
	}
	
	public static int numAdditions(int currSize, int currMote){
		
		int numAdd = 0;
		sizeAfter = currSize;
		if(currSize == 1) return 1000000;
		
		while(sizeAfter <= motes[currMote]){
			sizeAfter += sizeAfter-1;
			numAdd++;
		}
		
		return numAdd;
	}
	
}
