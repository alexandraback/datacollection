package gcjpractice;

import java.util.Scanner;

/**
 * FileName:     PartElf.java
 * @Description: 
 *
 * @author Xunhu(Tiger) Sun
 *         email: sunx2013@my.fit.edu
 * @date May 11, 2014 5:17:06 AM 
 */
public class PartElf {
    final Scanner sc = new Scanner(System.in);

    void read () {
        String[] str = sc.nextLine().split("/");
        p = Long.parseLong(str[0]);
        q = Long.parseLong(str[1]);
    }

    long p;
    long q;
    
    void solve () {
        int count = 0;
        int minCount = -1;
        while (count < 40 && p != 0){
            p *= 2;
            count++;
            if (p >= q){
                if (minCount ==-1){
                    minCount = count;
                }
                p -= q;
            }
        }
        if (minCount != -1 && p == 0 ){
            System.out.println(minCount);
        } else {
            System.out.println("impossible");
        }
    }

    void run () {
        final int cn = sc.nextInt();
        sc.nextLine();
        for (int ci = 1; ci <= cn; ci++) {
            read();
            System.out.printf("Case #%d: ", ci);
            solve();
        }
    }

    public static void main (String[] args) {
        new PartElf().run();
    }
}
