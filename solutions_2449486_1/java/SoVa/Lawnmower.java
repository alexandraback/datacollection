package org.ivansopin.jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Lawnmower {
	final static String fileName = "E:/temp/jam/B-large";

	final static String inExtension = ".in";
	final static String outExtension = ".out";
	final static String source = fileName + inExtension;
	final static String destination = fileName + outExtension;

	static BufferedReader bufferedReader;
	static BufferedWriter bufferedWriter;

	/* this is problem-specific */
	static int numOfCases;
	static PriorityQueue<Cell> cells;
	static Cell[][] lawn;

	public static void main(String[] args) throws NumberFormatException, IOException, InterruptedException {
		bufferedReader = new BufferedReader(new FileReader(new File(source)));
		bufferedWriter = new BufferedWriter(new FileWriter(new File(destination)));

		numOfCases = Integer.parseInt(bufferedReader.readLine());
		
		Comparator<Cell> comp = new Comp();

		for (int c = 0; c < numOfCases; c++) {
			System.out.println("Case " + c + ":");
			
			StringTokenizer tokenizer = new StringTokenizer(bufferedReader.readLine());
			int n = Integer.parseInt(tokenizer.nextToken());
			int m = Integer.parseInt(tokenizer.nextToken());
			
			cells = new PriorityQueue<Cell>(n * m, comp);
			lawn = new Cell[n][m];
			Cell cell;
			
			for (int i = 0; i < n; i++) {
				tokenizer = new StringTokenizer(bufferedReader.readLine());
				lawn[i] = new Cell[m];
				for (int j = 0; j < m; j++) {
					int level = Integer.parseInt(tokenizer.nextToken());
					cell = new Cell(i, j, level);
					lawn[i][j] = cell;
					cells.add(cell);
				}
			}
			
			boolean possible = true;
			
			while ((cell = cells.poll()) != null) {
				System.out.println("\tChecking cell at " + cell.x + ", " + cell.y + " with level " + cell.level);
				
				/*
				if (cell.done) {
					System.out.println("\t\tskipping...");
					continue;
				}
				*/
				
				possible = true;
				int level = cell.level;
				
				int nPos = cell.x;
				for (int i = 0; i < m; i++) {
					if (lawn[nPos][i].level > level) {
						System.out.println("\t\timpossible horizontally...");
						possible = false;
						break;
					}
				}
				
				if (possible) {
					for (int i = 0; i < m; i++)
						lawn[nPos][i].done = true;
				} else {
					possible = true;
					int mPos = cell.y;
					for (int i = 0; i < n; i++) {
						if (lawn[i][mPos].level > level) {
							System.out.println("\t\timpossible vertically...");
							possible = false;
							break;
						}
					}
					
					if (possible) {
						for (int i = 0; i < n; i++)
							lawn[i][mPos].done = true;
					} else
						break;
				}
			}
			
			bufferedWriter.write("Case #" + (c + 1) + ": " + (possible ? "YES" : "NO") + "\n");
		}

		bufferedWriter.close();
		bufferedReader.close();
	}
	
	static class Cell {
		int x, y, level;
		boolean done = false;
		
		Cell (int x, int y, int level) {
			this.level = level;
			this.x = x;
			this.y = y;
		}
	}

	static class Comp implements Comparator<Cell> {
	    public int compare(Cell o1, Cell o2) {
	    	return new Integer(o2.level).compareTo(o1.level);
	    }
	}
}
