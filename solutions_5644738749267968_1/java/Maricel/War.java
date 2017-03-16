package D;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class War {

    Scanner in;
    BufferedWriter out;

    War(String input, String output) throws Exception {
        in = new Scanner(new File(input));
        FileWriter fstream = new FileWriter(output);
        out = new BufferedWriter(fstream);
    }

    public static void main(String[] args) throws Exception {
        War war = new War("src/D/in.txt", "src/D/out.txt");
        war.solve();
        System.out.println("finished");
        war.close();
    }

    public void solve() throws IOException {
        int T = in.nextInt();

        for (int t = 1; t <= T; t++) {
            out.flush();
            int n = in.nextInt();
            Double[] a = readDoubleArray(n);
            Double[] b = readDoubleArray(n);

            Arrays.sort(a);
            Arrays.sort(b);
            
            Queue<Double> qA = new LinkedList<>();
            qA.addAll(Arrays.asList(a));
            
            Deque<Double> dqB = new LinkedList<>();
            dqB.addAll(Arrays.asList(b));
            
            // deceitful war points
            int deceitfulWar = 0;
            for (int step = 0; step < n; step++) {
                if (qA.peek() > dqB.peekFirst()) {
                    deceitfulWar++;
                    dqB.pollFirst();
                } else {
                    dqB.pollLast();
                }
                qA.poll();
            }
            
            // war points
            int i = 0, j = 0;
            while(i < n && j < n) {
                if (a[i] < b[j]) {
                    i++; j++;
                } else {
                    j++;
                }
            }
            
            printSol(t, deceitfulWar, n-i);
        }
    }
    
    private Double[] readDoubleArray(int n) {
        Double[] a = new Double[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextDouble();
        }
        return a;
    }

    private void print(String s) throws IOException {
        out.write(s);
    }

    private void printSol(int test, int a, int b) throws IOException {        
        print("Case #" + test + ": " + a + " " + b + "\n");
    }

    private void close() throws IOException {
        this.in.close();
        this.out.close();
    }
}