import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class EjercicioA {
	public static boolean prueba = false;

	public static void main(String args[]) {

		try {
			FileOutputStream fos = new FileOutputStream(
					new File("solucion.txt"));

			OutputStream os = System.out;
			if (!prueba)
				os = fos;
			Scanner s = new Scanner(new File("problema.txt"));
			int a = s.nextInt();

			for (int i = 0; i < a; i++) {
				String str = s.next();
				int m = s.nextInt();
				int cant = 0;
				int cons = 0;
				boolean paso[] = new boolean[str.length()+1];
				
				for (int j = 0; j < str.length(); j++) {

					switch (str.charAt(j)) {
						case 'a':
						case 'e':
						case 'i':
						case 'o':
						case 'u':
							cons = 0;
							break;
						default:
							cons++;
					}
					if (cons >= m){
						int ant = j+1 - cons ; 
						int dsp = str.length() - (j +1) ;
						
						if (ant == 0 || dsp == 0)
							cant +=  ant + dsp ;
						else								
								cant +=  ant + dsp  + Math.abs(ant - dsp);						
						if (!paso[cons]){
							cant++;
							paso[cons] = true;
						}						
					}
				}

				os.write(("Case #" + (i + 1) + ": " + cant + "\n").getBytes());

			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
