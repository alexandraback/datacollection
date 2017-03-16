package r1A;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by suleymanuslu on 4/15/16.
 * CJ16 R1A 1
 */
public class A {

    String smallInput = "res/r1A/A/a_small.in";
    String smallOutput = "res/r1A/A/a_small.out";
    String bigInput = "res/r1A/A/a_big.in";
    String bigOutput = "res/r1A/A/a_big.out";

    int n;  // number of cases
    String[] a;
    String[] b;

    public void readInput() {

        try {
            Scanner sc = new Scanner(new FileReader(bigInput));
            n = sc.nextInt();
            a = new String[n];
            b = new String[n];
            sc.nextLine();
            for(int i=0; i<n; i++) {
                a[i] = sc.nextLine();
            }
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void writeOutput() {

        try {
            PrintWriter pw = new PrintWriter(bigOutput);
            for(int i=1; i<=n; i++) {
                pw.println("Case #"+i+": "+b[i-1]);
            }
            pw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void solve() {

        for(int i=0; i<n; i++) {
            String s = a[i];
            char p = s.charAt(0);
            String r = String.valueOf(p);
            for(int j=1; j<s.length(); j++) {
                char c = s.charAt(j);
                String con = String.valueOf(s.charAt(j));
                if(c<p)
                    r = r.concat(con);
                else {
                    r = con.concat(r);
                    p = c;
                }
            }
            b[i] = r;
        }
    }

    public static void main(String[] args) {

        A a = new A();
        a.readInput();
        a.solve();
        a.writeOutput();
    }
}
