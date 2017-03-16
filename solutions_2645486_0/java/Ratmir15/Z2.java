package c2013_r1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class Z2 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\tests\\zz2.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\B-small-attempt0.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\B-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int e = scanner.nextInt();
            int r = scanner.nextInt();
            int n = scanner.nextInt();
            System.out.println(e+" "+r+" "+n);
            int [] v = new int[n];
            for (int i=1;i<=n;i++) {
                v[i-1] = scanner.nextInt();
            }

            int sm = 0;
            for (int i=0; i<=e; i++) {
                int max = trye(n,i,1,r,e,e,v);
                if (max>sm) {
                    sm = max;
                }
            }            

            String s = "Case #" + ti + ": "+sm;
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

    private static int trye(int n,int energyToUse, int i, int r,int energyLeft,int energyAll, int[] v) {
        if (i<n) {
            if (energyToUse<=energyLeft) {
                int vi = energyToUse * v[i-1];
                int l = energyLeft - energyToUse + r;
                if (l>energyAll) {
                    l = energyAll;
                }
                int m = 0;
                for (int j=0;j<=l;j++) {
                    int mm = trye(n,j,i+1,r,l,energyAll,v);
                    if (mm>m) {
                        m = mm;
                    }
                }
                return m + vi;
            }
            return 0;
        } else {
            return energyLeft*v[i-1];
        }
    }

}
