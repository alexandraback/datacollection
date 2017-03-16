import java.util.Scanner;

import static java.lang.Math.sqrt;

public class MainC {

    private static long prime(long big) {
        for(long i = 2L; i<=sqrt(big); i++) {
            if(big % i == 0) {
                return i;
            }
        }
        return 0L;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Case #1:");
        int J=0, i=1;
        long arr[] = new long[9];
        String s = "1000000000000001";
        outer: while(J<50) {
            char c[] = s.toCharArray();
            String b = Integer.toBinaryString(i);
            i++;
            for(int j=s.length()-2, k=b.length()-1; k>=0; k--, j--) {
                c[j] = b.charAt(k);
            }
            b=new String(c);
            for(int j=2; j<=10;j++) {
                long big = Long.parseLong(b, j);
                arr[j-2] = prime(big);
                if(arr[j-2] == 0L) {
                    continue outer;
                }
            }
            J++;
            System.out.print(b);
            for(int j=0; j<9;j++) {
                System.out.print(" " + arr[j]);
            }
            System.out.println();

        }
    }
}
