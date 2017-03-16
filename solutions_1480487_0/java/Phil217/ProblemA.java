package problemA;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemA {
	public static double error = 0.000000001;
	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("A-practice.in"));
		 Scanner sc = new Scanner(new File("A-small.in"));
//		 Scanner sc = new Scanner(new File("A-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			int N = sc.nextInt();
			int[] values = new int[N];
			int sum = 0;
			for (int j = 0; j < values.length; j++) {
				values[j] = sc.nextInt();
				sum += values[j];
			}
			double[] results = new double[N];
			for (int j = 0; j < values.length; j++) {
				results[j] = bin(j, values, sum, 0, 1);
				results[j] = Math.round(results[j]*100000000)/1000000.0;
			}
			// do case things here
			System.out.format(Locale.US, "Case #%d: ", i);
			for (int j = 0; j < results.length; j++) {
				System.out.format(Locale.US, "%f ", results[j]);
			}
			System.out.println("");
		}
	}
	
	private static double bin(int pos, int[] values, int sum, double low, double high) {
		if (high-low<error) {
			return high;
		}
		double percent = (low+high)/2;
		double val = values[pos]+sum*percent;
		double temp = 1;
		for (int i = 0; i < values.length; i++) {
			if (values[i] < val) {
				double needed = (val-values[i])/sum;
				if (needed > temp + error) {
					return bin(pos, values, sum, low, percent);
				}
				temp -= needed;
			}
		}
		if (temp > error) {
			return bin(pos, values, sum, percent, high);
		}
		return percent;
	}
}
