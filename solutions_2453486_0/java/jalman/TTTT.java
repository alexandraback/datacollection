import java.io.*;
import java.util.*;

public class TTTT{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int t = Integer.parseInt(br.readLine());

		String[] b = new String[4];
		char[][] inp = new char[4][4];

		for(int i = 1; i <= t; i++) {
			for(int j = 0; j < 4; j++) b[j] = br.readLine();


			for(int j = 0; j < 4; j++) for(int k = 0; k < 4; k++) inp[j][k] = b[j].charAt(k);

			pw.println("Case #" + i + ": " + run(inp));

			try{
				br.readLine();
			} catch(Exception e) {}

		}

		pw.flush();
		pw.close();
	}

	public static String run(char[][] b){
		boolean done = true;


		LoopA: for(int r = 0; r < 4; r++) {
			for(int c = 0; c < 4; c++) {
				if(!(b[r][c] == 'X' || b[r][c]=='T')) continue LoopA;
			}
			return "X won";
		}


		LoopB: for(int r = 0; r < 4; r++) {
			for(int c = 0; c < 4; c++) {
				if(!(b[c][r] == 'X' || b[c][r]=='T')) continue LoopB;
			}
			return "X won";
		}

		LoopC: for(int r = 0; r < 4; r++) {
			for(int c = 0; c < 4; c++) {
				if(!(b[r][c] == 'O' || b[r][c]=='T')) continue LoopC;
			}
			return "O won";
		}


		LoopD: for(int r = 0; r < 4; r++) {
			for(int c = 0; c < 4; c++) {
				if(!(b[c][r] == 'O' || b[c][r]=='T')) continue LoopD;
			}
			return "O won";
		}

		LoopE: for(int r = 0; r < 5; r++) {
			if(r < 4)
				if(!(b[r][r] == 'O' || b[r][r]=='T')) break LoopE;
			if(r==4)
				return "O won";
		}

		LoopF: for(int r = 0; r < 5; r++) {
			if(r < 4)
				if(!(b[r][r] == 'X' || b[r][r]=='T')) break LoopF;
			if(r==4)
				return "X won";
		}

		LoopG: for(int r = 0; r < 5; r++) {
			if(r < 4)
				if(!(b[r][3-r] == 'O' || b[r][3-r]=='T')) break LoopG;
			if(r==4)
				return "O won";
		}

		LoopH: for(int r = 0; r < 5; r++) {
			if(r < 4)
				if(!(b[r][3-r] == 'X' || b[r][3-r]=='T')) break LoopH;
			if(r==4)
				return "X won";
		}

		for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) if(b[i][j] == '.') done=false;


		if(done) return "Draw";
		return "Game has not completed";
	}
}