package qual2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class A {
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("src/qual2012/A-small-3.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("src/qual2012/A-small-3.out"));

		int cases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= cases; i++) {
			writer.write("Case #" + i + ": ");
			new A().solve(reader, writer);
		}
		writer.close();
	}

	private String encoded = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvyeq";
	private String decoded = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upaoz";

	private void solve(BufferedReader reader, BufferedWriter writer) throws IOException {
		char[] map = new char[128];
		boolean[] left = new boolean[128];
		for (int i = 'a'; i <= 'z'; i++) {
		    left[i] = true;
		}

		for (int i = 0; i < encoded.length(); i++) {
			left[decoded.charAt(i)] = false;
			if (map[encoded.charAt(i)] != 0 && map[encoded.charAt(i)] != decoded.charAt(i))
				throw new RuntimeException();
		    map[encoded.charAt(i)] = decoded.charAt(i);
		}
		for (int i = 'a'; i <= 'z'; i++) {
			if (map[i] == 0) {
				for (int j = 'a'; j <= 'z' ; j++) {
				    if (left[j]) {
						map[i] = (char) j;
					}
				}
			}
		}


		String input = reader.readLine();
		for (int i = 0; i < input.length(); i++) {
			char out = map[input.charAt(i)];
			if (out < 32 || out > 126) {
				throw new RuntimeException();
			}
			writer.write(out);
		}
		writer.write("\n");
	}

}
