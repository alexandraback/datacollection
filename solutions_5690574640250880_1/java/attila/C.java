package at.jaki.round0.C;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class C {
    private static final String INPUT = "C-large.in";
    private static final String OUTPUT = "C-large.out";

    //private static final String INPUT = "C-small-attempt0.in";
    //private static final String OUTPUT = "C-small-attempt0.out";

    //private static final String INPUT = "C-test.in";
    //private static final String OUTPUT = "C-test.out";

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(OUTPUT);
        int totalTests = Integer.parseInt(br.readLine());
        for (int testNo = 1; testNo <= totalTests; testNo++) {
            String[] s = br.readLine().split(" ");
            int r = Integer.parseInt(s[0]);
            int c = Integer.parseInt(s[1]);
            int m = Integer.parseInt(s[2]);
            int w = r * c - m;

            StringBuilder sb = new StringBuilder();
            if (r == 1) {
                sb.append('c');
                w--;
                while (w > 0) {
                    sb.append('.');
                    w--;
                }
                while (sb.length() < c) {
                    sb.append('*');
                }
            } else if (c == 1) {
                sb.append('c');
                w--;
                sb.append('\n');
                while (w > 0) {
                    sb.append('.');
                    sb.append('\n');
                    w--;
                }
                while (sb.length() < r * 2) {
                    sb.append('*');
                    sb.append('\n');
                }
                sb.delete(sb.length() - 1, sb.length());
            } else if (w == 1) {
                sb.append('c');
                for (int i = 1; i < c; i++) sb.append('*');
                sb.append('\n');
                for (int i = 1; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        sb.append('*');
                    }
                    sb.append('\n');
                }
                sb.delete(sb.length() - 1, sb.length());
            } else if (w < 4 || w == 5 || w == 7) {
                sb = new StringBuilder("Impossible");
            } else if ((r == 2 || c == 2) && (w & 1) == 1) {
                sb = new StringBuilder("Impossible");
            } else {
                int[] b = new int[r];
                int count;
                int unt;
                if ((w & 1) == 0) {
                    b[0] = 2;
                    b[1] = 2;
                    count = 4;
                    unt = 2;
                } else {
                    b[0] = 3;
                    b[1] = 3;
                    b[2] = 3;
                    count = 9;
                    unt = 3;
                }
                int curr = 2;
                while (count < w) {
                    if (b[0] < c) {
                        b[0]++;
                        b[1]++;
                        count += 2;
                    } else if (unt < r) {
                        b[unt] = 2;
                        unt++;
                        count += 2;
                    } else {
                        if (b[curr] < c) {
                            b[curr]++;
                            count++;
                        } else {
                            curr++;
                            b[curr]++;
                            count++;
                        }
                    }
                }

                sb = print(b, r, c);
            }

            pw.println("Case #" + testNo + ": ");
            pw.println(sb);
            System.out.println(sb);
        }

        pw.flush();
        pw.close();

    }

    private static StringBuilder print(int[] b, int r, int c) {
        StringBuilder sb = new StringBuilder();
        sb.append('c');
        for (int i = 1; i < b[0]; i++) sb.append('.');
        for (int i = b[0]; i < c; i++) sb.append('*');
        sb.append('\n');
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < b[i]; j++) {
                sb.append('.');
            }
            for (int j = b[i]; j < c; j++) {
                sb.append('*');
            }
            sb.append('\n');
        }
        sb.delete(sb.length() - 1, sb.length());
        return sb;
    }
}
