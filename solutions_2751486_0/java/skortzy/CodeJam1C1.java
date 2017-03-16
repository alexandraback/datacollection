import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;

public class CodeJam1C1 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("A-small.in")));
            PrintWriter pw = new PrintWriter(new FileOutputStream("A-small.out"));
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
        boolean[][] matrix = new boolean[L][L];
        while (ending < L && !isVowel(name.charAt(ending))) {
            ending++;
        }
        while (starting < L) {
            System.out.print(starting + " " + ending);
            if (ending - starting >= n) {
                System.out.println(" - OK");
                for (int j = 0; j < ending - n + 1; j++) {
                    for (int k = starting + n - 1; k < L; k++) {
                        if (Math.abs(k - j) >= n - 1) {
                            matrix[k][j] = true;
                        }
                    }
                }
//                for (int j = starting + n - 1; j < ending; j++) {
//                    System.out.println("*" + j);
//                    for (int k = 0; k < L; k++) {
//                        if (Math.abs(k - j) >= n - 1) {
//                            matrix[k][j] = true;
//                        }
//                    }
//                }
            } else {
                System.out.println(" - NOK");
            }
            starting = ending + 1;
            ending++;
            while (ending < L && !isVowel(name.charAt(ending))) {
                ending++;
            }
        }


        for (int i = 0; i < L; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print("\t\t");
            }
            for (int j = i; j < L; j++) {
                System.out.print((matrix[i][j] | matrix[j][i]) + "\t");
                if (matrix[i][j] || matrix[j][i]) {
                    result++;
                }
            }
            System.out.println();
        }

        return result;
    }
}
