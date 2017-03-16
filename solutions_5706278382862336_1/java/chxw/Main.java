import sun.security.util.BigInt;

import java.math.BigInteger;
import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {

    //
    // boilerplate
    //
    static String path = "/Users/liwen/Downloads/";
    static String fname = "A-large";

    static BufferedWriter bw;
    static BufferedReader br;


    public static void init() throws IOException {

        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        br = new BufferedReader(new FileReader(path + fname + ".in"));
        bw = new BufferedWriter(new FileWriter(path + fname + ".txt"));

    }


    ///////////////////////////////////
    // code starts from here
    //


    //
    // code ends here
    //////////////////////////////////

    public static void main(String[] args) throws IOException {
        //
        // boilerplate
        //

        init();
        int N = Integer.parseInt(br.readLine());

        ///////////////////////////////////
        // code starts here
        //


        //
        // code ends here
        //////////////////////////////////

        for (int l = 1; l <= N; ++l) {
            bw.write("Case #" + l + ":");
            /////////////////////////////////////
            /// code starts here
            ///

            String[] buf = br.readLine().split("/");
            long P = Long.parseLong(buf[0]);
            long Q = Long.parseLong(buf[1]);

            long ans = -1;

            long res;
            for (res = Q; res > 1; res/=2) {
                if (res % 2 != 0)
                    break;
            }

            if (P % res == 0) {
                P /= res;
                Q /= res;
            } else {
                bw.write(" impossible\n");
                continue;
            }

            ans = -1;
            for (long i = 0; Q >= 0 && i <= 40; ++i) {
                if (P >= Q) {
                    ans = i;
                    break;
                }
                Q /= 2;
            }

            if (ans < 0)
                bw.write(" impossible\n");
            else
                bw.write(" " + ans + "\n");

            ///
            /// code ends here
            ////////////////////////////////////

        }

        bw.close();
    }
}
