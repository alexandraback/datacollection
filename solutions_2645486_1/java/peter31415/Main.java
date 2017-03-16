import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {
	static String file = "B-large";	

	public static void main(String[] args) throws IOException {

		FileInputStream fis = new FileInputStream(file + ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		String line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 0;
		for (int i = 0; i < problemCount; i++) {
			String[] v = lines.get(++currentIndex).split(" ");

			long e = Long.parseLong(v[0]);
			long r = Long.parseLong(v[1]);
			int n = Integer.parseInt(v[2]);

			int[] vals = new int[n];
			v = lines.get(++currentIndex).split(" ");
			for (int j = 0; j < v.length; j++) {
				vals[j] = Integer.parseInt(v[j]);
			}

			String solution = getSolution(e, r, vals);
			String res = "Case #" + (i + 1) + ": " + solution;

			System.out.println(res);
			bw.write(res);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
	}

	public static String getSolution(long e, long r, int[] v) {

		long gain = 0;
		long currentE = e;
		for (int i = 0; i < v.length; i++) {

			int nextBetter = -1;
			for (int j = i + 1; j < v.length; j++) {
				if (v[i] < v[j]) {
					nextBetter = j;
					break;
				}
			}

			long minam =0;
			if (nextBetter != -1) {
				minam = Math.max(0, Math.min(currentE, (currentE + (nextBetter - i) * r) - e));
			} else {
				minam = currentE;
			}
			
			gain += minam * v[i];
			currentE -= minam;
			currentE += r;
		}

		return "" + gain;
	}
}
