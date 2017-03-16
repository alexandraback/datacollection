import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class EqualSums {

	static int n = 20;
	static int[] m = new int[20];
	static boolean ok = false;
	static PrintWriter output;

	public static void main(String[] arg) throws NumberFormatException,
			IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File(
				"input.txt")));
		output = new PrintWriter(new File("output.txt"));

		int cases = Integer.valueOf(reader.readLine());
		for (int c = 0; c < cases; c++) {
			StringTokenizer tkn = new StringTokenizer(reader.readLine());
			System.out.println( tkn.nextToken() ); 
			
			int[] data = new int[20];
			for (int i = 0; i < 20; i++) {
				data[i] = Integer.valueOf(tkn.nextToken());
			}
			ok = false;
			output.println("Case #" + (c+1) + ": ");
			go(0, data);
			if (!ok) {
				output.println("Impossible");
			}
		}
		output.close(); 

	}

	public static void go(int i, int[] data) {
		if (i == n) {
			int unu = 0;
			int doi = 0;
			for (int j = 0; j < data.length; j++) {
				if (m[j] == 1) {
					unu+= data[j];
				}
				if (m[j] == 2) {
					doi+= data[j];
				}
			}

			if (unu != 0 && unu == doi) {
				for (int j = 0; j < data.length; j++) {
					if (m[j] == 1) {
						output.print(data[j] + " ");
					}
				}
				output.println();
				for (int j = 0; j < data.length; j++) {
					if (m[j] == 2) {
						output.print(data[j] + " ");
					}
				}
				output.println(); 
				ok = true;
			}

			return;
		} else {
			for (int k = 0; k <= 2; k++) {
				m[i] = k;
				if (!ok) {
					go(i + 1, data);
				}
			}

		}
	}

}
