import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {

    static int solve1(int N, int[] friends) {
        int res = 1;
        int[] select = new int[N];
        boolean[] circle = new boolean[N];
        Arrays.fill(select, -1);
        boolean[] head = new boolean[N];
        Arrays.fill(head, true);
        for (int val : friends) {
            head[val] = false;
        }
        for (int i = 0; i < N; ++i) {
            if (!head[i]) {
                ArrayList<Integer> data = new ArrayList<>();
                int current = i;
                boolean[] used = new boolean[N];
                used[current] = true;
                data.add(current);
                int next = friends[current];
                int count = 1;
                while (!used[next]) {
                    ++count;
                    used[next] = true;
                    data.add(next);
                    next = friends[next];
                }
                if (next == i) {
                    res = Math.max(res, count);
                    for (int val : data) {
                        circle[val] = true;
                    }
                    if (count == 2) {
                        select[data.get(0)] = 0;
                        select[data.get(1)] = 0;
                    }
                }
            }
        }
        // System.out.println(Arrays.toString(select));
        // System.out.println(Arrays.toString(head));
        // System.out.println(Arrays.toString(circle));
        for (int i = 0; i < N; ++i) {
            if (head[i]) {
                int current = i;
                int next = friends[current];
                int count = 1;
                while (!circle[next]) {
                    ++count;
                    next = friends[next];
                }
                if (select[next] >= 0) {
                    select[next] = Math.max(select[next], count);
                }
            }
        }
        // System.out.println(Arrays.toString(select));
        int temp = 0;
        for (int val : select) {
            if (val >= 0) {
                temp += val + 1;
            }
        }
        res = Math.max(res, temp);
        return res;
    }

    static int N;
    static int[] friends;
    static int r = 1;

    static void search(int[] arr, boolean[] used, int count) {
        if (count > 1) {
            boolean pass = true;
            for (int i = 0; i < count; ++i) {
                if (friends[arr[i]] == arr[(i + 1) % count] || friends[arr[i]] == arr[(i - 1 + count) % count]) {
                    continue;
                } else {
                    pass = false;
                    break;
                }
            }
            if (pass) {
                r = Math.max(r, count);
            }
        }
        if (count == arr.length) {
            return;
        }
        for (int i = 0; i < arr.length; ++i) {
            if (!used[i]) {
                used[i] = true;
                arr[count] = i;
                search(arr, used, count + 1);
                used[i] = false;
            }
        }
    }

    static int solve2(int N, int[] friends) {
        r = 0;
        int[] arr = new int[N];
        boolean[] used = new boolean[N];
        for (int i = 0; i < N; ++i) {
            used[i] = true;
            arr[0] = i;
            search(arr, used, 1);
            used[i] = false;
        }
        return r;
    }

    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            N = scan.nextInt();
            friends = new int[N];
            for (int i = 0; i < N; ++i) {
                friends[i] = scan.nextInt() - 1;
            }
            int res = solve1(N, friends);
            // int res = solve2(N, friends);
            System.out.println(String.format("Case #%d: %d", taskIndex, res));
        }
    }
}

class FastScanner {
    BufferedReader in;
    StringTokenizer tok;

    public FastScanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }

    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }

    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }
        return tok.nextToken();
    }

    private String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() {
        return Long.parseLong(nextToken());
    }

}
