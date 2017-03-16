
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.text.DecimalFormat;

public class Solve2014R0B {
	private static String filePath = "B-large.in";  // "B-small-attempt0.in";
	public static final int  imax = 2147483647;
	public static final long lmax = 9223372036854775807l;
	public static final DecimalFormat NUMBER_FORMAT = new DecimalFormat();

	private static int T = 0;  // 1 ≤ T ≤ 100
	private static double[] Cs = null; // [T] 1 ≤ C ≤ 500  /  1 ≤ C ≤ 10000
	private static double[] Fs = null; // [T] 1 ≤ F ≤ 4    /  1 ≤ F ≤ 100
	private static double[] Xs = null; // [T] 1 ≤ X ≤ 2000 /  1 ≤ X ≤ 100000

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		NUMBER_FORMAT.setMaximumFractionDigits(7);
		NUMBER_FORMAT.setMinimumFractionDigits(7);
		long startDatetime = System.currentTimeMillis();
		try {
			input();

			StringBuffer answer = new StringBuffer();
			for (int x = 0; x < T; x++) {
				answer.append("Case #" + (x+1) + ": ");
				System.out.print("Case #" + (x+1) + ": ");

				double C = Cs[x];
				double F = Fs[x];
				double X = Xs[x];
				double y = 0;

				// C/(2+Fi) + X/(2+Fi+F) <= X/(2+Fi)
				// => i <= X/C - 1 - 2/F
				int i = 0;
				while (F * X >= (2 + F * i + F) * C) {
					y += C / (2 + F * i);
					i++;
				}
				y += X / (2 + F * i);

				answer.append(NUMBER_FORMAT.format(y)).append("\n");
				System.out.println(NUMBER_FORMAT.format(y));
			}
			output(answer);
		} catch (Exception e) {
			e.printStackTrace();
		}
		long tm = System.currentTimeMillis() - startDatetime;
		long tms = tm / 1000;
		System.out.println("The process time: " + tms + "s " + (tm%1000) + "ms");
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

		Cs = new double[T];
		Fs = new double[T];
		Xs = new double[T];
		for (int x = 0; x < T;) {
			if ( (line = br.readLine()) == null) { throw new Exception("wrong! Case #" + (x+1)); }
			if (line.equals("")) continue;
			String[] sts = line.split(" ");
			Cs[x] = Double.parseDouble(sts[0]);
			Fs[x] = Double.parseDouble(sts[1]);
			Xs[x] = Double.parseDouble(sts[2]);
			x++;
		}
		br.close();
		br = null;

		// Confirm
//		System.out.println(T);
//		for (int x = 0; x < T; x++) {
//			System.out.println(NUMBER_FORMAT.format(Cs[x]) + " " + NUMBER_FORMAT.format(Fs[x]) + " " + NUMBER_FORMAT.format(Xs[x]));
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
