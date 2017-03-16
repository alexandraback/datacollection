package C;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

class FairSquare {

    Scanner in;
    BufferedWriter out;
    private BigInteger A;
    private BigInteger B;
    private Map<Integer, Set<String>> combinations;

    FairSquare(String input, String output) throws Exception {
        in = new Scanner(new File(input));
        FileWriter fstream = new FileWriter(output);
        out = new BufferedWriter(fstream);

        combinations = new HashMap<Integer, Set<String>>();
    }

    public static void main(String[] args) throws Exception {
        FairSquare fairsquare = new FairSquare("src/C/in", "src/C/out");
        fairsquare.solve();
        fairsquare.close();
    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        BigInteger a, b;

        for (int test = 1; test <= tests; test++) {
            readAB();

            a = sqrt(A);
            b = sqrt(B);

            if (!a.multiply(a).equals(A)) {
                a = a.add(BigInteger.ONE);
            }

            if (a.compareTo(b) > 0) {
                print(test, 0);
                continue;
            }

            BigInteger upperBoundA = getUpperBound(a);
            int i = upperBoundA.toString().length();
            BigInteger lowerBoundB = getLowerBound(b);
            int j = lowerBoundB.toString().length();

            long count = 0;
            if (i <= j) {
                count = count10s(i, j);

                count += countPalindromesWith2sBetween(a, upperBoundA, i - 1);
                count += countPalindromesWith2sBetween(lowerBoundB, b, j);

                count += countPalindromesWithout2sBetween(a, upperBoundA, i - 1);
                count += countPalindromesWithout2sBetween(lowerBoundB, b, j);
            } else {
                count += countPalindromesWith2sBetween(a, b, j);
                count += countPalindromesWithout2sBetween(a, b, j);
            }

            print(test, count);
            System.out.println("Done test #" + test);
            System.out.flush();
        }
    }

    private long countPalindromesWithout2sBetween(BigInteger a, BigInteger b, int i) {
        long count = 0;
        String s;

        if ((i & 1) == 1) {
            if(i == 1) {
                if(a.longValue() <= 1 && 1 <= b.longValue()) {
                    count ++;
                }
                if(a.longValue() <= 3 && 3 <= b.longValue()) {
                    count ++;
                }
                return count; // 1 and 3.
            } else {
            for (String x : getCombinations(i - 3 >> 1)) {
                s = "1" + x + "0" + reverse(x) + "1";
                if (checkIfSmaller(a, s) && checkIfSmaller(s, b)) {
                    count++;
                }
                s = "1" + x + "1" + reverse(x) + "1";
                if (checkIfSmaller(a, s) && checkIfSmaller(s, b)) {
                    count++;
                }
            }
            }
        } else {
            for (String x : getCombinations(i - 2 >> 1)) {
                s = "1" + x + reverse(x) + "1";
                if (checkIfSmaller(a, s) && checkIfSmaller(s, b)) {
                    count++;
                }
            }
        }

        return count;
    }
    
    private String reverse(String x) {
        return new StringBuilder(x).reverse().toString();
    }

    private Set<String> getCombinations(int n) {
        Set<String> set = new HashSet<String>();
        if (combinations.containsKey(n)) {
            return combinations.get(n);
        }
        if(n == 0) {
            set.add("");
            combinations.put(n, set);
            return set;
        }
        char[] s = new char[n];
        Arrays.fill(s, '0');
        set.add(new String(s));

        for (int i1 = 0; i1 <= n; i1++) {
            for (int i2 = i1 + 1; i2 <= n; i2++) {
                for (int i3 = i2 + 1; i3 <= n; i3++) {
                    add(set, s, i1);
                    add(set, s, i2);
                    add(set, s, i3);
                    
                    add(set, s, i1, i2);
                    add(set, s, i1, i3);
                    add(set, s, i2, i3);
                    
                    add(set, s, i1, i2, i3);
                }
            }
        }

        combinations.put(n, set);
        return set;
    }

    private void add(Set<String> list, char[] s, int i) {
        if (i < s.length) {
            s[i] = '1';
            list.add(new String(s));
            s[i] = '0';
        }
    }
    private void add(Set<String> list, char[] s, int i1, int i2) {
        if (i1 < s.length && i2 < s.length) {
            s[i1] = '1';
            s[i2] = '1';
            list.add(new String(s));
            s[i1] = '0';
            s[i2] = '0';
        }
    }
    private void add(Set<String> list, char[] s, int i1, int i2, int i3) {
        if (i1 < s.length && i2 < s.length && i3 < s.length) {
            s[i1] = '1';
            s[i2] = '1';
            s[i3] = '1';
            list.add(new String(s));
            s[i1] = '0';
            s[i2] = '0';
            s[i3] = '0';
        }
    }
    

