import java.io.*;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

//Problem A
public class Main {

    // system
    public static String charset = "UTF-8";
    public static Locale locale = new Locale("en", "US");
    public static PrintWriter stdOut, fileOut;
    public static Scanner stdIn, fileIn;

    // task
    public static Set<Character> vow;


    public static void main(String[] args) {
        setIO("A-small-attempt0.in", "output.out");
        Scanner input = fileIn;
        PrintWriter output = fileOut;

        vow = new HashSet<Character>(5);
        vow.add('a');
        vow.add('e');
        vow.add('i');
        vow.add('o');
        vow.add('u');

        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            input.nextLine();
            String s = input.next();
            int n = input.nextInt();

            int total = 0;
            int lastJ = 0;
            for (int j = 0; j < s.length() - n + 1; j++) {
                if (!vow.contains(s.charAt(j))) {
                    boolean isCons = true;
                    for (int k = j + 1; k < j + n; k++) {
                        if (vow.contains(s.charAt(k))) {
                            isCons = false;
                            break;
                        }
                    }
                    if (isCons) {
                        total++;
                        int rest = s.length() - j - n;
                        if (rest == 0) {
                            total += j - lastJ;
                        } else {
                            total += (j - lastJ) * (rest + 1) + rest;
                        }
                        lastJ = j + 1;
                    }
                }
            }

            String resStr = "Case #" + i + ": " + total;
            output.println(resStr);
            stdOut.println(resStr);
        }

        input.close();
        output.close();
    }

    // task
    public static String solve() {
        return "";
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
