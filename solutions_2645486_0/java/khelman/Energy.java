package pl.helman;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Energy {

	public static void main(String[] args) throws IOException {
		FileReader fr = new FileReader("d:\\cj\\ener.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter fo = new FileWriter("d:\\cj\\ener.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		for (int c = 1; c <= t; c++) {

			line = br.readLine().trim();
			String[] elems = line.split(" ");

			long e = Long.parseLong(elems[0]);
			long r = Long.parseLong(elems[1]);
			int n = Integer.parseInt(elems[2]);

			final long v[] = new long[n];
			
			long reserved[] = new long[n];
			long after[] = new long[n];

			line = br.readLine().trim();
			elems = line.split(" ");

			List<Elem> indexes = new ArrayList<Energy.Elem>(n);

			for (int i = 0; i < n; i++) {
				v[i] = Long.parseLong(elems[i]);
				indexes.add(new Elem(i));
				after[i] = e;
			}

			Collections.sort(indexes, new Comparator<Elem>() {
				@Override
				public int compare(Elem o1, Elem o2) {

					if (v[o1.index] != v[o2.index]) {
						return v[o1.index] > v[o2.index] ? -1
								: v[o1.index] == v[o2.index] ? 0 : 1;
					}

					return o1.index > o2.index ? -1 : (o1.index == o2.index ? 0
							: 1);
				}
			});

			BigInteger ret = BigInteger.ZERO;
			
			for (Elem index : indexes) {
				// calculate max energy
				int i = index.index;
				long maxEnergy = i > 0 ? after[i - 1] : e;
				
				// use energy
				
				after[i] = Math.min(reserved[i] + r, e);
				long energy = maxEnergy - reserved[i];
				ret = ret.add(BigInteger.valueOf(v[i]).multiply(
						BigInteger.valueOf(energy)));
				
				// make reservations
				long ener = maxEnergy;
				int j=i;
				
				while (j > 0 && ener - r > 0) {
					j--;
					reserved[j] = Math.max(0, ener - r);
					ener -= r;
				}
				
				// update afters
				j=i;
				while (j<n-1 && after[j] < e) {
					j++;
					after[j] = Math.min(after[j - 1] + r, e);
				}
			}

			fo.write("Case #" + c + ": " + ret.toString() + "\n");
		}

		fr.close();
		fo.close();

	}

	private static class Elem {
		int index;

		public Elem(int index) {
			this.index = index;
		}

		@Override
		public String toString() {
			return "" + index ;
		}
	}

}
