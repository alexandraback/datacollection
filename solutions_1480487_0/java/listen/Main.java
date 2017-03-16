import java.util.Scanner;
import java.io.OutputStreamWriter;
import java.net.URLConnection;
import java.util.Locale;
import java.net.URL;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.text.NumberFormat;
import java.io.File;
import java.io.BufferedInputStream;
import java.text.DecimalFormat;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.net.Socket;
import java.io.FileOutputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author @zhendeaini6001
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

    public void solve(int testNumber, Scanner in_t, PrintWriter out) {
        In in = new In("D:\\codeforce\\src\\A-small-attempt0.in");
        Out output = new Out("D:\\codeforce\\src\\A-small-attempt0.out");
        int T = in.readInt();
        for (int ii = 1; ii <= T; ++ii){
            int n = in.readInt();
            int[] input = new int[n];
            int min = 101, min_count = 0, total = 0;
            double [] res = new double[n];
            for (int i = 0; i < n; ++i){
                input[i] = in.readInt();
                total += input[i];
                if (input[i] < min){
                    min = input[i];
                    min_count = 1;
                }else if (input[i] == min){
                    ++min_count;
                }
            }


            for (int i = 0; i < n; ++i){
                double R = 1.1, L = 0;

                while(R - L > 1e-9){
	                double M = (L + R) / 2;

                    boolean test = false;
                    double p = input[i] + total * M;
                    double cnt = 0;
                    for (int j = 0; j < n; ++j){
                        if (i == j){
                            continue;
                        }
                        cnt += Math.max(0, (p - input[j]) / total + DoubleUtils.EPS);
                    }
                    if (cnt >= 1 - M + DoubleUtils.EPS){
                        test = false;
                    }else{
                        test = true;
                    }
                    if(test)
                        L = M;
                    else
                        R = M;
                }
                res[i] = L;
                if (i == 1){
                    int c = 0;
                }
                res[i] *= 100;
            }
            output.print("Case #" + ii + ":");
            for (int i = 0; i < n; ++i){
                output.print(" ");
                String str = String.format("%.6f",res[i]);
                output.print(str);
            }
            output.println();
        }
        return;
    }
}

class In {
    private Scanner scanner;

    // assume Unicode UTF-8 encoding
    //private String charsetName = "UTF-8";

    private String charsetName = "ISO-8859-1";

    // assume language = English, country = US for consistency with System.out.
    private Locale usLocale = new Locale("en", "US");

   /**
     * Create an input stream for standard input.
     */
    public In() {
        scanner = new Scanner(new BufferedInputStream(System.in), charsetName);
        scanner.useLocale(usLocale);
    }

   /**
     * Create an input stream from a socket.
     */
    public In(Socket socket) {
        try {
            InputStream is = socket.getInputStream();
            scanner = new Scanner(new BufferedInputStream(is), charsetName);
            scanner.useLocale(usLocale);
        }
        catch (IOException ioe) {
            System.err.println("Could not open " + socket);
        }
    }

   /**
     * Create an input stream from a URL.
     */
    public In(URL url) {
        try {
            URLConnection site = url.openConnection();
            InputStream is     = site.getInputStream();
            scanner            = new Scanner(new BufferedInputStream(is), charsetName);
            scanner.useLocale(usLocale);
        }
        catch (IOException ioe) {
            System.err.println("Could not open " + url);
        }
    }

   /**
     * Create an input stream from a file.
     */
    public In(File file) {

        try {
            scanner = new Scanner(file, charsetName);
            scanner.useLocale(usLocale);
        }
        catch (IOException ioe) {
            System.err.println("Could not open " + file);
        }
    }


   /**
     * Create an input stream from a filename or web page name.
     */
    public In(String s) {

        try {
            // first try to read file from local file system
            File file = new File(s);
            if (file.exists()) {
                scanner = new Scanner(file, charsetName);
                scanner.useLocale(usLocale);
                return;
            }

            // next try for files included in jar
            URL url = getClass().getResource(s);

            // or URL from web
            if (url == null) { url = new URL(s); }

            URLConnection site = url.openConnection();
            InputStream is     = site.getInputStream();
            scanner            = new Scanner(new BufferedInputStream(is), charsetName);
            scanner.useLocale(usLocale);
        }
        catch (IOException ioe) {
            System.err.println("Could not open " + s);
        }
    }

   /**
     * Is the input stream empty?
     */
    public boolean isEmpty() {
        return !scanner.hasNext();
    }

   /**
     * Does the input stream have a next line?
     */
    public boolean hasNextLine() {
        return scanner.hasNextLine();
    }

   /**
     * Read and return the next line.
     */
    public String readLine() {
        String line;
        try                 { line = scanner.nextLine(); }
        catch (Exception e) { line = null;               }
        return line;
    }



    // return rest of input as string
   /**
     * Read and return the remainder of the input as a string.
     */
    public String readAll() {
        if (!scanner.hasNextLine()) { return null; }

        // reference: http://weblogs.java.net/blog/pat/archive/2004/10/stupid_scanner_1.html
        return scanner.useDelimiter("\\A").next();
    }



   /**
     * Return the next string from the input stream.
     */
    public String  readString() {
        return scanner.next();
    }

   /**
     * Return the next int from the input stream.
     */
    public int readInt() {
        return scanner.nextInt();
    }

   /**
     * Return the next double from the input stream.
     */
    public double readDouble() {
        return scanner.nextDouble();
    }


   /**
     * Read ints from file
     */
    public static int[] readInts(String filename) {
        In in = new In(filename);
        String[] fields = in.readAll().trim().split("\\s+");
        int[] vals = new int[fields.length];
        for (int i = 0; i < fields.length; i++)
            vals[i] = Integer.parseInt(fields[i]);
        return vals;
    }

   /**
     * Close the input stream.
     */
    public void close() { scanner.close();  }



   }

class Out {

    // force Unicode UTF-8 encoding; otherwise it's system dependent
    private static final String UTF8 = "UTF-8";


    private PrintWriter out;

   /**
     * Create an Out object using an OutputStream.
     */
    public Out(OutputStream os) {
        try {
            OutputStreamWriter osw = new OutputStreamWriter(os, UTF8);
            out = new PrintWriter(osw, true);
        }
        catch (IOException e) { e.printStackTrace(); }
    }

   /**
     * Create an Out object using standard output.
     */
    public Out() { this(System.out); }

   /**
     * Create an Out object using a Socket.
     */
    public Out(Socket socket) {
        try {
            OutputStream os = socket.getOutputStream();
            OutputStreamWriter osw = new OutputStreamWriter(os, UTF8);
            out = new PrintWriter(osw, true);
        }
        catch (IOException e) { e.printStackTrace(); }
    }

   /**
     * Create an Out object using a file specified by the given name.
     */
    public Out(String s) {
        try {
            OutputStream os = new FileOutputStream(s);
            OutputStreamWriter osw = new OutputStreamWriter(os, UTF8);
            out = new PrintWriter(osw, true);
        }
        catch (IOException e) { e.printStackTrace(); }
    }

   /**
     * Close the output stream.
     */
    public void close() { out.close(); }



   /**
     * Terminate the line.
     */
    public void println() {
        out.println();
    }

   /**
     * Print an object and then terminate the line.
     */
    public void println(Object x) {
        out.println(x);
    }



   /**
     * Print an object and then flush the output stream.
     */
    public void print(Object x) {
        out.print(x);
        out.flush();
    }


   }

class DoubleUtils {
    public static double EPS = 1e-10;

    }

