
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

public class Solve2014R0D {
	private static String filePath = "D-small-attempt0.in";
	public static final DecimalFormat NUMBER_FORMAT = new DecimalFormat();

	private static int T = 0;  // 1 ≤ T ≤ 50
	private static int[] Ns = null; // [T] 1 ≤ N ≤ 10  /  1 ≤ N ≤ 1000
	private static List<double[]> Naomis = null; // [T][N]
	private static List<double[]> Kens   = null; // [T][N]

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		NUMBER_FORMAT.setMaximumFractionDigits(5);
		NUMBER_FORMAT.setMinimumFractionDigits(1);
		long startDatetime = System.currentTimeMillis();
		try {
			input();

			StringBuffer answer = new StringBuffer();
			for (int x = 0; x < T; x++) {
				answer.append("Case #" + (x+1) + ": ");
				System.out.print("Case #" + (x+1) + ": ");

				int N = Ns[x];
				double[] Naomi = Naomis.get(x);
				double[] Ken   = Kens.get(x);
				int y = 0, z = 0;

				// Calculate the y
				if (Naomi[0] < Ken[N-1]) y = 0;
				else {
					int naomiIdx = N - 1;
					for (int i = N-1; i >= 0; i--) {
						for (; naomiIdx > -1; naomiIdx--) {
							if (Naomi[naomiIdx] > Ken[i]) {
								y++;
								naomiIdx--;
								break;
							}
						}
					}
				}

				// Calculate the z
				int kenIdx = 0;
				for (int i = 0; i < N; i++) {
					if (Naomi[i] > Ken[kenIdx]) z++;
					else kenIdx++;
				}

				answer.append(y + " " + z).append("\n");
				System.out.println(y + " " + z);
			}
			output(answer);
		} catch (Exception e) {
			e.printStackTrace();
		}
		long tm = System.currentTimeMillis() - startDatetime;
		long tms = tm / 1000;
		System.out.println("The process time: " + tms + "s " + (tm%1000) + "ms");
	}

	private static void sortBigSmall(double[] dbls) {
		int cnt = dbls.length;
		if(cnt < 2) return;
		double b;
		for(int j = cnt - 1; j > 0; j--) {
			for(int i = 0; i < j; i++) {
				if(dbls[i] < dbls[i+1]) {
					b = dbls[i];
					dbls[i] = dbls[i+1];
					dbls[i+1] = b;
				}
			}
		}
	}

	/**
	 * read data from a file
	 * @param path : the data file's path
	 */
	private static void input() throws Exception {
		BufferedReader br = null;
		String line = null;
		if (filePath == null) br = new BufferedReader(new InputStreamReader(System.in));
		else br = new BufferedReader(new InputStreamReader(new FileInputStream(filePath)));

		T = Integer.parseInt(br.readLine());

		Ns = new int[T];
		Naomis = new ArrayList<double[]>();
		Kens = new ArrayList<double[]>();
		for (int x = 0; x < T;) {
			if ( (line = br.readLine()) == null) { throw new Exception("wrong! Case #" + (x+1)); }
			if (line.equals("")) continue;
			Ns[x] = Integer.parseInt(line);

			if ( (line = br.readLine()) == null) { throw new Exception("wrong! Case #" + (x+1)); }
			String[] sts = line.split(" ");
			double[] dbls = new double[Ns[x]];
			for (int i = 0; i < Ns[x]; i++) {
				dbls[i] = Double.parseDouble(sts[i]);
			}
			sortBigSmall(dbls);
			Naomis.add(dbls);

			if ( (line = br.readLine()) == null) { throw new Exception("wrong! Case #" + (x+1)); }
			sts = line.split(" ");
			dbls = new double[Ns[x]];
			for (int i = 0; i < Ns[x]; i++) {
				dbls[i] = Double.parseDouble(sts[i]);
			}
			sortBigSmall(dbls);
			Kens.add(dbls);
			x++;
		}
		br.close();
		br = null;

		// Confirm
//		System.out.println(T);
//		for (int x = 0; x < T; x++) {
//			System.out.println(Ns[x]);
//			for (int i = 0; i < Ns[x]; i++) {
//				System.out.print(NUMBER_FORMAT.format(Naomis.get(x)[i]) + " ");
//			}
//			System.out.println();
//			for (int i = 0; i < Ns[x]; i++) {
//				System.out.print(NUMBER_FORMAT.format(Kens.get(x)[i]) + " ");
//			}
//			System.out.println();
//		}
	}

	private static void output(StringBuffer answer) throws Exception {
		String outPath = "answer.out";
		if (filePath != null) outPath = filePath.substring(0, filePath.length()-2) + "out";
		FileOutputStream fos = new FileOutputStream(outPath, false);
		fos.write(answer.toString().getBytes());
		fos.close();
		fos = null;
	}
}
