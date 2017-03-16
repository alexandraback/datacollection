package gcj2012.round1b;

import java.util.Scanner;

public class A {
	public static void main(String args[]) {
		new A();
	}

	public A() {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int x=1; x<=T; x++) {
			int N = scan.nextInt();
			int[] s = new int[N];
			int sum = 0;
			for(int i=0; i<N; i++) {
				s[i] = scan.nextInt();
				sum += s[i];
			}
			double min = sum * 2.0 / N;

			int sum2 = 0;
			int M = 0;
			for(int i=0; i<N; i++) {
				if(min >= s[i]) M++;
				else sum2 += s[i];
			}
			sum2 = sum * 2 - sum2;

			double min2 = sum2 / (double)M;

			System.out.printf("Case #%d:", x);
			for(int i=0; i<N; i++) {
				double need = (min2 - s[i]) * 100.0 / sum;
				if(need < 0.0) need = 0.0;
				System.out.printf(" %f", need);
			}
			System.out.println();
		}
	}
}
