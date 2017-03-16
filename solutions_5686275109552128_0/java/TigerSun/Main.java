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
        int max = 0;
        for (int d = Integer.parseInt(sc.nextLine()); d > 0; d--) {
            int t = sc.nextInt();
            if (t > max) {
                max = t;
            }
        }
        sc.nextLine();
        n = max;
    }
    
    int n;
    
    void solve () {
        int count = 0;
        while(true){
            if(n == 0){
                break;
            }else if(n == 1){
                count++;
                break;
            } else if(n == 2){
                count+=2;
                break;
            } else {
                int big = n / 2;
                if(n % 2 == 1){
                    big++;
                }
                n = big;
                count++;
            }
            
        }
        System.out.println(count);
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
