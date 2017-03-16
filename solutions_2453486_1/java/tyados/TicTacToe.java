import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class TicTacToe {

	
	enum Output {
		O_WON,
		X_WON,
		DRAW,
		NOT_YET
	}
	
	static int caseNum;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br  = new BufferedReader(new InputStreamReader(new FileInputStream("tictactoe.in")));
		PrintWriter pw = new PrintWriter(new FileOutputStream("tictactoe.out"));
		
		caseNum = Integer.parseInt(br.readLine());
		
		for (int i = 1;i <= caseNum;i++) {
			char[][] input = new char[4][4];
			for (int j = 0;j < 4;j++) {
				String line = br.readLine();
				for (int k = 0;k < 4;k++)
					input[j][k] = line.charAt(k);
			}
			br.readLine();
			Output output = eval(input);
			switch (output) {
			case O_WON:
				pw.println("Case #" + i + ": O won");
				break;
			case X_WON:
				pw.println("Case #" + i + ": X won");
				break;
			case DRAW:
				pw.println("Case #" + i + ": Draw");
				break;
			case NOT_YET:
				pw.println("Case #" + i + ": Game has not completed");
				break;
			}
		}
		br.close();
		pw.close();
		
		
	}
	
	static boolean isrow(char[][] in, int i, char y) {
		for (int j = 0;j < 4;j++) {
			if (in[i][j] != y && in[i][j] != 'T')
				return false;
		}
		return true;
	}
	
	static boolean isColum(char[][] in, int i, char y) {
		for (int j = 0;j < 4;j++) {
			if (in[j][i] != y && in[j][i] != 'T')
				return false;
		}
		return true;
	}
	
	static boolean isDiag(char[][] in, char y) {
		boolean result = true;
		for (int j = 0;j < 4;j++) {
			if (in[j][j] != y && in[j][j] != 'T') {
				result = false;
				break;
			}
		}
		if (result)
			return true;
		for (int j = 0;j < 4;j++) {
			if (in[j][3-j] != y && in[j][3-j] != 'T')
				return false;
		}
		return true;
	}
	
	static Output eval(char[][] in) {
		for (int i = 0;i < 4;i++)
			if (isrow(in, i, 'X') || isColum(in, i, 'X'))
				return Output.X_WON;
		if (isDiag(in, 'X'))
			return Output.X_WON;
		
		for (int i = 0;i < 4;i++)
			if (isrow(in, i, 'O') || isColum(in, i, 'O'))
				return Output.O_WON;
		if (isDiag(in, 'O'))
			return Output.O_WON;
		
		for (int i = 0;i < 4;i++)
			for (int j = 0;j < 4;j++)
				if (in[i][j] == '.')
					return Output.NOT_YET;
		
		return Output.DRAW;
		
	}
	
}
