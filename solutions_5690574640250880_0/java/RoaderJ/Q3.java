import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Q3 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File file = new File("input.txt");  
		File dest = new File("output.txt");  
		BufferedReader reader = new BufferedReader(new FileReader(file));  
		BufferedWriter writer  = new BufferedWriter(new FileWriter(dest));  
		String data = reader.readLine();
		int num = Integer.parseInt(data);
		for (int t = 1; t <= num; t++){
			writer.write("Case #"+t+":\n");
			data = reader.readLine();
			String value[] = data.split(" ");
			int R = Integer.parseInt(value[0]);
			int C = Integer.parseInt(value[1]);
			int M = Integer.parseInt(value[2]);
			char board[][] = new char[R][C];
			int mine = 0;
			int flag = 0;
			// all mine
			if (M == R*C-1) {
				for (int x = 0; x < R; x++)
					for (int y = 0; y < C; y++) 
						board[x][y] = '*';
				board[0][0] = 'c';
			}
			// 1 row
			else if (R == 1) {
				mine = 0;
				for (int y = 0; y < C; y++) {
					if (mine < M) {
						board[0][y] = '*';
						mine++;
					}
					else board[0][y] = '.';
				}
				board[0][C-1] = 'c';
			}
			// 1 col
			else if (C == 1) {
				mine = 0;
				for (int x = 0; x < R; x++) {
					if (mine < M) {
						board[x][0] = '*';
						mine++;
					}
					else board[x][0] = '.';
				}
				board[R-1][0] = 'c';
			}
			// four no_mine
			else if (R*C-M == 4) {
				for (int x = 0; x < R; x++)
					for (int y = 0; y < C; y++) 
						board[x][y] = '*';
				board[0][0] = 'c';
				board[1][0] = '.';
				board[0][1] = '.';
				board[1][1] = '.';
			}
			// less than 4 no_mine, or 5 no_mine or 7 no_mine
			else if ((R*C-M < 4) || (R*C-M == 5) || (R*C-M == 7)) {
				flag = 1;
			}
			// 2 rows
			else if (R == 2) {
				if ((M & 1) != 0)
					flag = 1;
				else {
					for (int x = 0; x < (int)(M/2); x++) {
						board[0][x] = '*';
						board[1][x] = '*';
					}
					for (int x = (int)(M/2); x < C; x++) {
						board[0][x] = '.';
						board[1][x] = '.';
					}
					board[R-1][C-1] = 'c';
				}
			}
			// 2 cols
			else if (C == 2) {
				if ((M & 1) != 0)
					flag = 1;
				else {
					for (int x = 0; x < (int)(M/2); x++) {
						board[x][0] = '*';
						board[x][1] = '*';
					}
					for (int x = (int)(M/2); x < R; x++) {
						board[x][0] = '.';
						board[x][1] = '.';
					}
					board[R-1][C-1] = 'c';
				}
			}
			// else
			else {
				int lx = 0;
				int ly = 0;
				for (int x = 0; x < R-2; x++)
					for (int y = 0; y < C; y++) {
						if (mine < M) {
							board[x][y] = '*';
							mine++;
							lx = x;
							ly = y;
						}
						else board[x][y] = '.';
					}
				if (mine == M) {
					for (int x = R-2; x < R; x++)
						for (int y = 0; y < C; y++) 
							board[x][y] = '.';
					board[R-1][C-1] = 'c';
					if (ly == C-2) {
						if (lx != R-3) {
							board[lx][ly] = '.';
							board[lx+1][0] = '*';
						}
						else if (C == 3) {
							flag = 1;
						}
						else {
							board[lx][ly] = '.';
							board[lx][ly-1] = '.';
							board[lx+1][0] = '*';
							board[lx+2][0] = '*';
						}
					}
				}
				else if ((((M-(R-2)*C)) & 1) != 0) {
					if (R*C-M < 9)
						flag = 1;
					else {
						board[R-3][C-1] = '.';
						board[R-3][C-2] = '.';
						board[R-3][C-3] = '.';
						for (int x = 0; x < (int)((M+1-(R-2)*C)/2)+1; x++) {
							board[R-2][x] = '*';
							board[R-1][x] = '*';
						}
						for (int x = (int)((M+1-(R-2)*C)/2)+1; x < C; x++) {
							board[R-2][x] = '.';
							board[R-1][x] = '.';
						}
						board[R-1][C-1] = 'c';
					}
				}
				else {
					for (int x = 0; x < (int)((M-(R-2)*C)/2); x++) {
						board[R-2][x] = '*';
						board[R-1][x] = '*';
					}
					for (int x = (int)((M-(R-2)*C)/2); x < C; x++) {
						board[R-2][x] = '.';
						board[R-1][x] = '.';
					}
					board[R-1][C-1] = 'c';
				}	
			}
			if (flag == 1)
				writer.write("Impossible\n");
			else {
				for (int x = 0; x < R; x++) {
					for (int y = 0; y < C; y++) 
						writer.write(board[x][y]);
					writer.write("\n");
				}
			}
		}
		reader.close();
		writer.flush();
		writer.close();
	}
}
