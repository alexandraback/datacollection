package C;

import java.io.*;
import java.util.*;

public class C {

    public static void main(String[] args) {

      //  Reader in = new Reader();
      //  Writer out = new Writer();



      //   Reader in = new Reader("dsmall.in");
      //  Writer out = new Writer("dsmalloutput.out");

        Reader in = new Reader("dlarge.in");
        Writer out = new Writer("dlargeoutput.out");



        int T = in.nextInt();




        for (int i = 0; i < T; i++) {
            int cp=0,cm=0;
            TreapSet<Double> ts = new TreapSet<Double>();
            int n = in.nextInt();
            double a[],b[];
            a = new  double[n];
            b = new double[n];
            for (int j = 0; j < n; j++) {
                a[j]= in.nextDouble();

            }

            for (int j = 0; j < n; j++) {
                double t  = in.nextDouble();
                b[j] = t;
                ts.add(t);

            }



            for (int j = 0; j < n; j++) {
                double t = a[j];
                if(t<ts.last())
                {
                    ts.remove(ts.ceiling(t));
                    //  cm--;
                }
                else {

                    ts.remove(ts.first());
                    cp++;
                }

            }

            Arrays.sort(a);
            Arrays.sort(b);

            int ai=0,bi=0,aj=0,bj=0;
            for (int j = 0; j < n; j++) {
                if(a[ai]>b[bi])
                {
                    cm++;
                    ai++;
                    bi++;
                }
                else {
                    ai++;
                    bj--;
                }
            }

           // out.println(cp+"**"+cm);


           // System.out.println(Arrays.toString(a));
           // System.out.println(Arrays.toString(b));
            out.println("Case #" + (i + 1) + ": " + cm +" "+cp );
            // System.out.println("Case #" + (i + 1) + ": " + i );
        }


        out.close();

    }//Main -end



}



// for Fast IO

class Reader {
    private BufferedReader input;
    private StringTokenizer line = new StringTokenizer("");

    public Reader() {
        input = new BufferedReader(new InputStreamReader(System.in));
    }

    public Reader(String s) {
        try {
            input = new BufferedReader(new FileReader(s));
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void fill() {
        try {
            if(!line.hasMoreTokens()) line = new StringTokenizer(input.readLine());
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public double nextDouble() {
        fill();
        return Double.parseDouble(line.nextToken());
    }

    public String nextWord() {
        fill();
        return line.nextToken();
    }

    public int nextInt() {
        fill();
        return Integer.parseInt(line.nextToken());
    }

    public long nextLong() {
        fill();
        return Long.parseLong(line.nextToken());
    }

    public double readDouble() {
        double d = 0;
        try {
            d = Double.parseDouble(input.readLine());
        } catch(IOException io) {io.printStackTrace(); System.exit(0);}
        return d;
    }

    public int readInt() {
        int i = 0;
        try {
            i = Integer.parseInt(input.readLine());
        } catch(IOException io) {io.printStackTrace(); System.exit(0);}
        return i;
    }

    public int[] readInts(int n) {
        int[] a = new int[n];
        for(int i=0; i<n; i++)
            a[i] = nextInt();
        return a;
    }

    public void fillInts(int[] a) {
        for(int i=0; i<a.length; i++)
            a[i] = nextInt();
    }

    public long readLong() {
        long l = 0;
        try {
            l = Long.parseLong(input.readLine());
        } catch(IOException io) {io.printStackTrace(); System.exit(0);}
        return l;
    }

    public String readLine() {
        String s = "";
        try {
            s = input.readLine();
        } catch(IOException io) {io.printStackTrace(); System.exit(0);}
        return s;
    }
}

class Writer {

    private BufferedWriter output;

    public Writer() {
        output = new BufferedWriter(new OutputStreamWriter(System.out));
    }

    public Writer(String s) {
        try {
            output = new BufferedWriter(new FileWriter(s));
        } catch(Exception ex) { ex.printStackTrace(); System.exit(0);}
    }

    public void println() {
        try {
            output.append("\n");
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void print(Object o) {
        try {
            output.append(o.toString());
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void println(Object o) {
        try {
            output.append(o.toString()+"\n");
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void printf(String format, Object... args) {
        try {
            output.append(String.format(format, args));
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void printfln(String format, Object... args) {
        try {
            output.append(String.format(format, args)+"\n");
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void flush() {
        try {
            output.flush();
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void close() {
        try {
            output.close();
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }
}