package Round1C;

import java.io.FileInputStream;
import java.util.Scanner;

/**
 * Created by ocozalp on 5/11/14.
 */
public class A {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileInputStream("/home/ocozalp/Downloads/A-small-attempt3.in"));
        //Scanner sc = new Scanner(System.in);

        int testCase = sc.nextInt();
        sc.nextLine();

        for(int t = 1; t<=testCase; t++) {
            String line = sc.nextLine();
            int res = calculate(line);

            if(res == -1) System.out.println("Case #" + t + ": impossible");
            else System.out.println("Case #" + t + ": " + res);

        }
        sc.close();
    }

    private static int calculate(String line) {
        int index = line.indexOf("/");
        long num = Long.parseLong(line.substring(0, index));
        long denom = Long.parseLong(line.substring(index + 1));

        long g = gcd(num, denom);
        num /= g;
        denom /= g;

        int res = calc(num, denom);

        return res;
    }

    private static int calc(long num, long denom) {
        if((denom & (denom - 1)) != 0) return -1;

        while((num & (num - 1)) != 0) num--;

        int count = 0;
        while(denom > num) {
            count += 1;
            denom /= 2;
        }

        return count;
    }

    private static long gcd(long a, long b) {
        if(b == 0) return a;

        return gcd(b, a % b);
    }
}
