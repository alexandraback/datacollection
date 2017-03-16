import java.io.*;


public class CJ1C_C {
	public static void main (String[] args) {
		String fName = "C-small-attempt0";
		try {
			BufferedReader inp = new BufferedReader(new FileReader(fName + ".in"));
			PrintWriter out = new PrintWriter(new FileWriter(fName + ".out"));
			PrintStream scr = System.out;
			String l = inp.readLine();
			String[] lArr;
			int T = Integer.parseInt(l);
			for (int ii = 1; ii <= T; ii++) {
				l = inp.readLine();
				int N = Integer.parseInt(l);
				int[] d = new int [N];
				int[] n = new int [N];
				int[] w = new int [N];
				int[] intrvl = new int [N];
				int[] s = new int [N];
				int[] delta_d = new int [N];
				int[] delta_s = new int [N];
				int[] delta_p = new int [N];
				int[] nextAttack = new int [N];
				int[] strength = new int [N];
				int[] curPos = new int [N];
				int left = Integer.MAX_VALUE, right = Integer.MIN_VALUE, tDays = 0;
				int minDay = Integer.MAX_VALUE;
				for (int i = 0; i < N; i++) {
					l = inp.readLine();
					lArr = l.split(" ");
					d[i] = Integer.parseInt(lArr[0]);
					n[i] = Integer.parseInt(lArr[1]);
					w[i] = Integer.parseInt(lArr[2]);
					intrvl[i] = Integer.parseInt(lArr[3]) - w[i];
					s[i] = Integer.parseInt(lArr[4]);
					delta_d[i] = Integer.parseInt(lArr[5]);
					delta_p[i] = Integer.parseInt(lArr[6]);
					delta_s[i] = Integer.parseInt(lArr[7]);
					int days = d[i] + (n[i] - 1) * delta_d[i];
					tDays = tDays > days ? tDays : days;
					int mW = w[i] + (n[i] - 1) * delta_p[i];
					if (delta_p[i] >= 0) {
						left = left < w[i] ? left : w[i];
						right = right > (mW + intrvl[i]) ? right : (mW + intrvl[i]);
					}
					else {
						left = left < mW ? left : mW;
						right = right > (w[i] + intrvl[i]) ? right : (w[i] + intrvl[i]);
					}
					nextAttack[i] = d[i];
					strength[i] = s[i];
					curPos[i] = w[i];
					minDay = nextAttack[i] < minDay ? nextAttack[i] : minDay;
				}
				int[] wall = new int [right - left + 1];
				long count = 0;
				for (int i = minDay; i <= tDays; i++) {
					int[] maxIncr = new int [right - left + 1];
					for (int j = 0; j < N; j++) {
						boolean isAttacked = false;
						if (i == nextAttack[j]) {
							for (int k = curPos[j] - left; k < curPos[j] + intrvl[j] - left; k++) {
								if (wall[k] < strength[j]) {
									isAttacked = true;
									int incr = strength[j] - wall[k];
									maxIncr[k] = maxIncr[k] > incr ? maxIncr[k] : incr;
								}
							}
							if (nextAttack[j] + delta_d[j] <= d[j] + (n[j] - 1) * delta_d[j])
								nextAttack[j] += delta_d[j];
							curPos[j] += delta_p[j];
							strength[j] += delta_s[j];
						}
						if (isAttacked)
							count++;
					}
					for (int j = 0; j < wall.length; j++)
						wall[j] += maxIncr[j];
				}
				String toPrint = String.valueOf(count);
				out.println("Case #" + ii + ": " + toPrint);
				scr.println("Case #" + ii + ": " + toPrint);
			}
			out.close();
			inp.close();
		}catch (Exception e) {
			e.printStackTrace();
		}
	}
}