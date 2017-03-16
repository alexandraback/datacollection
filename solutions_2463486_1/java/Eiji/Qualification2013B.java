package codejam2013.qualification.b;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.TreeSet;
import java.io.BufferedReader;

public class Qualification2013B {
	public static final String FOLDER = Qualification2013B.class.getSimpleName();
	
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
		String[] xy =  input.readLine().split(" ");
		int lin = Integer.parseInt(xy[0]);
		int col = Integer.parseInt(xy[1]);
		
		int [][] m = new int[lin][col];
		Coord[][] coordenadas = new Coord[lin][col];
		
		
		
		LinkedList<Coord> bag = new LinkedList<Coord>();
		
		for (int i = 0; i < lin; i++) {
			String[] linha = input.readLine().split(" ");
			for (int j = 0; j < col; j++) {
				int valor = Integer.parseInt(linha[j]);
				m[i][j] = valor;
				Coord coord = new Coord(i,j,valor);
				bag.add(coord);
				coordenadas[i][j] = coord;
			}
		}
		
		Collections.sort(bag, new Comparator<Coord>() {

			@Override
			public int compare(Coord o1, Coord o2) {
				return o1.valor - o2.valor;
			}
		});
		
		
		while (bag.size() > 0) {
			Coord p = bag.remove();
			
			boolean corta = true;
			int x = p.x;
			for (int j = 0; j < col; j++) {
				if (coordenadas[x][j] == null) {
					continue;
				}
				if (coordenadas[x][j].valor != p.valor) {
					corta = false;
					break;
				}
			}
			if (corta) {
				for (int j = 0; j < col; j++) {
					if (coordenadas[x][j] == null) {
						continue;
					}
					bag.remove(coordenadas[x][j]);
					coordenadas[x][j] = null;
				}	
			}
			
			
			corta = true;
			int y = p.y;
			for (int i = 0; i < lin; i++) {
				if (coordenadas[i][y] == null) {
					continue;
				}
				if (coordenadas[i][y].valor != p.valor) {
					corta = false;
					break;
				}
			}
			if (corta) {
				for (int i = 0; i < lin; i++) {
					if (coordenadas[i][y] == null) {
						continue;
					}
					bag.remove(coordenadas[i][y]);
					coordenadas[i][y] = null;
				}	
			}
			
		}
		
		
		for (int i = 0; i < lin; i++) {
			for (int j = 0; j < col; j++) {
				if (coordenadas[i][j] != null) {
					return "NO";
				}
			}
		}
		
		return "YES";
	}
	
	static class Coord {
		final int x; 
		final int y;
		final int valor;
		
		Coord(int x, int y, int valor) {
			this.x = x;
			this.y = y;
			this.valor = valor;
		}
		@Override
		public String toString() {
			
			return "{" + x + ", " + y + "} = " + valor;
		}
		@Override
		public boolean equals(Object arg0) {
			Coord c = (Coord) arg0;
			return c.x == x && c.y == y;
		}
		@Override
		public int hashCode() {
			return x * 100 + y;
		}
	}

}

