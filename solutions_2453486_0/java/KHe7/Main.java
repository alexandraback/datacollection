import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	/**
	 * @param args
	 * @throws IOException
	 * @throws NumberFormatException
	 */
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(in.readLine());
		loop:for(int i = 1;i <= N; ++i){
			System.out.print("Case #" + i + ": ");
			char[][] game = new char[4][];
			for(int j = 0;j < 4; ++j){
				game[j] = in.readLine().toCharArray();
			}
			in.readLine();
			boolean yet = false;
			for(int j = 0;j < 4; ++j){
				int nx = 0, no = 0, nt = 0;
				for(int k = 0;k < 4; ++k){
					switch(game[j][k]){
					case '.':
						yet = true;
						break;
					case 'X':
						++nx;
						break;
					case 'O':
						++no;
						break;
					case 'T':
						++nt;
						break;
					}
				}
				if(nx + nt == 4){
					System.out.println("X won");
					continue loop;
				} else if(no + nt == 4){
					System.out.println("O won");
					continue loop;
				}
			}
			for(int j = 0;j < 4; ++j){
				int nx = 0, no = 0, nt = 0;
				for(int k = 0;k < 4; ++k){
					switch(game[k][j]){
					case 'X':
						++nx;
						break;
					case 'O':
						++no;
						break;
					case 'T':
						++nt;
						break;
					}
				}
				if(nx + nt == 4){
					System.out.println("X won");
					continue loop;
				} else if(no + nt == 4){
					System.out.println("O won");
					continue loop;
				}
			}
			int nxl = 0, nol = 0, ntl = 0;
			for (int j = 0; j < 4; ++j) {
				switch (game[j][j]) {
				case 'X':
					++nxl;
					break;
				case 'O':
					++nol;
					break;
				case 'T':
					++ntl;
					break;
				}
				if (nxl + ntl == 4) {
					System.out.println("X won");
					continue loop;
				} else if (nol + ntl == 4) {
					System.out.println("O won");
					continue loop;
				}
			}
			nxl = 0; nol = 0; ntl = 0;
			for (int j = 0; j < 4; ++j) {
				switch (game[j][3-j]) {
				case 'X':
					++nxl;
					break;
				case 'O':
					++nol;
					break;
				case 'T':
					++ntl;
					break;
				}
				if (nxl + ntl == 4) {
					System.out.println("X won");
					continue loop;
				} else if (nol + ntl == 4) {
					System.out.println("O won");
					continue loop;
				}
			}
			if(yet){
				System.out.println("Game has not completed");
			} else {
				System.out.println("Draw");
			}
		}
	}

}
