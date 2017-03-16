package c2015.r1_3;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;

public class Z2_2 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\z2.txt";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\B-small-attempt0.in";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\B-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int k = scanner.nextInt();
            int l = scanner.nextInt();
            int s = scanner.nextInt();
            String alphabet = scanner.next();
            String word = scanner.next();
            boolean flag = true;
            for (int i=0;i<word.length();i++) {
                String substring = word.substring(i, i+1);
                if (!alphabet.contains(substring)) {
                    flag = false;
                }
            }
            Map<Character, Integer> map = new HashMap<Character, Integer>();
            for (int i=0;i<alphabet.length();i++) {
                Integer integer = map.get(alphabet.charAt(i));
                if (integer==null) {
                    integer = 0;
                }
                integer++;
                map.put(alphabet.charAt(i), integer);
            }
            Double res;
            if (flag) {
                double pow = Math.pow(alphabet.length(), s);
                double cnt = 0;
                long max = 0;
                Map<Integer, Double> x = new HashMap<Integer, Double>();
                for (int i=0;i< s;i++) {
                    Map<Integer, Double> x_n = new HashMap<Integer, Double>();
                    double ver = map.get(word.charAt(0));
                    x_n.put(1, ver /alphabet.length());
                    for (Map.Entry<Integer, Double> entry : x.entrySet()) {
                        int index = entry.getKey() + 1;
                        if (index>word.length()) {
                            System.out.println("xx");
                        }
                        char key = word.charAt(index-1);
                        double ver1 = map.get(key);
                        x_n.put(index, entry.getValue() * ver1 /alphabet.length());
                    }
                    x = x_n;
                    Double aDouble = x.get(word.length());
                    if (aDouble!=null && aDouble>0) {
                        cnt += aDouble;
                    }
                    x.remove(word.length());
                }
                max = s / word.length();
                if (word.length()>1) {
                    if (word.charAt(1) == word.charAt(0)) {
                        max *= 2;
                    }
                }
                System.out.println(cnt);
                System.out.println(max);
                res = max - cnt;
            } else {
                res = 0.0;
            }
            String s11;
            s11 = "Case #" + ti + ": "+res;
            System.out.println(s11);
            out.write(s11);
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
