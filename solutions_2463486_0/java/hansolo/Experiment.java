package partb;

import java.util.Collections;
import java.util.LinkedList;

public class Experiment {

	// INPUT
	public int rowAmt;
	public int colAmt;
	public int[][] lawn;
	public LinkedList<Integer> heightList;
	
	// INTERNAL
	private boolean patternFails;
	
	public Experiment(int rowAmt, int colAmt) {
		// TODO Auto-generated constructor stub
	
		lawn = new int[rowAmt][colAmt];
		heightList = new LinkedList<>();
		this.rowAmt = rowAmt;
		this.colAmt = colAmt;
		
		patternFails = false;
	}

	public void addHeight(int val) {
		// TODO Auto-generated method stub
		int searchResult = Collections.binarySearch(heightList, val);
		
		if(searchResult<0)
			heightList.add(Math.abs(searchResult)-1, val);
			
	}

	public String Solve() {
		// TODO Auto-generated method stub
		
		while(!heightList.isEmpty())
		{
			int currentHeight = heightList.pollFirst();
			checkSequences(currentHeight);
			
			if(patternFails)
				return "NO";
		}
		return("YES");
	}

	private void checkSequences(int currentHeight) {
		// TODO Auto-generated method stub
		checkRows(currentHeight);
		checkCols(currentHeight);
		
	}

	private void checkCols(int currentHeight) {
		// TODO Auto-generated method stub
		for(int col=0; col<colAmt && !patternFails; col++)
		{
			int colCntr=0;
			boolean risky= false;
			
			for(int row=0; row < rowAmt; row++)
				if(lawn[row][col] < currentHeight)
					colCntr++;
				else if(lawn[row][col] == currentHeight)
				{
					colCntr++;
					risky = true;
				}
			
			if(colCntr==rowAmt)
				zeroCol(col);
			else if(risky)
				patternFails = true;
		}
	}

	private void zeroCol(int col) {
		// TODO Auto-generated method stub
		for(int row=0; row < rowAmt; row++)
			lawn[row][col] = 0;
	}

	private void checkRows(int currentHeight) {
		// TODO Auto-generated method stub
		for(int row=0; row<rowAmt; row++)
		{
			int rowCntr=0;
			
			for(int col=0; col < colAmt; col++)
				if(lawn[row][col] <= currentHeight)
					rowCntr++;
			
			if(rowCntr==colAmt)
				zeroRow(row);
		}
		
	}

	private void zeroRow(int row) {
		// TODO Auto-generated method stub
		for(int col=0; col < colAmt; col++)
			lawn[row][col] = 0;
	}
	
	

}
