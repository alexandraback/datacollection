import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class C {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    public void task() throws IOException {
        int N = nextInt();
        int[] likes = new int[N];
        ArrayList<Integer>[] beingLikes = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            beingLikes[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < N; i++) {
            int like = nextInt()-1;
            likes[i] = like;
            beingLikes[like].add(i);
        }

        int best = 0;
        boolean[] computed = new boolean[N];
        for (int i = 0; i < N; i++) {
            if (computed[i]) continue;
            if (likes[likes[i]] == i) {
                computed[i] = true;
                computed[likes[i]] = true;

                int d1 = compute(i, likes[i], beingLikes);
                int d2 = compute(likes[i], i, beingLikes);

                best += (d1 + d2 + 2);

//                best = Math.max(best, d1 + d2 + 2);
            }
        }

        for (int i = 0; i < N; i++) {
            boolean[] used = new boolean[N];

            int cur = likes[i];
            used[i] = true;
            used[cur] = true;

            int d = 2;
            while (true) {
                if (likes[cur] == i) {
                    break;
                } else if (used[likes[cur]]) {
                    d = 0;
                    break;
                } else {
                    d++;
                    cur = likes[cur];
                    used[cur] = true;
                }
            }

            best = Math.max(best, d);
        }

        out.println(best);
    }

    public int compute(int start, int skip, ArrayList<Integer>[] beingLikes) {
        int N = beingLikes.length;
        int[] distances = new int[N];
        Arrays.fill(distances, -1);
        distances[start] = 0;
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(start);
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int v: beingLikes[cur]) {
                if (v == skip) continue;
                distances[v] = distances[cur] + 1;
                queue.add(v);
            }
        }
        int max = 0;
        for (int i = 0; i < N; i++) {
            max = Math.max(max, distances[i]);
        }
        return max;
    }

        
	public void solve() throws IOException {
		int T = nextInt();
		for(int t = 1; t <= T; t++){
			out.print("Case #" + (t) + ": ");
			task();
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new C().run();
	}
	
	public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            out = new PrintWriter(System.out);
            solve();
            reader.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

}
