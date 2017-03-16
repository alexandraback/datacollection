import com.sun.tools.javac.util.Pair;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class CloseMatch {
    public static long pow(int a, int b) {
        long res = 1;
        for (int i = 0; i < b; ++i) {
            res *= a;
        }
        return res;
    }

    public static boolean matches(String s, int number) {
        List<Integer> digits = new ArrayList<>();
        while (number > 0) {
            digits.add(number % 10);
            number /= 10;
        }
        while (digits.size() < s.length()) {
            digits.add(0);
        }
        Collections.reverse(digits);
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '?') continue;
            if (s.charAt(i) - '0' != digits.get(i)) return false;
        }
        return true;
    }

    public static String print(int number, int length) {
        List<Integer> digits = new ArrayList<>();
        while (number > 0) {
            digits.add(number % 10);
            number /= 10;
        }
        while (digits.size() < length) {
            digits.add(0);
        }
        Collections.reverse(digits);
        String res = "";
        for (int x : digits) res += (char)('0' + x);
        return res;
    }

    public static List<Integer> parse(String s) {
        List<Integer> res = new ArrayList<>();
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s.charAt(i) == '?') res.add(-1);
            else res.add((int)(s.charAt(i) - '0'));
        }
        return res;
    }

    public static Pair<Boolean, Long> getLeastDelta(int at, List<Integer> digitsA, List<Integer> digitsB,
                              boolean[][] cached, boolean[][] possible, long[][] cache, int cmp) {
        if (at == -1) {
            return cmp >= 0 ? Pair.of(true, 0L) : Pair.of(false, 0L);
        }
        if (cached[at][cmp]) {
            return Pair.of(possible[at][cmp], cache[at][cmp]);
        }

        int aLow = 0;
        int aHigh = 0;
        if (at < digitsA.size()) {
            if (digitsA.get(at) == -1) {
                aLow = 0;
                aHigh = 9;
            } else {
                aLow = aHigh = digitsA.get(at);
            }
        }
        int bLow = 0;
        int bHigh = 0;
        if (at < digitsB.size()) {
            if (digitsB.get(at) == -1) {
                bLow = 0;
                bHigh = 9;
            } else {
                bLow = bHigh = digitsB.get(at);
            }
        }
        long res = -1;
        boolean possibleNow = false;
        for (int a = aLow; a <= aHigh; ++a) {
            for (int b = bLow; b <= bHigh; ++b) {
                if (cmp < 0) continue;
                if (cmp == 0 && a >= b) {
                    Pair<Boolean, Long> cres = getLeastDelta(at - 1, digitsA, digitsB, cached, possible, cache, (a > b) ? 1 : 0);
                    if (!cres.fst) continue;
                    long current = pow(10, at) * (a - b) + cres.snd;
                    if (!possibleNow || res > current) {
                        res = current;
                        possibleNow = true;
                    }
                }
                if (cmp > 0) {
                    Pair<Boolean, Long> cres = getLeastDelta(at - 1, digitsA, digitsB, cached, possible, cache, 1);
                    if (!cres.fst) continue;
                    long current = pow(10, at) * (a - b) + cres.snd;
                    if (!possibleNow || res > current) {
                        res = current;
                        possibleNow = true;
                    }
                }
            }
        }
        possible[at][cmp] = possibleNow;
        cached[at][cmp] = true;
        cache[at][cmp] = res;
        return Pair.of(possibleNow, cache[at][cmp]);
    }

    public static long leastDelta(String a, String b) {;
        long res = -1;
        for (int option = 0; option < 2; ++option) {
            String sa = a;
            String sb = b;
            if (option == 1) {
                sa = b;
                sb = a;
            }

            List<Integer> digitsA = parse(sa);
            List<Integer> digitsB = parse(sb);

            int length = Math.max(digitsA.size(), digitsB.size());
            boolean[][] cached = new boolean[length + 1][2];
            boolean[][] possible = new boolean[length + 1][2];
            long[][] cache = new long[length + 1][2];
            Pair<Boolean, Long> delta = getLeastDelta(length - 1, digitsA, digitsB, cached, possible, cache, 0);
            if (delta.fst) {
                if (res < 0 || res > delta.snd) res = delta.snd;
            }
        }
        return res;
    }

    public static void main(String[] args) throws FileNotFoundException {
        String file = "B-large";
        final Scanner reader = new Scanner(new File(file + ".in"));
        final PrintWriter writer = new PrintWriter(new File(file + ".out"));
        final int testsCount = reader.nextInt();
        for (int test = 0; test < testsCount; ++test) {
            String a = reader.next();
            String b = reader.next();
            /*
            int bestDelta = 1000000000;
            int bestA = 10000;
            int bestB = 10000;
            for (int va = 0; va < pow(10, a.length()); ++va)
                for (int vb = 0; vb < pow(10, b.length()); ++vb) {
                    if (matches(a, va) && matches(b, vb)) {
                        if (Math.abs(va - vb) < bestDelta) {
                            bestDelta = Math.abs(va - vb);
                            bestA = va;
                            bestB = vb;
                        }
                    }
                }*/
            long leastDeltaOverall = leastDelta(a, b);
            for (int i = 0; i < a.length(); ++i) {
                if (a.charAt(i) == '?') {
                    char[] ca = a.toCharArray();
                    for (int digit = 0; digit <= 9; ++digit) {
                        ca[i] = (char)('0' + digit);
                        String na = new String(ca);
                        if (leastDeltaOverall == leastDelta(na, b)) {
                            a = na;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < b.length(); ++i) {

                if (b.charAt(i) == '?') {
                    char[] cb = b.toCharArray();
                    for (int digit = 0; digit <= 9; ++digit) {
                        cb[i] = (char)('0' + digit);
                        String nb = new String(cb);
                        if (leastDeltaOverall == leastDelta(a, nb)) {
                            b = nb;
                            break;
                        }
                    }
                }
            }
            //String slowA = print(bestA, a.length());
            //String slowB = print(bestB, b.length());

            //writer.write(String.format("Least delta = %d\n", leastDeltaOverall));
            //writer.write(String.format("Case #%d: %s %s\n", test + 1, print(bestA, a.length()),
            ///        print(bestB, b.length())));
            writer.write(String.format("Case #%d: %s %s\n", test + 1, a, b));
            //if (slowA.equals(a) && slowB.equals(b)) {

//            } else {
    //            reader.close();;
      //          writer.close();;
        //        System.out.println("Test " + test + " failed..");
          //      System.exit(1);
  //          }
        }
        reader.close();
        writer.close();
    }
}
