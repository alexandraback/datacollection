

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Map;
import java.util.Scanner;

import com.google.common.collect.Maps;

// Using the Google Guava library.
public class B {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/B-small-1.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
			int e = in.nextInt();
			int r = in.nextInt();
			int n = in.nextInt();
//			long [] energy = new long[e+1];
			Map<Integer, Long> energy = Maps.newHashMap();
			energy.put(e, 0L);
			Map<Integer, Long> nextEnergy = Maps.newHashMap();
			for (int i = 0; i < n; i++) {
				int v = in.nextInt();
				for (Map.Entry<Integer, Long> entry : Maps.newHashMap(energy).entrySet()) {
					int eNow = entry.getKey();
					long value = entry.getValue();
					// spend all
					{
						Long bestValue = nextEnergy.get(r);
						long vNext = value + eNow * v;
						if (bestValue == null || vNext > bestValue) {
							nextEnergy.put(r, vNext);
						}
					}
					// spend down to e - r
					{
						int toSpend = Math.max(eNow - (e - r), 0);
						for (int ts = toSpend; ts <= eNow; ts += r) {
							int endEnergy = eNow - ts + r;
							Long bestValue = nextEnergy.get(endEnergy);
							long vNext = value + ts * v;
							if (bestValue == null || vNext > bestValue) {
								nextEnergy.put(endEnergy, vNext);
							}
						}
					}
				}
				energy = nextEnergy;
			}
			long maxValue = 0;
			for (long val : energy.values()) {
				maxValue = Math.max(val, maxValue);
			}
			out.print("Case #"+cs+": "+maxValue);
			out.println();
		}
		out.close();
	}
}
