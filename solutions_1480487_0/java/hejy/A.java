import java.util.Scanner;

public class A {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		for (int k = 0; k < t; k++) {
			int n = sc.nextInt();

			int arr[] = new int[n];
			double sum = 0;

			for (int j = 0; j < n; j++) {
				arr[j] = sc.nextInt();
				sum += arr[j];
			}
			double avg = sum * 2 / n;

			int aboveavgct = 0;
			int belowavgsum = 0;
			for (int j = 0; j < n; j++) {
				if (arr[j] > avg) {
					aboveavgct++;
				}else{
					belowavgsum += arr[j];
				}
			}
			if (aboveavgct > 0) {
				avg = (sum + belowavgsum) / (n - aboveavgct);

				System.out.print("Case #" + (k + 1) + ": ");
				for (int j = 0; j < n; j++) {
					if (avg - arr[j] <= 0) {
						System.out.print(0 + " ");
					} else {
						System.out.print((avg - arr[j]) * 100 / sum + " ");
					}
				}
				System.out.print("\n");
			} 
			else {
				System.out.print("Case #" + (k + 1) + ": ");
				for (int j = 0; j < n; j++) {
					System.out.print((avg - arr[j]) * 100 / sum + " ");
				}
				System.out.print("\n");
			}
		}
	}
}