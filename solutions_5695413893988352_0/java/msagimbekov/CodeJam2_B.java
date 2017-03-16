
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Madi
 */
public class CodeJam2_B {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        try (BufferedReader br = new BufferedReader(new FileReader("C:/Users/Madi/codejam/B-small-practice.in"));
                BufferedWriter bw = new BufferedWriter(new FileWriter("C:/Users/Madi/codejam/B-small-practice.out"))) {

            int t = Integer.parseInt(br.readLine());

            for (int i = 0; i < t; i++) {
                String[] s = br.readLine().split(" ");
                solve(i + 1, s[0], s[1], bw);
            }

        }

    }

    private static void solve(int cs, String s1, String s2, BufferedWriter bw) throws FileNotFoundException, IOException {

        int n = s1.length();
        int x = (int) Math.pow(10, n - 1);
        int y = (int) Math.pow(10, n);

        String a;
        String b;

        int min = Integer.MAX_VALUE;
        int minSum = Integer.MAX_VALUE;
        int minb = Integer.MAX_VALUE;
        int mina = Integer.MAX_VALUE;

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < y; j++) {
                a = String.valueOf(i);
                while (a.length() < n) {
                    a = "0" + a;
                }
                b = String.valueOf(j);
                while (b.length() < n) {
                    b = "0" + b;
                }
                boolean eq = true;
                for (int k = 0; k < n; k++) {
                    if (s1.charAt(k) != '?' && s1.charAt(k) != a.charAt(k)) {
                        eq = false;
                        break;
                    }
                }

                if (eq) {
                    for (int k = 0; k < n; k++) {
                        if (s2.charAt(k) != '?' && s2.charAt(k) != b.charAt(k)) {
                            eq = false;
                            break;
                        }
                    }
                }

                if (eq) {
                    if (min > Math.abs(i - j)) {
                        min = Math.abs(i - j);
                        minSum = i + j;
                        mina = i;
                        minb = j;
                    } else if (min == Math.abs(i - j)) {
                        if (minSum > i + j) {
                            minSum = i + j;
                            mina = i;
                            minb = j;
                        } else if (minSum == i + j) {
                            if (minb > j) {
                                minb = j;
                                mina = i;
                            }
                        }
                    }
                }
            }
        }
        a = String.valueOf(mina);
        b = String.valueOf(minb);
        while (a.length() < n) {
            a = "0" + a;
        }

        while (b.length() < n) {
            b = "0" + b;
        }

        bw.write("Case #" + cs + ": ");
        bw.write(a + " " + b);
        bw.write("\n");
        bw.flush();
    }
}
