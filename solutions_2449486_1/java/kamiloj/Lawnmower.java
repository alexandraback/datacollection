import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileDescriptor;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class Lawnmower {

	int max = 101;
	int matriz[][] = new int[max][max];
	int maxVert[] = new int[max];
	int maxHori[] = new int[max];

	Scanner s;

	public Lawnmower() throws NumberFormatException, IOException {
		s = new Scanner(new File("B-large.in"));
		int t = s.nextInt();
		for (int i = 1; i <= t; i++) {
			System.out.println("Case #" + i + ": " + solve());
		}
	}

	private String solve() {
		int alto = s.nextInt();
		int ancho = s.nextInt();

		for (int i = 0; i < alto; i++) {
			maxHori[i] = 0;
		}

		for (int i = 0; i < ancho; i++) {
			maxVert[i] = 0;
		}

		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				matriz[i][j] = s.nextInt();
				maxHori[i] = Math.max(maxHori[i], matriz[i][j]);
				maxVert[j] = Math.max(maxVert[j], matriz[i][j]);
			}
		}

		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				if (matriz[i][j] < maxHori[i] && matriz[i][j] < maxVert[j])
					return "NO";
			}
		}

		return "YES";
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		FileOutputStream fdout = new FileOutputStream(new File("salida.out"));
		BufferedOutputStream bos = new BufferedOutputStream(fdout, 1024);
		PrintStream ps = new PrintStream(bos, false);
		System.setOut(ps);
		new Lawnmower();
		ps.close();
	}
}
