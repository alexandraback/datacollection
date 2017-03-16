package round1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;

public class ProblemA {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		Locale.setDefault(Locale.US);
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("A-large.out"));

		int t = Integer.parseInt(br.readLine());
		for (int i=1; i<=t; i++){
			String linha[] = br.readLine().split(" ");
			int a = Integer.parseInt(linha[0]);
			int b = Integer.parseInt(linha[1]);
			int c = b - a;
			double p[] = new double[a];
			
			linha = br.readLine().split(" ");
			for (int j=0; j<a; j++)
				p[j] = Double.parseDouble(linha[j]);
			
			double min = (2 * a) + c + 1;
			double prob = 1;
			
			for (int j=0; j<a; j++){
				prob *= p[j];
				int backspaces = a - (j + 1);
				int tOK = 2 * backspaces + c + 1;
				int tErro = tOK + a + c + 1;
				double n = (tOK * prob) + (tErro * (1 - prob));
				if (n < min) min = n;
			}
			int pressEnter = 1 + a + c + 1;
			if (pressEnter < min) min = pressEnter;
			
			bw.write(String.format("Case #%d: %.6f\n", i, min));
		}
		
		br.close();
		bw.close();
	}
}
