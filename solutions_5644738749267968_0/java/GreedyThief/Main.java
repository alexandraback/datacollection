package amazon;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader fileIn = new BufferedReader(new FileReader("D-small-attempt0.in"));
		PrintWriter fileOut = new PrintWriter(new FileWriter("result"));
		String line = fileIn.readLine();
		int num = Integer.parseInt(line);
		for (int i = 1; i <= num; i++) {
			line = fileIn.readLine();
			String[] namiPart = fileIn.readLine().split(" ");
			String[] kenPart = fileIn.readLine().split(" ");
			double[] nami = new double[namiPart.length];
			double[] ken = new double[kenPart.length];
			for (int j = 0; j < nami.length; j++) {
				nami[j] = Double.parseDouble(namiPart[j]);
				ken[j] = Double.parseDouble(kenPart[j]);
			}
			fileOut.println("Case #" + i + ": " + solve(nami, ken));
		}
		fileIn.close();
		fileOut.close();

	}
	
	public static String solve(double[] nami, double[] ken) {
		Arrays.sort(nami);
		Arrays.sort(ken);
		int normalScore = nami.length;
		int k = 0;
		for (int i = 0; i < nami.length; i++) {
			while (k < ken.length && ken[k] < nami[i]) {
				k++;
			}
			if (k < ken.length) {
				k++;
				normalScore--;
			}
		}
		int trickScore = nami.length;
		int kr = ken.length - 1;
		for (int i = 0; i < nami.length; i++) {
			if (nami[i] > ken[0]) {
				break;
			}
			if (nami[i] < ken[kr]) {
				trickScore--;
				kr--;
			}
		}
		return trickScore + " " + normalScore;
	}

}
