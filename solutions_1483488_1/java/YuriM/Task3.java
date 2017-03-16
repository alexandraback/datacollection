package qualification;

import java.io.FileInputStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by IntelliJ IDEA.
 * User: Yuri
 * Date: 14.04.12
 * Time: 12:18
 * To change this template use File | Settings | File Templates.
 */
public class Task3 {

    static int divider;

    static int recycle(int a) {
        int mod = a % divider;
        int digit = a / divider;
        return (mod * 10) + digit;
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(new FileInputStream("task32.txt"));
        int N = scanner.nextInt();
        Set<Integer> set = new HashSet<Integer>();
        for (int n = 0; n < N; n++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();

            int digitsCount = String.valueOf(a).length();
            divider = (int) Math.pow(10, digitsCount - 1);
            int count = 0;
            for (int c = a; c <= b; c++) {
                set.clear();
                int recycled = c;
                for (int i = 0; i < digitsCount - 1; i++) {
                    recycled = recycle(recycled);
                    if (recycled <= b && recycled > c) {
                        if (! set.contains(recycled)) {
                            set.add(recycled);
                            count++;
                        }
                    }
                }
            }
            System.out.println("Case #" + (n + 1) + ": " + count);
        }
    }
}
