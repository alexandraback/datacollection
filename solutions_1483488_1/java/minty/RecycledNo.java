
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class RecycledNo {

    Scanner in;
    BufferedWriter out;

    RecycledNo(String input, String output) throws Exception {
        in = new Scanner(new File(input));
        FileWriter fstream = new FileWriter(output);
        out = new BufferedWriter(fstream);
    }

    private void solveAll() throws IOException {
        int T = in.nextInt();
        int A, B;

        for (int test = 1; test <= T; test++) {
            A = in.nextInt();
            B = in.nextInt();
            out.write("Case #" + test + ": " + solve(A, B));
            out.newLine();
        }

    }

    private int solve(int A, int B) {
        int count = 0, dig, pow10, lastPart, firstPart, exp10, newNo;
        int noDig = 1 + (int) Math.log10(A);
        Set<Integer> set = new HashSet<Integer>();

        for (int n = A; n < B; n++) {
            set.clear();
            pow10 = 1;
            lastPart = 0;
            firstPart = n;
            exp10 = (int) Math.pow(10, noDig - 1);
            
            for (dig = 1; dig < noDig; dig++) {
                lastPart = (firstPart % 10) * pow10 + lastPart;
                firstPart = firstPart / 10;
                pow10 *= 10;

                newNo = lastPart * exp10 + firstPart;
                exp10 /= 10;
                if ((int) Math.log10(newNo) != noDig - 1) {
                    continue;
                }

                if (newNo > n && newNo <= B &&
                        !set.contains(newNo)) {
                    set.add(newNo);
                    count++;
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
        RecycledNo pb = new RecycledNo("input.txt", "output.txt");

        pb.solveAll();

        pb.close();
    }
}
