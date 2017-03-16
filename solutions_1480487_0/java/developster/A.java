package codejam.y2012.r1b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
    
    private Scanner scanner;
    private PrintWriter printWriter;
    
    int n;
    int s[];
    
    private void solve() {
        int t = 0;
        for (int i = 0; i < n; i++) {
            t+=s[i];
        }
        System.out.println("case...");
        double r[] = new double[n];
        double neg=0;
        int nc=0;
        for (int i = 0; i < n; i++) {
            
//            int mins = 101;
//            for (int j = 0; j < n; j++) {
//                if (i!=j) mins = Math.min(mins, s[j]);
//            }
            
            double p = 2.0*t/n;
//            double p = (t+s[i]+mins)/2.0;
            r[i] = (p-s[i])/t;
            r[i] *= 100;
//            r = Math.max(r, 0.0);
            if (r[i] < 0) { neg+=r[i]; nc++; }
        }
        if (nc > 0) {
            for (int i = 0; i < n; i++) {
                if (r[i] < 0) r[i]=0; else r[i]+=neg/(n-nc);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i>0) print(" ");
            System.out.println(" t=" + t + " p=" + (s[i] + t*r[i]/100));
            print(Double.toString(r[i]));
        }
    }
    
    void run(String inFile, String outFile) throws FileNotFoundException {
        scanner = new Scanner(new File(inFile));
        printWriter = new PrintWriter(new File(outFile));
        int cases = scanner.nextInt();
        for (int ci = 0; ci < cases; ci++) {
            n=readInt();
            s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = readInt();
            }
            print("Case #" + (ci+1) + ": ");
            solve();
            println();
        }
        printWriter.close();
        scanner.close();
    }
    
    Integer readInt() { return scanner.nextInt(); }
    Long readLong() { return scanner.nextLong(); }
    Double readDouble() { return scanner.nextDouble(); }
    String read() { return scanner.next(); }
    String readLine() { return scanner.nextLine(); }
    void print(String s) { printWriter.print(s); }
    void println() { printWriter.println(); }
    
    public static void main(String[] args) throws IOException {
//        String inFile = "/Users/octavian/Documents/workspace/codejam/2012/r2a/a.in";
//        String outFile = "/Users/octavian/Documents/workspace/codejam/2012/r2a/a.out";
        String inFile = "/Users/octavian/Documents/workspace/codejam/2012/r2a/A-small-attempt4.in.txt";
        String outFile = "/Users/octavian/Documents/workspace/codejam/2012/r2a/A-small-attempt4.out.txt";
        new A().run(inFile, outFile);
    }
}
