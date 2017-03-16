import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class StandingOvation {
	static String file = "A-small-attempt0";

	static String solve(int max, int[] a) {
		long s = a[0];
		long add = 0;
		for (int i = 1; i < a.length; i++) {
			if (s < i) {
				add += i - s;
				s += i - s;
			}

			s += a[i];
		}

		return Long.toString(add);
	}

	static int[] intArray(String l) {
		String[] vals = l.split(" ");
		int[] ans = new int[vals.length];
		for (int i = 0; i < vals.length; i++) {
			ans[i] = Integer.valueOf(vals[i]);
		}
		return ans;
	}

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
		int currentIndex = 1;
		for (int i = 0; i < problemCount; i++) {
			String c = lines.get(currentIndex++);
			String[] vals = c.split(" ");
			int[] a = new int[vals[1].length()];
			for (int j = 0; j < a.length; j++) {
				a[j] = Integer.parseInt(vals[1].substring(j, j + 1));
			}

			String r = "Case #" + (i + 1) + ": " + solve(Integer.valueOf(vals[0]), a);

//			System.out.println(r);
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
	}
}
