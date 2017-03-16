import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;


public class Main {
	private static HashSet<String> dict;

	public static int rec_1 (char[] letras, int curr_position, int min_distance) {
		if(curr_position >= letras.length)
			return 0;
		int bound = curr_position + 10;
		if(bound > letras.length)
			bound = letras.length;
		for(int tBound = bound; tBound > curr_position; tBound--) {
		//for(int tBound = curr_position + 1; tBound <= bound; tBound++) {
			if(dict.contains(String.valueOf(letras, curr_position, tBound - curr_position))) {
				int min = min_distance - (tBound  - curr_position);
				if(min < 0)
					min = 0;
				int probar = rec_1(letras, tBound, min);
				if(probar >= 0)
					return probar;
			}
		}
		for(int tBound = bound; tBound > curr_position; tBound--) {
		//for(int tBound = curr_position + 1; tBound <= bound; tBound++) {
			for(int i = curr_position + min_distance; i < tBound; i++) {
				char anterior = letras[i];
				letras[i] = '#';
				if(dict.contains(String.valueOf(letras, curr_position, tBound - curr_position))) {
					int min = 5 - (tBound  - i);
					if(min < 0)
						min = 0;
					int probar = rec_1(letras, tBound, min);
					if(probar >= 0)
						return probar + 1;
				}
				
				letras[i] = anterior;
			}
		}
		
		
		for(int tBound = bound; tBound > curr_position; tBound--) {
		//for(int tBound = curr_position + 1; tBound <= bound; tBound++) {
			for(int i = curr_position + min_distance; i < tBound - 5; i++) {
				char anterior = letras[i];
				letras[i] = '#';
				for(int j = i + 5; j < tBound; j++) {
					char anterior_2 = letras[j];
					letras[j] = '#';
					
					if(dict.contains(String.valueOf(letras, curr_position, tBound - curr_position))) {
						int min = 5 - (tBound  - j);
						if(min < 0)
							min = 0;
						int probar = rec_1(letras, tBound, min);
						if(probar >= 0)
							return probar + 2;
					}
					
					letras[j] = anterior_2;
				}
				
				letras[i] = anterior;
			}
		}
		return -1;
	}
	
	public static int rec_2 (char[] letras, int curr_position, int min_distance) {
		if(curr_position >= letras.length)
			return 0;
		int bound = curr_position + 10;
		if(bound > letras.length)
			bound = letras.length;
		//for(int tBound = bound; tBound > curr_position; tBound--) {
		for(int tBound = curr_position + 1; tBound <= bound; tBound++) {
			if(dict.contains(String.valueOf(letras, curr_position, tBound - curr_position))) {
				int min = min_distance - (tBound  - curr_position);
				if(min < 0)
					min = 0;
				int probar = rec_2(letras, tBound, min);
				if(probar >= 0)
					return probar;
			}
		}
		//for(int tBound = bound; tBound > curr_position; tBound--) {
		for(int tBound = curr_position + 1; tBound <= bound; tBound++) {
			for(int i = curr_position + min_distance; i < tBound; i++) {
				char anterior = letras[i];
				letras[i] = '#';
				if(dict.contains(String.valueOf(letras, curr_position, tBound - curr_position))) {
					int min = 5 - (tBound  - i);
					if(min < 0)
						min = 0;
					int probar = rec_2(letras, tBound, min);
					if(probar >= 0)
						return probar + 1;
				}
				
				letras[i] = anterior;
			}
		}
		
		
		//for(int tBound = bound; tBound > curr_position; tBound--) {
		for(int tBound = curr_position + 1; tBound <= bound; tBound++) {
			for(int i = curr_position + min_distance; i < tBound - 5; i++) {
				char anterior = letras[i];
				letras[i] = '#';
				for(int j = i + 5; j < tBound; j++) {
					char anterior_2 = letras[j];
					letras[j] = '#';
					
					if(dict.contains(String.valueOf(letras, curr_position, tBound - curr_position))) {
						int min = 5 - (tBound  - j);
						if(min < 0)
							min = 0;
						int probar = rec_2(letras, tBound, min);
						if(probar >= 0)
							return probar + 2;
					}
					
					letras[j] = anterior_2;
				}
				
				letras[i] = anterior;
			}
		}
		return -1;
	}
	
	public static String resolver(BufferedReader entrada, int c) throws Exception {
		String linea = entrada.readLine();
		char[] letras = linea.toCharArray();
		int contador = rec_1(letras, 0, 0);
		letras = linea.toCharArray();
		
		int contador_2 = rec_2(letras, 0, 0);
		
		if(contador == -1 && contador_2 == -1)
			System.out.println("Error fatal");
		
		if(contador == -1)
			return Integer.toString(contador_2);
		if(contador_2 == -1)
			return Integer.toString(contador);
		if(contador < contador_2)
			return Integer.toString(contador);
		else
			return Integer.toString(contador_2);
		
	}
	
	public static void loadDictionary() {
		BufferedReader lector = null;
		try {
			dict = new HashSet<String>();
			lector = new BufferedReader(new InputStreamReader(new FileInputStream("dict.txt")));
			String linea = null;

			int min = 0;
			while((linea = lector.readLine()) != null) {
				if(linea.length() == 0)
					continue;
				if(linea.length() > min)
					min = linea.length();
				dict.add(linea);
				char[] letras = linea.toCharArray();
				for(int i = 0; i < linea.length(); i++) {
					char anterior = letras[i];
					letras[i] = '#';
					dict.add(String.copyValueOf(letras));
					for(int j = i + 5; j < linea.length(); j++) {
						char anterior_2 = letras[j];
						letras[j] = '#';
						dict.add(String.copyValueOf(letras));
						letras[j] = anterior_2;
					}
					letras[i] = anterior;
				}
				
			}
		} catch(Exception e) {
			e.printStackTrace();
		}
		if(lector != null)
			try {
				lector.close();
			} catch(Exception e) {}
	}
	public static void main(String[] args) throws Exception {
		loadDictionary();
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
				salida.write("Case #" + contador + ": " + resolver(entrada, contador) + "\n");
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
