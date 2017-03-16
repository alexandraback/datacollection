import java.io.*;
import java.util.*;

public class B {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner console = new Scanner(new File("B-small-attempt0.in"));
		PrintStream output = new PrintStream(new File("b2.txt"));
		int caseNum = console.nextInt();
		for (int i = 1; i <= caseNum; i++) {
			int all = console.nextInt();
			int a[] = new int[all];
			for (int b = 0; b < all; b++) {
				a[b] = console.nextInt();
			}
			output.println("Case #" + i + ": " + find(all, a));
		}
	}

	public static int find(int all, int[] a) {
		int max = 0;
		for (int i = 0; i < all; i++) {
			if (max < a[i]) {
				max = a[i];
			}
		}
		int time = max;
		System.out.println();
		for (int b = 1; b < max; b++) {
			int temp = b;
			for (int i = 0; i < all; i++) {
				temp = temp + (a[i] - 1) / b;
			}
			if (temp < time) {
				time = temp;
			}
		}
		return time;
	}

}
