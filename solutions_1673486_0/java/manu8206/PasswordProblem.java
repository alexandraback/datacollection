package passwordproblem;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Emmanuel
 */
public class PasswordProblem {
    String executeCase(final BufferedReader reader) throws IOException {
        String line = reader.readLine();
        String words[] = line.split(" ");
        int A = Integer.parseInt(words[0]);
        int B = Integer.parseInt(words[1]);
        double p[] = new double[B];
        line = reader.readLine();
        words = line.split(" ");
        for (int i = 0; i < A; ++i)
            p[i] = Double.parseDouble(words[i]);
        
        double min = B + 2;
        for (int i = 0; i <= A; ++i) {
            double prod = 1;
            for (int j = 0; j < (A-i) ; ++j)
                prod *= p[j];
            double e = (2*B-A+2+2*i) - (B+1) * prod;
            if (e < min) min = e;
        }
        return Double.toString(min);
    }

    void execute() {
        try {
            InputStreamReader stream = new InputStreamReader(System.in);
            BufferedReader reader = new BufferedReader(stream);
        
            String line = reader.readLine();
            int cases = Integer.parseInt(line);
            for (int i = 1; i <= cases; ++i) {
                StringBuilder out = new StringBuilder();
                out.append("Case #");
                out.append(i);
                out.append(": ");
                out.append(executeCase(reader));
                System.out.println(out.toString());
            }
        } catch (Exception e) {
            e.printStackTrace(System.err);
        }
    }

    public static void main(String[] args) {
        new PasswordProblem().execute();
    }
}

