package round1;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {
    static int T;
    static int[] results;
    static int A;
    static int[] mote;

    public static void main(String[] args) throws IOException {
        read();
        process();
        write();
    }

    static void read() throws IOException {
        File input = new File("input.txt");
        Scanner scanner = new Scanner(input);
        T = scanner.nextInt();
        results = new int[T];
        for (int t=0; t<T; t++) {
            A = scanner.nextInt();
            int motes = scanner.nextInt();
            mote = new int[motes];
            for (int i=0; i<motes; i++) {
                mote[i] = scanner.nextInt();
            }
            Arrays.sort(mote);
            results[t] = process();
        }
    }

    static int process() {
        int steps = 0;
        int[] step = new int[mote.length+1];
        step[0] = 0;
        int index = 0;
        while (index < mote.length) {
            int nextMote = mote[index];
            if (nextMote < A) {
                A += nextMote;
                index++;
                step[index] = steps;                
            } else {
                if (A == 1) {
                    return mote.length;
                }
                A += A-1;
                steps++;
            }
        }
        int result = steps;
        for (int i=1; i<=step.length; i++) {
            result = Math.min(result, step[i-1]+(mote.length-i+1));
        }
        return result;
    }

    static void write() throws IOException {
        File output = new File("output.txt");
        PrintWriter pw = new PrintWriter(output);

        for (int t=0; t<T; t++) {
            pw.println("Case #"+(t+1)+": "+results[t]);
        }

        pw.close();
    }

}
