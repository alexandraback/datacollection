import java.util.*;
import java.io.*;

public class probA {
    
    public static long func(long r, long k) {
        return (2*r*k + k*(2*k-1));

    }

    public static int check(int r, int t) {
        long k = 1;
        while(func((long)r,k)<=t) {
            k++;
        }
        return (int)(k-1);
    }
    public static void main(String ... args) throws IOException {
        Scanner input = new Scanner(System.in);
        PrintWriter out = new PrintWriter("probA.out");
        int t = Integer.parseInt(input.nextLine());
        for(int i=1;i<=t;i++) {
            int r = input.nextInt();
            int m = input.nextInt();
            out.println("Case #"+i+": "+check(r,m));

        }
        out.close();

    }
}
