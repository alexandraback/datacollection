package round1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Oliver
 * 
 */
public class NewLotteryGame {

	private static BufferedReader br;
	private static BufferedWriter bw;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			// Open input file.
			br = new BufferedReader(new FileReader("B-small-attempt0.in"));

			// Open output file.
			bw = new BufferedWriter(new FileWriter("output.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		} catch (IOException e) {
			e.printStackTrace();
		}

		try {
			// Initialise input and read number of cases.
			int testCases = Integer.parseInt(br.readLine());

			// For each test case.
			analyseTestCases(testCases);
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				br.close();
				bw.flush();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	private static void analyseTestCases(int testCases) throws IOException {
		for (int i = 1; i <= testCases; i++) {
			String[] s = br.readLine().split(" ");

			int a = Integer.parseInt(s[0]);
			int b = Integer.parseInt(s[1]);
			int k = Integer.parseInt(s[2]);

			int c = 0;
			
			for (int ia = 0; ia < a; ia++) {
				for (int ib = 0; ib < b; ib++) {
					int and = ia & ib;
					
					if (and < k) {
						c ++;
					}
				}
			}
			
			write("Case #" + i + ": " + c + "\n");
		}
	}

	private static void write(String s) {
		try {
			bw.write(s);
			System.out.print(s);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
