/*
Original template used was test.java from USACO's training pages.

Name: Ante Qu
Problem: Safety In Numbers
Gmail Account: quante0

 * dependencies: algs4.jar, stdlib.jar
 * can be dled at:
 * http://algs4.cs.princeton.edu/code/algs4.jar
 * http://introcs.cs.princeton.edu/java/stdlib/stdlib.jar

*/
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;


public class safetyInNumbers
{
    public static void main (String [] args) throws IOException {

        
        // Use BufferedReader rather than RandomAccessFile; it's much faster
      BufferedReader f = new BufferedReader(new FileReader("in.in.txt"));
                                                    // input file name goes above
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
      // Use StringTokenizer vs. readLine/split -- lots faster
      //StringTokenizer st = new StringTokenizer("  K   K 1 K  1 ");

      int T=Integer.parseInt(f.readLine());
      for(int i=0;i<T;i++)
      {
        out.println("Case #" + (i+1) + ": " + solve(f.readLine()));                           // output result
      }
      out.close();                                  // close the output file
     // System.exit(0);                               // don't omit this!
    }
    // solve
    private static String solve(String input)
    {
        StringTokenizer st = new StringTokenizer(input);
        // input
        // N
        int N = Integer.parseInt(st.nextToken());
        // i, J_i
        int[][] s = new int[N][2];
        // X
        int X = 0;
        for (int i = 0; i < N; i++ )
        {
            s[i] = new int[] {i, Integer.parseInt(st.nextToken())};
            X += s[i][1];
        }
        Comparator<int[]> order2 = new Comparator<int[]>() {
            public int compare(int[] a, int[] b)
            {
                return a[1] - b[1];
            }
        };
        Comparator<int[]> order1 = new Comparator<int[]>() {
            public int compare(int[] a, int[] b)
            {
                return a[0] - b[0];
            }
        };
        Arrays.sort(s, order2);
        double[] xs = new double[N];
        boolean broken = false;
        // check from smallest to largest
        for (int i = 0; i < N - 1; i++)
        {
            //distribute total available from 0 to i
            int available = X;
            for (int j = 0; j <= i; j++)
            {
                available += s[j][1];
                //if (N == 9) System.out.print(s[i][1] + " ");
            }
           // System.out.println();
            // check if i + 1 is too big
            if (1.0 * available / (i + 1) < s[i + 1][1] )
            {
                // mark the undistributable amount
                // distribute the xs's accordingly
                for (int j = 0; j <= i; j++)
                {
                    double average = 1.0 * available / (i + 1);
                    xs[s[j][0]] = average - s[j][1];
                }
               
                broken = true;
                //System.out.println(s[0][1] + " " + s[1][1] + " " + s[2][1] + " " + s[3][1] +" " + s[4][1]);
                //System.out.println(N + " " + i + " " + available + " " + X + " " + xs[s[0][0]] + " "+xs[s[i][0]]); ;
                break;
            }
        }
        if (!broken)
        {
            for (int i = 0; i < N; i++)
            {
                xs[s[i][0]] = (2.0 * X - N * s[i][1]) / N;
            }
        }
        
        StringBuilder toReturn = new StringBuilder();
        // build results
        // Y_i = (2 X - N J_i ) / (N X)
        toReturn.append(100.0 * xs[0] / X);
        for (int i = 1; i < N; i++)
            toReturn.append(" " + 100.0 * xs[i] / X);
        return toReturn.toString();
        /*
        toReturn.append( max(100.0 * (2.0 * X - N * s[0]) / (N * X), 0));
        for (int i = 1; i < N; i++)
            toReturn.append(" " + max(100.0 * (2.0 * X - N * s[i]) / (N * X), 0));
        return toReturn.toString();*/
        
    }
    private static double max(double a, double b)
    {
        if (a > b) return a; else return b;
    }
    
}
