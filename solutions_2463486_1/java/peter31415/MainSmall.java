import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class MainSmall {
	static String file = "C-large-1";

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

			String solution = getSolution(v[0], v[1]);
		
			String r = "Case #" + (i + 1) + ": " + solution;

			System.out.println(r);
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();

	}

	public static String getSolution(String low, String high) {

		long sol = 0;

		long origLow = Long.parseLong(low);
		long origHigh = Long.parseLong(high);

		double sl = Math.sqrt(Double.parseDouble(low));
		double sh = Math.sqrt(Double.parseDouble(high));

		long l = (long) Math.ceil(sl);
		long h = (long) Math.floor(sh);

		String lowString = Long.toString(l);
		String highString = Long.toString(h);

		for (int i = lowString.length(); i <= highString.length(); i++) {
			int half = (i + 1) / 2;

			long from = (long) Math.pow(10, half - 1);
			long to = (long) (3 * Math.pow(10, half - 1));
		
			for (long j = from; j <= to; j++) {
				StringBuffer sb = new StringBuffer(Long.toString(j));
				char[] t = Long.toString(j).toCharArray();

				for (int k = t.length - 1 - (i % 2); k >= 0; k--) {
					sb.append(t[k]);
				}

				if (ok(sb.toString(), origLow, origHigh))
					sol++;
			}
		}

		return "" + sol;
	}

	static boolean ok(String c, long low, long high) {

		long small = Long.parseLong(c);
		long large = small * small;
		if (large < low || large > high)
			return false;

		char[] la = Long.toString(large).toCharArray();

		for (int i = 0; i < la.length / 2; i++) {
			if (la[i] != la[la.length - 1 - i])
				return false;
		}	

		return true;

	}

}
