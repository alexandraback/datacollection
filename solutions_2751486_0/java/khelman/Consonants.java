package pl.helman;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Consonants {

	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\cj\\cons.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter f0 = new FileWriter("d:\\cj\\cons.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		for (int c = 1; c <= t; c++) {
			System.out.println(c);

			line = br.readLine();
			String[] elems = line.split(" ");

			String name = elems[0];

			int n = Integer.parseInt(elems[1]);
			int ret = 0;

			for (int i = 0; i <= name.length(); i++) {
				for (int j = i + 1; j <= name.length(); j++) {
					int count = 0;
					int max = 0;
					for (int k = i; k < j; k++) {
						if (!isVowel(name.charAt(k))) {
							count++;
							if (count > max) {
								max = count;
							}
						} else {
							count = 0;
						}
					}

					if (max >= n) {
						ret++;
					}
				}
			}

			System.out.println("Case #" + c + ": " + ret);
			f0.write("Case #" + c + ": " + ret + "\r\n");
		}

		fr.close();
		f0.close();
	}

	private static boolean isVowel(char ch) {
		return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
	}

}
