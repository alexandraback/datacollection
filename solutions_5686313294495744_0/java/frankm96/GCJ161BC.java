//Uses Java 8

import java.io.*;
import java.util.*;

public class GCJ161BC {

    static Scanner sc = new Scanner(System.in);

    public void run(int Case) {
        int N = sc.nextInt();
        String[][] list = new String[N][2];

        for (int i = 0; i < N; i++) {
            list[i][0] = sc.next();
            list[i][1] = sc.next();

        }
        int best = 0;
        for (int i = 0; i < (1 << N); i++) {
            HashMap<String, Integer> A = new HashMap();
            HashMap<String, Integer> B = new HashMap();
            int current = 0;
            for (int j = 0; j < N; j++) {
                if (!A.containsKey(list[j][0])) {
                    A.put(list[j][0], 0);
                } else {
                    A.put(list[j][0], A.get(list[j][0]) + 1);
                }
                if (!B.containsKey(list[j][1])) {
                    B.put(list[j][1], 0);
                } else {
                    B.put(list[j][1], B.get(list[j][1]) + 1);
                }
            }
            for (int j = 0; j < N; j++) {
                if ((i & (1 << j)) == 0) {
                    continue;
                }
                if (A.get(list[j][0]) > 0 && B.get(list[j][1]) > 0) {
                    current++;
                }
                A.put(list[j][0], A.get(list[j][0]) - 1);
                B.put(list[j][1], B.get(list[j][1]) - 1);
            }
            best = Math.max(current, best);
        }

        String answer = "Case #" + Case + ": " + String.valueOf(best);
        System.out.println(answer);
    }

    public static void main(String[] args) throws FileNotFoundException {
        //Generates output file, can be removed to get everything from default output
        System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream("C://Users/s142589/Desktop/output.txt")), true));

        int runs = sc.nextInt();
        for (int i = 0; i < runs; i++) {
            new GCJ161BC().run(i + 1);
        }
    }
}
