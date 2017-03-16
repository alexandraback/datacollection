import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

/**
 *
 *
 */
public class C {

    private static List<Integer> primeList;
    private static List<BigInteger> primeBigIntegerList;

    public static void main(String[] args) {
         try {

             Scanner scanner = (new Scanner(new File("c:/users/rafal/ideaprojects/src/Cin.txt")));


             FileOutputStream out = new FileOutputStream("c:/users/rafal/ideaprojects/src/Cout.txt");

             int numberOfCases;
             numberOfCases = scanner.nextInt();
             scanner.nextLine();

             PrintWriter wr = new PrintWriter(out);
             for (int i = 0; i < numberOfCases; i++) {
                 doCase(i + 1, scanner, wr);
                 if (i < numberOfCases - 1)
                    scanner.nextLine();
             }
             wr.close();
             out.close();

         } catch (IOException e) {
             System.out.println("Error: " + e);
         }
     }



    private static void doCase(int caseNumber, Scanner scanner, PrintWriter wr) {

        int J, P, S, K;
        J = scanner.nextInt();
        P = scanner.nextInt();
        S = scanner.nextInt();
        K = scanner.nextInt();

        boolean [][][]b = new boolean[J][P][S];

        while (removeInvalid(b, J, P, S, K)) {
            //
        }

        String result = "" + count(b, J, P, S);


        wr.println("Case #" + caseNumber + ": " + result);
        System.out.println("Case #" + caseNumber + ": " + result);

        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s < S; s++) {
                    if (!b[j][p][s]) {
                        // add pairs
                        StringBuffer bb = new StringBuffer();
                        bb.append(j + 1);
                        bb.append(" ");
                        bb.append(p + 1);
                        bb.append(" ");
                        bb.append(s + 1);
                        wr.println(bb);
                        System.out.println(bb);
                    }
                }
            }
        }
        // ...

    }

    private static int count(boolean[][][] b, int J, int P, int S) {
        int cnt = 0;
        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s < S; s++) {
                    if (!b[j][p][s]) {
                        // add pairs
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    private static boolean removeInvalid(boolean[][][] b, int J, int P, int S, int k) {

        Map<Pair, Integer> JP = new HashMap<Pair, Integer>();
        Map<Pair, Integer> JS = new HashMap<Pair, Integer>();
        Map<Pair, Integer> PS = new HashMap<Pair, Integer>();

        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s < S; s++) {
                    if (!b[j][p][s]) {
                        // add pairs
                        addPair(JP, j, p);
                        addPair(JS, j, s);
                        addPair(PS, p, s);
                    }
                }
            }
        }

        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s < S; s++) {
                    if (!b[j][p][s]) {
                        // check if all 3 exceed
                        if (isConflict(JP, j, p, k) && isConflict(JS, j, s, k) && isConflict(PS, p, s, k)) {
                            b[j][p][s] = true;
                            return true;
                        }
                    }
                }
            }
        }

        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s < S; s++) {
                    if (!b[j][p][s]) {
                        // check if 2 exceed
                        int cnt = 0;
                        if (isConflict(JP, j, p, k)) {
                            cnt++;
                        }
                        if (isConflict(JS, j, s, k)) {
                            cnt++;
                        }
                        if (isConflict(PS, p, s, k)) {
                            cnt++;
                        }
                        if (cnt >= 2) {
                            b[j][p][s] = true;
                            return true;
                        }
                    }
                }
            }
        }

        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s < S; s++) {
                    if (!b[j][p][s]) {
                        // check if 2 exceed
                        int cnt = 0;
                        if (isConflict(JP, j, p, k)) {
                            cnt++;
                        }
                        if (isConflict(JS, j, s, k)) {
                            cnt++;
                        }
                        if (isConflict(PS, p, s, k)) {
                            cnt++;
                        }
                        if (cnt >= 1) {
                            b[j][p][s] = true;
                            return true;
                        }
                    }
                }
            }
        }

        return false;

    }

    private static boolean isConflict(Map<Pair, Integer> jp, int j, int p, int k) {
        Integer integer = jp.get(new Pair(j, p));
        return integer != null && integer > k;
    }

    private static void addPair(Map<Pair, Integer> jp, int j, int p) {
        Pair key = new Pair(j, p);
        Integer integer = jp.get(key);
        if (integer == null) {
            jp.put(key, 1);
        } else {
            jp.put(key, integer + 1);
        }
    }


    static class Pair {
        int a, b;

        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair pair = (Pair) o;

            if (a != pair.a) return false;
            if (b != pair.b) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = a;
            result = 31 * result + b;
            return result;
        }
    }

}