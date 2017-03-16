package com.nastya.code_jam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Mines {

	public static void main(String args[]) {
		try {
			BufferedReader in = new BufferedReader(new FileReader("data/in/mines.in"));
			PrintWriter out = new PrintWriter("data/out/mines.out");

			int amount = Integer.parseInt(in.readLine());
			
			for (int k = 0; k < amount; k++) {
				String row = in.readLine();
				String[] arrRow = row.split(" ");
				int rows = Integer.parseInt(arrRow[0]);
				int columns = Integer.parseInt(arrRow[1]);
				int mines = Integer.parseInt(arrRow[2]);

				out.println("Case #" + (k + 1) + ": ");
				String[][] res = play(rows, columns, mines);
				if (res == null)
					out.println("Impossible");
				else {
					for (int i = 0; i < rows; i++) {
						for (int j = 0; j < columns; j++)
							out.print(res[i][j]);
						out.print("\n");
					}
				}
			}
			
			in.close();
			out.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("Конец!");
	}

	private static String[][] play(int rows, int columns, int mines) {
		String[][] field = new String[rows][columns];
		
		if (rows == 1) {
			for (int i = 0; i < mines; i++)
				field[0][i] = "*";
			for (int i = mines; i < columns - 1; i++)
				field[0][i] = ".";
			if (columns > mines)
				field[0][columns - 1] = "c";
			return field;
				
		}
		
		if (columns == 1) {
			for (int i = 0; i < mines; i++)
				field[i][0] = "*";
			for (int i = mines; i < rows - 1; i++)
				field[i][0] = ".";
			if (rows > mines)
				field[rows - 1][0] = "c";
			return field;
				
		}
			
		int freeCells = rows * columns - mines;
		if (rows == 2) {
			if ((freeCells > 7 && freeCells % 2 != 0) ||
					(freeCells == 2 || freeCells == 3 || freeCells == 5 || freeCells == 7))
				return null;
			
			for (int i = 0; i < mines / 2; i++) {
				field[0][i] = "*";
				field[1][i] = "*";
			}
			for (int i = mines / 2; i < columns - 1; i++) {
				field[0][i] = ".";
				field[1][i] = ".";
			}
			if (freeCells > 1) {
				field[0][columns - 1] = ".";
				field[1][columns - 1] = "c";
			}
			else if (freeCells == 1){
				field[0][columns - 1] = "*";
				field[1][columns - 1] = "c";
			}
			else {
				field[0][columns - 1] = "*";
				field[1][columns - 1] = "*";
			}
			return field;	
		}
		
		if (columns == 2) {
			if ((freeCells > 7 && freeCells % 2 != 0) ||
					(freeCells == 2 || freeCells == 3 || freeCells == 5 || freeCells == 7))
				return null;
			
			for (int i = 0; i < mines / 2; i++) {
				field[i][0] = "*";
				field[i][1] = "*";
			}
			for (int i = mines / 2; i < rows - 1; i++) {
				field[i][0] = ".";
				field[i][1] = ".";
			}
			if (freeCells > 1) {
				field[rows - 1][0] = ".";
				field[rows - 1][1] = "c";
			}
			else if (freeCells == 1){
				field[rows - 1][0] = "*";
				field[rows - 1][1] = "c";
			}
			else {
				field[rows - 1][0] = "*";
				field[rows - 1][1] = "*";
			}
			return field;	
		}


		if (freeCells == 2 || freeCells == 3 || freeCells == 5 || freeCells == 7) {
			return null;
		}
		else {
			int row = 0;
			int col = 0;
			int sum = 0;
			while (sum < mines) {
				if (rows - col < columns - row) {
					for (int i = col; i < rows; i++) {
						if (sum == mines)
							break;
						if (sum == mines - 1 && i == rows - 2 && freeCells > 2)
							break;
						field[i][row] = "*";
						sum++;
					}
					row++;
				}
				else {
					for (int i = row; i < columns; i++) {
						if (sum == mines)
							break;
						if (sum == mines - 1 && i == columns - 2 && freeCells > 2)
							break;
						field[col][i] = "*";
						sum++;
					}	
					col++;
				}
			}

			int temp = 0;
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					if (field[i][j] == null)
						field[i][j] = ".";
					else 
						temp++;
				}
			}
			field[rows - 1][columns - 1] = "c" + (sum != temp ? "!!!!!!!!!!!!!!!!" : "");
			return field;
		}
		
		//return null;
	}
}
