import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

/**
 * @author khelman
 */
public class Elf {

    public static void main(String... args) throws IOException {
        FileReader fr = new FileReader("d:\\elf.in");
        BufferedReader br = new BufferedReader(fr);
        String s = br.readLine();

        FileWriter f0 = new FileWriter("d:\\elf.out");

        int t = Integer.parseInt(s.trim());

        for (int i = 1; i <= t; i++) {
            s = br.readLine();
            String[] elems = s.split("/");

            long p = Long.parseLong(elems[0]);
            long q = Long.parseLong(elems[1]);

            long divisor = egcd(p, q);

            p = p / divisor;
            q = q / divisor;

            //check if q is power of 2
            long testQ = q;
            while (testQ % 2 == 0) {
                testQ = testQ / 2;
            }
            if (testQ != 1) {
                System.out.println("Case #" + i + ": impossible");
                f0.write("Case #" + i + ": impossible\r\n");
                continue;
            }

            long ret = 0;
            while (p < q) {
                q = q / 2;
                ret++;
            }

            if (ret > 40) {
                System.out.println("Case #" + i + ": impossible");
                f0.write("Case #" + i + ": impossible\r\n");
                continue;
            }

            System.out.println("Case #" + i + ": " + ret);
            f0.write("Case #" + i + ": " + ret + "\r\n");
        }

        fr.close();
        f0.close();

    }

    public static long egcd(long a, long b) {

        BigInteger bia = BigInteger.valueOf(a);
        BigInteger bib = BigInteger.valueOf(b);

        BigInteger gcd = bia.gcd(bib);

        return gcd.longValue();
    }
}
