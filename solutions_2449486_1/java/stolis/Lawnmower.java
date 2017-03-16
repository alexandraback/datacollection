package qualification2013;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Lawnmower {
    static int T;
    static boolean[] result;
    static int N;
    static int M;
    static int[][] lawn;

    public static void main(String[] args) throws IOException {
        read();
        process();
        write();
    }

    static void read() throws IOException {
        File input = new File("input.txt");
        Scanner scanner = new Scanner(input);
        T = scanner.nextInt();
        result = new boolean[T];
        for (int t=0; t<T; t++) {
            N = scanner.nextInt();
            M = scanner.nextInt();
            lawn = new int[N][M];
            for (int n=0; n<N; n++) {
                for (int m=0; m<M; m++) {
                    lawn[n][m] = scanner.nextInt();
                }
            }
            result[t] = process();
        }
    }

    static boolean process() {
        for (int n=0; n<N; n++) {
            for (int m=0; m<M; m++) {
                int val = lawn[n][m];
                boolean ok = true;
                for (int x=0; x<N; x++) {
                    if (lawn[x][m] > val) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    ok = true;
                    for (int y=0; y<M; y++) {
                        if (lawn[n][y] > val) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    static void write() throws IOException {
        File output = new File("output.txt");
        PrintWriter pw = new PrintWriter(output);

        for (int t=0; t<T; t++) {
            pw.println("Case #"+(t+1)+": "+(result[t] ? "YES" : "NO"));
        }

        pw.close();
    }

}
