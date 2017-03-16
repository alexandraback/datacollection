package src;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Locale;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;


public class Main {

    Scanner in;
    PrintWriter out;

    void solve() {
        in.useLocale(Locale.US);
        int nTests = in.nextInt();
        for (int test = 1; test <= nTests; test++) {
            solveOne(test);
        }
    }

    void solveOne(int test) {
        String line = in.next();
        int fracPos = line.indexOf('/');
        long num = Long.parseLong(line.substring(0,fracPos));
        long den = Long.parseLong(line.substring(fracPos+1));

        if ((den & den-1)!=0 ){
            out.printf(Locale.US, "Case #" + test + ": impossible");
        } else{
            int cnt = 0;
            while(den>num){
                den/=2;
                cnt++;
            }
            out.printf(Locale.US, "Case #" + test + ": "+cnt);

        }
        out.println();


    }


    void run() {
        try {
            in = new Scanner(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } catch (IOException e) {
            throw new Error(e);
        }
        try {
            solve();
        } finally {
            out.close();
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }

}
