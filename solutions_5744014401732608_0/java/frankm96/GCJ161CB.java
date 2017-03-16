//Uses Java 8

import java.io.*;
import java.util.*;

public class GCJ161CB {

    static Scanner sc = new Scanner(System.in);
    int[][] A;
    int B, M;

    public void run(int Case) {
        B = sc.nextInt();
        M = sc.nextInt();
        A = new int[B][B];

        if (BruteForce(0, 1)) {
            String answer = "Case #" + Case + ": POSSIBLE";
            System.out.println(answer);
           // System.err.println(answer);
            for (int i = 0; i < B; i++) {
                for (int j = 0; j < B; j++) {
                    System.out.print(A[i][j]);
                }
                System.out.println("");
            }
        } else {
            String answer = "Case #" + Case + ": IMPOSSIBLE";
            System.out.println(answer);
        }

    }

    boolean BruteForce(int i, int j) {
        if (i == B - 1) {
            //System.err.println(DFS(0));
            return DFS(0) == M;
        } else if (j == B) {
            return BruteForce(i + 1, i + 2);
        } else {
            if (BruteForce(i, j + 1)) {
                return true;
            }
            A[i][j] = 1;
            if (BruteForce(i, j + 1)) {
                return true;
            }
            A[i][j] = 0;
        }
        return false;
    }

    int DFS(int i) {
        if(i==B-1) {
            return 1;
        }
        int count = 0;
        for (int j = i + 1; j < B; j++) {
            if (A[i][j] > 0) {
                
                count += DFS(j);
            }
        }
        return count;
    }

    public static void main(String[] args) throws FileNotFoundException {
        //Generates output file, can be removed to get everything from default output
        System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream("C://Users/s142589/Desktop/output.txt")), true));

        int runs = sc.nextInt();
        for (int i = 0; i < runs; i++) {
            new GCJ161CB().run(i + 1);
        }
    }
}
