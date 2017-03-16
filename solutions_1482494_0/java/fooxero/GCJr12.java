import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class GCJr12 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] hold = new String[n];
		for (int i = 0; i < n; i++) {
			int runs = 0, stars = 0, a = sc.nextInt();
			boolean[][] done = new boolean[a][2];
			int[][] complete = new int[a][2];
			for (int j = 0; j < a; j++) {
				complete[j][0] = sc.nextInt();
				complete[j][1] = sc.nextInt();
			}
			boolean cycle = true;
			while(cycle){
				boolean found = false;
				for (int j = 0; j < a; j++) {
					if (complete[j][1] <= stars && !done[j][1]) {
						if (done[j][0] == true){
							stars++;
							//System.out.println("1-1 " + stars);
						}
						else{
							stars += 2;
							//System.out.println("1-2 " + stars);
							}
						done[j][1] = true;
						found = true;
						runs++;
						j=a;
					}
				}
				if (found != true)
					for (int j = 0; j < a; j++) {
						if (complete[j][0] <= stars && !done[j][0] && !done[j][1]) {
							stars += 1;
							done[j][0] = true;
							found = true;
							runs++;
							j=a;
							//System.out.println("2-1 " + stars);
						}
					}
				if(found != true){
					hold[i] = "Too Bad";
					cycle = false;
				}
				if(stars == a*2)
					cycle = false;
			}
			hold[i] = Integer.toString(runs);
		}

		try {
			// Create file
			FileWriter fstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(fstream);
			for (int i = 0; i < n; i++) {
				if(hold[i].matches("0"))
					hold[i] = "Too Bad";
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
		for (int i = 0; i < input.length; i++) {
			correct *= input[i];
		}
		// System.out.println("m1 " +
		// (correct*(b-a+1)+(1-correct)*(2*(b+1)-a)));
		return correct * (b - a + 1) + (1 - correct) * (2 * (b + 1) - a);
	}

	static double m2(int a, int b, double[] input) {
		double min = a + b + 1;
		for (int i = 0; i <= a; i++) {
			double base = 1;
			for (int j = 0; j < i; j++) {
				base *= input[j];
			}
			double total = base * (2 * (a - i) + (b - a) + 1) + (1 - base)
					* (2 * (a - i) + (b - a) + 1 + b + 1);
			// System.out.println(i+" "+ base + " " +total);
			min = Math.min(min, total);

		}
		// System.out.println("m2 " + min);
		return min;
	}

	static double m3(int a, int b, double[] input) {
		// System.out.println("m3 " + (a + b + 1));
		return b + 2;
	}
}
