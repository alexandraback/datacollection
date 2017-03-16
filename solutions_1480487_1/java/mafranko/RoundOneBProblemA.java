
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;

import static java.lang.Math.*;


public class RoundOneBProblemA {

//	private static String inputFile = "round-one-a/A-small-practice.in";
	private static String inputFile = "A-large.in";

	public static void main(String[] args) throws IOException {

		System.setIn(new BufferedInputStream(new FileInputStream(inputFile)));
		Scanner sc = new Scanner(System.in);

		int numOfTestCases = sc.nextInt();

		for (int i = 1; i <= numOfTestCases; i++) {
			int N = sc.nextInt(); // numero de contestants

			double[] p = new double[N]; // pessoas
			
			double soma = 0;
			
			for (int j = 0; j < N; j++) {
				p[j] = sc.nextDouble();
				soma += p[j];
			}

			double total_points = (2.0*soma)/N;
			double total_points2 = total_points;
			double soma2 = soma;

			int i_maiores = 0;
			double[] pontuacao = new double[N];
			
			for (int k = 0; k < N; k++ ) {
				if (p[k] >= total_points) {
					pontuacao[k] = 0;
					i_maiores += 1;
					soma2 -= p[k];
					total_points = (soma2 + soma)/(N-i_maiores);
				} else {
					pontuacao[k] = -1;
				}
			}

			for (int k = 0; k < N; k++ ) {
				if (pontuacao[k] == -1) {
					pontuacao[k] = (total_points - p[k])/soma;
				}
			}
			
			System.out.printf("Case #" + i + ": ");
			for (int j = 0; j<N; j++) {
				System.out.printf("%f ", pontuacao[j] * 100);
			}
			System.out.println();
			System.out.flush();
		}
	}
}
