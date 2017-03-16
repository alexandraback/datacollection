package googlecodejam;

/**
 *
 * @author ffreakk
 */

import java.util.Scanner;
import java.lang.Math;
import java.lang.Object;
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException{
        Scanner in = new Scanner(new File("input.txt"));
        PrintStream out = new PrintStream(new File("output.txt"));
        //Scanner in = new Scanner(System.in);
        //PrintStream out = new PrintStream(System.out);
        int T = in.nextInt();

        for (int t=0; t<T; t++) {
            double D = in.nextDouble();
            int N = in.nextInt();
            int A = in.nextInt();

            double time[] = new double[N+1];
            double distance[] = new double[N+1];
            time[0] = 0;
            distance[0] = D;
            for (int n=1; n<=N; n++) {
                time[n] = in.nextDouble();
                distance[n] = in.nextDouble();
            }

            double accel[] = new double[A];
            for (int a=0; a<A; a++) {
                accel[a] = in.nextDouble();
            }

            int counter = 0;
            double result[] = new double[A];
            for (int a=0; a<A; a++) {
                result[a] = 0;
            }

            while (counter < time.length) {
                double iTime = time[counter];
                double iDistance = distance[counter];
                if (iDistance > D) {
                    iTime = time[counter-1] + (time[counter]-time[counter-1])*(D - distance[counter-1])/(distance[counter] - distance[counter-1]);
                    iDistance = D;
                }
                for (int a=0; a<accel.length; a++) {
                    double totalTravelTime = Math.sqrt(2*D/accel[a]);
                    double wait;
                    double distTime = Math.sqrt(2*iDistance/accel[a]);
                    if (distTime > iTime) wait=0;
                    else wait = (iTime - distTime);
                    double res = wait + totalTravelTime;
                    if (res>result[a]) result[a] = res;
                }
                counter++;
            }

            System.out.println("Case #" +(t+1)+":");
            for (int a=0; a<result.length; a++)
                System.out.println(result[a]);

        }
    }

}
