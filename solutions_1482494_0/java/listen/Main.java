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
import java.util.Map;
import java.io.IOException;
import java.util.TreeMap;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    public void solve(int testNumber, Scanner in_t, PrintWriter out) {
        In in = new In("D:\\codeforce\\src\\B-small-attempt0.in");
        Out output = new Out("D:\\codeforce\\src\\B-small-attempt0.out");
        int T = in.readInt();
        for (int tt = 1; tt <= T; ++tt){
            int n = in.readInt();

            long res = 0;
            int[] one_start = new int[n];
            int[] two_start = new int[n];
            for (int i = 0; i < n; ++i){
                one_start[i] = in.readInt();
                two_start[i] = in.readInt();
            }
            Map<Integer, List<Integer>> one_star_map = new TreeMap<Integer,List<Integer>>();
            Map<Integer, List<Integer>> two_start_map = new TreeMap<Integer,List<Integer>>();
            for (int i = 0; i < n; ++i){
                 if (one_star_map.containsKey(one_start[i])){
                     one_star_map.get(one_start[i]).add(i);
                 }                                         else{
                     List<Integer> list = new ArrayList<Integer>();list.add(i);
                     one_star_map.put(one_start[i], list);
                 }
                if (two_start_map.containsKey(two_start[i])){
                    two_start_map.get(two_start[i]).add(i);
                } else{
                     List<Integer> list = new ArrayList<Integer>();list.add(i);
                    two_start_map.put(two_start[i], list);
                }
            }
            int cur = 0, cnt = 0;
            boolean [] visited = new boolean[n];  boolean [] visited2 = new boolean[n];
            boolean found = true;
            if (tt == 5){
                int cc = tt * 2;
            }
            while(true){
                int first = (Integer)(two_start_map.keySet().toArray())[0];
                if (cur >= first){
                    ++cnt;++res;
                    if (cnt == n){
                        break;
                    }
                    List<Integer> list = two_start_map.get(Integer.valueOf(first));
                    int index = list.get(0);    visited2[index] = true;
                    if (visited[index]){
                        ++cur;
                    }else{
                        cur += 2;
                    }
                    list.remove(0);
                    if (list.size() == 0){
                        two_start_map.remove(first);
                    }
                } else{
                    if (one_star_map.size() == 0){
                       output.println("Case #" + tt + ": Too Bad");
                        found = false;
                        break;
                    }
                   first = (Integer)(one_star_map.keySet().toArray())[0];
                   if (cur >= first){
                        List<Integer> list = one_star_map.get(Integer.valueOf(first));
                        int index = list.get(0);
                       if (visited2[index]){
                            list.remove(0);
                            if (list.size() == 0){
                                one_star_map.remove(first);
                            }
                           continue;
                       }
                        ++cur; ++res;
                        visited[index] = true;
                        list.remove(0);
                        if (list.size() == 0){
                            one_star_map.remove(first);
                        }
                    }
                    else{
                        output.println("Case #" + tt + ": Too Bad");
                        found = false;
                            break;
                    }
                }
            }
            if (found)
                output.println("Case #" + tt + ": " + res);
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

