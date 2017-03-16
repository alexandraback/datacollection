package round1b;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/*
 * Google Code Jam 2014
 * Round 1B
 * raguenets@gmail.com
 * Usage : java NewLotteryGame inputFileName outputFileName
 */
public class NewLotteryGame {
	public static final String FEGLA_WON = "Fegla Won";

	public static void main(String[] args) {
		int T = 0;
		int A = 0;
		int B = 0;
		int K = 0;

		if (args.length == 2) {
			String inputFilename = args[0];
			File finput = new File(inputFilename);
			String outputFilename = args[1];
			File foutput = new File(outputFilename);
			Scanner scanner = null;
			BufferedWriter bw = null;
			try {
				bw = new BufferedWriter(new FileWriter(foutput));
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			if (finput.exists()) {
				try {
					scanner = new Scanner(finput);
					scanner.useLocale(Locale.US);
					// Reads first line : number of Tests
					if (scanner.hasNextInt()) {
						T = scanner.nextInt();
					}
					for (int i = 0; i < T; i++) {
						// Read number of flies
						A = scanner.nextInt();
						B = scanner.nextInt();
						K = scanner.nextInt();
						bw.write("Case #" + (i + 1) + ": "
								+ newLotteryGame(A,B,K) + "\n");
					}
				} catch (FileNotFoundException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} finally {
					try {
						bw.close();
						if (scanner != null) {
							scanner.close();
						}
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
		}
	}

	public static String newLotteryGame(int A,int B,int K) {
		System.err.println(A+" "+B+" "+K);
		int cases = 0;
		for (int i = 0; i < A; i++) {
			for (int j=0; j < B; j++) {
				int r = i & j;
				if (r>=0 && r < K) {
					cases++;
				}
			}
		}
		return Integer.toString(cases);
	}

}
