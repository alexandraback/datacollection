package Round1B;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Problem1 {
	public static void main(String[] args) throws Exception {
		File f = new File("C:\\Users\\Reik Val\\Desktop\\A-large.in");
		Scanner sc = new Scanner(f);
		FileWriter salida =  new FileWriter("C:\\Users\\Reik Val\\Desktop\\salida.txt");
        PrintWriter pw = new PrintWriter(salida);
		long registros = sc.nextLong();
		ArrayList<Long> motas = new ArrayList<Long>();
		System.out.println("El tamaño de registros es : " + registros);
		for(long k = 1; k <= registros; k++) {
			motas.clear();
			long A = sc.nextLong();
			long n =  0;
			long numMotas = sc.nextLong();
			for(long i = 0; i < numMotas; i++) {
				long mota = sc.nextLong();
				if(mota < A) {
					A+=mota;
				} else {
					motas.add(mota);
				}
			}
			if(A == 1) {
				pw.println("Case #"+k+": " + motas.size());
				pw.flush();
			} else {
				Collections.sort(motas);
				for(int i = 0; i < motas.size(); i++) {
					long mota = motas.get(i);
					long cantidad = 0;
					while(A <= mota) {
						A = 2*A-1;
						n++;
						cantidad++;
					}
					A+=mota;
					motas.remove(i);
					motas.add(i, cantidad);
				}
				for(int i = motas.size()-1; i >= 0; i--) {
					long s = motas.get(i);
					if(s >= 1) {
						n = n - s + 1;
					} else {
						break;
					}
				}
				pw.println("Case #"+k+": " + (n>motas.size()?motas.size():n));
				pw.flush();
			}
		}
		pw.close();
		System.out.println("Final del programa");
	}
}
