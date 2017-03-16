import java.io.*;
import java.util.*;

public class B {
    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;
    int n;
    int res;
    StringBuilder[] arr;
    HashMap<StringBuilder, Integer> same;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    void gen(boolean[] used, StringBuilder s, int k, ArrayList<Integer> a) {
        if (k == 0) {
            res += check(s);
        }
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                s.append(arr[i]);
                a.add(arr[i].length());
                used[i] = true;
                gen(used, s, k - 1, a);
                used[i] = false;
                s.delete(s.length() - a.remove(a.size() - 1), s.length());
            }
        }
    }

    int check(StringBuilder s) {
        boolean[] finished = new boolean[26];
        boolean flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (finished[(int)s.charAt(i) - (int)'a']) {
                flag = false;
                break;
            }
            if (i >= 1 && s.charAt(i - 1) != s.charAt(i)) {
                finished[(int)s.charAt(i - 1) - (int)'a'] = true;
            }
        }
        if (flag) {
            return 1;
        } else {
            return 0;
        }
    }

    public void solve() throws IOException {
        int t = nextInt();
        for (int c = 1; c <= t; c++) {
            n = nextInt();
            res = 0;
            arr = new StringBuilder[n];
            same = new HashMap<StringBuilder, Integer>();
            for (int i = 0; i < n; i++) {
                arr[i] = new StringBuilder(nextToken());
            }
            for (int i = 0; i < n; i++) {
                if (same.containsKey(arr[i])) {
                    same.put(arr[i], same.get(arr[i]) + 1);
                } else {
                    same.put(arr[i], 1);
                }
            }
            gen(new boolean[n], new StringBuilder(), n, new ArrayList<Integer>());
            for (int i = 0; i < n; i++) {
                res *= same.get(arr[i]);
                same.put(arr[i], 1);
            }
            out.println("Case #" + c + ": " + res);
            out.flush();
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}