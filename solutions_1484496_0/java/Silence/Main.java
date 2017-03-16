import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

	public static boolean cango(int[][] c, int[][] f, int i, int j, int ni,
			int nj) {
		return f[ni][nj] <= c[ni][nj] - 50 && f[i][j] <= c[ni][nj] - 50
				&& f[ni][nj] <= c[i][j] - 50 && f[i][j] <= c[i][j] - 50;
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int tN = sc.nextInt();
		sc.nextLine();
		oppa : for (int tn = 0; tn < tN; tn++) {
			int n = sc.nextInt();
			int [] arr = new int[n];
			for(int i = 0; i < n; i++) {
				arr[i] = sc.nextInt();
			}
			int[] how = new int[1000000];
			for(int mask = 1; mask < (1<<n); mask++) {
				int sum = 0;
				for(int i = 0; i < n; i++) {
					if((mask & (1 << i)) != 0) {
						sum += arr[i];
					}
				}
				if(how[sum] != 0) {
					pw.print("Case #" + (tn + 1) + ":\n");
					for(int i = 0; i < n; i++) {
						if((mask & (1 << i)) != 0) {
							pw.print(arr[i] + " ");
						}
					}
					pw.println();
					for(int i = 0; i < n; i++) {
						if((how[sum] & (1 << i)) != 0) {
							pw.print(arr[i] + " ");
						}
					}
					pw.println();
					continue oppa;
				}
				how[sum] = mask;
			}
			pw.println("Case #" + (tn + 1) + ": Impossible");
		}
		pw.close();
	}
}
