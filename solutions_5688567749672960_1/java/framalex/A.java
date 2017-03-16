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

    private long pow10(int val) {
        long ans = 1L;
        for (int i = 0; i < val; ++i) {
            ans *= 10;
        }
        return ans;
    }

    private long clearN(long num, int n) {
        long t = (num/pow10(n))*pow10(n)+1;
        if (t > num) {
            t = (num/pow10(n) - 1)*pow10(n)+1;
        }
        return t;
    }

    private int upperDigit(long num) {
        return (int)(num/pow10(zeroes(num)-1));
    }

    private long reqToLessZeroes(long num) {
        return pow10(zeroes(num));
    }

    public void run() {
        int tests = nextInt();
        for (int iter = 1; iter <= tests; ++iter) {
            long ans = 0;
            long n = nextLong();

           // long corrAns = getCorrAns(n);

                //get enought zeroes
                ans = calc(n)+1;


           // if (ans != corrAns) {
           //     System.out.println("Error! for n="+n+" ans=" + corrAns + ", not " + ans);
           // }
            out.println("Case #" + iter + ": " + ans);
        }
        out.flush();
    }

    private long calc(long n) {
        HashMap<Long, Long> map = new HashMap<>();
        map.put(n, 0L);
        LinkedList<Long> q = new LinkedList<>();
        q.add(n);

        while(!q.isEmpty()) {
            long cur = q.removeFirst();
            if (cur < 10) {
                long score = 0;
                if (map.containsKey(cur)) {
                    score = map.get(cur);
                }
                if (!map.containsKey(1L) || map.get(1L) > cur + score - 1) {
                    map.put(1L, cur - 1 + score);
                }
            }
            for (int i = 1; i < zeroes(cur); ++i) {
                long score = 0;
                long t = clearN(cur, i);
                if (t > cur) {
                    continue;
                }
                score += cur - t;
                long t2 = t;
                long score2 = score;

                if (!map.containsKey(t) || map.get(t) > map.get(cur) + score) {
                    map.put(t, map.get(cur) + score);
                    q.addLast(t);
                }
                if (upperDigit(t) == 1) {
                    long sub =  (t-pow10(zeroes(t)-1)) + 9;
                    t -= sub;
                    score += sub;

                    if (!map.containsKey(t) || map.get(t) > map.get(cur) + score) {
                        map.put(t, map.get(cur) + score);
                        q.addLast(t);
                    }
                }

                t2 = rev(t2);
                ++score2;


                if (!map.containsKey(t2) || map.get(t2) > map.get(cur) + score2) {
                    map.put(t2, map.get(cur) + score2);
                    q.addLast(t2);
                }

                if (upperDigit(t2) == 1) {
                    long sub =  (t2-pow10(zeroes(t2)-1)) + 9;
                    t2 -= sub;
                    score2 += sub;

                    if (!map.containsKey(t2) || map.get(t2) > map.get(cur) + score2) {
                        map.put(t2, map.get(cur) + score2);
                        q.addLast(t2);
                    }
                }
            }
        }
        return map.get(1L);
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
