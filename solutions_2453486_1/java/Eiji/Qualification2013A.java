package codejam2013.qualification.a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Qualification2013A {
	public static final String FOLDER = Qualification2013A.class.getSimpleName();
	
	public static void main(String[] args) throws Exception {
		BufferedReader input = new BufferedReader(new FileReader(FOLDER+"/input.txt"));
		BufferedWriter output = new BufferedWriter(new FileWriter(FOLDER+"/output.txt"));

		int n = Integer.parseInt(input.readLine());
		
		for (int i = 0; i < n; i++) {
			
			StringBuilder resposta = new StringBuilder();
			String solucao = solve(input);
			resposta.append("Case #").append(i +1).append(": ").append(solucao).append("\n");
			String texto = resposta.toString();
			output.write(texto);
			System.out.print(texto);
		}
		input.close();
		output.close();

	}

	private static String solve(BufferedReader input) throws IOException {
		String[] matriz = new String[4];
		int lin = 0;
		matriz[lin++] = input.readLine().trim();
		matriz[lin++] = input.readLine().trim();
		matriz[lin++] = input.readLine().trim();
		matriz[lin++] = input.readLine().trim();
		input.readLine();
		
		return resolve(matriz);
	}

	private static String resolve(String[] m) {
		boolean incomplete = false;
		for (int i =0; i < 4; i++) {
			boolean x[] = new boolean [2]; // vertical, horizontal 
			boolean o[] = new boolean [2];
			x[0] = true;
			x[1] = true;
			o[0] = true;
			o[1] = true;
			for (int j = 0; j < 4; j++) {
				char c = pos(m, i, j);
				incomplete = incomplete | marcaDirecao(x, o, c, 0);
				
				c = pos(m, j, i);
				incomplete = incomplete | marcaDirecao(x, o, c, 1) ;
			}
			if (x[0] || x[1]) {
				return "X won";
			}
			if (o[0] || o[1]) {
				return "O won";
			}
		}
		
		
		// diagonal1, diagonal2;
		boolean x[] = new boolean [2]; // vertical, horizontal, diagonal1, diagonal2; 
		boolean o[] = new boolean [2];
		x[0] = true;
		x[1] = true;
		o[0] = true;
		o[1] = true;
		for (int i =0; i < 4; i++) {
			char c = pos(m, i, i);
			incomplete = incomplete | marcaDirecao(x, o, c, 0);
			
			c = pos(m, i, 3 - i);
			incomplete = incomplete | marcaDirecao(x, o, c, 1);
		}
		
		if (x[0] || x[1]) {
			return "X won";
		}
		if (o[0] || o[1]) {
			return "O won";
		}
		if (incomplete) {
			return "Game has not completed";
		}
		
		return "Draw";
	}

	private static boolean marcaDirecao(boolean[] x, boolean[] o, char c, int dir) {
		boolean incomplete = false;
		if (c == 'X') {
			o[dir] = false;
		} else {
			if (c == 'O') {
				x[dir] = false;
			} else {
				if (c == '.') {
					incomplete = true;
					x[dir] = false;
					o[dir] = false;
				}
			}
		}
		return incomplete;
	}

	private static char pos(String[] m, int linha, int coluna) {
		return m[linha].charAt(coluna);
		
	}

}
