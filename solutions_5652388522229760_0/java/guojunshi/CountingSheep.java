package qualification;

import java.util.Scanner;

public class CountingSheep {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			int result = lastNumber(in.nextInt());
			if (result == -1) {
				System.out.println("Case #" + (i + 1) + ": INSOMNIA");
			} else {
				System.out.println("Case #" + (i + 1) + ": " + result);
			}
		}
		in.close();
	}

	public static int lastNumber(int num) {
		if (num == 0) {
			return -1;
		}
		boolean exist[] = new boolean[10];
		int count = 0, number = num;
		while (true) {
			count += countingFigure(number, exist);
			if (count == 10) {
				return number;
			}
			number += num;
		}
	}

	public static int countingFigure(int num, boolean[] exist) {
		int figure, ret = 0;
		while (num > 0) {
			figure = num % 10;
			num /= 10;
			if (exist[figure] == false) {
				exist[figure] = true;
				ret++;
			}
		}
		return ret;
	}

}
