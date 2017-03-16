import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class BFF {
	//static boolean[][] bucket;
	static boolean[] started;
	public static void main(String[] args) throws IOException {
		// BufferedReader in = new BufferedReader(new
		// InputStreamReader(System.in));
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("largeout.txt"));
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			int n = in.nextInt();
			started = new boolean[n+1];
			//bucket = new boolean[n + 1][n + 1];
			int[] map = new int[n + 1];
			for (int j = 1; j <= n; j++) {
				map[j] = in.nextInt();
				//bucket[j][map[j]] = true;
			}
			// go through cycles
			int max = 0;
			for(int j = 1;j<=n;j++){
				if(started[j]){
					continue;
				}
				max = Math.max(max, cycle(map,j));
			}
			out.println("Case #" + String.valueOf(i+1)+": " + String.valueOf(max));
		}
		out.close();
	}

	static int cycle(int[] map, int start) {
		int count = 0;
		boolean[] tracker = new boolean[map.length];
		int[] cumCount = new int[map.length];
		int n = start;
		while (!tracker[n]) {
			tracker[n] = true;
			started[n] = true;
			cumCount[n] = count;
			count++;
			n = map[n];
		}
		if (n == start) {
			return count;
		}
		// a goes to b and b goes to a
		if (map[map[n]] == n) {
			int last = map[n];
			boolean x = false;
			loop:
			while (!x) {
				for (int i = 1; i < tracker.length; i++) {
					// keep adding someone to the end

					if (!tracker[i] && map[i] == last) {
						last = i;
						tracker[i] = true;
						started[i] = true;
						count++;
						continue loop;
					}
				}
				x= true;
			}
			return count;
		}
		//sad case
		count = count-cumCount[n]+1;
		return count;
	}
}
