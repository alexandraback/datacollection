package gcj_2014_pr;
import java.util.*;
import java.io.*;

public class TicTacToeTomek {
	public String state(char[][] map){
		boolean fin = true;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if( map[i][j] == '.' ){
					fin = false;
					break;
				}
			}
		}
		int x = 0;
		int o = 0;
		int t = 0;
		for(int i = 0; i < 4; i++){
			if( map[i][i] == 'X' ){
				x++;
			} else if( map[i][i] == 'O' ){
				o++;
			} else if ( map[i][i] == 'T' ){
				t++;
			}
		}
		if( x+t == 4 ){
			return "X won";
		} else if( o+t == 4 ){
			return "O won";
		}
		x = 0;
		o = 0;
		t = 0;
		for(int i = 0; i < 4; i++){
			if( map[i][3-i] == 'X' ){
				x++;
			} else if( map[i][3-i] == 'O' ){
				o++;
			} else if ( map[i][3-i] == 'T' ){
				t++;
			}
		}
		if( x+t == 4 ){
			return "X won";
		} else if( o+t == 4 ){
			return "O won";
		}
		for(int i = 0; i < 4; i++){
			x = 0;
			o = 0;
			t = 0;
			for(int j = 0; j < 4; j++){
				if( map[i][j] == 'X' ){
					x++;
				} else if( map[i][j] == 'O' ){
					o++;
				} else if ( map[i][j] == 'T' ){
					t++;
				}
			}
			if( x+t == 4 ){
				return "X won";
			} else if( o+t == 4 ){
				return "O won";
			}
			x = 0;
			o = 0;
			t = 0;
			for(int j = 0; j < 4; j++){
				if( map[j][i] == 'X' ){
					x++;
				} else if( map[j][i] == 'O' ){
					o++;
				} else if ( map[j][i] == 'T' ){
					t++;
				}
			}
			if( x+t == 4 ){
				return "X won";
			} else if( o+t == 4 ){
				return "O won";
			}
		}
		if( fin ){
			return "Draw";
		} else {
			return "Game has not completed";
		}
	}
	public void solve() throws IOException {
		int n = nextInt();
		for(int i = 0; i < n; i++){
			char[][] map = new char[4][4];
			for(int j = 0; j < 4; j++){
				map[j] = nextToken().toCharArray();
			}
			writer.println("Case #" + (i+1) + ": " + state(map));
		}
	}

	public static void main(String[] args) throws IOException {
		new TicTacToeTomek().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() throws IOException {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
}
