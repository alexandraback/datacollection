
public class A {
	public static void main(String[]args) throws Exception {
		java.io.File file = new java.io.File(args[0]);
		java.io.FileInputStream finput = new java.io.FileInputStream(file);
		java.io.DataInputStream dinput = new java.io.DataInputStream(finput);
		java.io.BufferedReader breader = new java.io.BufferedReader(new java.io.InputStreamReader(dinput));
		
		java.io.File result_file = new java.io.File(args[0]+"_result.txt");
		java.io.FileOutputStream foutput = new java.io.FileOutputStream(result_file);
		java.io.DataOutputStream doutput = new java.io.DataOutputStream(foutput);
		java.io.BufferedWriter bwriter = new java.io.BufferedWriter(new java.io.OutputStreamWriter(doutput));
		
		String line="";
		String result;
		int xwin, owin, complete;
		int[]Xcheckwinx;
		int[]Xcheckwiny;
		int[]Xcheckwind;
		int[]Ocheckwinx;
		int[]Ocheckwiny;
		int[]Ocheckwind;
		
		char playerX = 'X';
		char playerO = 'O';
		char empty = '.';
		char any = 'T';
		
		line = breader.readLine();
		int times=Integer.parseInt(line);
		
		for ( int i=1; i<=times; i++){
			result="Case #"+i+": ";
			xwin = 0;
			owin = 0;
			complete = 1;
			
			char[][] board = new char[4][4]; 
			line = breader.readLine();
			board[0] = line.toCharArray();
			line = breader.readLine();
			board[1] = line.toCharArray();
			line = breader.readLine();
			board[2] = line.toCharArray();
			line = breader.readLine();
			board[3] = line.toCharArray();
			line = breader.readLine();
			// elimination
			Xcheckwinx = new int[4];
			Xcheckwiny = new int[4];
			Xcheckwind = new int[2];
			Ocheckwinx = new int[4];
			Ocheckwiny = new int[4];
			Ocheckwind = new int[2];
			for (int dx=0; dx<=3; dx++){
				Xcheckwinx[dx] = 1;
				Xcheckwiny[dx] = 1;
				Ocheckwinx[dx] = 1;
				Ocheckwiny[dx] = 1;
				if ( dx < 2 ) {
					Xcheckwind[dx] = 1;
					Ocheckwind[dx] = 1;
				}
			}
			for (int dx=0; dx<=3; dx++){
				for (int dy=0; dy<=3; dy++){
					
					if (!(playerX == board[dx][dy] || any == board[dx][dy])){
						Xcheckwinx[dx] = 0;
						Xcheckwiny[dy] = 0;
						if (dx == dy) {
							Xcheckwind[0] = 0;
						}
						if (dy == 3-dx) {
							Xcheckwind[1] = 0;
						}
					}
					if (!(playerO == board[dx][dy] || any == board[dx][dy])){
						Ocheckwinx[dx] = 0;
						Ocheckwiny[dy] = 0;
						if (dx == dy) {
							Ocheckwind[0] = 0;
						}
						if (dy == 3-dx) {
							Ocheckwind[1] = 0;
						}
					}
					if (empty == (board[dx][dy])) {
						complete = 0;
					}
				}
			}
			for (int dx=0; dx<=3; dx++){
				if (Xcheckwinx[dx]==1||Xcheckwiny[dx]==1) {
					xwin = 1;
				}
				if (Ocheckwinx[dx]==1||Ocheckwiny[dx]==1) {
					owin = 1;
				}
			}
			if (Xcheckwind[0] == 1 || Xcheckwind[1] == 1) {
				xwin = 1;
			}
			if (Ocheckwind[0] == 1 || Ocheckwind[1] == 1) {
				owin = 1;
			}
			
			if(xwin == 1){
				result = result + "X won";
			} else if (owin == 1){
				result = result + "O won";
			} else if (complete == 0) {
				result = result + "Game has not completed";
			} else {
				result = result + "Draw";
			}
			bwriter.write(result);
			if ( i != times) {
				bwriter.newLine();
			}
			bwriter.flush();
		}
		doutput.close();
		dinput.close();
	}
}
