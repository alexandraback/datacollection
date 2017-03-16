package round1c;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class A {

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));

	public static void main(String[] args) throws IOException {
		int T;

		T = Integer.parseInt(br.readLine());
		for (int i = 1; i <= T; i++) {
			System.out.println("Case #" + i + ": " + resolve());
		}
	}

	private static int resolve() throws IOException {
		int n_value = 0;
		int esq, dir, ultimo_indice = 0;
		String[] linha = br.readLine().split(" ");
		String nome = linha[0];
		boolean ok;
		int n = Integer.parseInt(linha[1]);
		for (int i = 0; i <= nome.length() - n; ++i) {
			ok = true;
			for (int j = i; j < i + n; ++j) {
				if (isVowel(nome.substring(j, j + 1))) {
					ok = false;
					break;
				}
			}
			if (ok) {
				esq = i - ultimo_indice;
				dir = nome.length() - (i + n);
				n_value += (dir + 1) * (esq + 1);
				ultimo_indice = i + 1;
			}
		}
		return n_value;
	}

	private static boolean isVowel(String substring) {
		return (substring.equals("a") || substring.equals("e")
				|| substring.equals("i") || substring.equals("o") || substring
					.equals("u"));
	}
}
