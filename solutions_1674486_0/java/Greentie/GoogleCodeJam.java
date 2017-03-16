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
        int Weight = 50;
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
                    if (list[e-1] != null) {
                        z.remove(e);
                        for (int j : list[e-1]) {
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
            t &= list[e-1] == null;
        }
        return t;

    }

    public static String problemAb(String G[]) {
        return null;
    }

    public static String problemBs(String G[]) {
        return null;
    }

    public static String problemBb(String G[]) {
        return null;
    }

    public static String problemCs(String G[]) {
        return null;
    }

    public static String problemCb(String G[]) {
        return null;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here

        String filename = "A-small-attempt0";

        String input = filename + ".in";
        String output = filename + ".out";

        BufferedReader br = new BufferedReader(new FileReader(new File(input)));
        int x = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        System.setOut(new PrintStream(new File(output)));
        for (int i = 1; i <= x; i++) {
            String[] temp = new String[1];
            temp[0] = br.readLine().trim();
            int classnum = Integer.valueOf(temp[0]);
            temp = new String[classnum];
            for (int j = 0; j < classnum; j++) {
                temp[j] = br.readLine().trim();
            }
            String result = problemAs(temp);

            System.out.printf("Case #%d: %s\n", i, result);


            //sb.append("Case #").append(i).append(": ").append(Result[compute(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]))]).append('\n');
            //System.out.printf("Case #%d: %s\n",i,Result[compute(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]))]);   
        }


        br.close();

    }
}
