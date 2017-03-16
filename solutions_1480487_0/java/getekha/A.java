package a;

import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();

		int nbr = 1;
		while (t-- > 0) {
			int n = sc.nextInt();

			int[] scores = new int[n];
			int[] org = new int[n];

			int sum = 0;
			for (int i = 0; i < scores.length; i++) {
				scores[i] = sc.nextInt();
				sum += scores[i];
				org[i] = scores[i];
			} 


			double[] numbers = new double[n];

			int optOuts = 0;

			boolean clear = false;
			
			double available =  sum;
			
			while (!clear) {
				double target = (available + sum) / (n - optOuts);
				clear = true;
				for (int i = 0; i < numbers.length; i++) {
					if (scores[i] == -1) {
						continue;
					} else if (scores[i] >= target) {
						numbers[i] = 0;
						clear = false;
						available -= scores[i];
						scores[i] = -1;
						optOuts++;
					} else {
						double req = target - scores[i];
						numbers[i] = req / sum;
					}

				}
			}

			
			double numbersSum = 0;
			
			for (int i = 0; i < numbers.length; i++) {
				numbersSum += numbers[i];
			}
//
//			for (int i = 0; i < numbers.length; i++) {
//				numbers[i] /= numbersSum;
//			}

			System.out.printf("Case #%d:", nbr++);
			for (int i = 0; i < numbers.length; i++) {
				System.out.print(" " + numbers[i] * 100);
//				if (scores[i] != -1){
//					System.out.print(" " + (org[i] + sum * numbers[i]));					
//				} else {
//					System.out.print(" Safe" + org[i]);
//				}
			}
			System.out.println();
			sc.nextLine().toCharArray();
		}
	}
}
