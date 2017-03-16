package gcj;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class DeceitfulWar {

	public static void main(String[] args) throws Exception {
		String name = "D-large";
		Locale.setDefault(Locale.US);
		Scanner scanner = new Scanner(new File("C:\\Users\\m\\Desktop\\training\\"+name+".in"));
		final long len = scanner.nextInt() + 1;
		FileWriter fw = new FileWriter("C:\\Users\\m\\Desktop\\training\\"+name+".out");
		BufferedWriter out = new BufferedWriter(fw);
		for (int n = 1; n < len; n++) {
			int nb = scanner.nextInt();
			List<Double> NS = new ArrayList<Double>(nb);
			for (int i = 0; i < nb; i++) {
				NS.add(scanner.nextDouble());
			}
			List<Double> KS = new ArrayList<Double>(nb);
			for (int i = 0; i < nb; i++) {
				KS.add(scanner.nextDouble());
			}
			Collections.sort(NS);
			Collections.sort(KS);
			List<Double> NS2 = new ArrayList<Double>(NS);
			List<Double> KS2 = new ArrayList<Double>(KS);
			String str = "Case #" + n + ": " + solve(nb, NS, KS) + " " + solveSimpleWar(nb, NS2, KS2);
			System.out.println(str);
			out.write(str);
			out.newLine();
		}
		out.flush();
		out.close();
	}

	private static int solveSimpleWar(int nb, List<Double> nS, List<Double> kS) {
		for (int i = nb; i > 0; i--) {
			Double smallest = nS.remove(0);
			int idx = Collections.binarySearch(kS, smallest);
			//(-(insertion point) - 1)
			idx = - idx - 1;
			if (idx >= i) {
				return i;
			}
			kS.remove(idx);
		}
		return 0;
	}
	
	private static int solve(int nb, List<Double> nS, List<Double> kS) {
		int r = 0;
		for (int i = nb; i > 0; i--) {
			//System.out.println(nS);
			//System.out.println(kS);
			Double smallest = nS.remove(0);
			if (smallest > kS.get(i - 1)) {
				return r + i;
			}
			if (smallest > kS.get(0)) {
				r++;
				kS.remove(0);
			} else {
				kS.remove(i - 1);
			}
		}
		return r;
	}
}