    BigInteger sqrt(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while (b.compareTo(a) >= 0) {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if (mid.multiply(mid).compareTo(n) > 0) {
                b = mid.subtract(BigInteger.ONE);
            } else {
                a = mid.add(BigInteger.ONE);
            }
        }
        return a.subtract(BigInteger.ONE);
    }

    private long countPalindromesWith2sBetween(BigInteger a, BigInteger b, int i) {
        long count = 0;
        int mid = i >> 1;
        char[] val = new char[i];

        Arrays.fill(val, '0');
        val[0] = val[i - 1] = '2';
        if (checkIfSmaller(a, val) && checkIfSmaller(val, b)) {
            count++;
        }

        if ((i & 1) == 1 && i > 2) {
            val[mid] = '1';

            if (checkIfSmaller(a, val) && checkIfSmaller(val, b)) {
                count++;
            }

            val[0] = val[i - 1] = '1';
            val[mid] = '2';

            if (checkIfSmaller(a, val) && checkIfSmaller(val, b)) {
                count++;
            }

            for (int k = 1; k <= (i - 3) >> 1; k++) {
                val[mid - k] = val[mid + k] = '1';
                if (checkIfSmaller(a, val) && checkIfSmaller(val, b)) {
                    count++;
                }
                val[mid - k] = val[mid + k] = '0';
            }

        }

        return count;
    }

    private boolean checkIfSmaller(String val, BigInteger a) {
        BigInteger temp = new BigInteger(val);
        if (a.compareTo(temp) >= 0) {
            return true;
        }
        return false;
    }

    private boolean checkIfSmaller(char[] val, BigInteger a) {
        BigInteger temp = new BigInteger(new String(val));
        if (a.compareTo(temp) >= 0) {
            return true;
        }
        return false;
    }

    private boolean checkIfSmaller(BigInteger a, String val) {
        BigInteger temp = new BigInteger(val);
        if (a.compareTo(temp) <= 0) {
            return true;
        }
        return false;
    }

    private boolean checkIfSmaller(BigInteger a, char[] val) {
        BigInteger temp = new BigInteger(new String(val));
        if (a.compareTo(temp) <= 0) {
            return true;
        }
        return false;
    }

    /**
     * counts the number of palindromic numbers which squares are also palindromes
     * whose value x is:
     * 10^(i-1) <= x < 10^i
     * 
     * @param i
     * @return 
     */
    private long count10(int i) {
        if (i <= 0) {
            throw new RuntimeException("you failed me");
        }
        if (i == 1) {
            return 3;
        }
        // 200....002
        long count = 1;

        if ((i & 1) == 1) {
            // 200...010..002
            // 100...020..001
            // 100...01210..001
            // 100...10201..001
            // ...
            // 110...020...011
            count += (i + 1) >> 1;

            // 100..00000..001
            // 100..01010..001
            // 100..10001..001
            // 100..11011..001
            // ...
            // 111..11011..001

            // 100..00100..001
            // 100..01110..001
            // 100..10101..001
            // 100..11111..001
            // ...
            // 111..11111..001 -- at most 9 ones at any time.
            int l = i - 3 >> 1;
            count += 2;
            if(l>=1) {
                count += l * 2;
            }
            if(l>=2) {
                count += (l-1)*l;
            }
            if(l>=3){
                count += (l-2)*(l-1)*l/3;
            }
        } else {
            // 100..0000..001
            // 100..0110..001
            // 100..1001..001
            // 100..1111..001
            // ...
            // 11110..0100..1111  -- at most 9 ones at any time.
            int l = i - 2 >> 1;
            count += 1;
            if(l>=1) {
                count += l;
            }
            if(l>=2) {
                count += (l-1)*l/2;
            }
            if(l>=3){
                count += (l-2)*(l-1)*l/6;
            }
        }

        return count;
    }

    /**
     * 10^i <= x < 10^j
     * @param i
     * @param j
     * @return 
     */
    private long count10s(int i, int j) {
        long count = 0;
        for (int k = i; k < j; k++) {
            count += count10(k);
        }
        return count;
    }

    private BigInteger getUpperBound(BigInteger n) {
        BigInteger i = n;
        BigInteger result = BigInteger.ONE;
        while (!i.equals(BigInteger.ZERO)) {
            i = i.divide(BigInteger.TEN);
            result = result.multiply(BigInteger.TEN);
        }
        return result;
    }

    private BigInteger getLowerBound(BigInteger n) {
        return getUpperBound(n).divide(BigInteger.TEN);
    }

    private void readAB() {
        A = in.nextBigInteger();
        B = in.nextBigInteger();
    }

    private void print(int test, long count) throws IOException {
        String s = "Case #" + test + ": " + count + "\n";
        out.write(s);
    }

    private void print(int test, String count) throws IOException {
        String s = "Case #" + test + ": " + count + "\n";
        out.write(s);
    }

    private void close() throws IOException {
        this.in.close();
        this.out.close();
    }
}
