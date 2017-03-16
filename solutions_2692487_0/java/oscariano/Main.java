import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;


public class Main {
public static String resolver(BufferedReader entrada) throws Exception {
		String linea = entrada.readLine();
		String[] pedazos = linea.split(" ");
		long ini_size = Long.parseLong(pedazos[0]);
		int num_motes = Integer.parseInt(pedazos[1]);
		long[] motes = new long[num_motes];
		linea = entrada.readLine();
		pedazos = linea.split(" ");
		for(int i = 0; i < pedazos.length; i++) {
			motes[i] = Long.parseLong(pedazos[i]);
		}
		Arrays.sort(motes);
		int contador = 0;
		
		int[] ope = new int[num_motes];
		for(int i = 0; i < ope.length; i++) {
			ope[i] = 0;
		}
		int final_pos = motes.length - 1;
		for(int i = 0; i < motes.length; i++) {
			int max_contador = motes.length - i;
			int curr_contador = 0;
			while(ini_size <= motes[i] && curr_contador < max_contador) {
				curr_contador++;
				ini_size += ini_size - 1; 
			}
			ini_size += motes[i];
			if(curr_contador == 0)
				continue;
			if(curr_contador < max_contador) {
				ope[i] = curr_contador;
				contador += curr_contador;
			} else {
				contador += max_contador;
				final_pos = i - 1;
				break;
			}
		}
		int cont_temporal = contador;
		int min = contador;
		for(int i = final_pos; i >= 0; i--) {
			cont_temporal++;
			cont_temporal -= ope[i];
			if(cont_temporal < min)
				min = cont_temporal;
		}
		
		return Integer.toString(min);
	}
	
	public static void main(String[] args) throws Exception {
        System.out.println("?");
		BufferedReader lector = null;
		BufferedReader entrada = null;
		BufferedWriter salida = null;
		try {
			lector = new BufferedReader(new InputStreamReader(System.in));
			String tipo = lector.readLine().trim();
			entrada = new BufferedReader(new InputStreamReader(new FileInputStream(tipo + ".in")));
			salida = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(tipo + ".out")));
			int casos = Integer.parseInt(entrada.readLine());
			int contador = 1;
			while(casos > 0) {
				salida.write("Case #" + contador + ": " + resolver(entrada) + "\n");
				contador++;
				casos--;
			}
		} catch(Exception e) {
			e.printStackTrace();
		} finally {
			if(lector != null) {
				try {
					lector.close();
				} catch(Exception e) {}
			}
			if(entrada != null) {
				try {
					entrada.close();
				} catch(Exception e) {}
			}
			if(salida != null) {
				try {
					salida.close();
				} catch(Exception e) {}
			}
		}
        System.out.println("Fin");
    }
}
