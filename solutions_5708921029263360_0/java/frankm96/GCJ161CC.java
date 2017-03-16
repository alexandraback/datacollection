//Uses Java 8

import java.io.*;
import java.util.*;

public class GCJ161CC {

    static Scanner sc = new Scanner(System.in);

    public void run(int Case) {
        int J = sc.nextInt();
        int P = sc.nextInt();
        int S = sc.nextInt();
        int K = sc.nextInt();

        int[][] conf1 = new int[20][20];
        int[][] conf2 = new int[20][20];
        int[][] conf3 = new int[20][20];
        for (int[] a : conf1) {
            Arrays.fill(a, K);
        }
        for (int[] a : conf2) {
            Arrays.fill(a, K);
        }
        for (int[] a : conf3) {
            Arrays.fill(a, K);
        }
        int count = 0;
        for (int k = 1; k <= S; k++) {
            for (int j = 1; j <= P; j++) {
                for (int i = 1; i <= J; i++) {
                    if (conf1[i][j] > 0 && conf2[i][k] > 0 && conf3[j][k] > 0) {
                        conf1[i][j]--;
                        conf2[i][k]--;
                        conf3[j][k]--;
                        count++;
                    }
                }
            }
        }

        String answer = "Case #" + Case + ": " + count;
        System.out.println(answer);

        for (int[] a : conf1) {
            Arrays.fill(a, K);
        }
        for (int[] a : conf2) {
            Arrays.fill(a, K);
        }
        for (int[] a : conf3) {
            Arrays.fill(a, K);
        }
        for (int k = 1; k <= S; k++) {

            for (int j = 1; j <= P; j++) {
                for (int i = 1; i <= J; i++) {
                    if (conf1[i][j] > 0 && conf2[i][k] > 0 && conf3[j][k] > 0) {
                        conf1[i][j]--;
                        conf2[i][k]--;
                        conf3[j][k]--;
                        System.out.println(i + " " + j + " " + k);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        //Generates output file, can be removed to get everything from default output
        System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream("C://Users/s142589/Desktop/output.txt")), true));

        int runs = sc.nextInt();
        for (int i = 0; i < runs; i++) {
            new GCJ161CC().run(i + 1);
        }
    }
}
