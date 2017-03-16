package q1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Question1 {

	static String filename = "A-small-attempt0.in";
	char[][] grid;

	public static void main(String[] args) {
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(filename));
			String line = br.readLine();
			int T = Integer.parseInt(line);
			for (int i = 1; i <= T; i++) {
				line = br.readLine();
				String temp[] = line.split("\\s");
				String name = temp[0];
				int n = Integer.parseInt(temp[1]);

				Pattern pattern = Pattern.compile("[a-z]*[b-df-hj-np-tv-z]{"
						+ n + "}[a-z]*");
				int count = 0;
				Matcher matcher = pattern.matcher(name);
				for (int s = 0; s < name.length(); s++) {
					for (int e = name.length(); e > s; e--) {
						matcher = pattern.matcher(name.substring(s, e));
						while (matcher.find()) {
							count++;
						}
					}
				}

				System.out.println("Case #" + i + ": " + count);
			}

			br.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
