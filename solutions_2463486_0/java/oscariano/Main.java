import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.ArrayList;


public class Main {
	private static int count;
	private static BigInteger[] list;
	private static void precompute() {
		count = 0;
		list = new BigInteger[41551];
		list[count++] = new BigInteger("1");
		list[count++] = new BigInteger("4");
		list[count++] = new BigInteger("9");
		for(int i = 2; i <= 50; i++)
			precompute(i);
		System.out.println(count);
	}
	private static void precompute(int length) {
		int middle = length / 2;
		boolean extra  = length % 2 == 1;
		char[] arreglo = new char[length];
		for(int i = 0; i < length; i++)
			arreglo[i] = '0';
		int last_pos = length - 1;
		arreglo[0] = '1';
		arreglo[last_pos] = arreglo[0];
		int one_count = 1;
		while(true) {
			BigInteger numero = new BigInteger(new String(arreglo));
			numero = numero.multiply(numero);
			list[count++] = numero;
			if(extra) {
				switch(arreglo[middle]) {
				case '0':
					arreglo[middle] = '1';
					continue;
				case '1':
					if(one_count <= 2) {
						arreglo[middle] = '2';
						continue;
					}
					arreglo[middle] = '0';
					break;
				case '2':
					arreglo[middle] = '0';
					break;
				}
			}
			int pos = middle - 1;
			boolean valid = false;
			while(!valid && pos > 0) {
				if(arreglo[pos] == '0') {
					if(one_count < 4) {
						one_count++;
						arreglo[pos] = '1';
						arreglo[last_pos - pos] = arreglo[pos];
						valid = true;
					}
				} else {
					one_count--;
					arreglo[pos] = '0';
					arreglo[last_pos - pos] = arreglo[pos];
				}
				pos--;
			}
			if(!valid)
				break;
		}
		for(int i = 0; i < length; i++)
			arreglo[i] = '0';
		arreglo[0] = '2';
		arreglo[last_pos] = arreglo[0];
		
		BigInteger numero = new BigInteger(new String(arreglo));
		numero = numero.multiply(numero);
		list[count++] = numero;
		if(extra) {
			arreglo[middle] = '1';
			numero = new BigInteger(new String(arreglo));
			numero = numero.multiply(numero);
			list[count++] = numero;
		}
		if(length == 50) {
			System.out.println(numero.toString());
			System.out.println("L" + numero.toString().length());
		}
	}
	public static String resolver(String[] parametros) {
		BigInteger lower_bound = new BigInteger(parametros[0]);
		BigInteger upper_bound = new BigInteger(parametros[1]);
		int inicio = -1;
		int pos = 0;
		while(pos < list.length && list[pos] != null && upper_bound.compareTo(list[pos]) >= 0 ) {
			if(inicio < 0) {
				if(lower_bound.compareTo(list[pos]) <= 0)
					inicio = pos;
			}
			pos++;
		}
		if(inicio < 0)
			return "0";
		
		return Integer.toString(pos - inicio);
		
	}
	
	public static void main(String[] args) throws Exception {
		precompute();
        System.out.println("?");
        BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
        String tipo = lector.readLine().trim();
        BufferedReader entrada = new BufferedReader(new InputStreamReader(new FileInputStream(tipo + ".in")));
        BufferedWriter salida = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(tipo + ".out")));
        int casos = Integer.parseInt(entrada.readLine());
        int contador = 1;
        while(casos > 0) {
        	String[] parametros = entrada.readLine().trim().split(" ");
            salida.write("Case #" + contador + ": " + resolver(parametros) + "\n");
            contador++;
            casos--;
        }
        entrada.close();
        salida.close();
        System.out.println("Fin");
    }
	
	/*
	private static boolean esPalindromo(String numero) {
		int length = numero.length() - 1;
		int mitad = numero.length() / 2;
		for(int i = 0; i < mitad; i++) {
			if(numero.charAt(i) != numero.charAt(length- i))
				return false;
		}
		return true;
	}
	private static void precompute2(int length) {
		int mitad = length / 2;
		boolean extra = length % 2 == 1;
		char[] arreglo = new char[length];
		for(int i = 0; i < length; i++)
			arreglo[i] = '0';
		arreglo[0] = '1';
		int last_pos = length - 1;
		arreglo[last_pos] = '1';
		while(arreglo[0] <= '9') {
			BigInteger numero = new BigInteger(new String(arreglo));
			numero = numero.multiply(numero);
			if(esPalindromo(numero.toString())) {
				System.out.println(new String(arreglo) + " -> " + numero.toString());
				count++;
			}
			
			//System.out.println(numero);
			int pos = mitad;
			if(!extra)
				pos--;
			arreglo[pos]++;
			arreglo[last_pos - pos] = arreglo[pos];
			while(arreglo[pos] > '9' && pos > 0) {
				arreglo[pos] = '0';
				arreglo[last_pos - pos] = arreglo[pos];
				pos--;
				if(pos < 0)
					break;
				arreglo[pos]++;
				arreglo[last_pos - pos] = arreglo[pos];
			}
		}
		
	}
	*/
}
