
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Dance {

    Scanner in;
    BufferedWriter out;

    Dance(String input, String output) throws Exception {
        in = new Scanner(new File(input));
        FileWriter fstream = new FileWriter(output);
        out = new BufferedWriter(fstream);
    }
    
    public void solveAll() throws IOException {
        int T = in.nextInt();
        int N, S, P;

        for (int test = 1; test <= T; test++) {
            N = in.nextInt();
            S = in.nextInt();
            P = in.nextInt();
            int[] t = new int[N];
            for(int i = 0; i < N; i++) {
                t[i] = in.nextInt();
            }
            out.write("Case #" + test + ": " + solve(N, S, P, t));
            out.newLine();
        }

    }

    public int solve(int N, int S, int P, int[] t) {
        int count = 0;
        for(int i = 0; i < N; i++) {
            if(t[i] % 3 == 0) {
                if(t[i]/3 >= P) {
                    count++;
                } else {
                    if(S > 0 && t[i] != 0 && t[i]/3 + 1 >= P) {
                        count++;
                        S--;
                    }
                }
            } else if(t[i] % 3 == 1) {
                if(t[i]/3 + 1 >= P) {
                    count ++;
                }
            } else {
                if(t[i]/3 + 1 >= P) {
                    count++;
                } else {
                    if(S > 0 && t[i]/3 + 2 >= P) {
                        count++;
                        S--;
                    }
                }
            }
        }
        return count;
    }

    
    public void close() throws IOException {
        in.close();
        out.close();
    }

    public static void main(String[] args) throws Exception {
        Dance pb = new Dance("input.txt", "output.txt");

        pb.solveAll();

        pb.close();
    }
}
