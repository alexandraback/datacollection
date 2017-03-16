package D;

import java.io.*;
import java.util.*;

public class D {


    public static void main(String[] args) {

     //   Reader in = new Reader();
     //   Writer out = new Writer();



        //Reader in = new Reader("csmall.in");
        //Writer out = new Writer("csmalloutput.out");

        Reader in = new Reader("clarge.in");
        Writer out = new Writer("clargeoutput.out");



        int T = in.nextInt();


        for (int i = 0; i < T; i++) {

            int r = in.nextInt();
            int c = in.nextInt();
            int es = in.nextInt();
            char ms[][] = new char[r+1][c+1];

            for (int j = 0; j < r + 1; j++) {
                Arrays.fill(ms[j],'.');
            }

            boolean flag = fillMineSweep(ms,r,c,es);

            out.println("Case #" + (i + 1) + ": ");

            if(flag)
            {
                printMS(ms,out);
            }
            else {
                out.println("Impossible");
            }
            // System.out.println("Case #" + (i + 1) + ": " + i );
        }


        out.close();

    }//Main -end

    public static void printMS(char[][] a,Writer out)
    {
        for (int i = 1; i < a.length; i++) {

            for (int j = 1; j < a[0].length; j++) {
                out.print((a[i][j]=='l')?'.':a[i][j]);
            }
            out.println();
        }
    }


    public static boolean fillMineSweep(char[][] ms,int r,int c,int es){

      //  printMS(ms,out);
       // trival case

/*
        {

            int res = 2 * r + 2 * c - 4;

            if (res <= es) {
                for (int i = x1; i <= x2; i++) {
                    ms[i][y1] = '*';
                    ms[i][y2] = '*';
                }

                for (int i = y1; i <= y2; i++) {
                    ms[x1][i] = '*';
                    ms[x2][i] = '*';
                }

                return fillMineSweep(ms, x1 - 1, y1 - 1, x2 - 1, y2 - 1, es - res);
            }
        }

*/
     //   if(r*c<)

        int min = r>c?c:r;

        if(min<=es)
        {

            if(r<c)
            {
                for (int i = 1; i <= r; i++) {
                    ms[i][c] ='*';
                    ms[i][c-1]='l';
                }

                return fillMineSweep(ms,r,c-1,es-r);


            }else
            {
                for (int i = 1; i <= c; i++) {
                    ms[r][i] ='*';
                    ms[r-1][i]='l';
                }
                return fillMineSweep(ms,r-1,c,es-c);

            }

        }else {
            return fillBaseMS(ms,r,c,es);
        }


    }

public static boolean fillBaseMS(char[][] ms,int r,int c,int es){

   // printMS(ms,out);

    boolean result = false;


    if(es==0)
    {
    if(r==1 && c==1) {
        ms[1][1]='c'; return true;
    } else if(ms[1][1]!='.')
        {return false;}

        for (int i = 1; i <=r ; i++) {

            for (int j = 1; j <=c; j++) {

                ms[i][j] = '.';
            }
        }

        ms[1][1] = 'c';

        return true;
    }


    if(r==2 && c==2) return false;

    if(r==2 && c==3) return false;

    if((r==2 || c==2) && es%2==1) return false;

    if(r==3 && c==3)
    {
        if(es==2) return false;
        else
        {

            for (int i = 1; i <=r ; i++) {

                for (int j = 1; j <=c; j++) {
                    ms[i][j] = '.';
                }
            }

            ms[1][1] = 'c';
            ms[r][c] = '*';
            return true;
        }
    }

    if(es==1) {
        ms[1][1] = 'c';
        ms[r][c] = '*';
        return true;
    }

    if(r+c-5<es)  return false;

    if(r>c) {
        ms[1][1] = 'c';
        int cout = es;
        if(c!=3){
            ms[r][c - 1] = '*';
            cout--;
        }
        for (int i = r; i > 2 && cout != 0; i--) {
            ms[i][c] = '*';
            cout--;
        }

        return true;
    }
    else {

        ms[1][1] ='c';
        int cout = es;
        if(r!=3) {
            ms[r - 1][c] = '*';
            cout--;
        }
        for (int i = c; i > 2 && cout != 0; i--) {
            ms[r][i] = '*';
            cout--;
        }

        return true;
    }

}

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