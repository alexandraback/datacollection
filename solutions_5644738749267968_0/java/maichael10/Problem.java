/**
 * 
 */
package problem;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

import general.IO;

/**
 * @author michael
 *
 */
public class Problem {

	/**
	 * Metodo main que corre el programa.
	 * @param args Argumentos con los que es llamado el programa.
	 * @throws Exception Si hubo excepcion.
	 */
	public static void main(String args[]) throws Exception {

		String file = "D-small-attempt3";

		Object[] pairIO = IO.openIO(file);
		BufferedReader red = (BufferedReader) pairIO[0];
		PrintWriter wr = (PrintWriter) pairIO[1];


		int problemas = Integer.parseInt(red.readLine());
		outer: for (int w = 0 ; w < problemas ; w++) {
			int numBlock = Integer.parseInt(red.readLine());
			double nBl[] = new double[numBlock];
			double kBl[] = new double[numBlock];
			String p1 [] = red.readLine().split(" ");
			String p2 [] = red.readLine().split(" ");
			for (int i = 0 ; i < numBlock ; i++) {
				nBl[i] = Double.parseDouble(p1[i]);
				kBl[i] = Double.parseDouble(p2[i]);
			}
			Arrays.sort(nBl);
			Arrays.sort(kBl);
			
			// Resolve deceive war
			int h = 0;
			int deceiveWar = 0;
			for (int i = 0 ; i < numBlock ; i++) {
				if (nBl[i] > kBl[h]) {
					deceiveWar++;
					h++;
				}
			}
			
			// Resolve war
			int war = 0;
			int bL = 0;
			for (int i = numBlock-1 ; i >= 0 ; i--) {
				int j = numBlock -1;
				while ( kBl[j] == 0 ) j--;
				if (nBl[i] > kBl[j]) {
					war++;
					kBl[bL++] = 0;
					continue;
				}
				int before = j;
				while( j >= 0 && (kBl[j] == 0 || kBl[j] > nBl[i])) {
					if (kBl[j]!=0) before = j;
					j--;
				}
				
				kBl[before] = 0;
			}
			
			wr.println("Case #" + (w+1) + ": " + deceiveWar + " " + war);
		}
	}
}
