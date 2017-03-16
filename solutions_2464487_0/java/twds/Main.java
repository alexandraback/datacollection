
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author wd
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
            long r = scan.nextLong();
            long t = scan.nextLong();
            
            long sum = 0;
            int res = 0;
            while (true) {
                long temp = 2 * r + 1;
                sum += temp;
                if (sum > t) {
                    break;
                }
                r += 2;
                res++;
            }
            
            System.out.println(String.format("Case #%d: %d", taskIndex, res));
        }
    }
}
