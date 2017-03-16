import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Main {
	public static String resolver(BufferedReader entrada) throws Exception {
		String linea = entrada.readLine();
		String[] pedazos = linea.split(" ");
		char[] texto = pedazos[0].toCharArray();
		
		int num = Integer.parseInt(pedazos[1]);
		
		int contador = 0;
		int inicio_anterior = -1;
		for(int i = 0; i <= (texto.length - num); i++) {
			boolean valido = true;
			for(int j = 0; j < num; j++) {
				char c = texto[i + j];
				if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
					valido = false;
					break;
				}
			}
			if(!valido)
				continue;
			
			int prev = i - inicio_anterior;
			int post = texto.length - (i + num) + 1;
			
			contador += prev * post;
			
			inicio_anterior = i;
		}
		
		
		
		return Integer.toString(contador);
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
