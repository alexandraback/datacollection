
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;


public class Solve2014R1BBL {
	private static String filePath = "B-large.in";  // "B-small-attempt0.in";

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		long startDatetime = System.currentTimeMillis();

		StringBuffer answer = new StringBuffer();
		try {
			BufferedReader br = null;
			String line = null;
			if (filePath == null) br = new BufferedReader(new InputStreamReader(System.in));
			else br = new BufferedReader(new InputStreamReader(new FileInputStream(filePath)));

			int T = Integer.parseInt(br.readLine());
			//System.out.println(T);

			for (int x = 1; x <= T; x++) {
				if ( (line = br.readLine()) == null) { throw new Exception("wrong! Case #" + x); }
				System.out.println("Case #" + x + ": ");
				answer.append("Case #" + x + ": ");

				String[] sts = line.split(" ");
				long A = Long.parseLong(sts[0]);
				long B = Long.parseLong(sts[1]);
				long K = Long.parseLong(sts[2]);

				long y = 0;
				if (A <= K || B <= K) {
					y = A * B;
				} else {
					y = K * K + (A-K) * K + (B-K) * K;
					for (long i = K; i < A; i++) {
						for (long j = K; j < B; j++) {
							if ((i & j) < K) y++;
						}
					}
				}
				answer.append(y).append("\n");
			}
			br.close();
			br = null;
			output(answer);
		} catch (Exception e) {
			e.printStackTrace();
		}
		long tm = System.currentTimeMillis() - startDatetime;
		long tms = tm / 1000;
		System.out.println("The process time: " + tms + "s " + (tm%1000) + "ms");
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
