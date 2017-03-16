
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Stream;


// 10^6 ~ 2 sec
public class Main {

    private static final String IN_FILENAME = "/Users/kyesipau/dev/personal/src/B-small-attempt0.in";
    private static final String OUT_FILENAME = "/Users/kyesipau/dev/personal/src/out.txt";

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(IN_FILENAME));
        PrintWriter writer = new PrintWriter(OUT_FILENAME, "UTF-8");
        int t = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < t; i++) {
            int caseNum = i + 1;
            String[] input = reader.readLine().trim().split(" ");
            String[] res = solve(input);
            String out = res[0] + " " + res[1];
            writer.println("Case #" + caseNum + ": " + out);
        }

        reader.close();
        writer.close();
    }

    private static String[] solve(String[] input) {
        String first = input[0];
        String second = input[1];

        int len = first.length();


        String fRes = "";
        String sRes = "";

        int index = 0;
        char f = first.charAt(index);
        char s = second.charAt(index);
        boolean equal = true;
        boolean firstMore = true;

        if (f != '?' && s != '?') {
            fRes = fRes + f;
            sRes = sRes + s;

            if (f != s) {
                equal = false;
                firstMore = f > s;
            }
        } else if (f != '?') {
            fRes = fRes + f;
            sRes = sRes + f;
        } else if (s != '?') {
            fRes = fRes + s;
            sRes = sRes + s;
        } else {
            fRes = fRes + '0';
            sRes = sRes + '0';
        }

        for (index = 1; index < len; index++) {
            f = first.charAt(index);
            s = second.charAt(index);
            if (equal) {
                if (f != '?' && s != '?') {
                    fRes = fRes + f;
                    sRes = sRes + s;

                    if (f != s) {
                        equal = false;
                        firstMore = f > s;
                    }
                } else if (f != '?') {
                    fRes = fRes + f;
                    sRes = sRes + f;
                } else if (s != '?') {
                    fRes = fRes + s;
                    sRes = sRes + s;
                } else {
                    fRes = fRes + '0';
                    sRes = sRes + '0';
                }
            } else {
                if (firstMore) {
                    if (f != '?' && s != '?') {
                        fRes = fRes + f;
                        sRes = sRes + s;
                    } else if (f != '?') {
                        fRes = fRes + f;
                        sRes = sRes + '9';
                    } else if (s != '?') {
                        fRes = fRes + '0';
                        sRes = sRes + s;
                    } else {
                        fRes = fRes + '0';
                        sRes = sRes + '9';
                    }
                } else {
                    if (f != '?' && s != '?') {
                        fRes = fRes + f;
                        sRes = sRes + s;
                    } else if (f != '?') {
                        fRes = fRes + f;
                        sRes = sRes + '0';
                    } else if (s != '?') {
                        fRes = fRes + '9';
                        sRes = sRes + s;
                    } else {
                        fRes = fRes + '9';
                        sRes = sRes + '0';
                    }
                }
            }
        }
        return new String[]{fRes, sRes};
    }
}
