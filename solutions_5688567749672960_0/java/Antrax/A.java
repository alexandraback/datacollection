package CodeJam20152A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Andres
 */
public class A {
    
    static long dp[] = new long [10000000];

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File("A-small-attempt0.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter(new File("out.txt")));
//        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new File("in.txt"));
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            long N = sc.nextLong();
            long count = best(N);

            System.out.println("Case #" + (i + 1) + ": " + count);
            bw.write("Case #" + (i + 1) + ": " + count);
            bw.newLine();

        }
        bw.close();
    }

    private static long reverseNumber(long num) {
        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            int dig = (int) (num % 10);
            sb.append(dig);
            num = num / 10;
        }
        if (sb.length() == 0) {
            return 0;
        }
        return Long.parseLong(sb.toString());
    }
//    private static int best(long N) {
//        int count = 0;
//        long num = 0;
//        while (num < N) {
//            long rev = reverseNumber(num);
//            System.out.println(num);
//            if (rev <= N && rev > num + 1) {
//                num = rev;
//            } else {
//                num++;
//            }
//            count++;
//        }
//        return count;
//    }

    private static long best(long N) {
//        System.out.println(N);
        if(N < dp.length && dp[(int)N]!=0)return dp[(int)N];
        long count = N;
        long num = N;
        int dig = (int) (num%10); 
        int i=1;
        while (dig >= 0) {
            if(dig==0){
                count = Math.min(count, best(num-1)+i);
                break;
            }
            if(num==1)return count;
            long rev = reverseNumber(num);
            if(rev < num){
//                System.out.println("num " + num + " rev " + rev);
//                System.out.println("count " + count + " bestRev " + (best(rev)+i));
                count = Math.min(count, (best(rev)+i));
            }
            i++;
            num--;
            dig = (int)(num%10);
        }
        if(N < dp.length)dp[(int)N]=count;
        return count;
    }
}
