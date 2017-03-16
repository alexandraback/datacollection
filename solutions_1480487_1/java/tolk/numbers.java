import java.io.*;
import java.util.*;

class numbers {
	public static void main (String [] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new FileReader("numbers.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("numbers.out")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			int[] scores = new int[num];
			int tot = 0;
			for (int j = 0; j < num; j++) {
				scores[j] = Integer.parseInt(st.nextToken());
				tot += scores[j];
			}
			double[] percent = new double[num];
			out.print("Case #" + (i+1) + ": ");
			for (int j = 0; j < num; j++) {
				int curscore = scores[j];
				ArrayList newscores = new ArrayList();
				for (int k = 0; k < num; k++) {
					if (k != j) {
						newscores.add(scores[k]);
					}
				}
				Collections.sort(newscores);
				int cursum = 0;
				for (int k = 0; k < num - 1; k++) {
					cursum = cursum + Integer.parseInt(newscores.get(k).toString());
					double curtest = (double)(1/((double)k+2))*(double)((double)cursum+(double)tot+(double)curscore);
					if (i == 5) {
						System.out.println(curtest + " " + k + " " + cursum + " " + tot + " " + curscore);
					}
					if (k != num - 2) {
						if (curtest <= Integer.parseInt(newscores.get(k+1).toString())) {
							percent[j] = Math.max((curtest - curscore)/tot*100,0);
							out.print(percent[j] + " ");
							break;
						}
					} else {
						percent[j] = Math.max((curtest - curscore)/tot*100,0);
						out.print(percent[j] + " ");
						break;
					}
				}
			}
			out.println();
		}
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		out.close();
		System.exit(0);
	}
}

