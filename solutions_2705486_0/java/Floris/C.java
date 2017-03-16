
import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class C {
    static ArrayList<String> words = new ArrayList<>();
    public static void main(String[] args) throws Exception {
        System.setOut(new PrintStream("/home/floris/temp/dev/codejam2013/src/out.txt"));
        Scanner sc = new Scanner(new File("/home/floris/temp/dev/codejam2013/src/C-small-attempt0.in"));

        readWordlist();

        for (int count = sc.nextInt(), current = 1; count > 0; count--, current++) {
            System.out.printf("Case #%d: %d%n", current, solve(sc.next()));
        }
    }

    static int solve(String s) {
        int[][] solutions = new int[5000][6];
        for (int i = 1; i <solutions.length; i++) for (int j = 0; j < solutions[0].length; j++) solutions[i][j] = 1000000;
        for (int i = 0; i < s.length(); i++) {
            for (int firsterror = 0; firsterror <= 4; firsterror++) {
w:              for (String w : words) {
                    if (i+w.length() > s.length()) continue w;
                    int npe = firsterror;
                    int cur = 0;
                    for (int j = 0; j < w.length(); j++) {
                        if (w.charAt(j) != s.charAt(i+j)) {
                            if (j < npe) continue w;
                            npe = j+5;
                            cur++;
                        }
                    }
                    npe -= w.length();
                    if (npe<0) npe=0;
                    for (int j = npe; j <= 4; j++) {
                        solutions[i + w.length()][j] = Math.min(solutions[i + w.length()][j], solutions[i][firsterror]+cur);
                    }
                }
            }
        }
        return solutions[s.length()][4];
    }

    static void readWordlist() throws IOException {
        Scanner sc = new Scanner(new File("/home/floris/temp/dev/codejam2013/src/garbled_email_dictionary.txt"));
        String s;
        while (sc.hasNext()) words.add(sc.next());
    }

}
