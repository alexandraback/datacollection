/*
Original template used was test.java from USACO's training pages.

Name: Ante Qu
Problem: Out of Gas (small input)
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

public class outOfGas
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
            out.println("Case #" + (i + 1) + ": " + solve(f)); // output
                                                                          // result
        }
        out.close(); // close the output file
        // System.exit(0); // don't omit this!
    }
    private static String solve(BufferedReader f) throws IOException
    {
        StringTokenizer st = new StringTokenizer(f.readLine());
        double D = Double.parseDouble(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int A = Integer.parseInt(st.nextToken());
        double[] t = new double[N];
        double[] x = new double[N];
        for (int i = 0; i < N; i++)
        {
            st = new StringTokenizer(f.readLine());
            t[i] = Double.parseDouble(st.nextToken());
            x[i] = Double.parseDouble(st.nextToken());
            if (x[i] > D)
            {
                double tminus = 0; double xminus = 0;
                if (i == 0) { tminus = 0; xminus = 0; }
                else { tminus = t[i - 1]; xminus = x[i - 1];}
                t[i] = tminus + (D - xminus) * (t[i] - tminus) / (x[i] - xminus);
                x[i] = D;
            }
        }
        double results[] = new double[A];
        st = new StringTokenizer(f.readLine());
        StringBuilder toReturn = new StringBuilder();
        for (int r = 0; r < A; r++)
        {
            double a = Double.parseDouble(st.nextToken());
            
            // store velocities
            double[] v = new double[N];
            v[0] = x[0] / t[0];
            for (int i = 1; i < N; i++)
            {
                v[i] = (x[i] - x[i-1]) / (t[i] - t[i-1]);
                
            }
            double[] reachable = new double[N];
            int reach = 0;
            // check if each max is reachable
            // at t[i] , and between t[i] and t[i + 1]
           /* for (int i = N - 2; i > -1; i--)
            {
                double ti = t[i];
                if (t[i] < D)
                {
                    // calculate t[i] times
                    double distances[] = new double[i + 1];
                    boolean broken = false;
                    distances[i] = x[i];
                    for (int j = i - 1; j > -1; j--)
                    {
                        // velocity going back to t[j]
                        double vbefore = v[j+2] - (t[j+ 1] - t[j]) * a;
                        // average velocity between t[j1] and t[j]
                        double AvgV = 0.5 * (v[j + 2] + vbefore);
                        // distance at t[j]
                        distances[j] = distances[j + 1] - (t[j + 1] - t[j ]) * AvgV;
                        if (distances[j] < x[j])
                        {
                            broken = true;
                            break;
                        }
                    }
                    double AvgV = 0.5 * v[2];
                    
                    if (broken)
                    {
                        ti = t[i + 1];
                        // calculate t[i + 1] times
                    }
                    else
                        reachable[i] = t[i];
                        
                }
            }*/
            // check if second one is reachable
            int reachy = -1;
            // check if accelerating from start works
            if (N == 2)
                    {
                
            if (0.5 * a * t[1] * t[1] > x[1])
                 reachy = 1;
                
                    }
            
            
            double result = 0;
            if (reachy == 1)
            {
                double time1 = Math.sqrt(2 * x[0] / a);
                double timeshift1 = t[0] - time1;
                double other = t[1];
                double thistime = timeshift1 + Math.sqrt(2 * D / a);
                if (other > thistime) result = other; else result = thistime;
            }
            else
            {
                
                double thistime = Math.sqrt(2 * D / a);
                double other = 0;
                if (N == 2) other = t[1];
                if (other > thistime) result = other; else result = thistime;
            }
            /*if (reachy == -1)
            {
                result = Math.sqrt(2 * D / a);
            }
            /*else if (reachy == 0)
            {
               
                // accelerate to x[0]
                double time1 = Math.sqrt(2 * x[0] / a);
                double timeshift = t[0] - time1;
                if (N == 2)
                {
                    double vel = v[1];
                    double time2 = t[1] - t[0];
                    double vel2 = (time1 + time2) * a;
                    if (vel2 > vel)
                    {
                        // this is the speed it can accelerate to
                        // if it slows down a bit first
                        double canaccelerateto = vel + time2 * a / 2;
                        double dist = D - x[1];
                        double addtime = -canaccelerateto + Math.sqrt(canaccelerateto * canaccelerateto + 2 * dist * a);
                        addtime = addtime / a;
                        result = t[1] + addtime;
                    }
                    else
                        result = Math.sqrt(2 * D / a) + timeshift;
                }
                else
                // check when we have to accelerate to v2
                result = Math.sqrt(2 * D / a) + timeshift;
            }
            else
            {
                // accelerate to x[1]
                double time0 = Math.sqrt(2 * x[1] / a);
                double timeshift = t[1] - time0;
                double time1 = Math.sqrt(2 * x[0] / a);
                double timeshift1 = t[0] - time1;
                if (timeshift1 > timeshift) timeshift = timeshift1;
                if (N == 2)
                {
                    double vel = v[1];
                    double time2 = t[1] - t[0];
                    double vel2 = (time1 + time2) * a;
                    if (vel2 > vel)
                    {
                        // this is the speed it can accelerate to
                        // if it slows down a bit first
                        double canaccelerateto = vel + time2 * a / 2;
                        double dist = D - x[1];
                        double addtime = -canaccelerateto + Math.sqrt(canaccelerateto * canaccelerateto + 2 * dist * a);
                        addtime = addtime / a;
                        result = t[1] + addtime;
                    }
                    else
                        result = Math.sqrt(2 * D / a) + timeshift;
                }
                result = Math.sqrt(2 * D / a) + timeshift;
            }*/
            results[r] = result;
            // accelerate to the last reachable max
            toReturn.append("\n" + result);
        }
        return toReturn.toString();
    }
}
