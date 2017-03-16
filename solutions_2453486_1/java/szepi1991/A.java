import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class A {

	public static void main(String[] args) {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		try {
			String line = in.readLine();
			int cases = Integer.parseInt(line);
			
			String[] field = new String[4];
			for (int c = 1; c <= cases; ++c) {
//				if (c == 5)
//					System.out.println("juj");
				
				for (int l = 0; l < 4; ++l) {
					field[l] = in.readLine();
				}
				in.readLine(); // TODO what about very last line!!
				
				char winner = 'N';
				// check horizontal and vertical
				for (int o = 0; o < 4; ++o) {
					boolean OwonH = true, OwonV = true;
					boolean XwonH = true, XwonV = true;
					for (int i = 0; i < 4; ++i) {
						char hor = field[o].charAt(i);
						char ver = field[i].charAt(o);
						if (hor == 'O' || hor == '.') XwonH = false;
						if (ver == 'O' || ver == '.') XwonV = false;
						if (hor == 'X' || hor == '.') OwonH = false;
						if (ver == 'X' || ver == '.') OwonV = false;
					}
					
					if (XwonH || XwonV) {
						winner = 'X';
						break;
					}
					if (OwonH || OwonV) {
						winner = 'O';
						break;
					}
				}
				
				if (winner == 'N') {
					// also check the diagonals
					boolean OwonH = true, OwonV = true;
					boolean XwonH = true, XwonV = true;
					for (int i = 0; i < 4; ++i) {
						char hor = field[i].charAt(i);
						char ver = field[i].charAt(3-i);
						if (hor == 'O' || hor == '.') XwonH = false;
						if (ver == 'O' || ver == '.') XwonV = false;
						if (hor == 'X' || hor == '.') OwonH = false;
						if (ver == 'X' || ver == '.') OwonV = false;
					}
					if (XwonH || XwonV) winner = 'X';
					if (OwonH || OwonV) winner = 'O';
				}
				
				if (winner == 'N') {
					// check if it's a draw, ie everything is filled in
					boolean full = true;
					for (int o = 0; o < 4; ++o) {
						for (int i = 0; i < 4; ++i) {
							if (field[o].charAt(i) == '.') {
								full = false;
								break;
							}
						}
						if (!full) break;
					}
					if (full) winner = 'D';
				}
				
				// output results
				String res;
				switch (winner) {
				case 'N': res = "Game has not completed"; break;
				case 'D': res = "Draw"; break;
				case 'O':
				case 'X': res = winner + " won"; break;
				default: throw new RuntimeException("Impossible!");
				}
				System.out.println("Case #" + c + ": " + res);
				
			}
			
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
	
}
