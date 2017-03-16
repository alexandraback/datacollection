import gcj.GCJ;

import java.util.Arrays;
import java.util.Scanner;

public class FairandSquare {

    static final int MX = 10000001;

    long[] table;

    int cnt = 0;

    public void go() {
        Scanner s = GCJ.createScanner('C', true);
        init();
        int t = s.nextInt();
        for (int i = 1; i <= t; i++) {
            long a = s.nextLong();
            long b = s.nextLong();
            int idxA = Arrays.binarySearch(table, a);
            if (idxA < 0) {
                idxA = -idxA - 1;
            }
            int idxB = Arrays.binarySearch(table, b);
            if (idxB < 0) {
                idxB = -idxB - 2;
            }
            GCJ.out(i, Integer.toString(idxB - idxA + 1));
        }
    }

    private void init() {
        long[] tmp = new long[MX];
        for (long i = 1; i < MX; i++) {
            if (isPal(i)) {
                long ii = i * i;
                if (isPal(ii)) {
                    tmp[cnt++] = ii;
                }
            }
        }
        table = new long[cnt];
        for (int i = 0; i < cnt; i++) {
            table[i] = tmp[i];
        }
    }

    private boolean isPal(long num) {
        if (num % 10 == 0) {
            return false;
        }
        long pre = 0;
        while (num > pre) {
            pre = pre * 10 + num % 10;
            if (num == pre) {
                return true;
            }
            num /= 10;
        }
        return num == pre;
    }

    public static void main(String[] args) {
        FairandSquare fs = new FairandSquare();
        fs.go();
    }

}
