package round1;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class SafetyInNumbers {
    static int T;
    static int N;
    static int[] points;
    static double[] results;
    static int sum;

    public static void main(String[] args) throws IOException {
        read();
    }

    static PrintWriter pw;
    static void read() throws IOException {
        File output = new File("output.txt");
        pw = new PrintWriter(output);
        File input = new File("input.txt");
        Scanner scanner = new Scanner(input);
        T = scanner.nextInt();
        for (int t=0; t<T; t++) {
            sum = 0;
            N = scanner.nextInt();
            points = new int[N];
            results = new double[N];
            for (int n=0; n<N; n++) {
                points[n] = scanner.nextInt();
                sum += points[n];
            }
            process(t);
        }
        pw.close();
    }

    static void process(int t) throws IOException {
        int[] temp = new int[N+1];
        System.arraycopy(points, 0, temp, 0, N);
        temp[N] = 2*sum;
        Arrays.sort(temp);
        double value = 0;
        double limit = 0;
        for (int k=0; k<N; k++) {
            double step = (k+1)*(temp[k+1]-temp[k])/((double)sum);
            if (step+value > 1) {
                limit = temp[k]+(1-value)*((double)sum)/(k+1);
                break;
            } else {
                value += step;
            }
        }
        for (int n=0; n<N; n++) {
            results[n] = (limit-points[n])/((double)sum);
            if (results[n]<0) {
                results[n]=0;
            }
        }
        write(t);
    }

    static void write(int t) throws IOException {

        pw.print("Case #"+(t+1)+": ");
        for (int n=0; n<N; n++) {
            pw.print((100*results[n])+" ");
        }
        pw.println();
    }

}
