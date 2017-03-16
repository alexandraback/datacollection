import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class D {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int no = 1; no <= T; no++) {
			System.out.printf("Case #%d: ", no);

			int N = in.nextInt();
			List<Double> o1 = new ArrayList<>();
			List<Double> o2 = new ArrayList<>();
			for (int i = 0; i < N; i++) {
				o1.add(in.nextDouble());
			}
			for (int i = 0; i < N; i++) {
				o2.add(in.nextDouble());
			}
			Collections.sort(o1);
			Collections.sort(o2);

			int winDec = 0;
			List<Double> w1 = new ArrayList<Double>(o1);
			List<Double> w2 = new ArrayList<Double>(o2);
			for (int i = 0; i < N; i++) {
				if (w1.get(0) < w2.get(0)) {
					w1.remove(0);
					w2.remove(w2.size() - 1);
				} else {
					winDec++;
					w1.remove(0);
					w2.remove(0);
				}
			}

			int winWar = 0;
			w1 = new ArrayList<Double>(o1);
			w2 = new ArrayList<Double>(o2);
			for (int i = 0; i < N; i++) {
				int sel = 0;
				int bs = -(Collections.binarySearch(w2, w1.get(sel)) + 1);
				if (bs == w2.size()) {
					winWar++;
					w1.remove(sel);
					w2.remove(0);
				} else {
					w1.remove(sel);
					w2.remove(bs);
				}
			}

			System.out.printf("%d %d%n", winDec, winWar);
		}
	}

}
