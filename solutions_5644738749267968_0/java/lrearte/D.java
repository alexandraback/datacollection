package qualy;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class D {
	private static int N;
	
	private static int doIt(List<Double> first, List<Double> second) {
		int ret = 0, secondPos = 0;
		for (int firstPos = 0 ; firstPos < N ; firstPos++) {
			if (first.get(firstPos) > second.get(secondPos)) ret++;
			else secondPos++;
		}
		return ret;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caze = 1; caze <= cases; caze++) {
			N = sc.nextInt();
			List<Double> first = new ArrayList<Double>(N), second = new ArrayList<Double>(N);
			for (int i = 0; i < N; i++) {
				first.add(sc.nextDouble());
			}
			for (int i = 0; i < N; i++) {
				second.add(sc.nextDouble());
			}
			Collections.sort(first, Collections.reverseOrder());
			Collections.sort(second, Collections.reverseOrder());

			System.out.println("Case #" + caze + ": " + (N-doIt(second, first)) +  " " + doIt(first, second));
		}
	}

}
