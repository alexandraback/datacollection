import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.StringTokenizer;

public class FallingDiamonds {
	private static String PROG_NAME = FallingDiamonds.class.getSimpleName();
	private static PrintWriter out;
	private static long spareBlocks = 0;

	public static void main(String[] args) throws Exception {
		main(new FileReader(PROG_NAME + ".small.in"), new FileWriter(PROG_NAME + ".small.out"));
		// main(new FileReader(PROG_NAME + ".large.in"), new
		// FileWriter(PROG_NAME + ".large.out"));
	}

	public static String caseStr(int caseId) {
		return "Case #" + caseId + ":";
	}

	public static void main(FileReader fileReader, FileWriter fileWriter) throws Exception {
		BufferedReader f = new BufferedReader(fileReader);
		out = new PrintWriter(new BufferedWriter(fileWriter));
		Integer caseCount = Integer.parseInt(f.readLine());
		for (int caseId = 1; caseId <= caseCount; caseId++) {
			StringTokenizer st = new StringTokenizer(f.readLine());
			long N = Long.parseLong(st.nextToken());
			int X = Integer.parseInt(st.nextToken());
			int Y = Integer.parseInt(st.nextToken());
			spareBlocks = 0;

			long b = prevFullPiramidBase(N);
			// is in full base? 100%
			if (X >= 0) {
				if (Y <= -X + b) {
					System.out.println("100% a");
					System.out.println(caseStr(caseId) + " 1.0");
					out.println(caseStr(caseId) + " 1.0");
					continue;
				}
			} else {
				if (Y <= X + b) {
					System.out.println("100% b");
					System.out.println(caseStr(caseId) + " 1.0");
					out.println(caseStr(caseId) + " 1.0");
					continue;
				}
			}

			// is out of possible piramid? 0%
			if (X >= 0) {
				if (Y > -X + b + 2) {
					System.out.println("0% c");
					System.out.println(caseStr(caseId) + " 0.0");
					out.println(caseStr(caseId) + " 0.0");
					continue;
				}
			} else {
				if (Y > X + b + 2) {
					System.out.println("0% d");
					System.out.println(caseStr(caseId) + " 0.0");
					out.println(caseStr(caseId) + " 0.0");
					continue;
				}
			}

			// chance
			// how high?
			if (spareBlocks < Y + 1) {
				System.out.println("0% e");
				System.out.println(caseStr(caseId) + " 0.0");
				out.println(caseStr(caseId) + " 0.0");
				continue;
			}
			if (Y == b + 1) {
				System.out.println("0% f");
				System.out.println(caseStr(caseId) + " 0.0");
				out.println(caseStr(caseId) + " 0.0");
				continue;
			}
			if (Y + 1 <= spareBlocks - (b + 1)) {
				System.out.println("100% g");
				System.out.println(caseStr(caseId) + " 1.0");
				out.println(caseStr(caseId) + " 1.0");
				continue;
			}

			long randomBlocks = spareBlocks <= b + 1 ? spareBlocks : (b + 1) * 2 - spareBlocks;
			if (randomBlocks > Integer.MAX_VALUE) {
				throw new RuntimeException("whoops");
			}
			BigDecimal possibilities = new BigDecimal("2").pow((int) randomBlocks);
			BigDecimal notHitting = BigDecimal.ONE;
			for (int i = 1; i <= Y - (spareBlocks - randomBlocks); i++) {
				notHitting = notHitting.add(nChooseK(randomBlocks, i));
			}
			// if (notHitting.equals(BigDecimal.ZERO)) {
			// notHitting = BigDecimal.ONE;
			// }
			BigDecimal ans = BigDecimal.ONE.subtract(notHitting.divide(possibilities));

			System.out.println(caseStr(caseId) + " " + ans);
			out.println(caseStr(caseId) + " " + ans);
		}

		out.close(); // close the output file
	}

	private static BigDecimal nChooseK(long n, long k) {
		BigDecimal num = BigDecimal.ONE;
		for (long i = n; i > k; i--) {
			num = num.multiply(BigDecimal.valueOf(i));
		}

		for (long i = 2; i <= n - k; i++) {
			num = num.divide(BigDecimal.valueOf(i));
		}
		return num;
	}

	private static long prevFullPiramidBase(long N) {
		long currSum = 0;
		for (int base = 1; true; base += 2) {
			currSum += base * 2 - 1;
			if (currSum > N) {
				return base - 2;
			} else {
				spareBlocks = N - currSum;
			}
		}
	}

	private static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj) {
				return true;
			}
			if (obj == null) {
				return false;
			}
			if (getClass() != obj.getClass()) {
				return false;
			}
			Point other = (Point) obj;
			if (x != other.x) {
				return false;
			}
			if (y != other.y) {
				return false;
			}
			return true;
		}

		@Override
		public String toString() {
			return x + ":" + y;
		}
	}

}
