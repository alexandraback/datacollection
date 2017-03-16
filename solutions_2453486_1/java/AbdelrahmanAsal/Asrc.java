import java.io.BufferedReader;
import java.io.InputStreamReader;


public class A {

	void run() throws Exception {
		BufferedReader bfd = new BufferedReader(
				new InputStreamReader(System.in));
		int tc = Integer.parseInt(bfd.readLine());
		char[][] arr;
		ML: for(int t = 1; t <= tc; ++t) {
			if(t > 1)
				bfd.readLine();
			System.out.print("Case #"+ t +": ");
			arr = new char[4][4];
			for(int i = 0; i < 4; ++i) {
				arr[i] = bfd.readLine().toCharArray();
			}
			// r
			for(int i = 0; i < 4; ++i) {
				int X = 0, O = 0, T = 0; 
				for(int j = 0; j < 4; ++j) {
					if (arr[i][j]=='X')
						++X;
					else if (arr[i][j]=='O')
						++O;
					else if (arr[i][j]=='T')
						++T;
				}
				if(X == 4 || (X==3 && T == 1)) {
					System.out.println("X won");
					continue ML;
				} else if(O == 4 || (O==3 && T == 1)) {
					System.out.println("O won");
					continue ML;
				}
			}
			// c
			for(int i = 0; i < 4; ++i) {
				int X = 0, O = 0, T = 0; 
				for(int j = 0; j < 4; ++j) {
					if (arr[j][i]=='X')
						++X;
					else if (arr[j][i]=='O')
						++O;
					else if (arr[j][i]=='T')
						++T;
				}
				if(X == 4 || (X==3 && T == 1)) {
					System.out.println("X won");
					continue ML;
				} else if(O == 4 || (O==3 && T == 1)) {
					System.out.println("O won");
					continue ML;
				}
			}
			// 1st diag
			int X = 0, O = 0, T = 0;
			for(int i = 0; i < 4; ++i) {
				char c = arr[i][i];
				if(c == 'X')
					++X;
				else if(c == 'O')
					++O;
				else if(c == 'T')
					++T;
			}
			if(X == 4 || (X==3 && T == 1)) {
				System.out.println("X won");
				continue ML;
			} else if(O == 4 || (O==3 && T == 1)) {
				System.out.println("O won");
				continue ML;
			}
			// 2nd diag
			X = 0; O = 0; T = 0;
			for(int i = 0; i < 4; ++i) {
				char c = arr[i][4 - i - 1];
				if(c == 'X')
					++X;
				else if(c == 'O')
					++O;
				else if(c == 'T')
					++T;
			}
			if(X == 4 || (X==3 && T == 1)) {
				System.out.println("X won");
				continue ML;
			} else if(O == 4 || (O==3 && T == 1)) {
				System.out.println("O won");
				continue ML;
			}
			//---
			boolean ended = true;
			for (int i = 0; i < 4; ++i) {
				if((new String(arr[i])).contains(".")) {
					ended = false;
					break;
				}
			}
			if(ended)
				System.out.println("Draw");
			else
				System.out.println("Game has not completed");
		}

	}
	
	public static void main(String[] args) throws Exception {
		new A().run();
	}

}

