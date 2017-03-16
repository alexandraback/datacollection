import java.io.*;
import java.util.*;

class subsets {
	public static void main (String [] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new FileReader("subsets.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("subsets.out")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int[] nums = new int[N];
			for (int j = 0; j < N; j++) {
				nums[j] = Integer.parseInt(st.nextToken());
			}
			ArrayList subsets = new ArrayList();
			out.println("Case #" + (i+1) + ": ");
			boolean worked = false;
			for (int j = 1; j < Math.pow(2, N); j++) {
				int cursum = 0;
				for (int k = 0; k < N; k++) {
					if ((j & (int)(Math.pow(2, k))) == Math.pow(2,k)) {
						cursum += nums[k];
					}
				}
				for (int k = 0; k < subsets.size(); k++) {
					int[] curtest = (int[])subsets.get(k);
					if (curtest[0] == cursum) {
						worked = true;
						int curj = curtest[1];
						for (int l = 0; l < N; l++) {
							if ((curj & (int)(Math.pow(2, l))) == Math.pow(2,l)) {
								out.print(nums[l] + " ");
							}
						}
						out.println();								
						for (int l = 0; l < N; l++) {
							if ((j & (int)(Math.pow(2, l))) == Math.pow(2,l)) {
								out.print(nums[l] + " ");
							}
						}
						out.println();
					}
				}
				if (worked) {
					break;
				} else {
					int[] current = new int[2];
					current[0] = cursum;
					current[1] = j;
					subsets.add(current);
				}
			}
			if (!worked) {
				out.println("IMPOSSIBLE");
			}
		}
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		out.close();
		System.exit(0);
	}
}
