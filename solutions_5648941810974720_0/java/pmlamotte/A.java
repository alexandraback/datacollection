import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class A {

    public static String[] cStrings = new String[] {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    public static int[][] cCounts = new int[10][26];

    public static void main(String[] args) {
        for (int i = 0 ; i < cStrings.length; i++) {
            for (char x : cStrings[i].toCharArray()) {
                cCounts[i][x - 'A']++;
            }
            //System.out.println(Arrays.toString(cCounts[i]));
        }

        try {
            System.setOut(new PrintStream(new FileOutputStream("A.out")));
            Scanner scan = new Scanner(new FileInputStream("A.in"));
            int cases = scan.nextInt();

            for (int c = 0; c < cases; c++) {
                String str = scan.next();

                int[] converted = new int[26];
                for (char x : str.toCharArray()) {
                    converted[x - 'A']++;
                }

                String res = "";
                for (int i = 0; i < 10; i++) {
                    res = answer("", converted, i);
                    if (res.equals("")) {
                        continue;
                    }
                    break;
                }

                System.out.printf("Case #%d: %s%n", c+1, res);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static int sum(int[] arr) {
        int sum = 0;
        for (int x : arr) {
            sum += x;
        }
        return sum;
    }

    public static boolean sub(int[] arr1, int[] arr2) {
        boolean neg = false;
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] -= arr2[i];
            if (arr1[i] < 0) {
                neg = true;
            }
        }
        return neg;
    }

    public static boolean allZero(int[] arr) {
        for (int x : arr) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }

    public static String answer(String current, int[] remaining, int toTry) {
        if (allZero(remaining)) {
            return current;
        }
        if (toTry < 0) {
            return "";
        }
        int[] clone = new int[26];
        System.arraycopy(remaining, 0, clone, 0, 26);

        while (true) {
            int[] subClone = new int[26];
            System.arraycopy(clone, 0, subClone, 0, 26);

            String res = answer(current, subClone, toTry - 1);
            if (!res.equals("")) {
                return res;
            }

            boolean anyNeg = sub(clone, cCounts[toTry]);
            if (anyNeg) {
                return "";
            }
            current = toTry + current;
        }
    }
}
