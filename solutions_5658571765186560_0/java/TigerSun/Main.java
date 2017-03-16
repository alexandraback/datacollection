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
        x = sc.nextInt();
        r = sc.nextInt();
        c = sc.nextInt();
        sc.nextLine();
    }
    int x;
    int r;
    int c;
    void solve () {
        boolean gab = true;
        if(x == 1){
            gab = true;
        } else if(x == 4){
            if(r*c== 16 || r*c==12){
                gab = true;
            } else {
                gab = false;
            }
        } else if(x == 2){
            if(r*c%2==0){
                gab = true;
            } else {
                gab = false;
            }
        } else {
            if(r*c%3==0){
                if(r*c== 3){
                    gab = false;
                }else {
                    gab = true;
                }
            } else {
                gab = false;
            }
        }
        String ans = gab? "GABRIEL":"RICHARD";
        System.out.println(ans);
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
