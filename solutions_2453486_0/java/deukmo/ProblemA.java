package com.google.codejam.deukmo;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemA {
    private static final String INPUT_FILENAME = "A-small-attempt0.in";
    private static final String OUTPUT_FILENAME = "A-small-attempt0.out";
    
	public static void main(String[] args) throws Exception {
		System.out.println("Start!");
		
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        char[][] board = new char[4][4];
        String row;
        char winner;
        boolean hasEmptySquare;
        int ocount;
        int xcount;
        
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
            // START
        	hasEmptySquare = false;
        	input.nextLine();
        	for (int i=0; i<4; i++) {
        		row = input.nextLine();
        		for (int j=0; j<4; j++) {
        			board[i][j] = row.charAt(j);
        			if (board[i][j] == '.') hasEmptySquare = true;
        		}
        	}
        	
        	winner = '.';
        	for (int i=0; i<4; i++) {
        		// a row
        		ocount = 0;
        		xcount = 0;
        		for (int j=0; j<4; j++) {
        			if (board[i][j] == 'O') {
        				ocount++;
        			} else if (board[i][j] == 'X') {
        				xcount++;
        			} else if (board[i][j] == 'T') {
        				ocount++;
        				xcount++;
        			}
        		}
        		if (ocount >= 4) {
        			winner = 'O';
        		} else if (xcount >= 4) {
        			winner = 'X';
        		}
        		
        		// a column
        		ocount = 0;
        		xcount = 0;
        		for (int j=0; j<4; j++) {
        			if (board[j][i] == 'O') {
        				ocount++;
        			} else if (board[j][i] == 'X') {
        				xcount++;
        			} else if (board[j][i] == 'T') {
        				ocount++;
        				xcount++;
        			}
        		}
        		if (ocount >= 4) {
        			winner = 'O';
        		} else if (xcount >= 4) {
        			winner = 'X';
        		}
        	}
        	
        	// a diagonal
    		ocount = 0;
    		xcount = 0;
    		for (int i=0; i<4; i++) {
    			if (board[i][i] == 'O') {
    				ocount++;
    			} else if (board[i][i] == 'X') {
    				xcount++;
    			} else if (board[i][i] == 'T') {
    				ocount++;
    				xcount++;
    			}
    		}
    		if (ocount >= 4) {
    			winner = 'O';
    		} else if (xcount >= 4) {
    			winner = 'X';
    		}
    		
    		ocount = 0;
    		xcount = 0;
    		for (int i=0; i<4; i++) {
    			if (board[i][3-i] == 'O') {
    				ocount++;
    			} else if (board[i][3-i] == 'X') {
    				xcount++;
    			} else if (board[i][3-i] == 'T') {
    				ocount++;
    				xcount++;
    			}
    		}
    		if (ocount >= 4) {
    			winner = 'O';
    		} else if (xcount >= 4) {
    			winner = 'X';
    		}
        	
        	output.format("Case #%d: ", caseNum);
        	if (winner != '.') { 
        		output.format("%c won", winner);
        	} else if (hasEmptySquare) {
        		output.format("Game has not completed");
        	} else {
        		output.format("Draw");
        	}
        	output.format("\n");
            // END
        }
        
        input.close();
        output.close();
        
		System.out.println("Done!");
	}
}
