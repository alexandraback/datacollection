/*
 * ID: antonio13
 * LANG: JAVA
 * PROG: A
 */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 * @author antonio081014
 * @time: 2012-5-6, 1:49:13
 */

public class A {

    int[][] node;

    public static void main(String[] args) throws Exception {
        A main = new A();
        main.run();
        System.exit(0);
    }

    public void run() throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("A.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("A.out"));
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            int N = Integer.parseInt(br.readLine());
            node = new int[N + 1][N + 1];

            init(N);
            for (int i = 1; i <= N; i++) {
                String[] str = br.readLine().split("\\s");
                for (int j = 1; j < str.length; j++) {
                    node[i][Integer.parseInt(str[j])] = 1;
                }
            }
            out.write("Case #" + Integer.toString(t) + ": ");
            boolean flag = true;
            for (int k = 1; k <= N && flag; k++) {
                for (int i = 1; i <= N && flag; i++) {
                    if (i != k)
                        for (int j = 1; j <= N && flag; j++) {
                            if (j != k && j != i) {
                                if (node[i][j] == 0) {
                                    if (node[i][k] > 0 && node[k][j] > 0)
                                        node[i][j] = 1;
                                }
                                else {
                                    if (node[i][k] > 0 && node[k][j] > 0) {
                                        out.write("Yes\n");
                                        flag = false;
                                    }
                                }
                            }
                        }
                }
            }
            if (flag)
                out.write("No\n");
        }
        out.close();
    }

    public void init(int N) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++)
                node[i][j] = 0;
        }
    }
}
