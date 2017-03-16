import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static private PrintWriter writer;
    static int nt;

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        writer = new PrintWriter(new FileWriter("answer.txt"));

        for (nt = 1; nt <= T; nt++) {
            int N, result1 = 0, result2 = 0, tmpresult = 0;
            N = in.nextInt();

            double A[] = new double[1005];
            double B[] = new double[1005];
            double C[] = new double[1005];

            for (int i = 0; i < N; i++)
                A[i] = in.nextDouble();
            for (int i = 0; i < N; i++)
                B[i] = in.nextDouble();

            Arrays.sort(A, 0, N);
            Arrays.sort(B, 0, N);
            C = Arrays.copyOf(B, N);


            int pointerA = 0, pointerB = 0;
            while (pointerA <= N-1 && pointerB <= N-1) {
                if (A[pointerA] < B[pointerB]) {
                    tmpresult++;
                    pointerB++;
                    pointerA++;
                } else {
                    pointerB++;
                }
            }
            result2 = N-tmpresult;

//            for (int i = 0; i < N; i++) {
//                for (int j = 0; j < N; j++) {
//                    if (A[i] < C[j]) {
//                        C[j] = -1;
//                        break;
//                    }
//                }
//            }
//
//            for (int i = 0; i < N; i++) {
//                if (C[i] >= 0)
//                    result2++;
//            }

            pointerA = 0; pointerB = 0;
            int endA = N-1, endB = N-1;

            while (pointerA <= endA && pointerB <= endB) {
                if (A[pointerA] < B[pointerB]) {
                    endB--;
                    A[pointerA] = -1;
                } else {
                    pointerB++;
                    result1++;
                }
                pointerA++;
            }


            writer.println("Case #" + nt + ": " + result1 + " " + result2);
        }

        writer.close();
    }
}
