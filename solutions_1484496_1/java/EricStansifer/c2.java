import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class c2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));

        int T = sc.nextInt();

        for (int casenumber = 1; casenumber <= T; ++casenumber) {

            int N = sc.nextInt();
            long[] s = new long[N];
            for (int i = 0; i < N; ++i)
                s[i] = sc.nextLong();

            HashMap<Long, ArrayList<Long>> hm = new HashMap<Long, ArrayList<Long>>(10000000);

outer:
            while (true) {
                for (int i = 1; i < N / 2; ++i) {
                    int j = (int) (Math.random() * (i + 1));
                    if (j < i) {
                        long temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
                }

                ArrayList<Long> al = new ArrayList<Long>();
                for (int i = 0; i < N / 2; ++i) {
                    al.add(s[i]);
                }

                long ss = 0;
                for (int i = 0; i < N / 4; ++i) {
                    ss += s[i];
                }
                for (int i = N / 4; i < N / 2; ++i) {
                    if (hm.containsKey(ss)) {
                        ArrayList<Long> al2 = hm.get(ss);
                        int j = 0;
                        while (j < N) {
                            ss -= al2.get(j);
                            ++j;
                            if (ss == 0) break;
                        }
                        System.out.format("Case #%d:%n", casenumber);
                        for (int i1 = 0; i1 < i; ++i1) {
                            System.out.print(al.get(i1));
                            System.out.print(" ");
                        }
                        System.out.println();
                        for (int j1 = 0; j1 < j; ++j1) {
                            System.out.print(al2.get(j1));
                            System.out.print(" ");
                        }
                        System.out.println();
                        break outer;
                    } else {
                        hm.put(ss, al);
                    }
                    ss += al.get(i);
                }
            }
        }
    }
}
