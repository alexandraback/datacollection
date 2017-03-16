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
public class A {

	public static void main(String[] args) throws Exception {
		final Scanner in = new Scanner("IO_2016/inputs/A-large.in");
		final PrintWriter out = new PrintWriter("IO_2016/outputs/A-large.out");

		int t = in.nextInt();

		StringBuilder sb = new StringBuilder();
		
		for (int i = 1; i <= t; i++) {
			in.nextLine();
			out.printf("Case #%d: ", i);

			int first, last;
			
			sb.append(in.line.charAt(0));
			
			first = last = in.line.charAt(0);
			
			for(int j = 1; j < in.line.length();j++){
				if(in.line.charAt(j) >= first){
					sb.insert(0, in.line.charAt(j));
					first = in.line.charAt(j);
				}
				else{
					sb.append(in.line.charAt(j));
					last = in.line.charAt(j);
				}
			}
			
			out.println(sb.toString());
			sb.setLength(0);
		}

		out.close();
	}

	static void ListPermutations(char[] str) {
		RecursivePermute(str, 0);
	}

	static void RecursivePermute(char[] str, int k) {
		int i, len;

		len = str.length;
		if (k == len) {
			for(int j = 0; j < str.length;j++)
				System.out.print(str[j]);
		} else {
			for (i = k; i < len; i++) {
				ExchangeCharacters(str, k, i);
				RecursivePermute(str, k + 1);
				ExchangeCharacters(str, i, k);
			}
		}
	}

	static void ExchangeCharacters(char[] str, int p1, int p2) {
		char tmp;
		tmp = str[p1];
		str[p1] = str[p2];
		str[p2] = tmp;
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
