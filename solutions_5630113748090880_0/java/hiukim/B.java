import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.*;

public class B {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    public void task() throws IOException {
        int N = nextInt();
        int[][] lists = new int[2*N-1][N];
        for (int i = 0; i < 2*N-1; i++) {
            lists[i] = new int[N];
            for (int j = 0; j < N; j++) {
                lists[i][j] = nextInt();
            }
        }

        Arrays.sort(lists, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] < o2[0]? -1: 1;
            }
        });

        int listCount = 2*N-1;
        outer: for (int m = 0; m < (1 << listCount); m++) {
            ArrayList<Integer> rows = new ArrayList<Integer>();
            ArrayList<Integer> cols = new ArrayList<Integer>();
            for (int i = 0; i < listCount; i++) {
                if ( (m & (1<<i)) != 0) {
                    rows.add(i);
                } else {
                    cols.add(i);
                }
            }

            if (rows.size() != N && rows.size() != N-1) {
                continue;
            }

//            out.println( Arrays.toString(rows.toArray()));
//            out.println( Arrays.toString(cols.toArray()));

            int[][] grid = new int[N][N];
            ArrayList<Integer> fullDimension = rows.size() == N? rows: cols;
            ArrayList<Integer> anotherDimension = rows.size() == N? cols: rows;

//            out.println();
            for (int i = 0; i < N; i++) {
                int[] list = lists[fullDimension.get(i)];
//                out.println("list " + fullDimension.get(i) + ": " + Arrays.toString(list));
                for (int j = 0; j < N; j++) {
                    grid[i][j] = list[j];
                }
            }

            for (int i = 1; i < N; i++) {
                if (grid[i][0] <= grid[i - 1][0]) {
                    continue outer;
                }
            }
//            out.println("cool");

            int missing = -1;
            int curAnother = 0;
            for (int i = 0; i < N; i++) {
                if (curAnother == N-1) {
                    missing = N-1;
                } else {
                    int[] list = lists[anotherDimension.get(curAnother)];
                    if (grid[0][i] == list[0]) {
                        for (int j = 0; j < N; j++) {
                            if (grid[j][i] != list[j]) {
                                continue outer;
                            }
                        }

                        curAnother++;
                    }
                    else if (missing != -1) {
                        continue outer;
                    } else {
                        missing = i;
                    }
                }
            }

            for (int j = 0; j < N; j++) {
                out.print(grid[j][missing] + " ");
            }
            out.println();
            break;

        }


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
		new B().run();
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
