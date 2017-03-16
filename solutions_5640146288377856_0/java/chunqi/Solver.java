package brattleship;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Solver {
	private FileReader m_fileReader;
	private FileWriter m_fileWriter;
	private BufferedReader m_bufferedReader;
	private BufferedWriter m_bufferedWriter;
	
	private int m_numCases;
	
	public Solver() {
		try {
			m_fileReader = new FileReader("input.txt");
			m_fileWriter = new FileWriter("output.txt");
			m_bufferedReader = new BufferedReader(m_fileReader);
			m_bufferedWriter = new BufferedWriter(m_fileWriter);
			
			m_numCases = Integer.parseInt(m_bufferedReader.readLine());
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		for(int x = 1; x <= m_numCases; x++) {
			_solveCase(x);
		}
		
		try {
			m_bufferedReader.close();
			m_bufferedWriter.close();
			m_fileReader.close();
			m_fileWriter.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private int blankRowCost(int C, int W) {
		assert(W > 1);
		System.out.println(C + "\t" + W);
		//Run through row leaving gaps of W - 1
		int cost = 0;
		for(int x = W - 1; x < C; x += W) {
			//hit this spot unless is last cell
			if(x != C - 1) {
				System.out.println("Hit:" + (x + 1));
				cost++;
			}
		}
		return cost;
	}
	
	private int hitRowCost(int C, int W) {
		assert(W > 1);
		//blank row cost to find hit point
		int cost = blankRowCost(C, W);
		
		//Optimal is 1 miss + rest of the ship
		cost += W;
		return cost;
	}
	
	private void _solveCase(int caseNum) {
		try {
			int R, C, W, cost = 0;
			String[] parts = m_bufferedReader.readLine().split(" ");
			R = Integer.parseInt(parts[0]);
			C = Integer.parseInt(parts[1]);
			W = Integer.parseInt(parts[2]);
			
			//Width = 1, must try all cells
			if(W == 1) {
				cost = R * C;
			}
			else {
				//Cost to eliminate all other rows
				if(R > 1) cost += (R - 1) * blankRowCost(C, W);
				//Cost to find ship in the correct row
				cost += hitRowCost(C, W);
			}
			
			m_bufferedWriter.write("Case #" + caseNum + ": " + cost + "\n");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
