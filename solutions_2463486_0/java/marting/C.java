import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
    static Scanner cin;
    public static void main(String[] args) throws FileNotFoundException {
        cin = new Scanner(new File("C.in"));
        PrintWriter out = new PrintWriter(new File("C.out"));
        int T = cin.nextInt();
        for (int I = 0; I < T; I++) {
            String s = String.format("Case #%d: %d", I+1, solve());
            System.out.println(s);
            out.println(s);
        }
        out.close();
    }

    private static long solve() {
        long A = cin.nextLong();
        long B = cin.nextLong();
        long res = 0;
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
