import java.util.HashSet;
import java.util.Scanner;

/**
 * FileName: Main.java
 * @Description:
 *
 * @author Xunhu(Tiger) Sun
 *         email: sunx2013@my.fit.edu
 * @date Apr 10, 2015 8:05:22 PM
 */
public class Main {
    final Scanner sc = new Scanner(System.in);

    void read () {
        char[] cs = sc.nextLine().split(" ")[1].toCharArray();
        s = new int[cs.length];
        for(int i = 0; i < cs.length; i++){
            s[i] = cs[i]-'0';
        }
    }

    int[] s;

    void solve () {
        long have = 0;
        long need = 0;
        for(int si = 0; si < s.length;si++){
            if(have < si){
                long inv = si - have;
                need+=inv;
                have+=inv+ s[si];
            } else {
                have+=s[si];
            }
        }
        System.out.println(need);
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
        new Main().run();
    }
}
