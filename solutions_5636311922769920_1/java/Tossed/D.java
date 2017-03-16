package google.code.jam.qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;

/**
 * Created by chen on 4/9/16.
 */
public class D {

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader("D.in"));
        PrintWriter out = new PrintWriter(new FileWriter("D.out"));

        int T = Integer.parseInt(in.readLine());

        for (int k = 1; k <= T; k ++) {
            String line = in.readLine();

            int K = Integer.parseInt(line.split(" ")[0]);
            int C = Integer.parseInt(line.split(" ")[1]);
            int S = Integer.parseInt(line.split(" ")[2]);

            if (C * S >= K) {
                out.printf("Case #%d:", k);

                for (int i = 0; i < (K - 1) / C + 1; i ++) {
                    BigInteger pos = BigInteger.ONE;
                    BigInteger pow = BigInteger.ONE;
                    for (int j = i * C; j < (i + 1) * C; j ++) {
                        pos = pos.add(BigInteger.valueOf(Math.min(j, K - 1)).multiply(pow));
                        pow = pow.multiply(BigInteger.valueOf(K));
                    }

                    out.printf(" %d", pos);
                }

                out.printf("\n");
            }
            else {
                out.printf("Case #%d: IMPOSSIBLE\n", k);
            }
        }

        in.close();
        out.close();
    }
}
