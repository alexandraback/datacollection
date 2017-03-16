package codejam.y2012.r1b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
    
    private Scanner scanner;
    private PrintWriter printWriter;
    
    int n;
    int s[];
    
    int b[];
    int p[];
    
    private void solve() {
        System.out.println(n);
        Arrays.sort(s);
        int max = (n*5)*10000+1;
        b = new int[max];
        p = new int[max];
        for (int j = 0; j < max; j++) {b[j]=-1; p[j]=-1;}
        for (int i = 0; i < n; i++) {
            p[s[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < max; j++) {
                if (j != s[i] && p[j] >= 0 && s[p[j]] < s[i]) {
                    
                    if (p[j+s[i]] >= 0) {
                        print(j+s[i]);
                        p[j+s[i]] = i;
                        b[j+s[i]] = j;
                        print(j+s[i]);
                        return;
                    }
                    
                    p[j+s[i]] = i;
                    b[j+s[i]] = j;
                }
            }
        }
        print("Impossible");
    }
    
    private void print(int i) {
        print(""+s[p[i]]);
        int k = b[i];
        while (k >= 0) {
            print(" "+s[p[k]]);
            if (k == b[k]) {
                break;
            }
            k = b[k];
        };
        println();
        printWriter.flush();
    }
    
    void run(String inFile, String outFile) throws FileNotFoundException {
        scanner = new Scanner(new File(inFile));
        printWriter = new PrintWriter(new File(outFile));
        int cases = scanner.nextInt();
        for (int ci = 0; ci < cases; ci++) {
            n = readInt();
            s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = readInt();
            }
            print("Case #" + (ci+1) + ": ");
            println();
            solve();
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
        String inFile = "/Users/octavian/Documents/workspace/codejam/2012/r2a/C-small-attempt0.in.txt";
        String outFile = "/Users/octavian/Documents/workspace/codejam/2012/r2a/C-small-attempt0.out.txt";
        new C().run(inFile, outFile);
    }
}
