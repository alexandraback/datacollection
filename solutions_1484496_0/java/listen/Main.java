import java.util.Scanner;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.net.URLConnection;
import java.util.InputMismatchException;
import java.util.Locale;
import java.net.URL;
import java.io.PrintStream;
import java.net.Socket;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.BufferedInputStream;
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

    public void solve(int testNumber, Scanner in_t, PrintWriter out) {
             In in = new In("D:\\codeforce\\src\\C-small-attempt0.in");
        Out output = new Out("D:\\codeforce\\src\\C-small-attempt0.out");
        int ca,n,i,j,T,k = 0;    ca = in.readInt();

          for(int ii=1;ii<=ca;++ii)
          {
              output.println("Case #" + ii + ":");
              n = in.readInt();
              long[] input = new long[n];
              for(i=0;i<n;i++){
                  input[i] = in.readLong();
              }

               long Max = (1L<<n)-1;
              boolean[] b = new boolean[300];
              boolean flag=false;
              for(i=1;i<=Max;i++)
              {
                   int sum1=0,sum2=0;
                  Arrays.fill(b, false);
                  for(j=0;j<n;j++)
                  {
                      if((i&(1L<<j))>0)
                      {
                          b[j]=true;
                          sum1+=input[j];
                      }
                  }

                  for(k=1;k<=Max;k++)
                  {
                      if(k==i) continue;
                      sum2=0;
                          for(j=0;j<n;j++)
                          if((k&(1L<<j))>0 && b[j]==true) break;
                          else if((k&(1L<<j))>0 ) sum2+=input[j];
                          if(j==n && sum1==sum2) {flag=true;break;}
                  }
                  if(flag==true) break;
              }
              if(flag==true)
              {
                 int ss=0;
                  for(j=0;j<n;j++)
                  if(b[j]==true)
                  {
                      if(ss==0) {output.print(input[j]); ss=1;}
                      else output.print( " " + input[j]);
                  }
                  output.println();
                  ss=0;
                  for(j=0;j<n;j++)
                  if((k&(1L<<j))>0)
                  {
                      if(ss==0) { ss=1;output.print(input[j]);}
                      else output.print( " " + input[j]);
                  }
                  output.println();
              }
              else
              {
                  output.println("Impossible");
              }
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

   /**
     * Print a long and then flush the output stream.
     */
    public void print(long x) {
        out.print(x);
        out.flush();
    }


   }

