import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;

public class ProblemA {
	public static void main(String[] args) {
		BufferedReader r = null;
		BufferedWriter bw = null;
		FileWriter fw = null;

		try {
			InputStreamReader myInputStreamReader = new InputStreamReader(
					new FileInputStream("A-large.in"));
			r = new BufferedReader(myInputStreamReader);

			File file = new File("A-large.out");

			if (!file.exists()) {
				file.createNewFile();
			}

			fw = new FileWriter(file.getAbsoluteFile());
			bw = new BufferedWriter(fw);

			String line = r.readLine().toString();
			int T = Integer.parseInt(line);

			for (int t = 0; t < T; t++) {
				line = r.readLine().toString();

				String[] inputStrings = line.split("/");

				long P = Long.parseLong(inputStrings[0]);
				long Q = Long.parseLong(inputStrings[1]);
				String strAnswer = "";
				
				long quotient = 1;
				long tempQ = Q;
				while(tempQ % 2 == 0) {
					quotient = tempQ / 2;
					tempQ = tempQ / 2;
				}
				
				if (P % quotient == 0) {
					P = P / quotient;
					Q = Q / quotient;
					
					if (!isPowerOfTwo(Q)) {
						strAnswer = "impossible";
					} else {
						strAnswer = "" + nearestElfAncestor(P, Q);
					}
				} else {
					strAnswer = "impossible";
				}
				
				String strCase = "Case #" + (t + 1) + ": ";
				System.out.println(strCase + strAnswer);
				bw.write(strCase + strAnswer);
				if (t < T - 1) {
					bw.write("\n");
				}
			}

		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				r.close();
				bw.close();
				fw.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	private static boolean isPowerOfTwo(long n) {
		long product = 2;
		
		while(product < n) {
			product *= 2;
			
			if (product > n) {
				return false;
			}
		}
		return true;
	}
	
	private static int nearestElfAncestor(long P, long Q) {
		
		
		if ((2 * P) / Q >= 1) {
			return 1;
		}
		
		return (1 + nearestElfAncestor(P, Q / 2));
	}
}
