package codeJam2014;
import java.util.*;
import java.util.Scanner;
import java.io.*;

public class DeceitfulWar {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File(args[0]));
		FileWriter out = new FileWriter("war.txt");
		
		int T = in.nextInt();
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int N = in.nextInt();

			double[] naomi = new double[N], ken = new double[N];
			for (int i = 0; i < N; i++) {
				naomi[i] = in.nextDouble();
			}
			for (int i = 0; i < N; i++) {
				ken[i] = in.nextDouble();
			}
			
			Arrays.sort(naomi);
			Arrays.sort(ken);
			
			/*int j = N - 1, l = N - 1, war = 0;
			while (j > 0) {
				if (naomi[j] > ken[l]) {
					war++;
					j--;
				}
				else {
					j--;
					l--;
				}
			}*/
			
			int n1 = 0, k1 = 0, war = 0;
			while (n1 < N && k1 < N) {
				if (naomi[n1] < ken[k1]) {
					war++;
					n1++;
					k1++;
				}
				else {
					k1++;
				}
			}
			war = N - war;
			
			int n = 0, k = 0, deceit = 0;
			while (n < N && k < N) {
				if (naomi[n] > ken[k]) {
					deceit++;
					n++;
					k++;
				}
				else {
					n++;
				}
			}
			System.out.println("Case #" + caseNum + ": " + deceit + " " + war);
			out.write("Case #" + caseNum + ": " + deceit + " " + war + "\n");
			
		}
		in.close();
		out.close();
	}

}
