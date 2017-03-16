import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main {
	static BufferedReader reader;
	static PrintWriter writer;
	static String fin = "A.in";
	static String fout = "A.out";

	public static void main(String[] args) throws NumberFormatException, IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(fin)));
		writer = new PrintWriter(fout);
		banana();
		reader.close();
		writer.close();
	}

	static void banana() throws NumberFormatException, IOException {
		int n = Integer.parseInt(reader.readLine());
		for (int i = 0; i < n; i++) {
			writer.print("Case #" + (i + 1) + ": ");
			solve();
		}
	}

	static void solve() throws IOException {
		String s = reader.readLine();
		String curr = "";
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			String s1 = curr + c;
			String s2 = c + curr;
			if (s1.compareTo(s2) > 0) {
				curr = s1;
			} else {
				curr = s2;
			}
		}
		writer.println(curr);
	}
}
