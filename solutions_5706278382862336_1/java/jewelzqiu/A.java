import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Jewelz on 5月11日.
 */
public class A {

    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("input"));
            PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("output")));
            int T = Integer.valueOf(reader.readLine());
            for (int round = 1; round <= T; round++) {
                StringBuilder builder = new StringBuilder("Case #" + round + ": ");
                long p, q;
                StringTokenizer tokenizer = new StringTokenizer(reader.readLine(), "/");
                p = Long.valueOf(tokenizer.nextToken());
                q = Long.valueOf(tokenizer.nextToken());

                long a = p;
                long b = q;
                long temp;
                while (true) {
                    temp = b % a;
                    if (temp == 0) {
                        break;
                    }
                    b = a;
                    a = temp;
                }
                p /= a;
                q /= a;

                int count = 0;
                boolean found = false;
                boolean impossible = false;
                while (true) {
                    if (p == 1) {
                        double log = Math.log(q) / Math.log(2);
                        if (log - (int) log != 0) {
                            impossible = true;
                        } else if (!found) {
                            count += log;
                        }
                        break;
                    }
                    if (!found) {
                        count++;
                    }
                    if (q % 2 != 0) {
                        impossible = true;
                        break;
                    } else {
                        q /= 2;
                    }
                    if (p > q) {
                        p = p - q;
                        found = true;
                    }
                }
                if (impossible) {
                    builder.append("impossible");
                } else {
                    builder.append(count);
                }
                writer.println(builder.toString());
            }
            reader.close();
            writer.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
