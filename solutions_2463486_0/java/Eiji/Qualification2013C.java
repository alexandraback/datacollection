package codejam2013.qualification.c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Qualification2013C {
	public static final String FOLDER = Qualification2013C.class.getSimpleName();
	
	static long[] fairAndSquare = new long[]{1L, 4L, 9L, 121L, 484L, 10201L, 12321L, 14641L, 40804L, 44944L, 1002001L, 1234321L, 4008004L, 100020001L, 102030201L, 104060401L, 121242121L, 123454321L, 125686521L, 400080004L, 404090404L, 10000200001L, 10221412201L, 12102420121L, 12345654321L, 40000800004L, 1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L, 1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L, 1234567654321L, 4000008000004L, 4004009004004L};
	
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader input = new BufferedReader(new FileReader(FOLDER+"/input.txt"));
		BufferedWriter output = new BufferedWriter(new FileWriter(FOLDER+"/output.txt"));

		int n = Integer.parseInt(input.readLine());
		
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

	private static String solve(BufferedReader input) throws IOException {
		String [] entrada = input.readLine().split(" ");
		
		long de = Long.valueOf(entrada[0]);
		long ate = Long.valueOf(entrada[1]);
		
		int cont = 0;
		int pos = 0;
		
		while (pos < fairAndSquare.length && fairAndSquare[pos] <= ate) {
			if (fairAndSquare[pos] >= de) {
				cont++;
			}
			pos++;
		}
		
		
		
		return cont + "";
	}

}

