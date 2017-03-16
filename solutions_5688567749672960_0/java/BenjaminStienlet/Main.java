package GCJ2015.round1B.problemA;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main();
    }

    public Main() throws Exception {
        solve();
    }

    private void solve() throws Exception {
        memo = new HashMap<>();
        memo.put(1, 1);

        System.out.println(">>> Input: ");
        Scanner sc = new Scanner(System.in);
        BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));

        int test_cases = sc.nextInt();
        int n;

        for (int test_case = 1; test_case <= test_cases; test_case++) {
            n = sc.nextInt();

            String result = "Case #" + test_case + ": " + getResult(n);
            out.write(result + "\n");
            System.out.println(result);
        }

        out.flush();
        out.close();
        sc.close();
    }

    Map<Integer, Integer> memo;
    private String getResult(int number) {

        return dp(number) + "";

    }

    private int dp(int number) {
        if (memo.containsKey(number)) {
            return memo.get(number);
        }
        // -1
        int c_min = dp(number - 1) + 1;

        int reverse = reverse(number);

        // switch
        int c_switch;
        if (reverse >= number || number != reverse(reverse)) {
            c_switch = Integer.MAX_VALUE;
        }
        else {
            c_switch = dp(reverse) + 1;
        }

        if (c_min < c_switch) {
            memo.put(number, c_min);
            return c_min;
        } else {
//            System.out.println("switch " + number);
            memo.put(number, c_switch);
            return c_switch;
        }
    }

    private int reverse(int n) {
        int reverse = 0;
        while( n != 0 ) {
            reverse = reverse * 10;
            reverse = reverse + n%10;
            n = n/10;
        }
        return reverse;
    }

}