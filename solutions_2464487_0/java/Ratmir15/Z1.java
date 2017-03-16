package c2013_r1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigDecimal;
import java.util.*;

public class Z1 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\tests\\zz2.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-small-attempt0.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int r = scanner.nextInt();
            int t = scanner.nextInt();
            System.out.println(r+" "+t);
            //BigDecimal x = new BigDecimal(t);
            //BigDecimal prev = new BigDecimal(k);
            double x = t;
            double prev = r;
            int res = 0;
            while (x>=0) {
                double p = prev * prev;
                double pn = (prev+1) * (prev+1);
                double need = pn - p;
                System.out.println("need: "+need+" "+x);
                if (x>= need) {
                    x = x - need;
                    prev = prev + 2;
                    res++;
                } else {
                    break;
                }
            }
            String s = "Case #" + ti + ": "+res;
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

}
