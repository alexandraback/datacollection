import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class GCJr11 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		double[] hold = new double[n];
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			double[] probs = new double[a];
			for (int j = 0; j < a; j++) {
				probs[j] = sc.nextDouble();
			}
			hold[i] = Math.min(m1(a, b, probs), Math.min(m2(a, b, probs),
					m3(a, b, probs)));
		}

		try {
			// Create file
			FileWriter fstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(fstream);
			for (int i = 0; i < n; i++) {
				out.write("Case #" + (1 + i) + ": " + hold[i]);
				if (i < n - 1)
					out.write("\n");
			}
			out.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}

	static double m1(int a, int b, double[] input) {
		double correct = 1;
		for(int i = 0;i<input.length;i++){
			correct *= input[i];
		}
		System.out.println("m1 " + (correct*(b-a+1)+(1-correct)*(2*(b+1)-a)));
		return correct*(b-a+1)+(1-correct)*(2*(b+1)-a);
	}

	static double m2(int a, int b, double[] input) {
		double min = a+b+1;
		for(int i = 0;i<=a;i++){
			double base = 1;
			for(int j=0;j<i;j++){
				base *= input[j];
			}
			double total = base*(2*(a-i)+(b-a)+1)+(1-base)*(2*(a-i)+(b-a)+1+b+1);
			//System.out.println(i+" "+ base + " " +total);
			min = Math.min(min, total);
				
		}
		//System.out.println("m2 " + min);
		return min;
	}

	static double m3(int a, int b, double[] input) {
		//System.out.println("m3 " + (a + b + 1));
		return b+2;
	}
}
