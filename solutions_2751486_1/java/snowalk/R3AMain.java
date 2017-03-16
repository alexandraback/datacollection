/**
 * 
 */
package main;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author ya
 * 
 */
public class R3AMain {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(
					new FileInputStream(new File("A-large (2).in"))));
			FileWriter out = new FileWriter(new File("output.out"));

			int l = Integer.parseInt(br.readLine());
			nextstep: for (int t = 0; t < l; t++) {

				out.write("Case #" + (t + 1) + ": ");
				String line = br.readLine();
				String name = line.split(" ")[0];
				int n = Integer.parseInt(line.split(" ")[1]);

				for(int i=0;i<name.length();i++) {
					
				}
				int count = 0;
				for (int i = 0; i < name.length(); i++) {
					for (int j = i + 1; j <= name.length(); j++) {
						if (count(name.substring(i, j)) >= n)
							count++;
					}
				}

				out.write(count + "\n");

			}
			out.flush();
			out.close();
			br.close();
		} catch (NumberFormatException | IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * @param substring
	 * @return
	 */
	private static int count(String substring) {
		int count = 0;
		int max = 0;
		for (int i = 0; i < substring.length(); i++) {
			switch (substring.charAt(i)) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				if (max < count)
					max = count;
				count = 0;
				break;
			default:
				count++;
			}
		}
		if (max < count)
			max = count;
		count = 0;
		return max;
	}

}