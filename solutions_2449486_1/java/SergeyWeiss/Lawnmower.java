package gcj2013.qualification;
import java.io.*;

public class Lawnmower {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

    public Lawnmower() throws IOException {
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

    void solve(int test) throws IOException {
        writer.printf("Case #%d: ", test);
        int R = readInt();
        int C = readInt();
        int[][] A = new int[R][];
        for(int r = 0; r < R; r++) {
            A[r] = readInts();
        }
        int[] mr = new int[R], mc = new int[C];
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                mr[r] = Math.max(mr[r], A[r][c]);
                mc[c] = Math.max(mc[c], A[r][c]);
            }
        }
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                if(mr[r] > A[r][c] && mc[c] > A[r][c]) {
                    writer.println("NO");
                    writer.flush();
                    return;
                }
            }
        }
        writer.println("YES");
        writer.flush();
    }

    void multiSolve() throws IOException {
        int n = readInts()[0];
        for(int i = 0; i < n; i++) {
            solve(i + 1);
        }
    }

    public static void main(String[] args) throws IOException{
        new Lawnmower().multiSolve();
    }
}
