package gcj2015_Qualification;

import java.io.*;
//import java.util.Scanner;

public class C {

    static BufferedReader in;
//    static String taskname = "C-small";
//    static String taskname = "C-small-attempt0";
//    static String taskname = "C-small-attempt1";
    static String taskname = "C-large";
//    static String taskname = "C-small-practice";
    static String[][] multiplyMap = {
        { "1",  "i",  "j",  "k"},
        { "i", "-1",  "k", "-j"},
        { "j", "-k", "-1",  "i"},
        { "k",  "j", "-i", "-1"}
    };

    public static int getIndex(String s) {
        if ( s.equals("1")) return 0;
        if ( s.equals("i")) return 1;
        if ( s.equals("j")) return 2;
        if ( s.equals("k")) return 3;

        return -1;
    }

    // str must not be too long
    public static String multiply (String str) {
        String result = "" + str.charAt(0);
        for (int i=1; i < str.length(); i++) {
            String first = result.substring(result.length() - 1);
            String second = "" + str.charAt(i);

            boolean resultWasNegative = result.startsWith("-");
            result = multiplyMap[getIndex(first)][getIndex(second)];
            if (result.startsWith("-")) {
                if ( resultWasNegative ) result = result.substring(1);
            }
            else if ( resultWasNegative ) result = "-" + result;
        }
        return result;
    };

    public static String multiply (String first, String second) {
        Boolean firstIsNegative = first.startsWith("-");
        Boolean secondIsNegative = second.startsWith("-");

        Boolean positiveBeforeMultiplyResult =
                ( firstIsNegative  && secondIsNegative ) ||
                ( !firstIsNegative && !secondIsNegative );

        String p1 = first.substring(first.length() - 1);
        String p2 = second.substring(second.length() - 1);

        String product = multiplyMap[getIndex(p1)][getIndex(p2)];

        if ( !positiveBeforeMultiplyResult ) {

            return product.startsWith("-") ? product.substring(1) : "-" + product;
        }

        return product;
    };

    public static String pow(String s, long x) {
        if (s.equals("1")) return "1";
        if (s.equals("-1")) {
            if (x % 2 == 0 ) return "1";
            return "-1";
        }
        if (x % 4 == 0) return "1";
        if (x % 4 == 1) return s;
        if (x % 4 == 2) return "-1";
        return s.startsWith("-") ? s.substring(1) : "-" + s;
    }

    public static String solve() throws IOException {
        String L_X = in.readLine();
        String[] spitted = L_X.split("\\s+");
        long L = Long.parseLong(spitted[0]);
        long X = Long.parseLong(spitted[1]);

        if ( L * X < 3) return "NO";

        Boolean hasI = false;
        Boolean hasJ = false;
        Boolean hasK = false;

        Boolean Icreated = false;
        Boolean Jcreated = false;

        String product = "1";

        for (long i = 0; i < L ; i++) {
            char[] l = Character.toChars(in.read());
            char ch = l[0];
            if ( ch == 'i' ) {
                hasI = true;
            }
            if ( ch == 'j' ) {
                hasJ = true;
            }
            if ( ch == 'k') {
                hasK = true;
            }

            product = multiply(product , "" + ch);
            if (product.equals("i")) Icreated = true;

            // ( first substring creates i ) * ( second substring creates j )
            // i * j == k
            if (Icreated && product.equals("k")) Jcreated = true;
        }

        // if final product wont be equal to product of i*j*k then NO
        if (  !pow(product, X).equals("-1")  ) return "NO";

        // if final product is -1 and j somehow created, that means that the tail will give k
        if ( Jcreated ) return "YES";

        // if only one type of letters repeated
        if ( !hasI && !hasJ ) return "NO";
        if ( !hasI && !hasK ) return "NO";
        if ( !hasK && !hasJ ) return "NO";

        // if j not created
        if ( Icreated && X > 1) return "YES";

        // if i not created (or X = 1)
        if ( X < 5) return "NO";

        return "YES";
    }

    public static void main(String[] args) {

        try {
            PrintWriter pW = new PrintWriter(new FileOutputStream("output/"
                    + taskname + ".out"));
            try {
                in = new BufferedReader(new FileReader("input/"
                        + taskname + ".in"));
                int T = Integer.parseInt( in.readLine());
                for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
                    pW.println("Case #" + caseNumber + ": " + solve());
                    in.readLine();
                }
                in.close();
                pW.close();
            } catch (IOException e) {
                System.out.println("Can not find file " + taskname + ".in");
            }
        } catch (IOException e) {
            System.out.println("Open or create exception with "
                    + taskname + ".out");
        }
    }
}

