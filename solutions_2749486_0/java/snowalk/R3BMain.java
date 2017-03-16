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
public class R3BMain {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(
					new FileInputStream(new File("B-small-attempt0 (2).in"))));
			FileWriter out = new FileWriter(new File("output.out"));

			int l = Integer.parseInt(br.readLine());
			nextstep: for (int t = 0; t < l; t++) {

				out.write("Case #" + (t + 1) + ": ");
				String line = br.readLine();
				int x = Integer.parseInt(line.split(" ")[0]);
				int y = Integer.parseInt(line.split(" ")[1]);

				String xadd = "EW";
				if (x < 0) {
					xadd = "WE";
					x = -x;
				}
				String yadd = "SN";
				if (y < 0) {
					yadd = "NS";
					y = -y;
				}
				String all = "";
				for (int i = 0; i < x; i++)
					all += xadd;
				for (int i = 0; i < y; i++)
					all += yadd;

				out.write(all + "\n");

			}
			out.flush();
			out.close();
			br.close();
		} catch (NumberFormatException | IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * @param x
	 */
	private static int getDir(int x) {
		if (x < 0)
			x = -x;

		return (int) ((Math.sqrt(8 * x + 1) - 1) / 2);

	}
}