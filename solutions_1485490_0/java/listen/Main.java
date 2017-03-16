import java.util.Scanner;
import java.io.OutputStreamWriter;
import java.net.URLConnection;
import java.util.Locale;
import java.net.URL;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.BufferedInputStream;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
     long[] box_count;
    long[] toy_count;
     List<Integer>  box_type_list, toy_type_list;
    List<Long> box_count_list, toy_count_list;
    int n, m;
    public long dfs(int b, int t){
        if (b >= n || t >= m){
            return 0L;
        }
        if (box_type_list.get(b) == toy_type_list.get(t)){
            int type = box_type_list.get(b);
            long min = Math.min(box_count[type], toy_count[type]);
            box_count[type] -= min; toy_count[type] -= min; long res = min;
            if (box_count[type] < toy_count[type]){
                ++b;
                if (b < n){
                    if (box_type_list.get(b) == type){
                         box_count[box_type_list.get(b)] += box_count_list.get(b);
                    }else{
                        box_count[box_type_list.get(b)] = box_count_list.get(b);
                    }
                    res += dfs(b, t);
                }
                return  res;
            }else{
                ++t;
                if (t < m){
                    if (toy_type_list.get(t) == type){
                        toy_count[toy_type_list.get(t)] += toy_count_list.get(t);
                    } else{
                        toy_count[toy_type_list.get(t)] = toy_count_list.get(t);
                    }
                    res += dfs(b, t);
                }
                return  res;
            }

        }else{
            long res1 = 0, res2 = 0;
            long[] box_count_t = new long[101];long[] toy_count_t = new long[101];
            System.arraycopy(box_count, 0, box_count_t, 0, 101);
            System.arraycopy(toy_count, 0, toy_count_t, 0, 101);

            ++b;
            if (b < n){
                if (box_type_list.get(b) == box_type_list.get(b-1)){
                   box_count[box_type_list.get(b)] += box_count_list.get(b);
                }else{
                    box_count[box_type_list.get(b)] = box_count_list.get(b);
                }
                res1 = dfs(b, t);
            }
            --b;
            System.arraycopy(box_count_t, 0, box_count, 0, 101);
            System.arraycopy(toy_count_t, 0, toy_count, 0, 101);
            ++t;
            if (t < m){
                if (toy_type_list.get(t) == toy_type_list.get(t-1)){
                   toy_count[toy_type_list.get(t)] += toy_count_list.get(t);
                }else{
                    toy_count[toy_type_list.get(t)] = toy_count_list.get(t);
                }
                res2 = dfs(b, t);
            }
            --t;
            return Math.max(res1, res2);
        }
    }
    public void solve(int testNumber, Scanner in_t, PrintWriter out) {
        In in = new In("D:\\codeforce\\src\\C-small-attempt0.in");
        Out output = new Out("D:\\codeforce\\src\\C-small-attempt0.out");

        int T = in.readInt();
        for (int ii = 1; ii <= T; ++ii){
            n = in.readInt();
            m = in.readInt();
            box_count = new long[101];
            toy_count = new long[101];
            box_count_list = new ArrayList<Long>();
            toy_count_list = new ArrayList<Long>();
            box_type_list  = new ArrayList<Integer>();
            toy_type_list =    new ArrayList<Integer>();

            for (int i = 0; i < n; ++i){
                long count = in.readLong();
                int type = in.readInt();
                box_type_list.add(type);
                box_count_list.add(count);
            }
            for (int i = 0; i < m; ++i){
                long count = in.readLong();
                int type = in.readInt();
                toy_type_list.add(type);
                toy_count_list.add(count);
            }
            box_count[box_type_list.get(0)] = box_count_list.get(0);
            toy_count[toy_type_list.get(0)] = toy_count_list.get(0);
            output.println("Case #" + ii + ": " +  dfs(0, 0));
        }
        return ;
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
     * Return the next long from the input stream.
     */
    public long readLong() {
        return scanner.nextLong();
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

