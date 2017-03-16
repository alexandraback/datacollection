package fuku.round1C;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author fuku
 */
public class TaskA {
    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = TaskA.class.getResourceAsStream("A-small-attempt0.in");
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(new FileOutputStream("./out.txt"));

        int T = in.nextInt(); in.nextLine();
        for (int i = 0; i < T; i++) {
            System.out.println("------------------");
            System.out.println("test " + (i+1));
            SolA solver = new SolA();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i+1) + ": " + ans);
            System.out.println("Case #" + (i+1) + ": " + ans);
        }
        out.close();
    }
}

class SolA {

    public String solve(int testNumber, Scanner in, PrintWriter out) {
        String line = in.nextLine();
        String[] nums = line.split("/");
        long P = Long.parseLong(nums[0]);
        long Q = Long.parseLong(nums[1]);

        System.out.printf("P=%s,Q=%s\n", P, Q);

        long g = gcd(P, Q);
        P /= g;
        Q /= g;

        System.out.printf("gg P=%s,Q=%s\n", P, Q);

        long q = Q;
        while(q > 1){
            if ( q % 2 != 0 ) return "impossible";
            q /= 2;
        }

        q = Q;
        int b = 1;
        while(q >= 1){
            if ( 2 * P >= q ) break;
            q /= 2;
            b++;
        }


        String ans = "" + b;
        return ans;
    }

    public static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}
