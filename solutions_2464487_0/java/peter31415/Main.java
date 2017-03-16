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
	static String file = "A-small-attempt0";

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
			long r = Long.parseLong(v[0]);
			long t = Long.parseLong(v[1]);

			String solution = getSolution(r, t);
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

	public static String getSolution(long r, long t) {
		long counter = 0;
		long sum = 0;
		long tt = 1;
		while (true) {
			sum += (2 * r + tt * tt - (tt - 1) * (tt - 1));

			if (sum <= t) {
				counter++;
				tt += 2;
			} else {
				break;

			}
		}

		return "" + counter;
	}
}
