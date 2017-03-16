package c2014_c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class Z4_1 {
    //x/c-2/f

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\tests\\2014\\z4.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int n = scanner.nextInt();
            double  [] w1 = new double[n];
            int  [] u1 = new int[n];
            double  [] w2 = new double[n];
            int  [] u2 = new int[n];
            for (int i=0;i<n;i++) {
                w1[i] = scanner.nextDouble();
            }
            for (int i=0;i<n;i++) {
                w2[i] = scanner.nextDouble();
            }
            //playing war
            // naomi plays min
            // ken plays more than naomi if can and min if not can
            int cnt = 0;
            for (int i=1;i<=n;i++) {
                int idx = -1;
                double mn = Double.MAX_VALUE;
                for (int j=0;j<n;j++) {
                    if (u1[j]==0) {
                        if (w1[j]<mn) {
                            mn = w1[j];
                            idx = j;
                        }
                    }
                }
                u1[idx] = 1;
                int idx_min = -1;
                double min_mn = Double.MAX_VALUE;
                int idx_max = -1;
                double max_mn = Double.MAX_VALUE;
                for (int j=0;j<n;j++) {
                    if (u2[j]==0) {
                        if (w2[j]<min_mn) {
                            min_mn = w2[j];
                            idx_min = j;
                        }
                        if (w2[j]>w1[idx] && w2[j]<max_mn) {
                            max_mn = w2[j];
                            idx_max = j;
                        }
                    }
                }
                if (idx_max>-1) {
                    u2[idx_max] = 1;
                } else {
                    u2[idx_min] = 1;
                    cnt++;
                }
            }
            int cntd = 0;
            int  [] ud1 = new int[n];
            int  [] ud2 = new int[n];
            //playing d war
            // if naomi has block more than minimum than it lies that it is very big
            // and takes it for ken's minimum
            for (int i=1;i<=n;i++) {
                int idx_min = -1;
                double min = Double.MAX_VALUE;
                for (int j=0;j<n;j++) {
                    if (ud2[j]==0) {
                        if (w2[j]<min) {
                            min = w2[j];
                            idx_min = j;
                        }
                    }
                }
                int idx_min1 = -1;
                double min1 = Double.MAX_VALUE;
                int idx_max1 = -1;
                double max1 = Double.MAX_VALUE;
                for (int j=0;j<n;j++) {
                    if (ud1[j]==0) {
                        if (w1[j]<min1) {
                            min1 = w1[j];
                            idx_min1 = j;
                        }
                        if (w1[j]>w2[idx_min] && w1[j]<max1) {
                            max1 = w1[j];
                            idx_max1 = j;
                        }
                    }
                }
                ud2[idx_min] = 1;
                if (idx_max1>-1) {
                    cntd++;
                    ud1[idx_max1] = 1;
                } else {
                    ud1[idx_min1] = 1;
                }
            }
            String s;
            //if (cnt>cntd) {
            //    cntd = cnt;
            //}
            s = "Case #" + ti + ": " + +cntd + " " +cnt;
            System.out.println(s);
            //System.out.println(i);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

}
