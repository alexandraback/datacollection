package cj.y2015.qr;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.*;

/**
 * Created by admin on 4/6/2015.
 */
public class A {

    private Scanner scanner;
    private Writer writer;

    public static void main(String[] args) throws IOException {
        A a = new A();
        a.meat();
    }

    private void meat() throws IOException {
        scanner = new Scanner(new FileInputStream("src/cj/y2015/qr/A-large.in"));
        writer = new FileWriter("src/cj/y2015/qr/A-large.out", false);
        int t = scanner.nextInt();
        for (int i=0; i<t; i++) {
            int smax = scanner.nextInt();
            String str = scanner.nextLine();
            if (str.startsWith(" ")) {
                str = str.substring(1);
            }
            long sum = 0;
            long cur = 0;
            for (int j=0; j<smax+1; j++) {
                int sj = str.charAt(j)-48;
                System.out.println("j="+j+", sj="+sj);
                if (j==0) {
                    sum += sj;
                } else {
                    if (sum<j) {
                        long temp = j - sum;
                        cur += temp;
                        sum += temp + sj;
                    } else {
                        sum += sj;
                    }
                }
            }
            writer.write("Case #" +(i+1)+": "+cur+"\n");
            System.out.println("Case #" + (i + 1) + ": " + cur);
        }
        scanner.close();
        writer.close();
    }

    private class AbsComparator implements Comparator<Long> {

        @Override
        public int compare(Long o1, Long o2) {
            return (Math.abs(o1)>Math.abs(o2))?-1:((Math.abs(o1)==Math.abs(o2))?0:1);
        }
    }
}
