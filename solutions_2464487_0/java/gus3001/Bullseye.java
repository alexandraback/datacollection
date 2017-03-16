import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Bullseye {
	private static String PROG_NAME = Bullseye.class.getSimpleName();
	private static PrintWriter out;

	public static void main(String[] args) throws Exception {
		main(new FileReader(PROG_NAME + ".small.in"), new FileWriter(PROG_NAME + ".small.out"));
		// main(new FileReader(PROG_NAME + ".large.in"), new
		// FileWriter(PROG_NAME + ".large.out"));
	}

	public static String caseStr(int caseId) {
		return "Case #" + caseId + ":";
	}

	public static void main(FileReader fileReader, FileWriter fileWriter) throws Exception {
		long start = System.currentTimeMillis();
		BufferedReader f = new BufferedReader(fileReader);
		out = new PrintWriter(new BufferedWriter(fileWriter));
		Integer caseCount = Integer.parseInt(f.readLine());
		for (int caseId = 1; caseId <= caseCount; caseId++) {
			StringTokenizer st = new StringTokenizer(f.readLine());
			long r = Long.parseLong(st.nextToken());
			long t = Long.parseLong(st.nextToken());

			long blackCount = 0;
			long blackRadius = 0;
			long blackArea = 0;
			long whiteRadius = r - 2;
			long whiteArea = 0;
			long ringArea = 0;
			long totalRingArea = 0;
			long r2 = 2 * r;
			long n = -1;
			while (true) {
				n += 2;
				ringArea = r2 + 2 * n - 1;
				if (ringArea + totalRingArea > t) {
					break;
				}
				blackCount++;
				totalRingArea += ringArea;
			}
			System.out.println(caseStr(caseId) + " " + blackCount);
			out.println(caseStr(caseId) + " " + blackCount);
		}
		System.out.println(System.currentTimeMillis() - start);
		out.close(); // close the output file
	}
}
