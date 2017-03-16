package ondra;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Match {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        new Match().run();
    }

    private void run() throws FileNotFoundException, IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader("B-small-attempt0.in"));
                PrintWriter writer = new PrintWriter(new FileWriter("B-small-attempt0.out"))) {
            String line;
            reader.readLine(); // ignore
            int c = 1;
            while ((line = reader.readLine()) != null) {
                String[] split = line.split(" ");
                String codersString = split[0];
                String jammersString = split[1];
                int maximum = 0;
                if (codersString.length() == 1) maximum = 10;
                else if (codersString.length() == 2) maximum = 100;
                else if (codersString.length() == 3) maximum = 1000;
                else throw new RuntimeException("Unexpected length.");
                int result = -1;
                int resultCoders = -1;
                int resultJammers = -1;
                for (int coders = 0; coders < maximum; coders++) {
                    for (int jammers = 0; jammers < maximum; jammers++) {
                        if (match(coders, codersString) && match(jammers, jammersString)) {
                            if (result == -1) {
                                result = Math.abs(coders - jammers);
                                resultCoders = coders;
                                resultJammers = jammers;
                            }
                            else {
                                if (Math.abs(coders - jammers) < result || (Math.abs(coders - jammers) == result && (coders < resultCoders || (coders == resultCoders && jammers < resultJammers)))) {
                                    result = Math.abs(coders - jammers);
                                    resultCoders = coders;
                                    resultJammers = jammers;
                                }
                            }
                        }
                    }
                }
                if (result == -1) throw new RuntimeException("No match found.");
//                System.out.println(alignNumber(resultCoders, codersString.length()));
//                System.out.println(alignNumber(resultJammers, jammersString.length()));
//                System.out.println();
                writer.println(String.format("Case #%d: %s %s", c, alignNumber(resultCoders, codersString.length()), alignNumber(resultJammers, jammersString.length())));

                System.out.println(c);
                c++;
            }
        }
    }

    private String alignNumber(int number, int length) {
        String numberString = String.valueOf(number);
        if (length - numberString.length() == 1) numberString = "0" + numberString;
        else if (length - numberString.length() == 2) numberString = "00" + numberString;
        if (length - numberString.length() != 0) throw new RuntimeException("Error aligning strings");
        return numberString;
    }

    private boolean match(int number, String string) {
        String numberString = alignNumber(number, string.length());
        for (int i = 0; i < string.length(); i++) {
            if (string.charAt(i) != '?' && string.charAt(i) != numberString.charAt(i)) {
                return false;
            }
        }
        return true;
    }

}
