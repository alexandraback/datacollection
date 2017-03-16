import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int tN = sc.nextInt();
		sc.nextLine();
		for(int tn = 0; tn < tN; tn++) {
			int n = sc.nextInt();
			int[] arr = new int[n];
			int sum = 0;
			for(int i = 0; i < n; i++) {
				arr[i] = sc.nextInt();
				sum += arr[i];
			}
			double l = 0;
			double r = sum;
			for(int cnt = 0; cnt < 100; cnt++) {
				double m = (l + r) * 0.5;
				double tmp = 0;
				for(int i = 0; i < n; i++) {
					tmp += Math.max(0, m - arr[i]);
				}
				if(tmp > sum) {
					r = m;
				} else {
					l = m;
				}
			}
			pw.print("Case #" + (tn + 1) + ":");
			for(int i = 0; i < n; i++) {
				pw.print(" " + (Math.max(l - arr[i], 0) / sum * 100));
			}
			pw.println();
		}
		pw.close();
	}
}
