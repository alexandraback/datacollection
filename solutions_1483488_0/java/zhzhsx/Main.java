import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int ti = 0; ti < t; ti++) {
			int a = sc.nextInt(), b = sc.nextInt();
			int sum = 0;
			for (int i = a; i <= b; i++) {
				int numOfDigits, power;
				if (i < 10) {
					numOfDigits = 1;
					power = 1;
				} else if (i < 100) {
					numOfDigits = 2;
					power = 10;
				} else if (i < 1000) {
					numOfDigits = 3;
					power = 100;
				} else if (i < 10000) {
					numOfDigits = 4;
					power = 1000;
				} else if (i < 100000) {
					numOfDigits = 5;
					power = 10000;
				} else if (i < 1000000) {
					numOfDigits = 6;
					power = 100000;
				} else {
					numOfDigits = 7;
					power = 1000000;
				}
				int tmp = i;
				for (int j = 0; j < numOfDigits - 1; j++) {
					int leastSig = tmp % 10;
					tmp = power * leastSig + tmp / 10;
					if (tmp == i)
						break;
					if (leastSig != 0 && tmp < i && tmp >= a)
						sum++;
				}
			}
			System.out.printf("Case #%d: %d%n", ti + 1, sum);
		}
	}
}
