import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;

public class A {

    public static String[] cStrings = new String[] {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    public static int[][] cCounts = new int[10][26];

    public static void main(String[] args) {
//
//        String wat = "";
//        while (true) {
//            Random random = new Random();
//            wat += cStrings[random.nextInt(10)];
//            if (wat.length() >= 1990) {
//                break;
//            }
//        }
//        System.out.println(wat);

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


                String res = answer("", converted, 0);
                char[] carr = res.toCharArray();
                Arrays.sort(carr);
                res = new String(carr);

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

    public static void add(int[] arr1, int[] arr2) {
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] += arr2[i];
        }
    }

    public static boolean allZero(int[] arr) {
        for (int x : arr) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }

    public static String arrToStr(int[] arr) {
        StringBuilder builder = new StringBuilder();
        for (int x : arr) {
            builder.append(x);
            builder.append(' ');
        }
        //builder.append(toTry);
        String str = builder.toString();
        return builder.toString();
    }

    public static HashSet<String> memo = new HashSet();

    public static String answer(String current, int[] remaining, int toTry) {
//        if (memo.contains(arrToStr(remaining))) {
//            System.out.println("memoized!");
//            return "";
//        }

        if (allZero(remaining)) {
            return current;
        }
        if (toTry == -1) {
            return "";
        }
        //System.out.println(toTry);
        int[] clone = new int[26];
        System.arraycopy(remaining, 0, clone, 0, 26);

        int max = 0;
        while (true) {
            boolean anyNeg = sub(clone, cCounts[toTry]);
            if (anyNeg) {
                add(clone, cCounts[toTry]);
                break;
            }
            max++;
            current += toTry;
        }

        int lowLimit = 0;
        if (toTry == 0 || toTry == 2 || toTry == 4 || toTry == 6 || toTry == 8) {
            lowLimit = max;
        }
        int next = -1;
        switch(toTry) {
            case 0: next = 2; break;
            case 2: next = 4; break;
            case 4: next = 8; break;
            case 8: next = 6; break;
            case 6: next = 7; break;
            case 7: next = 1; break;
            case 1: next = 3; break;
            case 3: next = 5; break;
            case 5: next = 9; break;
            case 9: next = -1; break;
        }
        for (int i = max; i >= lowLimit; i--) {
            String res = answer(current.substring(0, current.length() - (max - i)), clone, next);
            if (!res.equals("")) {
                return res;
            }
//            memo.add(arrToStr(clone));

            current = toTry + current;
            add(clone,cCounts[toTry]);
        }

        return "";
    }
}
