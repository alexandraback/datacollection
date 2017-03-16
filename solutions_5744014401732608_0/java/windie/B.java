import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by linxy on 4/29/16.
 */
public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new FileOutputStream("B-small-attempt0.out"));
        int numCase = in.nextInt();
        in.nextLine();
        for (int caseNum = 1; caseNum <= numCase; caseNum++) {
            out.print("Case #" + caseNum + ": ");
            String line = in.nextLine();
            String[] splits = line.split(" ");
            int b = Integer.parseInt(splits[0]);
            long m = Long.parseLong(splits[1]);
            int[][] answer = new int[b][b];
            answer[0][b - 1] = 1;
            for (int i = 0; i < b - 1; i++) {
                answer[i][b - 1] = 1;
            }
            long path = 1;
            if (path != m) {
                outer:
                for (int i = 0; i <= b - 2; i++) {
                    for (int j = i + 1; j <= b - 2; j++) {
                        answer[i][j] = 1;
                        if (i == 0 || i == 1) {
                            path += 1;
                        } else {
                            path += (1L << (i - 2));
                        }
                        if (path >= m) {
                            break outer;
                        }
                    }
                }
            }
            if (path < m) {
                out.println("IMPOSSIBLE");
                continue;
            } else {
                out.println("POSSIBLE");
            }
            if (path > m) {
                long diff = path - m;
                for (int i = 0; i < 64; i++) {
                    if ((diff & (1L << i)) > 0) {
                        answer[i + 1][b - 1] = 0;
                    }
                }
            }
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < b; j++) {
                    out.print(answer[i][j]);
                }
                out.println();
            }
        }
        in.close();
        out.close();
    }
}
