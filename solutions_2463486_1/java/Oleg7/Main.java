import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.Scanner;

public class Main {

    // system
    public static String charset = "UTF-8";
    public static Locale locale = new Locale("en", "US");
    public static PrintWriter stdOut, fileOut;
    public static Scanner stdIn, fileIn;

    // task
    public static BigInteger A, B;

    // Problem C. Fair and Square
    public static void main(String[] args) {
        setIO("C-large-1.in", "output.out");
        Scanner input = fileIn;
        PrintWriter output = fileOut;

        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            A = new BigInteger(input.next());
            B = new BigInteger(input.next());
            String resStr = "Case #" + i + ": " + solve();
            output.println(resStr);
            stdOut.println(resStr);
        }

        input.close();
        output.close();
    }

    // task
    public static long solve() {
        long count = 0;
        BigInteger n, square;

        // first ones (pre-calc)
        String[] arr = new String[10];
        arr[0] = "1"; arr[1] = "4"; arr[2] = "9"; arr[3] = "121"; arr[4] = "484";
        arr[5] = "10201"; arr[6] = "12321"; arr[7] = "14641"; arr[8] = "40804"; arr[9] = "44944";
        for (int i = 0; i < arr.length; i++) {
            square = new BigInteger(arr[i]);
            if (square.compareTo(B) == 1) return count;
            if (square.compareTo(A) != -1) {
                count++;
            }
        }

        // others (algorithm)
        String[] oneOdd = new String[3];
        oneOdd[0] = "0"; oneOdd[1] = "1"; oneOdd[2] = "2";
        String[] oneEven = new String[1];
        oneEven[0] = "";
        String[] twoOdd = new String[2];
        twoOdd[0] = "0"; twoOdd[1] = "1";
        String twoEven = "0";
        boolean evenDigits = true;
        while (true) {
            if (evenDigits) {
                //even
                // 1..1
                int len = oneEven.length;
                String[] newOneEven = new String[len * 2];
                int cur = 0;
                for (int i = 0; i < len; i++) {
                    String s = "0" + oneEven[i] + "0";
                    n = new BigInteger("1" + s + "1");
                    square = n.multiply(n);
                    if (square.compareTo(B) == 1) return count;
                    if (square.compareTo(A) != -1) {
                        count++;
                        //stdOut.println(n.toString());
                    }
                    newOneEven[cur] = s;
                    cur++;
                }
                for (int i = 0; i < len; i++) {
                    String s = "1" + oneEven[i] + "1";
                    n = new BigInteger("1" + s + "1");
                    square = n.multiply(n);
                    if (square.compareTo(B) == 1) return count;
                    if (square.compareTo(A) != -1) {
                        count++;
                        //stdOut.println(n.toString());
                    }
                    newOneEven[cur] = s;
                    cur++;
                }
                oneEven = newOneEven;
                // 2..2
                twoEven += twoEven;
                n = new BigInteger("2" + twoEven + "2");
                square = n.multiply(n);
                if (square.compareTo(B) == 1) return count;
                if (square.compareTo(A) != -1) {
                    count++;
                    //stdOut.println(n.toString());
                }
            }
            else {
                // odd
                // 1...1
                int len = oneOdd.length;
                String[] newOneOdd = new String[len * 2];
                int cur = 0;
                for (int i = 0; i < len; i++) {
                    String s = "0" + oneOdd[i] + "0";
                    n = new BigInteger("1" + s + "1");
                    square = n.multiply(n);
                    if (square.compareTo(B) == 1) return count;
                    if (square.compareTo(A) != -1 && isPalindrom(square.toString())) {
                        count++;
                        //stdOut.println(n.toString());
                    }
                    newOneOdd[cur] = s;
                    cur++;
                }
                for (int i = 0; i < len; i++) {
                    String s = "1" + oneOdd[i] + "1";
                    n = new BigInteger("1" + s + "1");
                    square = n.multiply(n);
                    if (square.compareTo(B) == 1) return count;
                    if (square.compareTo(A) != -1 && isPalindrom(square.toString())) {
                        count++;
                        //stdOut.println(n.toString());
                    }
                    newOneOdd[cur] = s;
                    cur++;
                }
                oneOdd = newOneOdd;
                // 2...2
                for (int i = 0; i < 2; i++) {
                    String s = "0" + twoOdd[i] + "0";
                    n = new BigInteger("2" + s + "2");
                    square = n.multiply(n);
                    if (square.compareTo(B) == 1) return count;
                    if (square.compareTo(A) != -1 && isPalindrom(square.toString())) {
                        count++;
                        //stdOut.println(n.toString());
                    }
                    twoOdd[i] = s;
                }
            }
            evenDigits = !evenDigits;
        }
    }

    /*public static long solve() {
        long count = 0;
        BigInteger one = new BigInteger("1");
        BigInteger two = new BigInteger("2");
        BigInteger n = one;
        BigInteger square = one;
        BigInteger nextSquareDelta = one;
        // search start num
        while (square.compareTo(A) < 0) {
            nextSquareDelta = nextSquareDelta.add(two);
            square = square.add(nextSquareDelta);
            n = n.add(one);
        }

        while (square.compareTo(B) < 1) {
            if (isPalindrom(square.toString()) && isPalindrom(n.toString())) {
                count++;
                stdOut.println(n.toString() + ": " + square.toString());
                //BigInteger square = n.multiply(n);
                //if (square.compareTo(B) == 1) break;
                //if (isPalindrom(square.toString())) {count++; stdOut.println(square.toString());}
                //int sqrt = Math.round(Math.sqrt(n.doubleValue()));
            }
            nextSquareDelta = nextSquareDelta.add(two);
            square = square.add(nextSquareDelta);
            n = n.add(one);
        }
        return count;
    }*/

    /*public static long solve() {
        long count = 0;
        BigInteger one = new BigInteger("1");
        BigInteger n = one;
        while (n.compareTo(B) < 1) {
            if (isPalindrom(n.toString())) {
                BigInteger square = n.multiply(n);
                if (square.compareTo(A) != -1) {
                    if (square.compareTo(B) == 1) break;
                    if (isPalindrom(square.toString())) {count++; stdOut.println(square.toString());}

                }
            }
            n = n.add(one);
        }
        return count;
    }*/

    /*public static long solve() {
        long count = 0;
        BigInteger one = new BigInteger("1");
        BigInteger n = one;
        while (n.compareTo(B) < 1) {
            if (isPalindrom(n.toString())) {
                BigInteger square = n.multiply(n);
                if (square.compareTo(A) != -1) {
                    if (square.compareTo(B) == 1) break;
                    if (isPalindrom(square.toString())) count++;
                }
            }
            n = n.add(one);
        }
        return count;
    }*/

    public static boolean isPalindrom(String s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) return false;
        }
        return true;
    }

    // system
    public static void setIO(String fileInName, String fileOutName) {
        // Standard input
        stdIn = new Scanner(new BufferedInputStream(System.in), charset);
        stdIn.useLocale(locale);

        // Standard output
        try {
            stdOut = new PrintWriter(new OutputStreamWriter(System.out, charset), true);
        }
        catch (UnsupportedEncodingException e) {
            System.err.println(e);
        }

        // File input
        if (fileInName != null) {
            try {
                File file = new File(fileInName);
                if (file.exists()) {
                    fileIn = new Scanner(file, charset);
                    fileIn.useLocale(locale);
                }
            }
            catch (IOException ioe) {
                System.err.println("Could not open " + fileInName);
            }
        }

        // File output
        if (fileOutName != null) {
            try {
                OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream(fileOutName), charset);
                fileOut = new PrintWriter(osw, true);
            }
            catch (IOException e) {
                System.err.println(e);
            }
        }
    }
}

