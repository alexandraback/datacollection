
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
    static int N;
    static int M;
    static long max;
    static long boxNum[];
    static int boxType[];
    static long toyNum[];
    static int toyType[];
    public static void main(String args[]) throws Exception {
        final String PATH = "/home/goalboy/software installation/codejam-commandline-1.0-beta4/source/";
        final String FILE = "C-small-0";
        Scanner in = new Scanner(new File(PATH + FILE + ".in"));
        PrintWriter out = new PrintWriter(PATH + FILE + ".out");

        int test = in.nextInt();
        for (int t = 1; t <= test; t++) {
            N = in.nextInt();
            M = in.nextInt();
            boxNum = new long[N];
            boxType = new int[N];
            toyNum = new long[M];
            toyType = new int[M];
            for (int i = 0; i < N; i++) {
                boxNum[i] = in.nextLong();
                boxType[i] = in.nextInt();
            }
            for (int i = 0; i < M; i++) {
                toyNum[i] = in.nextLong();
                toyType[i] = in.nextInt();
            }
            max=-1;
            search(0, 0, 0, 0, 0);
            out.println("Case #" + t + ": " + max);
        }

        out.close();
    }
    
    static void search(int boxIndex, int toyIndex, long restBox, long restToy, long sent) {
        if (boxIndex>=N && toyIndex>=M) {
            max=Math.max(max, sent);
            return;
        }
        if (boxIndex<N) {
            if (toyIndex==0 || boxType[boxIndex]!=toyType[toyIndex-1]) {
                search(boxIndex+1, toyIndex, boxNum[boxIndex], restToy, sent);
            }
            else {
                long addition=Math.min(boxNum[boxIndex], restToy);
                search(boxIndex+1, toyIndex, boxNum[boxIndex]-addition, restToy-addition, sent+addition);
            }
        }
        if (toyIndex<M) {
            if (boxIndex==0 || boxType[boxIndex-1]!=toyType[toyIndex]) {
                search(boxIndex, toyIndex+1, restBox, toyNum[toyIndex], sent);
            }
            else {
                long addition=Math.min(restBox, toyNum[toyIndex]);
                search(boxIndex, toyIndex+1, restBox-addition, toyNum[toyIndex]-addition, sent+addition);
            }
        }
    }
}
