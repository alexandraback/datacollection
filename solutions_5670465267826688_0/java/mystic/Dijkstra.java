import java.util.*;
import java.io.*;
import java.math.*;

public class Dijkstra {
    final static String PROBLEM_NAME = "dijkstra";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    final int[][] mul = new int[8][8];

    final int _1 = 0, I = 1, J = 2, K = 3;

    int m(int x) {
        return (x + 4) % 8;
    }

    int pow(int a, long B) {
        if (B == 1) {
            return a;
        }
        int res = pow(a, B/2);
        res = mul[res][res];
        if (B % 2 == 1) {
            res = mul[res][a];
        }
        return res;
    }

    // 1, i, j, k, -1, -i, -j, -k
    void solve(Scanner sc, PrintWriter pw) {
        for (int i = 0; i < 8; i++) {
            Arrays.fill(mul[i], -1);
        }

        mul[_1][_1] = _1; mul[_1][I] = I; mul[_1][J] = J; mul[_1][K] = K;
        mul[I][_1] = I; mul[I][I] = m(_1); mul[I][J] = K; mul[I][K] = m(J);
        mul[J][_1] = J; mul[J][I] = m(K); mul[J][J] = m(_1); mul[J][K] = I;
        mul[K][_1] = K; mul[K][I] = J; mul[K][J] = m(I); mul[K][K] = m(_1);

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                mul[m(i)][m(j)] = mul[i][j];
                mul[i][m(j)] = m(mul[i][j]);
                mul[m(i)][j] = m(mul[i][j]);
            }
        }

        int L = sc.nextInt();
        long X = sc.nextLong();

        String s = sc.next();
        int[] A = new int[L];
        for (int i = 0; i < L; i++) {
            A[i] = s.charAt(i) - 'i' + 1;
        }

        int prod = _1;
        for (int x : A) {
            prod = mul[prod][x];
        }

        prod = pow(prod, X);

        int wantProd = mul[mul[I][J]][K];

        if (prod != wantProd) {
            pw.println("NO");
            return;
        }

        int[][] best = new int[L][24];
        for (int i = 0; i < L; i++) {
            Arrays.fill(best[i], -1);
        }

        int[] QL = new int[24*L];
        int[] QS = new int[24*L];
        int qBeg = 0, qEnd = 0;

        QL[qBeg] = 0; QS[qBeg++] = _1;
        best[0][_1] = 0;

        while (qEnd < qBeg) {
            int curL = QL[qEnd], curS = QS[qEnd++];

            int nextL = (curL + 1) % L;

            int base = (curS / 8) * 8;
            int state = curS % 8;

            int nextS = base + 8 + A[curL];
            if ((curS == I || curS == 8 + J) && best[nextL][nextS] == -1) {
                QL[qBeg] = nextL;
                QS[qBeg++] = nextS;
                best[nextL][nextS] = best[curL][curS] + 1;
            }

            nextS = base + mul[state][A[curL]];
            if (best[nextL][nextS] == -1) {
                QL[qBeg] = nextL;
                QS[qBeg++] = nextS;
                best[nextL][nextS] = best[curL][curS] + 1;
            }
        }

        if (best[0][16 + K] == -1 || best[0][16 + K] > X * L) {
            pw.println("NO");
        } else {
            pw.println("YES");
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Dijkstra().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
