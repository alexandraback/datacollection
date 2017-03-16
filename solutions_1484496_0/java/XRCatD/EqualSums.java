/*
Original template used was test.java from USACO's training pages.

Name: Ante Qu
Problem: Equal Sums (small input)
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

public class EqualSums
{
    public static void main(String[] args) throws IOException
    {

        // Use BufferedReader rather than RandomAccessFile; it's much faster
        BufferedReader f = new BufferedReader(new FileReader("in.in.txt"));
        // input file name goes above
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
                "out.txt")));
        // Use StringTokenizer vs. readLine/split -- lots faster
        // StringTokenizer st = new StringTokenizer("  K   K 1 K  1 ");

        int T = Integer.parseInt(f.readLine());
        for (int i = 0; i < T; i++)
        {
            out.println("Case #" + (i + 1) + ": " + solve(f.readLine())); // output
                                                                          // result
        }
        out.close(); // close the output file
        // System.exit(0); // don't omit this!
    }
    private static String solve(String input)
    {
        StringTokenizer st = new StringTokenizer(input);
        int N = Integer.parseInt(st.nextToken());
        int[] ints = new int[N];
        for (int i = 0; i < N; i++)
        {
            ints[i] = Integer.parseInt(st.nextToken());
        }
        LinearProbingHashST<Integer, Integer> sums = new LinearProbingHashST<Integer, Integer>();
        
        int[] powers = new int[N + 1];
        for (int j = 0; j < N + 1; j++)
            powers[j] = (int) Math.pow(2,j);
        for (int i = 0; i < powers[N]; i++)
        {
            if (i % 100000 == 0) System.out.println(i);
            int sum = 0;
            for (int j = 0; j < N; j++)
                if (((i / powers[j]) % 2) == 1) sum += ints[j];
            if (sums.contains(sum))
            {
                int k = sums.get(sum);
               

                System.out.println(sum);
                        StringBuilder stt = new StringBuilder();
                        stt.append("\n");
                        for (int j = 0; j < N; j++)
                            if (((i / powers[j]) % 2) == 1) stt.append(ints[j] + " ");
                        stt.append("\n");
                        
                        for (int j = 0; j < N; j++)
                            if (((k / powers[j]) % 2) == 1) stt.append(ints[j] + " ");
                        return stt.toString();
                
            }
            else
                sums.put(sum, i);
        }
        return "\nImpossible";
    }
}
