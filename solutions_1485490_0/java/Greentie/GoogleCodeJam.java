/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.io.*;
import java.util.*;

/**
 *
 * @author GreenTie
 */
public class GoogleCodeJam {

    /**
     * @param args the command line arguments
     */
//    public static double problemAs(String G[]) {
//        String temp[] = G[0].split(" ");
//        int A = Integer.valueOf(temp[0]);
//        int B = Integer.valueOf(temp[1]);
//        temp = G[1].split(" ");
//        double[] p = new double[temp.length];
//        for (int i = 0; i < p.length; i++) {
//            p[i] = Double.valueOf(temp[i]);
//        }
//        double x = B + 2;
//        double b = B + 1;
//        double y = 1;
//        for (int n = A - 1; n >= 0; n--) {
//            if (2 * n >= A + 1) {
//                y = y * (p[A - 1 - n]);
//                continue;
//            } else {
//                y = y * (p[A - 1 - n]);
//                double k = (2 * B - A + 2 + 2 * n) + (y * (b) * (-1));
//                if (k <= x) {
//                    x = k;
//
//                }
//            }
//        }
//        return x;
//    }
//    public static double[] problemAs(String G[]) {
//        String temp[] = G[0].split(" ");
//        int s[] = new int[temp.length];
//        int sum = 0;
//        for (int i = 0; i < s.length; i++) {
//            s[i] = Integer.valueOf(temp[i]);
//            if (i >= 1) {
//                sum += s[i];
//            }
//        }
//        int x = sum * 2;
//        double y = sum * s[0];
//        int count = s[0];
//        double[] result = new double[s.length - 1];
//
//        for (int i = 1; i < s.length; i++) {
//            if (sum * 2 - s[i] * s[0] <= 0) {
//                x -= s[i];
//                count--;
//            }
//        }
//
//        System.err.println(count);
//
//
//
//        for (int i = 0; i < result.length; i++) {
//            double t = ((double) x) / count - s[i + 1];
//            if (t >= 0) {
//                result[i] = t / sum;
//
//            } else {
//                result[i] = 0;
//            }
//             result[i]*=100;
//        }
//
//
//
//        return result;
//    }
    public static String problemAs(String G[]) {
        String y = "Yes";
        String n = "No";
        int Weight = 1000;
        int classnum = G.length;
        int[][] list = new int[classnum][];

        for (int i = 0; i < list.length; i++) {
            String temp[] = G[i].split(" ");
            int t = Integer.valueOf(temp[0]);
            if (t != 0) {
                list[i] = new int[t];
                for (int j = 0; j < list[i].length; j++) {
                    list[i][j] = Integer.valueOf(temp[j + 1]);
                }
            } else {
                list[i] = null;
            }
        }

        for (int i = 0; i < list.length; i++) {
            if (list[i] == null) {
                continue;
            }
            if (list[i].length == 1) {
                continue;
            }
            List<Integer> x = new ArrayList<Integer>(Weight);
            List<Integer> z = new ArrayList<Integer>(Weight);
            for (int j : list[i]) {
                x.add(j);
                z.add(j);
            }

            do {
                for (Integer e : x) {
                    if (list[e - 1] != null) {
                        z.remove(e);
                        for (int j : list[e - 1]) {
                            if (z.contains(j)) {
                                return y;
                            } else {
                                z.add(j);
                            }
                        }
                    }
                }

                x.clear();

                for (Integer e : z) {
                    x.add(e);
                }

            } while (check(x, list) != true);

        }



        return n;
    }

    public static boolean check(List<Integer> x, int[][] list) {
        boolean t = true;
        for (Integer e : x) {
            t &= list[e - 1] == null;
        }
        return t;

    }

    public static String problemBs(String G[]) {
        return null;
    }

    public static String problemBb(String G[]) {
        return null;
    }

    public static String problemCs(String G[]) {

        String[] a = G[0].split(" ");
        String[] b = G[2].split(" ");
        int ag = Integer.valueOf(a[0]);
        int bg = Integer.valueOf(a[1]);
        a = G[1].split(" ");

        long[] al = new long[a.length];
        long[] bl = new long[b.length];
        for (int i = 0; i < al.length; i++) {
            al[i] = Long.valueOf(a[i]);
        }
        for (int i = 0; i < bl.length; i++) {
            bl[i] = Long.valueOf(b[i]);
        }



        return "" + match(al, bl, 0, 0);
    }

    public static long match(long[] al, long[] bl, int pa, int pb) {
        long x = 0;
        long y = 0;
        long z = 0;



        if (pa == al.length) {
            return 0;
        } else if (pb == bl.length) {
            return 0;
        }


        long[] al1 = new long[al.length];
        long[] al2 = new long[al.length];
        long[] al3 = new long[al.length];

        long[] bl1 = new long[bl.length];
        long[] bl2 = new long[bl.length];
        long[] bl3 = new long[bl.length];

        System.arraycopy(al, 0, al1, 0, al.length);
        System.arraycopy(al, 0, al2, 0, al.length);
        System.arraycopy(al, 0, al3, 0, al.length);
        System.arraycopy(bl, 0, bl1, 0, bl.length);
        System.arraycopy(bl, 0, bl2, 0, bl.length);
        System.arraycopy(bl, 0, bl3, 0, bl.length);

        if (al[pa + 1] == bl[pb + 1]) {
            x = al[pa] <= bl[pb] ? al[pa] : bl[pb];
            al1[pa] -= x;
            bl1[pb] -= x;
            if (al1[pa] == 0) {
                pa += 2;
            }
            if (bl1[pb] == 0) {
                pb += 2;
            }
            x += match(al1, bl1, pa, pb);
        } else {
            y = match(al2, bl2, pa + 2, pb);
            z = match(al3, bl3, pa, pb + 2);

        }

        return comp(x, y, z);
    }

    public static long comp(long a, long b, long c) {
        long x = a > b ? a : b;
        return x > c ? x : c;
    }

    public static String problemCb(String G[]) {
        return null;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here

        String filename = "C-small-attempt0";

        String input = filename + ".in";
        String output = filename + ".out";

        BufferedReader br = new BufferedReader(new FileReader(new File(input)));
        int x = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        System.setOut(new PrintStream(new File(output)));
        for (int i = 1; i <= x; i++) {
            String[] temp = new String[3];
            for (int j = 0; j < 3; j++) {
                temp[j] = br.readLine().trim();
            }
            String result = problemCs(temp);

            System.out.printf("Case #%d: %s\n", i, result);


            //sb.append("Case #").append(i).append(": ").append(Result[compute(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]))]).append('\n');
            //System.out.printf("Case #%d: %s\n",i,Result[compute(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]))]);   
        }


        br.close();

    }
}
