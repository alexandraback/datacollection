package c2014_c.c2014_r2;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;

public class Z2_1 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\z2_1.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\B-small-attempt0.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int k = scanner.nextInt();
            int cnt = 0;
            for (int i=0;i<a;i++) {
                for (int j=0;j<b;j++) {
                    if ((i&j)<k) {
                        cnt++;
                    }
                }
            }
            String s;
                s = "Case #" + ti + ": "+cnt;
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

    private static int[][] read2DArray(Scanner scanner, int n, int m) {
        int [][]m1 = new int[n][m];
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                m1[i][j] = scanner.nextInt();
            }
        }
        return m1;
    }

    // 1 0 1 -> [1,0,1]
    private static int[] readIntArray(Scanner scanner, int n) {
        int [] a = new int[n];
        for (int i=0;i<n;i++) {
            a[i] = scanner.nextInt();
        }
        return a;
    }

    // 1 2/ 2 3 -> [[0 1 0],[1 0 1],[0 1 0]]
    private static void readGraphAsMatrix(Scanner scanner, int n, int[][] matrix) {
        for (int i=0;i<n-1;i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            matrix[x-1][y-1] = 1;
            matrix[y-1][x-1] = 1;
        }
    }

    // sdf ssf ggg -> [3]
    private static String[] readArray(Scanner scanner, int n) {
        String[] l2 = new String[n];
        for (int i=0;i<n;i++) {
            l2[i] = scanner.next();
        }
        return l2;
    }

    // 1 2 3 4 5 - > (1,2,3,4,5)
    private static HashSet<String> readSet(Scanner scanner, int n) {
        String[] l1 = new String[n];
        HashSet<String> set1 = new HashSet<String>();
        for (int i=0;i<n;i++) {
            l1[i] = scanner.next();
            set1.add(l1[i]);
        }
        return set1;
    }

}
