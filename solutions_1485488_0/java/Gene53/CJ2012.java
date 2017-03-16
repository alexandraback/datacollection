package org.digiharbor.gene;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Console;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;

public class CJ2012 {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		new CJ2012();
	}
	public CJ2012() throws FileNotFoundException, IOException {
		BufferedReader sysin = new BufferedReader(new InputStreamReader(System.in));

		String stage = "Round_1B";
		System.out.printf("Stage %s Problem to run: (ae, a0, a1, al, be...): ", stage);
		String cmd = sysin.readLine().toUpperCase().trim();
		char problem = cmd.charAt(0);
		String fname = "";
		if (cmd.charAt(1) == 'E')
			fname = stage + "/" + problem + "-example";
		else if (cmd.charAt(1) == 'L')
			fname = stage + "/" + problem + "-large";
		else
			fname = stage + "/" + problem + "-small-attempt" + cmd.charAt(1);

		String inf = fname + ".in";
		String outf = fname + ".out";
		BufferedReader f = new BufferedReader(new FileReader(inf));
		BufferedWriter out = new BufferedWriter(new FileWriter(outf));
		int cnt = Integer.parseInt(f.readLine());

		long start = System.currentTimeMillis();
		System.out.printf("Running %s => %s ...", inf, outf);
		switch (problem) {
		case 'A':
			new R1B_A_SafetyInNumbers(cnt, f, out);
			break;
		case 'B':
			new R1B_B_TideGoesOut(cnt, f, out);
			break;
		case 'C':
			new R1B_C_EqualSums(cnt, f, out);
			break;
		}
		long finish = System.currentTimeMillis();
		System.out.printf(" %dmsec", finish - start);
		f.close();
		out.close();
	}
	public int[] readInts(BufferedReader infile, int cnt) throws IOException {
		String[] ln = infile.readLine().trim().split(" ");
		int[] vals = new int[cnt];
		for (int j = 0; j < cnt; j++)
			vals[j] = Integer.parseInt(ln[j]);
		return vals;
	}

	class A_SpeakingInTongues {
		public A_SpeakingInTongues(int cnt, BufferedReader infile, BufferedWriter outfile) throws IOException {
			String key = "yhesocvxduiglbkrztnwjpfmaq";
			for (int i = 0; i < cnt; i++) {
				String ln = infile.readLine();
				String res = "";
				for (int p = 0; p < ln.length(); p++) {
					if (ln.charAt(p) == ' ')
						res += ' ';
					else
						res += key.charAt(ln.charAt(p) - 'a');
				}
				outfile.write(String.format("Case #%d: %s\r\n", i + 1, res));
			}
		}
	}
	class B_DancingWithTheGooglers {
		public B_DancingWithTheGooglers(int cnt, BufferedReader infile, BufferedWriter outfile) throws IOException {
			Scanner in = new Scanner(infile);
			for (int i = 0; i < cnt; i++) {
				int nGoog = in.nextInt();
				int nSurprise = in.nextInt();
				int best = in.nextInt();

				int bestcnt = 0;
				int surprises = 0;
				int surescore = best * 3 - 2;  // i.e. >=22 ensures a best of 8 (8,7,7)
				if (surescore < 0)
					surescore = 0;
				int surprisescore = surescore - 2;  // i.e. 20,21 could get an 8 with a surprise (8,7,6) (8,6,6)
				if (surprisescore < 0)
					surprisescore = 0;
				for (int j = 0; j < nGoog; j++) {
					int total = in.nextInt();
					if (total >= best && total >= surescore)
						bestcnt++;
					else if (total >= best && total >= surprisescore)
						surprises++;
				}
				int res = bestcnt + (nSurprise >= surprises ? surprises : nSurprise);
				outfile.write(String.format("Case #%d: %d\r\n", i + 1, res));
			}
		}
	}
	class C_RecycledNumbers {
		public C_RecycledNumbers(int cnt, BufferedReader infile, BufferedWriter outfile) throws IOException {
			for (int i = 0; i < cnt; i++) {
				String[] ln = infile.readLine().trim().split(" ");
				int a = Integer.parseInt(ln[0]);
				int b = Integer.parseInt(ln[1]);
				int len = ln[0].length();
				int rescnt = 0;
				String[] rvals = new String[len];
				int rvc;
				for (int v = a; v <= b; v++) {
					String val = Integer.toString(v);
					if (val.length() < len)
						val = "0000000000".substring(0, len - val.length()) + val;
					rvc = 0;
					for (int r = 1; r < len; r++) {
						String rval = val.substring(len - r) + val.substring(0, len - r);
						int rv = Integer.parseInt(rval);
						if (rv > v && rv <= b) {
							boolean isnew = true;
							for (int k = 0; k < rvc; k++)
								if (rvals[k].equals(rval))
									isnew = false;
							if (isnew) {
								rvals[rvc++] = rval;
								rescnt++;
							}
							// else
							// for (int k = 0; k < rvc; k++) {
							// outfile.write(String.format("%s <= %s < %s <= %s\r\n", ln[0], val, rval, ln[1]));
							// }
						}
					}
				}
				outfile.write(String.format("Case #%d: %d\r\n", i + 1, rescnt));
			}
		}
	}
	class D_HallOfMirrors {
		public D_HallOfMirrors(int cnt, BufferedReader infile, BufferedWriter outfile) throws IOException {
			for (int i = 0; i < cnt; i++) {
				String[] ln = infile.readLine().trim().split(" ");
				int nrows = Integer.parseInt(ln[0]);
				int ncols = Integer.parseInt(ln[1]);
				String top = "###############################".substring(0, ncols);
				String mid = "#..............................".substring(0, ncols - 1) + "#";
				float dist = Float.parseFloat(ln[2]);
				String[] rows = new String[nrows];
				int x = -1, y = -1;
				for (int k = 0; k < nrows; k++) {
					rows[k] = infile.readLine().trim();
					if (k == 0 || k == nrows - 1) {
						if (!rows[k].equals(top))
							outfile.write(String.format("Bad top: %d %d %s", i, k, rows[k]));
					} else if (!rows[k].equals(mid)) {
						x = rows[k].indexOf('X');
						y = k;
					}
				}
				assert (x > 0 && y > 0);
				int rescnt = 0;
				System.out.printf("HoM %d: w%d x h%d d=%2.1f (%d,%d) \r\n", i + 1, ncols, nrows, dist, x, y);
				rescnt += rayCnt(dist, ncols - 2f, y - 0.5f, x - 0.5f, "up");  // up
				rescnt += rayCnt(dist, ncols - 2f, nrows - y - 1.5f, x - 0.5f, "dw"); // down
				rescnt += rayCnt(dist, nrows - 2f, x - 0.5f, y - 0.5f, "rt");  // right
				rescnt += rayCnt(dist, nrows - 2f, ncols - x - 1.5f, y - 0.5f, "lf"); // left
				outfile.write(String.format("Case #%d: %d\r\n", i + 1, rescnt));
				System.out.printf("HoM %d: w%d x h%d d=%2.1f (%d,%d) => %d \r\n", i + 1, ncols, nrows, dist, x, y, rescnt);
			}
		}
		private int rayCnt(float maxdist, float width, float depth, float pos, String dir) {
			System.out.printf("%s: ", dir);
			int cnt = 0;
			if (depth * 2f <= maxdist)  // bounce straight back
			{
				cnt++;
				System.out.printf("| ");
			}
			if (2.0 * Math.sqrt(pos * pos + depth * depth) <= maxdist)  // direct to one corner
			{
				cnt++;
				System.out.printf("\\ ");
			}
			if (2.0 * SingleBounceLen(width, depth, pos, 0f) <= maxdist)  // single bounce to corner
			{
				cnt++;
				System.out.printf("<1 ");
			}
			if (2.0 * SingleBounceLen(width, depth, pos, width - pos) <= maxdist) // single bounce to back wall
			{
				cnt++;
				System.out.printf("^1 ");
			}
			for (int i = 2; i < maxdist / width; i++) {   // 1/30 .. 50/3
				if (2.0 * PathLen(i, width, depth, pos, 0f) <= maxdist)  // i bounces to one corner
				{
					cnt++;
					System.out.printf("/%d ", i);
				}
				if (2.0 * PathLen(i, width, depth, pos, width - pos) <= maxdist)  // i bounces to far wall
				{
					cnt++;
					System.out.printf("^%d ", i);
				}
			}
			System.out.printf(" rays %s cnt=%d  \r\n", dir, cnt);
			return cnt;
		}
		private double RadToDeg = 180.0 / Math.PI;
		private double SingleBounceLen(float width, float depth, float nearpos, float farpos) {
			// find bounce angle (ba) such that:
			// depth = Lnear*cos(ba) + Lfar*cos(ba)
			// Lnear*sin(ba) = nearpos
			// Lfar*sin(ba) = farpos
			// bounce angle (ba) must be > 0 (closest if large depth && nearpos==farpos)
			// must also be < 90 (closest if small depth && nearpos + farpos is small)
			double ba = Math.abs(2 * width - nearpos - farpos) / depth;   // ranges from 0..60/3
			ba = (ba * Math.PI / 40.0) + 0.01;  // 0.01..PI/4
			if (ba >= Math.PI / 4.0)
				ba = Math.PI / 4.0 - 0.01;
			System.out.printf("SBLen(w=%2.1f, d=%2.1f, np=%2.1f, fp=%2.1f, ba=%3.2f): ", width, depth, nearpos, farpos, ba * RadToDeg);
			double lnear = 0, lfar = 0, dist = 0.0;
			double adjust = 0.1, preverr = 0;
			int cnt;
			for (cnt = 0; cnt < 20; cnt++) {
				double sba = Math.sin(ba);
				double cba = Math.cos(ba);
				lnear = nearpos / sba;
				lfar = (width - farpos) / sba;
				dist = depth / cba;
				double err = Math.abs(dist - lfar - lnear);
				if (preverr != 0 && err > preverr)
					adjust /= -2;
				// System.out.printf(" [%d  ba=%3.2f ln=%3.2f lf=%3.2f sm=%3.2f e=%3.2f a=%3.2f]\r\n", cnt, ba*RadToDeg, lnear, lfar, dist, err, adjust);
				if (err < 0.1)
					break;
				preverr = err;
				ba += adjust;
			}
			System.out.printf("%d: ba=%3.2f => %f \r\n", cnt, ba * RadToDeg, dist);
			return dist;
		}
		private double PathLen(int nbounces, float width, float depth, float nearpos, float farpos) {
			// calc length of path with nbounces from (nearpos,0) .. (farpos, depth)
			// bounce angle (ba) must be > 0 (closest if nbounces==1 && depth >> width)
			// must also be < 90 (closest if nbounces is large && width >> depth)
			// depth = cos(ba)/Lnear + cos(ba)/Lfar + (nbounces-1)*cos(ba)/Lmid == cos(ba)*(1/Lnear + 1/Lfar + (nb-1)/Lmid)
			// also Lnear*sin(ba) = nearpos && Lfar*sin(ba) = farpos
			double ba = nbounces * width / depth;   // ranges from 2*3/30 = .2 to 17*30/3 == 170
			ba = (ba * 90.0 / 170.0 * Math.PI / 4.0) + 0.01;		// 0.01..90 degrees == 0..PI/4 radians
			if (ba >= Math.PI / 4.0)
				ba = Math.PI / 4.0 - 0.01;
			double lnear = 0, lfar = 0, lmid = 0;
			// but also: width = Lmid*sin(ba)
			// so adjust ba until Lmid = width/sin(ba)
			System.out.printf("PathLen(nb=%d, w=%2.1f, d=%2.1f, np=%2.1f, fp=%2.1f, ba=%3.2f): ", nbounces, width, depth, nearpos, farpos, ba * RadToDeg);

			double preverr = 0;
			double adjust = 0.1;
			int cnt;
			for (cnt = 0; cnt < 20; cnt++) {
				double sba = Math.sin(ba);
				double cba = Math.cos(ba);
				lnear = nearpos / sba;
				lfar = farpos / sba;
				lmid = width / sba;
				double tdepth = lnear * cba + lfar * cba + (nbounces - 1) * lmid * cba;
				double err = Math.abs(depth - tdepth);
				if (preverr != 0 && err > preverr)
					adjust /= -2;
				// System.out.printf(" [%d  ba=%3.2f ln=%3.2f lf=%3.2f lm=%3.2f td=%3.2f e=%3.2f a=%3.2f]\r\n",cnt, ba*RadToDeg, lnear, lfar, lmid, tdepth, err, adjust);

				if (err < 0.1)
					break;
				preverr = err;
				ba += adjust;
			}
			double dist = lnear + lfar + (nbounces - 1) * lmid;
			System.out.printf("%d: ba=%2.0f %3.2f+lf=%3.2f+%d*%3.2f => %f \r\n", cnt, ba * RadToDeg, lnear, lfar, nbounces - 1, lmid, dist);
			return dist;
		}
	}
	class R1B_A_SafetyInNumbers {
		public R1B_A_SafetyInNumbers(int cnt, BufferedReader infile, BufferedWriter outfile) throws IOException {
			for (int i = 0; i < cnt; i++) {
				String[] ln = infile.readLine().trim().split(" ");
				int n = Integer.parseInt(ln[0]);
				int[] scores = new int[n];
				for (int j = 0; j < n; j++)
					scores[j] = Integer.parseInt(ln[j + 1]);

				float[] fraction = new float[n];
				String res = String.format("Case #%d: ", i + 1);
				for (int j = 0; j < n; j++)
					res += String.format(" %f", fraction[j]);
				outfile.write(String.format("%s\r\n", res));
			}
		}
	}
	class R1B_B_TideGoesOut {
		int[][] floor = null;
		int[][] ceiling = null;
		float[][] earliest = null;
		int N, M;
		float WaterHeight;

		public R1B_B_TideGoesOut(int cnt, BufferedReader infile, BufferedWriter outfile) throws IOException {
			for (int i = 0; i < cnt; i++) {
				String[] ln = infile.readLine().trim().split(" ");
				int H = Integer.parseInt(ln[0]);
				WaterHeight = H;
				N = Integer.parseInt(ln[1]);
				M = Integer.parseInt(ln[2]);
				ceiling = new int[N][];
				for (int j = 0; j < N; j++)
					ceiling[j] = readInts(infile, M);
				floor = new int[N][];
				for (int j = 0; j < N; j++)
					floor[j] = readInts(infile, M);

				float MAX = 1000000000f;
				earliest = new float[N][];
				for (int j = 0; j < N; j++) {
					earliest[j] = new float[M];
					for (int k = 0; k < M; k++)
						earliest[j][k] = MAX;
				}

				System.out.printf("\r\n\r\n %d x %d", N, M);
				earliest[0][0] = 0f;
				Reachable(0, 0, 0);
				outfile.write(String.format("Case #%d: %4.1f\r\n", i + 1, earliest[N - 1][M - 1]));
			}
		}
		public void Reachable(int i, int j, float atEarliest) {
//			System.out.printf("\r\n[%d][%d] reachable at %4.2f", i, j, atEarliest);
			if (i==N-1 && j==M-1) return;
			if (i > 0)
				update(i, j, i - 1, j, atEarliest); // N
			if (j < M - 1)
				update(i, j, i, j + 1, atEarliest); // E
			if (i < N - 1)
				update(i, j, i + 1, j, atEarliest); // S
			if (j > 0)
				update(i, j, i, j - 1, atEarliest); // W
		}
		public void update(int si, int sj, int di, int dj, float sourceEarliest) {
			if (earliest[di][dj] <= sourceEarliest)
				return;
//			System.out.printf("\r\n%4.0f [%d][%d]@%3.1f %d..%d => [%d][%d] %d..%d", WaterHeight, si, sj, sourceEarliest, floor[si][sj], ceiling[si][sj], di, dj, floor[di][dj], ceiling[di][dj]);
			if (ceiling[di][dj] - floor[di][dj] < 50)
				return;
			if (ceiling[di][dj] - floor[si][sj] < 50)
				return;
			if (ceiling[si][sj] - floor[di][dj] < 50)
				return;
			float destEarliest = sourceEarliest;
			if (earliest[di][dj] <= sourceEarliest + 1)
				return;

			if (ceiling[di][dj] - WaterHeight > 50) {
				if (sourceEarliest == 0f) {
					destEarliest = 0f;
				} else {
					float travel = 10f;
					if (WaterHeight - floor[si][sj] - 10 * sourceEarliest >= 20f)
						travel = 1f;
					destEarliest = sourceEarliest + travel;
				}
			} else {
				float opens = (WaterHeight - (ceiling[di][dj] - 50)) / 10f;
				if (opens < sourceEarliest) opens = sourceEarliest;
				float travel = 10f;
				if (WaterHeight - floor[si][sj] - 10 * opens >= 20f)
					travel = 1f;
				destEarliest = opens + travel;
			}
			if (destEarliest >= earliest[di][dj])
				return;
			earliest[di][dj] = destEarliest;
			Reachable(di, dj, destEarliest);
		}
	}
	class R1B_C_EqualSums {
		public R1B_C_EqualSums(int cnt, BufferedReader infile, BufferedWriter outfile) throws IOException {
			for (int i = 0; i < cnt; i++) {
				String[] ln = infile.readLine().trim().split(" ");
				int n = Integer.parseInt(ln[0]);
				int[] vals = new int[n];
				for (int j = 0; j < n; j++)
					vals[j] = Integer.parseInt(ln[j + 1]);

				ArrayList<Long> set1 = new ArrayList<Long>();
				ArrayList<Long> set2 = new ArrayList<Long>();
				long total = 0;
				outfile.write(String.format("Case #%d:\r\n", i + 1));
				String res = "";
				for (int j = 0; j < n; j++)
					res += String.format(" %d", set1.get(j));
				outfile.write(res);
				res = "";
				for (int j = 0; j < n; j++)
					res += String.format(" %d", set2.get(j));
				outfile.write(res);
			}
		}
	}
}
