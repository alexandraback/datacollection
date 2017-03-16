package com.vahid.codejam.codejam2016.round1b;

import java.io.*;
import java.util.*;


public class ProblemA {
    public static void main(String[] args) throws IOException {
        Scanner scanner = null;
        BufferedWriter output = null;
        try {
            scanner = new Scanner(new BufferedReader(
                    new FileReader("input.txt")));
            output = new BufferedWriter(new FileWriter("output.txt"));

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i=0; i < n; i++){
            String str = scanner.nextLine();
            output.write( "Case #"+(i+1)+": " + solve(str));
            output.newLine();
        }

        output.close();
    }

    private static String solve(String str) {
        String[] digits = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
        String result = "";
        List<Integer> list = new ArrayList<>();
        int i = 0;
        while (str.trim().length() > 0) {
            System.out.println(str);
            if (has(str, list(i), digits)) {
                str = remove(str, list(i), digits);
                list.add(list(i));
            } else {
                i++;
            }
        }
        list.sort( (o1, o2) -> o1.intValue() - o2.intValue());
        for (Integer a : list) {
            result += a.intValue();
        }
        return result;
    }

    private static int list(int i) {
        int[] list = {2,4,0,6,8,3,1,5,7,9};
        return list[i];
    }

    private static String remove(String str, int d, String[] digits) {
        for (int i=0; i<digits[d].length(); i++) {
            str = str.replaceFirst("" + digits[d].charAt(i), "");
        }
        return str;
    }

    private static boolean has(String str, int d, String[] digits) {
        System.out.println(d);
        for (int i=0; i<digits[d].length(); i++) {
            if (str.indexOf(digits[d].charAt(i)) == -1)
                return false;
        }
        return true;
    }

}
