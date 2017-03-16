package gcj2013.qualification;
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class FairAndSquare {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

    public FairAndSquare() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
    }

    int[] readInts() throws IOException {
        String[] strings = reader.readLine().split(" ");
        int[] ints = new int[strings.length];
        for(int i = 0; i < ints.length; i++) {
            ints[i] = Integer.parseInt(strings[i]);
        }
        return ints;
    }

    int[] tt = null;
    int tx = 0;
    int readInt() throws IOException {
        if(tt == null || tx >= tt.length) {
            tt = readInts();
            tx = 0;
        }
        return tt[tx++];
    }

    long[] readLongs() throws IOException {
        String[] strings = reader.readLine().split(" ");
        long[] ints = new long[strings.length];
        for(int i = 0; i < ints.length; i++) {
            ints[i] = Long.parseLong(strings[i]);
        }
        return ints;
    }

    long[] ttl = null;
    int txl = 0;
    long readLong() throws IOException {
        if(ttl == null || txl >= ttl.length) {
            ttl = readLongs();
            txl = 0;
        }
        return ttl[txl++];
    }


    void solve(int test) throws IOException {
        writer.printf("Case #%d: ", test);
        long a = readLong();
        long b = readLong();
        int ans = 0;
        for(long c : numbers) {
            if(c >= a && c <= b) {
                ans++;
            }
        }
        writer.println(ans);
        writer.flush();
    }

    boolean isPalindrome(long x) {
        String s = Long.toString(x);
        for(int i = 0; i < s.length() / 2; i++) {
            if(s.charAt(i) != s.charAt(s.length() - 1 - i)) return false;
        }
        return true;
    }

    List<Long> numbers = new ArrayList<Long>();

    void preSolve() {
        for(long i = 1; i <= 10 * 1000 * 1000; i++) {
            if(isPalindrome(i) && isPalindrome(i * i)) {
                numbers.add(i * i);
            }
        }
    }

    void multiSolve() throws IOException {
        preSolve();
        int n = readInts()[0];
        for(int i = 0; i < n; i++) {
            solve(i + 1);
        }
    }

    public static void main(String[] args) throws IOException{
        new FairAndSquare().multiSolve();
    }
}
