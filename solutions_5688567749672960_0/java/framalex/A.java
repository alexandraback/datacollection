package gcj.c2015.r1b;



import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;

public class A implements Runnable {

    private int zeroes(long n) {
        int ans = 0;
        while (n > 0) {
            n /= 10;
            ++ans;
        }
        return ans;
    }

    private long rev(long n) {
        long ans = 0;
        while (n > 0) {
            ans *= 10;
            ans += n%10;
            n /= 10;
        }
        return ans;
    }

    private long getNextNum(long cur, int reqLastNum) {
        long p = 1;
        for (int i = 0; i < zeroes(cur); ++i) {
            p *= 10;
        }
        p += reqLastNum;
        return p;
    }

    public void run() {
        int tests = nextInt();
        for (int iter = 1; iter <= tests; ++iter) {
            long ans = 0;
            long n = nextLong();

            long corrAns = getCorrAns(n);

            if (n <= 20) {
                ans = n;
            } else if (n < 100) {
                ans += 10 + n/10;
                ans += n - (n/10*10+1)+1;
            } else {
                //get enought zeroes

                ans += 19;
                long cur = 19;
                while (zeroes(cur) + 1 < zeroes(n)) {
                    cur = rev(cur);
                    ans += 1;
                    long next = getNextNum(cur, 9);
                    ans += next-cur;
                    cur = next;
                }
                cur = rev(cur);
                ++ans;

                long req = n/(getNextNum(cur, 0));
                long next = getNextNum(cur, (int)req);
                ans += next - cur;
                cur = next;

                cur = rev(cur);
                ++ans;

                ans += n-cur;

            }

            if (ans != corrAns) {
                System.out.println("Error! for n="+n+" ans=" + corrAns + ", not " + ans);
            }
            out.println("Case #" + iter + ": " + corrAns);
        }
        out.flush();
    }

    private long getCorrAns(long n) {
        HashMap<Integer, Integer> map = new HashMap<>();
        HashMap<Integer, Integer> prev = new HashMap<>();
        map.put(1, 1);
        LinkedList<Integer> q = new LinkedList<>();
        q.add(1);

        while (!q.isEmpty()) {
            int num = q.removeFirst();

            int nn = num + 1;
            if (!map.containsKey(nn) || map.get(nn) > map.get(num) + 1) {
                if (nn <= n) {
                    map.put(nn, map.get(num) + 1);
                    prev.put(nn, num);
                    q.addLast(nn);
                }
            }

            nn = (int)rev(num);
            if (!map.containsKey(nn) || map.get(nn) > map.get(num) + 1) {
                if (nn <= n) {
                    map.put(nn, map.get(num) + 1);
                    prev.put(nn, num);
                    q.addLast(nn);
                }
            }
        }

        int pos = (int)n;
        while (pos != 1) {
        //    System.out.printf("%d ", pos);
            pos = prev.get(pos);
        }
        System.out.printf("\n");
        return map.get((int)n);
    }

    private static BufferedReader br = null;
    private static PrintWriter out = null;
    private static StringTokenizer stk = null;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new FileReader(new File("A.txt")));
        out = new PrintWriter("AA.txt");
        (new A()).run();
    }

    private void loadLine() {
        try {
            stk = new StringTokenizer(br.readLine());
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    private String nextLine() {
        try {
            return (br.readLine());
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private int nextInt() {
        while (stk == null || !stk.hasMoreElements()) loadLine();
        return Integer.parseInt(stk.nextToken());
    }

    private long nextLong() {
        while (stk == null || !stk.hasMoreElements()) loadLine();
        return Long.parseLong(stk.nextToken());
    }

    private double nextDouble() {
        while (stk == null || !stk.hasMoreElements()) loadLine();
        return Double.parseDouble(stk.nextToken());
    }

    private String nextWord() {
        while (stk == null || !stk.hasMoreElements()) loadLine();
        return (stk.nextToken());
    }
}
