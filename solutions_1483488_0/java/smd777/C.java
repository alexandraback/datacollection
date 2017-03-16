package gcj2012.qr;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 *
 * @author Scott DellaTorre
 */
public class C {

    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new FileReader("src/gcj2012/qr/in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/gcj2012/qr/C.out")));

        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int A = Integer.parseInt(st.nextToken()); // Number of Googlers
            int B = Integer.parseInt(st.nextToken()); // Number of suprising cases

            int pairs = 0;

            for (int j = A; j <= B; j++) {
                pairs += countRecycled(j, B);
            }

            out.println("Case #" + (i + 1) + ": " + pairs);
        }

        out.close();
    }

    private static int countRecycled(int number, int max) {
        List<Integer> list = new ArrayList<>();
        int log10 = (int) Math.log10(number);
        for (int i = 1; i <= log10; i++) {
            int recycled = recycle(number, i, max);
            if (recycled != -1 && !list.contains(recycled)) {
                list.add(recycled);
            }
        }
        return list.size();
    }

    private static int recycle(int number, int count, int max) {
        int oldNumber = number;

        int divisor = (int) Math.pow(10, count);
        int end = number % divisor;
        number /= divisor;
        int multiplicand = (int) Math.pow(10, (int) Math.log10(number) + 1);
        number += end * multiplicand;

        if (number <= oldNumber || number > max) {
            return -1;
        }
        return number;
    }
}
