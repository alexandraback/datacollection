import java.io.*;
import java.util.Scanner;

public class A {

    public static void main(String [] args) throws IOException {
            //Scanner s = new Scanner(new BufferedReader(new FileReader("A-small-attempt0.in")));
            Scanner s = new Scanner(new BufferedReader(new FileReader("A-large.in")));
           // Scanner s = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
            int ncase = s.nextInt();
            for (int i = 1; i <= ncase; i++) {
                String str = s.next();
                System.out.printf("Case #%d: %s\n", i, solve(str));
            }
            s.close();
    }

    public static String solve(String S) {

        if ( S.length() == 1 ) return S;

        String rv = Character.toString( S.charAt(0) );
        for (int i = 1; i < S.length(); i++) {
            if ( S.charAt(i) >= rv.charAt(0) )
                rv = S.charAt(i) + rv;
            else
                rv += S.charAt(i);
        }
        return rv;
    }

}
