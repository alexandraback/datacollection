package Round1C;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Problem2 {
	public static void main(String[] args) throws Exception {
		long inicio = System.currentTimeMillis();
		File f = new File("C:\\Users\\Reik Val\\Desktop\\B-small-attempt0.in");
		Scanner sc = new Scanner(f);
		FileWriter salida =  new FileWriter("C:\\Users\\Reik Val\\Desktop\\salida.txt");
	    PrintWriter pw = new PrintWriter(salida);
		int registros = sc.nextInt();
		for(int k = 1; k <= registros; k++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			String resultado = "";
			if(x > 0) {
				for(int i = 0; i < x; i++) {
					resultado += "WE";
				}
			} else {
				for(int i = 0; i > x; i--) {
					resultado += "EW";
				}
			}
			if(y > 0) {
				for(int i = 0; i < y; i++) {
					resultado += "SN";
				}
			} else {
				for(int i = 0; i > y; i--) {
					resultado += "NS";
				}
			}
			pw.println("Case #" + k + ": " + resultado);
		}
		pw.close();
		System.out.println("Fin del programa: " + ((float)(System.currentTimeMillis() - inicio)/1000f) + " secs.");
	}
}
