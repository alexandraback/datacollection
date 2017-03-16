package A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

class PartElf {

    Scanner in;
    BufferedWriter out;

    PartElf(String input, String output) throws Exception {
        in = new Scanner(new File(input));
        FileWriter fstream = new FileWriter(output);
        out = new BufferedWriter(fstream);
    }

    public static void main(String[] args) throws Exception {
        PartElf partElf = new PartElf("src/A/in.txt", "src/A/out.txt");
        partElf.solve();
        System.out.println("finished");
        partElf.close();
    }
    long n, m;    
    
    public void solve() throws IOException {
        int T = in.nextInt();

        for (int t = 1; t <= T; t++) {
            out.flush();
            System.out.println("running test " + t);
            String s = in.next();
            String[] a = s.split("/");
            n = Long.parseLong(a[0]);
            m = Long.parseLong(a[1]);
            
            long c = gcd(n, m);
            n /= c;
            m /= c;
            
            if (isPow2(m)) {
                long p2 = greatestPow2(n);
                m /= p2;
                printSol(t, getPow2(m));
            } else {
                printImpossible(t);
            }            

        }
    }
    
    public long greatestPow2(long n) {
        long newN;
        while (true) {
            newN = n & (n - 1);
            if (newN == 0) {
                return n;
            }
            n = newN;
        }
    }

    public long gcd(long a, long b) {
        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }
        if (a > b) {
            return gcd(b, a % b);
        }
        return gcd(a, b % a);
    }

    public boolean isPow2(long m) {
        return ((m & (m - 1)) == 0);
    }
    
    public int getPow2(long m) {
        int k = 0;
        while (m != 0) {
            k++;
            m >>= 1;
        }
        return k - 1;
    }

    private void print(String s) throws IOException {
        out.write(s);
    }

    private void printSol(int test, long pow) throws IOException {        
        print("Case #" + test + ": " + pow + "\n");
    }
    
    private void printImpossible(int test) throws IOException {        
        print("Case #" + test + ": impossible\n");
    }

    private void close() throws IOException {
        this.in.close();
        this.out.close();
    }
}