import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class InfiniteHouse {
	// static String file = "B";
	static String file = "B-small-attempt3";

	static long solve(int[] a) {
		int min = Integer.MAX_VALUE;
		for (int i = 1; i <= 1000; i++) {
			int current = i;
			for (int j = 0; j < a.length; j++) {
				current += a[j] / i;
				if (a[j] % i == 0) {
					current--;
				}
			}
			
			min = Math.min(current, min);
		}
		
		return min;

	}

	static int[] intArray(String l) {
		String[] vals = l.split(" ");
		int[] ans = new int[vals.length];
		for (int i = 0; i < vals.length; i++) {
			ans[i] = Integer.valueOf(vals[i]);
		}
		return ans;
	}

	static Random r = new Random();

	static int[] getRandomInput(int l) {
		int[] a = new int[l];
		for (int i = 0; i < a.length; i++) {
			a[i] = r.nextInt(1000) + 1;
		}

		return a;
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
			if (line.length() > 0)
				lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 1;
		for (int i = 0; i < problemCount; i++) {
			currentIndex++;
			// String r = "Case #" + (i+1) + ": " + solve(getRandomInput(1000));
			int[] a = intArray(lines.get(currentIndex++));
			String r = "Case #" + (i+1) + ": " + solve(a);
								
			// System.out.println("****************************");
			// System.out.println(Arrays.toString(a));
//			 System.out.println(r);

			 bw.write(r);
			 bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
	}
}
