import java.io.*;
import java.util.*;

public class C {

	
	private static boolean nextPerm(int O[], int N) {
		int i = N - 1;
		while(O[i] >= O[i+1])
			if(--i == 0)
				return false;
		int j = N;
		while(O[j] < O[i])
			j--;
		int t = O[i];
		O[i] = O[j];
		O[j] = t;
		j = N + 1;
		while(++i < --j) {
			t = O[i];
			O[i] = O[j];
			O[j] = t;
		}
		return true;
	}
	
	private static int perm(int BFF[], int N) {
		int O[] = new int[N + 1];
		for(int n = 1; n <= N; n++)
			O[n] = n;
		int max = 2;
		do {
		_N:
			for(int n = max + 1; n <= N; n++) {
				int bff = BFF[O[1]], prev = O[n], next = O[2];
				if(bff != prev && bff != next)
					continue _N;
				for(int k = 2; k < n; k++) {
					bff = BFF[O[k]];
					prev = O[k - 1];
					next = O[k + 1];
					if(bff != prev && bff != next)
						break _N;
				}
				bff = BFF[O[n]];
				prev = O[n - 1];
				next = O[1];
				if(bff != prev && bff != next)
					continue _N;
				max = n;
			}
		} while(nextPerm(O, N));
		return max;
	}
	
	public static void main(String args[]) throws Exception {
		String fn = args.length > 0 ?  args[0] :
		//	"C.in";
		//	"C-.in";
		//	"C-small-attempt0.in";
			"C-large.in";
		LineNumberReader in = new LineNumberReader(new FileReader(fn));
		PrintWriter out = new PrintWriter(new FileWriter(fn.replace(".in", ".out")));
		int T = Integer.parseInt(in.readLine());
		for(int i = 0; i < T; i++) {
			out.print("Case #" + (i+1) + ": ");
			final int N = Integer.parseInt(in.readLine());
			int BFF[] = new int[N + 1];
			StringTokenizer st = new StringTokenizer(in.readLine());
			for(int n = 1; n <= N; n++)
				BFF[n] = Integer.parseInt(st.nextToken());
		
			if(false) {
				int max = perm(BFF, N);
				out.println(max);
				out.flush();
				continue;
			}
			
			int visited[] = new int[N + 1];
			int maxCircle = 0;
			int maxSegment[] = new int[N + 1];
			for(int a = 1; a <= N; a++) {
				int cur = a;
				int len = 1, next;
				for(;;) {
					next = BFF[cur];
					if(next == a) {
						if(len > maxCircle)
							maxCircle = len;
						break;
					}
					if(visited[next] > 0)
						break;
					visited[next] = cur;
					cur = next;
					len++;
				}
				if(visited[cur] == next)
					if(maxSegment[next] < len)
						maxSegment[next] = len;
				while(cur > 0) {
					int prev = visited[cur];
					visited[cur] = 0;
					cur = prev;
				}
			}
			int maxSegments = 0;
			for(int a = 1; a <= N; a++)
				if(BFF[BFF[a]] == a) {
					int s = maxSegment[a] + maxSegment[BFF[a]] - 2;
					maxSegments += s;
				}
			out.println(Math.max(maxCircle, maxSegments / 2));
			out.flush();
		}
		out.close();
	}
}
