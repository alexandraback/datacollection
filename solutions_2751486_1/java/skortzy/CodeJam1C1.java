import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;

public class CodeJam1C1 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("A-large.in")));
            PrintWriter pw = new PrintWriter(new FileOutputStream("A-large.out"));
            String line = br.readLine();
            int T = Integer.parseInt(line);
            for (int i = 0; i < T; i++) {
                System.out.println((i + 1) + " / " + T + "...");

                line = br.readLine();
                String[] values = line.split(" ");
                String name = values[0];
                int n = Integer.parseInt(values[1]);

                long result = solve(name, n);

                pw.println("Case #" + (i + 1) + ": " + result);
            }
            pw.close();
            System.out.println("DONE");
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static long[] total;

    private static boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    private static long solve(String name, int n) {
        long result = 0;
        int starting = 0;
        int ending = 0;
        int L = name.length();

        int[] last = new int[L];

        while (ending < L && !isVowel(name.charAt(ending))) {
            ending++;
        }

        for (int i = 0; i < L; i++) {
            char c = name.charAt(i);
            char prev = (i > 0) ? name.charAt(i-1) : 'a';
            if (isVowel(c)) {
                last[i] = (i > 0) ? last[i-1] : 0;
            } else {
                if (isVowel(prev)) {
                    starting = i;
                    ending = i;
                } else {
                    ending = i;
                }
                if (ending - starting >= n - 1) {
                    last[i] = ending - n + 2;
                } else {
                    last[i] = (i > 0) ? last[i-1] : 0;
                }
            }
            result += last[i];
            //System.out.print(last[i] + " ");
        }
        //System.out.println();
        return result;
    }
}
