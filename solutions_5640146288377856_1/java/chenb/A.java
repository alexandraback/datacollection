package CJ15.round1C;

import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: chenbin
 * Date: 5/10/15
 * Time: 5:53 PM
 * To change this template use File | Settings | File Templates.
 */
public class A {
    public static void main(String... args) {
        A a = new A();
        Scanner scanner = new Scanner(System.in);
        int caseNum = scanner.nextInt();
        for(int i=0; i< caseNum; i++) {

            int R = scanner.nextInt();
            int C = scanner.nextInt();
            int W = scanner.nextInt();

            System.out.println(String.format("Case #%d: %d", i+1, a.tryCount(R, C, W)));
        }
    }

    public int tryCount(int R, int C, int W) {
        int tryRows = (int) Math.floor((C/W) * 1.0);
        int ret = W + (int)Math.ceil((C-W) * 1.0 /W);
        return tryRows * (R-1) + ret;
    }


}
