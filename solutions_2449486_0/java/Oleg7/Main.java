import java.io.*;
import java.util.Locale;
import java.util.Scanner;

// Problem B. Lawnmower
public class Main {

    // system
    public static String charset = "UTF-8";
    public static Locale locale = new Locale("en", "US");
    public static PrintWriter stdOut, fileOut;
    public static Scanner stdIn, fileIn;

    //task
    public static int[][] lawn;
    public static int N, M;

    public static void main(String[] args) {
        setIO("B-small-attempt0.in", "output.out");
        Scanner input = fileIn;
        PrintWriter output = fileOut;

        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            N = input.nextInt();
            M = input.nextInt();
            lawn = new int[N][M];
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    lawn[j][k] = input.nextInt();
                }
            }
            String resStr = "Case #" + i + ": " + solve();
            output.println(resStr);
            stdOut.println(resStr);
        }

        input.close();
        output.close();
    }

    //task
    public static String solve() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int item = lawn[i][j];
                // check horizontal
                boolean isHoriz = true;
                for (int k = 0; k < M; k++) {
                    if (lawn[i][k] > item) {
                        isHoriz = false;
                        break;
                    }
                }
                // check vertical
                boolean isVert = true;
                for (int k = 0; k < N; k++) {
                    if (lawn[k][j] > item) {
                        isVert = false;
                        break;
                    }
                }
                // decide
                if (!(isHoriz || isVert)) {
                    return "NO";
                }
            }
        }
        return "YES";
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
