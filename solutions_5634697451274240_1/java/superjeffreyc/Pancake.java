import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Pancake {

	static String current;
	static char[] arr;

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(new File("C:\\Users\\JeffreyChan\\Downloads\\B-large.in"));
		//		Scanner scan = new Scanner(System.in);
		int cases = Integer.parseInt(scan.nextLine());

		for (int i = 0; i < cases; i++) {
			current = scan.nextLine();
			arr = current.toCharArray();
			int counter = 0;

			while (!isHappy()) {
				int index = findLeftHappy();
				if (index == -1) {
					counter++;
					break;
				}

				int k;
				if (hasMinusLeft(index)) {
					k = index - 1;
					if (k < 0) k = 0;

					for (int j = 0; j <= k; j++) {
						swap(j, k);
						k--;
					}
				} else {
					k = index;
					for (int j = 0; j <= k; j++) {
						swap(j, k);
						k--;
					}
				}

				counter++;
			}

			System.out.println("Case #" + (i + 1) + ": " + counter);

		}
	}

	private static boolean isHappy() {
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] != '+') return false;
		}
		return true;
	}

	private static int findLeftHappy() {
		boolean foundMinus = false;
		boolean foundPlus = false;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == '+' && foundMinus) {
				return i;
			} else if (arr[i] == '-' && foundPlus) {
				return i - 1;
			} else if (arr[i] == '-')
				foundMinus = true;
			else if (arr[i] == '+') foundPlus = true;
		}
		return -1;
	}

	private static boolean hasMinusLeft(int i) {
		for (; i >= 0; i--) {
			if (arr[i] == '-') return true;
		}
		return false;
	}

	private static void swap(int i, int j) {

		if (i == j) {
			if (arr[i] == '+')
				arr[i] = '-';
			else
				arr[i] = '+';
			return;
		}

		char c1 = arr[i];
		char c2 = arr[j];

		if (c1 == '+')
			c1 = '-';
		else
			c1 = '+';

		if (c2 == '+')
			c2 = '-';
		else
			c2 = '+';

		arr[i] = c2;
		arr[j] = c1;
	}
}
