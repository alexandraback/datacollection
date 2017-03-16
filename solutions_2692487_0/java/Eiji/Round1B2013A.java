package codejam2013.round1b.a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Round1B2013A {
	public static final String FOLDER = Round1B2013A.class.getSimpleName();
	
	public static void main(String[] args) throws Exception {
//		BufferedReader input = new BufferedReader(new FileReader(FOLDER+"/input.txt"));
		BufferedWriter output = new BufferedWriter(new FileWriter(FOLDER+"/output.txt"));
		Scanner input = new Scanner(new File(FOLDER+"/input.txt"));

		int n = input.nextInt();
		
		for (int i = 0; i < n; i++) {
			
			StringBuilder resposta = new StringBuilder();
			String solucao = solve(input);
			resposta.append("Case #").append(i +1).append(": ").append(solucao).append("\n");
			String texto = resposta.toString();
			output.write(texto);
			System.out.print(texto);
		}
		input.close();
		output.close();

	}

	private static String solve(Scanner input) throws IOException {
		final long A = input.nextLong();
		final int N = input.nextInt();
		
		final long[] MOTES = new long[N];
		for (int i = 0; i < N; i++) {
			MOTES[i] = input.nextLong();
		}
		
		Arrays.sort(MOTES);
		
		long size = A;
		
		int valorMax = N;
		int cont = 0;
		int i = 0;
		if (size  == 1) 
			return "" + N;
		while (i < N) {
			if(MOTES[i] < size) {
				size+= MOTES[i];
				i++;
				continue;
			}
			
			// se compensar remover prox, o valor seria o prox + restante de motes;
			if (cont + (N - i) < valorMax) {
				valorMax = cont + (N - i); 
			}
			
			// acrescenta um menor
			size += (size - 1);
			cont++;
		}
		
		if (valorMax < cont) 
			cont = valorMax;
		return "" + cont;
	}
	
}

