import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("input"));
		BufferedWriter w = new BufferedWriter(new FileWriter(new File("output")));
		int cases = s.nextInt();
		for (int i = 0; i < cases; i++) {
			s.nextLine();
			int n = s.nextInt();
			int surprising = s.nextInt();
			int target = s.nextInt();


			int answer = 0;
			if (target == 0) {
				answer = n;
			} else {
				int lowestBound = target * 3 - 4;
				ArrayList<Integer> l = new ArrayList<Integer>();

				for (int j = 0; j < n; j++) {
					int si = s.nextInt();
					if (si >= lowestBound && si >= target) {
						l.add(si);
					}
				}

				Collections.sort(l);
				Collections.reverse(l);

				for (int si : l) {
					int roundedAverage = si / 3;
					int mod = si % 3;
					if (mod == 0) {
						if (roundedAverage >= target) {
							answer++;
						} else if (roundedAverage + 1 == target && surprising > 0) {
							answer++;
							if (--surprising == 0) {
								break;
							}
						}
					} else if (mod == 1) {
						answer++;
					} else {
						if (roundedAverage + 1 >= target) {
							answer++;
						} else if (roundedAverage + 2 >= target && surprising > 0) {
							answer++;
							if (--surprising == 0) {
								break;
							}
						}
					}
				}
			}

			w.write("Case #");
			w.write(String.valueOf(i + 1));
			w.write(": ");

			w.write(String.valueOf(answer));

			w.write("\n");
		}
		w.close();
	}

}
