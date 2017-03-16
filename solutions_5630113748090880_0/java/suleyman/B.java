package r1A;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by suleymanuslu on 4/15/16.
 * CJ16 R1A 2
 */
public class B {

    String smallInput = "res/r1A/B/b_small.in";
    String smallOutput = "res/r1A/B/b_small.out";
    String bigInput = "res/r1A/B/b_big.in";
    String bigOutput = "res/r1A/B/b_big.out";

    int n;  // number of cases
    int d;
    int a[] = new int[2501];


    public void zeroize() {

        for(int i=0; i<2501; i++) {
            a[i] = 0;
        }
    }

    public void readInput() {

        try {
            Scanner sc = new Scanner(new FileReader(smallInput));
            PrintWriter pw = new PrintWriter(smallOutput);
            n = sc.nextInt();

            for(int c=1; c<=n; c++) {
                d = sc.nextInt();
                zeroize();
                for (int i = 0; i < 2 * d * d - d; i++) {
                    int r = sc.nextInt();
                    a[r]++;
                }
                pw.print("Case #"+c+":");
                for(int j=0; j<2501; j++) {
                    if(a[j]%2==1)
                        pw.print(" "+j);
                }
                pw.println();
            }
            sc.close();
            pw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void writeOutput() {

        try {
            PrintWriter pw = new PrintWriter(smallOutput);
            for(int i=1; i<=n; i++) {
                pw.print("Case #"+i+":");
                zeroize();
                for(int j=0; j<2501; j++) {
                    if(a[j]%2==1)
                        pw.print(" "+j);
                }
                pw.println();
            }
            pw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void solve() {

        for(int i=0; i<n; i++) {
            //...
        }
    }

    public static void main(String[] args) {

        B b = new B();
        b.readInput();
        //b.solve();
        //b.writeOutput();
    }
}
