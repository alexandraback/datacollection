package elves;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Elves {
    public static void main(String[] args) {
        try {
            BufferedReader reader = Files.newBufferedReader(Paths.get("./elves-in.txt"), Charset.forName("US-ASCII"));
            BufferedWriter writer = Files.newBufferedWriter(Paths.get("./elves-out.txt"), Charset.forName("US-ASCII"));
            int T = Integer.parseInt(reader.readLine());
            for (int t = 1; t <= T; t++) {
                String line = reader.readLine();
                String[] splitted = line.split("/");
                long P = Long.parseLong(splitted[0]);
                long Q = Long.parseLong(splitted[1]);
                long gcd = longGcd(P, Q);
                P = P / gcd;
                Q = Q / gcd;
                if (isPowerOfTwo(Q)) {
                    long i = 1;
                    long cur = Q / 2;
                    while (cur > P) {
                        cur /= 2;
                        i++;
                    }
                    writer.write(String.format("Case #%s: %d", t, i));
                } else {
                    writer.write(String.format("Case #%s: impossible", t));
                }
                writer.newLine();
            }
            writer.close();
            reader.close();
        } catch (IOException e) {

        }
    }

    private static boolean isPowerOfTwo(long x) {
        return (x != 0) && ((x & (x - 1)) == 0);
    }

    private static long longGcd(long x1, long x2) {
        BigInteger b1 = BigInteger.valueOf(x1);
        BigInteger b2 = BigInteger.valueOf(x2);
        BigInteger bgcd = b1.gcd(b2);
        return bgcd.longValue();
    }
}