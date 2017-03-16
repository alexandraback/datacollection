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

		String file = "C-small-attempt5";
		//String file = "test";

		Object[] pairIO = IO.openIO(file);
		BufferedReader red = (BufferedReader) pairIO[0];
		PrintWriter wr = (PrintWriter) pairIO[1];


		int problemas = Integer.parseInt(red.readLine());
		outer: for (int w = 0 ; w < problemas ; w++) {
			wr.println("Case #" + (w+1) + ":" );
			String p1 [] = red.readLine().split(" ");
			int R = Integer.parseInt(p1[0]);
			int C = Integer.parseInt(p1[1]);
			int M = Integer.parseInt(p1[2]);

			int NM = R*C - M;

			for (int i = 1 ; i <=C ; i++) {
				// Si considero una columna de 1 y el numero de minas es mayor a 1
				if (i==1 && ((C !=1 && NM > 1) )) continue;
				// Si considero una fila de 1 y el numero de minas es mayor a 1
				if (NM <= i && ((R!=1 && NM>1))) continue;
				// Si se necesitan mas filas de las que hay.
				if ((NM%i==0 &&  NM/i> R) || (NM%i!=0 && ((int)NM/i)+1 > R)) continue;
				// Hay dos filas y la ultima no esta llena no hay forma de emparejar.
				if (NM%i!=0 && ((int)NM/i)+1==2) continue;
				
				// Si la ultima fila tiene solo 1 y no hay forma de emparejar
				if (NM%i == 1 && (i<3 || ((int)NM/i)+1 < 4)) continue;	
				
				int emparejar = 0;
				if (NM%i == 1) emparejar = i/2;
				
				int numNoMin = NM;
				for (int y = 0 ; y < R ; y++) {
					for (int x = 0 ; x < C ; x++) {
						if (y==0 && x==0) {
							wr.print("c");
							numNoMin--;
						}
						else if (x > i-1)
							wr.print("*");
						else if (NM%i == 1 && y > R-3 && emparejar != 0 && x > emparejar)
							wr.print("*");
						else if (numNoMin > 0) {
							wr.print(".");
							numNoMin--;
						}
						else
							wr.print("*");
					}
					wr.println("");
				}
				continue outer;
			}
			wr.println("Impossible" );
		}
	}
}

