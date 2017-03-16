import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {
    static Scanner cin;
    static Set<Long> all = new HashSet<>();
    static {
        for (long a = 1; a*a <= 100000000000000l; a++) {
            long a2 = a*a;
            if (rev(a)==a && rev(a2)==a2)
                all.add(a2);
        }
    }
    public static void main(String[] args) throws FileNotFoundException {
        cin = new Scanner(new File("C.in"));
        PrintWriter out = new PrintWriter(new File("C.out"));
        int T = cin.nextInt();
        for (int I = 0; I < T; I++) {
            String s = String.format("Case #%d: %d", I+1, solveLarge());
            System.out.println(s);
            out.println(s);
        }
        out.close();
    }

    static long solveLarge() {
        long A = cin.nextLong();
        long B = cin.nextLong();
        if (B>100000000000000l)
            System.exit(1);
        int res = 0;
        for (long a : all)
            if (A<=a && a<=B)
                res++;
        return res;
    }

    private static int solve() {
        long A = cin.nextLong();
        long B = cin.nextLong();
        int res = 0;
        for (long a = (long) (Math.sqrt(A)+0.5); a*a <= B; a++) {
            long a2 = a*a;
            if (a2>=A && rev(a)==a && rev(a2)==a2)
                res++;
        }
        return res;
    }
    static long rev(long a) {
        long r = 0;
        while (a>0) {
            r = r*10 + (a%10);
            a /= 10;
        }
        return r;
    }
}
