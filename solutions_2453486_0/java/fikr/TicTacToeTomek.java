// Google Code Jam Qualification Round 2013
// Problem A. Tic-Tac-Toe-Tomek

import java.util.*;
import java.io.*;

class TicTacToeTomek{
    static String inname = "A-small-attempt0.in";    // input file name here
    static String outname = "A-small-attempt0.out";  // output file name here
    static char[][] b; // the board
    static boolean full;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	String ans = "";
            	b = new char[4][4];
            	full = true;
            	for (int i = 0; i < 4; i++){
            		String line = in.nextLine();
            		for (int j = 0; j < 4; j++){
            			b[i][j] = line.charAt(j);
            			if (b[i][j] == '.') full = false;
            		}
            	}
            	in.nextLine();
            	char h, v, d;
            	while (true){ 	// dummy loop
            		h = checkHorizontal();
            		if (h != '.'){
            			if (h == 'O') ans = "O won";
            			else if (h == 'X') ans = "X won";
            			break;
            		}
            		v = checkVertical();
               		if (v != '.'){
            			if (v == 'O') ans = "O won";
            			else if (v == 'X') ans = "X won";
            			break;
            		}
            		d = checkDiagonal();
               		if (d != '.'){
            			if (d == 'O') ans = "O won";
            			else if (d == 'X') ans = "X won";
            			break;
            		}
               		if (full){
               			ans = "Draw";
               			break;
               		}
               		ans = "Game has not completed";
            		break;
            	}
                //System.out.print("Case #" + cas + ": " + ans + "\n");
                out.write("Case #" + cas + ": " + ans + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

	private static char checkHorizontal() {
		char l;
		for (int i = 0; i < 4; i++){
			if (b[i][0]!='T') l = b[i][0];
			else l = b[i][1];
			if ((b[i][0] == l || b[i][0] == 'T') && b[i][0] != '.' &&
				(b[i][1] == l || b[i][1] == 'T') && b[i][1] != '.' &&
				(b[i][2] == l || b[i][2] == 'T') && b[i][2] != '.' &&
				(b[i][3] == l || b[i][3] == 'T') && b[i][3] != '.') return l;
		}
		return '.';
	}
	
	private static char checkVertical() {
		char l;
		for (int i = 0; i < 4; i++){
			if (b[0][i]!='T') l = b[0][i];
			else l = b[1][i];
			if ((b[0][i] == l || b[0][i] == 'T') && b[0][i] != '.' &&
				(b[1][i] == l || b[1][i] == 'T') && b[1][i] != '.' &&
				(b[2][i] == l || b[2][i] == 'T') && b[2][i] != '.' &&
				(b[3][i] == l || b[3][i] == 'T') && b[3][i] != '.') return l;
		}
		return '.';
	}
	
	private static char checkDiagonal() {
		char l;
		if (b[0][0]!='T') l = b[0][0];
		else l = b[1][1];
		if ((b[0][0] == l || b[0][0] == 'T') && b[0][0] != '.' &&
			(b[1][1] == l || b[1][1] == 'T') && b[1][1] != '.' &&
			(b[2][2] == l || b[2][2] == 'T') && b[2][2] != '.' &&
			(b[3][3] == l || b[3][3] == 'T') && b[3][3] != '.') return l;
		
		if (b[0][3]!='T') l = b[0][3];
		else l = b[1][2];
		if ((b[0][3] == l || b[0][3] == 'T') && b[0][3] != '.' &&
			(b[1][2] == l || b[1][2] == 'T') && b[1][2] != '.' &&
			(b[2][1] == l || b[2][1] == 'T') && b[2][1] != '.' &&
			(b[3][0] == l || b[3][0] == 'T') && b[3][0] != '.') return l;
		
		return '.';
	}

	
}