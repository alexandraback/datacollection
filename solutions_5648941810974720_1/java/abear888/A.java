import java.io.*;
import java.util.*;

public class A {
    public static void main(String[]args) throws IOException {
        BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(x.readLine());
        for (int cases = 1; cases <= t; cases++) {
            String s = x.readLine();
            int[]letters = new int[26];
            for (int i = 0; i < s.length(); i++) {
                letters[s.charAt(i)-'A']++;
            }
            int[]numbers = new int[10];
            numbers[0] = letters['Z'-'A'];
            numbers[6] = letters['X'-'A'];
            numbers[8] = letters['G'-'A'];
            numbers[3] = letters['H'-'A'] - numbers[8];
            numbers[2] = letters['W'-'A'];
            numbers[4] = letters['U'-'A'];
            numbers[5] = letters['F'-'A'] - numbers[4];
            numbers[7] = letters['V'-'A'] - numbers[5];
            numbers[1] = letters['O'-'A'] - numbers[0] - numbers[2] - numbers[4];
            numbers[9] = letters['I'-'A'] - numbers[5] - numbers[6] - numbers[8];
            System.out.print("Case #" + cases + ": ");
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < numbers[i]; j++) {
                    System.out.print(i);
                }
            }
            System.out.println();
        }
    }
}