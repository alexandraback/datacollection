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
        public static String outputWithN(double res, int n){
        StringBuilder sb = new StringBuilder("0.");
        for (int i = 0; i < n; ++i){
            sb.append("0");
        }
        DecimalFormat df = new DecimalFormat(sb.toString());
        String num = df.format(res);
        return num;
    }
    public void solve(int testNumber, Scanner in_t, PrintWriter out) {
        In in = new In("D:\\codeforce\\src\\A-small-attempt0.in");
        Out output = new Out("D:\\codeforce\\src\\A-small-attempt0.out");
        int T = in.readInt();
        for (int tt = 1; tt <= T; ++tt){
            int typed_count = in.readInt();
            int total_count = in.readInt();
            double[] p = new double[typed_count+1];
            for (int i = 0; i < typed_count; ++i){
                p[i+1] = in.readDouble();
            }
            double[] total_right = new double[typed_count+1];
            double[] first_bad = new double[typed_count + 1];
            total_right[0] = 1;first_bad[0] = 1;
            for (int i = 1; i <= typed_count; ++i){
                total_right[i] = total_right[i-1] * p[i];
                first_bad[i] = total_right[i-1] * (1 - p[i]);
            }
            double res1 = total_right[typed_count] * (total_count - typed_count + 1);
            res1 += (1 - total_right[typed_count]) * (total_count - typed_count + 1 + total_count + 1);

            double res2 = 1e8;

            double res3 = 1 + total_count + 1;
            for (int i = 1; i <= typed_count; ++i){
                double e1 = total_right[typed_count - i] * (i + i + total_count - typed_count + 1);
                double e2 = (1 - total_right[typed_count - i]) * (i + i + total_count - typed_count + 1 + total_count + 1);
               res2 = Math.min(res2, e1 + e2);
            }
            double res = Math.min(res1, Math.min(res2, res3)) ;
            String res_string = outputWithN(res, 6);
            output.println("Case #" + tt + ": "  + res_string);
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
     * Print an object and then terminate the line.
     */
    public void println(Object x) {
        out.println(x);
    }



   }

