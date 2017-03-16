package round1_A;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

/* *****************************************************************************************************************************
 * Juiz: Google Code Jam
 * Problema: 
 * URL: 
 * Descrição: 
 *******************************************************************************************************************************/
public class B {

	public static void main(String[] args) throws Exception {
		final Scanner in = new Scanner("IO_2016/inputs/B-small-attempt0.in");
		final PrintWriter out = new PrintWriter("IO_2016/outputs/B-small-attempt0.out");

		int t = in.nextInt();

		for (int i = 1; i <= t; i++) {
			in.nextLine();
			out.printf("Case #%d: ", i);

			int n = in.nextInt();

			int[] vet = new int[2501];

			for (int x = 0; x < 2 * n - 1; x++) {
				in.nextLine();
				for (int y = 0; y < n; y++) {
					vet[in.nextInt()]++;
				}
			}
			
			for (int j = 1; j < vet.length; j++) {
				if(vet[j] > 0 && vet[j] % 2 != 0){
					out.print(j);
					n--;
					
					if(n > 0)
						out.print(" ");
				}
			}
			
			out.println();
		}

		out.close();
	}

	private static class Scanner {
		private final BufferedReader in;
		private String line = "";
		private int pos;
		private int lineNo;

		public Scanner(String Arquive) throws Exception {
			in = new BufferedReader(new FileReader(Arquive));
			nextLine();
		}

		public void close() {
			try {
				in.close();
			} catch (IOException e) {
				throw new AssertionError("Failed to close with " + e);
			}
		}

		public boolean hasNext() throws IOException {
			return in.ready();
		}

		public String next() {
			if (pos != 0) {
				pos++;
			}
			StringBuilder sb = new StringBuilder();
			while (pos < line.length() && line.charAt(pos) > ' ')
				sb.append(line.charAt(pos++));
			return sb.toString();
		}

		public int nextInt() {
			int num, total = 0;
			boolean negativo = false;

			if (pos != 0) {
				pos++;
			}
			if (pos < line.length() && line.charAt(pos) == '-') {
				negativo = true;
				pos++;
			}

			while (pos < line.length() && line.charAt(pos) > ' ') {
				num = line.charAt(pos++) - '0';
				total *= 10;
				total += num;
			}
			if (negativo)
				total *= -1;

			return total;
		}

		public void nextLine() {
			try {
				line = in.readLine();
			} catch (IOException e) {
				throw new AssertionError("Failed to read line with " + e);
			}
			pos = 0;
			lineNo++;
		}

		public long nextLong() {
			long num, total = 0;
			boolean negativo = false;
			if (pos != 0) {
				pos++;
			}
			if (pos < line.length() && line.charAt(pos) == '-') {
				negativo = true;
				pos++;
			}
			while (pos < line.length() && line.charAt(pos) > ' ') {
				num = line.charAt(pos++) - '0';
				total *= 10;
				total += num;
			}
			if (negativo)
				total *= -1;
			return total;
		}
	}
}
