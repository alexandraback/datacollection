package shutovich;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

/**
 * Created by U on 4/9/2016.
 */
public class SheepDigits {
    static Pattern ex = Pattern.compile("^(20+)+$");

    static void markDigits(int x, boolean[] hasDigit) {
        String s = "" + x;
        for (int i = 0; i < s.length(); i++) {
            hasDigit[s.charAt(i) - '0'] = true;
        }
    }

    static int getResult(int n) {
        if (ex.matcher("" + n).find()) {
            return n * 45;
        } else {
            boolean[] hasDigit = new boolean[10];
            int n1 = n;
            while (true) {
                markDigits(n1, hasDigit);
                int i = 0;
                for (i = 0; i < 10; i++) {
                    if (!hasDigit[i]) {
                        break;
                    }
                }
                if (i == 10) {
                    return n1;
                }
                n1 += n;
            }

        }
    }


    public static void main(String[] args) throws IOException {
        List<String> lines = Files.readAllLines(new File("input1").toPath());
        int count = Integer.parseInt(lines.get(0));
        List<String> resultLines = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            int n = Integer.parseInt(lines.get(i + 1));
            String result = (n == 0)? "INSOMNIA" : "" + getResult(n);
            resultLines.add("Case #" + (i + 1) + ": " + result);
        }
        Files.write(new File("output1").toPath(), resultLines);

    }

}
