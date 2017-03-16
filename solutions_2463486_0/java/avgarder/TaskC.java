import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class TaskC implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer stok;

    String nextToken() {
        try {
            while (stok == null || !stok.hasMoreTokens()) {
                stok = new StringTokenizer(in.readLine());
            }
            return stok.nextToken();
        } catch (IOException e) {
            return null;
        }
    }

    int nextInt() {
        return Integer.parseInt(nextToken());
    }

    long nextLong() {
        return Long.parseLong(nextToken());
    }

    double nextDouble() {
        return Double.parseDouble(nextToken());
    }


    int[] nums = new int[30];
    boolean isPalindrom(long x) {

        int len = 0;
        while (x > 0) {
            nums[len] = (int) x % 10;
            x /= 10;
            len++;
        }

        for (int i = 0; i < len / 2; i++) {
            if (nums[i] != nums[len - 1 - i]) {
                return false;
            }
        }

        return true;
    }

    long reverse(long x) {
        int len = 0;
        while (x > 0) {
            nums[len] = (int) x % 10;
            x /= 10;
            len++;
        }

        long res = 0;
        for (int i = 0; i < len; i++) {
            res = res * 10 + nums[i];
        }
        return res;
    }

//    BigInteger toPal(long x) {
//        String s = "" + x;
//        String t = s;
//        for (int i = s.length() - 1; i >= 0; i--) {
//            t += s.charAt(i);
//        }
//        return new BigInteger(t);
//    }
//
//    BigInteger toPal2(long x, int num) {
//        String s = "" + x;
//        String t = num + s;
//        for (int i = s.length() - 1; i >= 0; i--) {
//            t += s.charAt(i);
//        }
//        return new BigInteger(t);
//    }

    boolean isPalindrom(BigInteger x) {
        String s = x.toString();
        for (int i = 0, len = s.length(); i < len / 2; i++) {
            if (s.charAt(i) != s.charAt(len - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    BigInteger toPal(BigInteger x) {
        String s = "" + x;
        String t = s;
        for (int i = s.length() - 1; i >= 0; i--) {
            t += s.charAt(i);
        }
        return new BigInteger(t);
    }

    BigInteger toPal2(BigInteger x, int num) {
        String s = "" + x;
        String t = s + num;
        for (int i = s.length() - 1; i >= 0; i--) {
            t += s.charAt(i);
        }
        return new BigInteger(t);
    }

    // File names!!!

    int sum(long x) {
        int res = 0;
        while (x > 0) {
            res += x % 2;
            x /= 2;
        }
        return res;
    }

    void solve() throws IOException {
        ArrayList<BigInteger> ans = new ArrayList<BigInteger>();
        for (long i = 1; i < 10; i++) {
            if (isPalindrom(i * i)) {
                ans.add(BigInteger.valueOf(i * i));
            }
        }
        for (int i = 0; i <= 25; i ++) {
            System.out.println(i);
            long p = 1 << i;
            for (long mask = 0; mask < p; mask++) {
                if (sum(mask) > 5) {
                    continue;
                }
                long t = p | mask;
                String s = Long.toBinaryString(t);
                BigInteger c = new BigInteger(s);
                BigInteger c1 = toPal(c);
                if (isPalindrom(c1.pow(2))) {
                    ans.add(c1.pow(2));
                }
                for (int j = 0; j < 3; j++) {
                    c1 = toPal2(c, j);
                    if (isPalindrom(c1.pow(2))) {
                        ans.add(c1.pow(2));
                    }
                }
            }
            String s = Long.toBinaryString(p);
            BigInteger c = new BigInteger(s).multiply(BigInteger.valueOf(2));
            BigInteger c1 = toPal(c);
            if (isPalindrom(c1.pow(2))) {
                ans.add(c1.pow(2));
            }

            for (int j = 0; j < 2; j++) {
                c1 = toPal2(c, j);
                if (isPalindrom(c1.pow(2))) {
                    ans.add(c1.pow(2));
                }
            }
        }

        Collections.sort(ans);

        System.out.println(ans.get(ans.size() - 1).toString().length());

        int ct = nextInt();
        for (int nt = 1; nt <= ct; nt++) {
            out.print("Case #" + nt + ": ");
            BigInteger a = new BigInteger(nextToken());
            BigInteger b = new BigInteger(nextToken());
            int ansc = 0;
            for (BigInteger i : ans) {
                if (i.compareTo(a) >= 0 && i.compareTo(b) <= 0) {
                    ansc++;
                }
            }
            out.println(ansc);
        }
    }

    public void run() {
        try {
            in = new BufferedReader(new FileReader("taskc.in"));
            out = new PrintWriter("taskc.out");
            solve();
            out.close();
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        new Thread(new TaskC()).start();
    }
}
