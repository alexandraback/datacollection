//package denxx;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	    Scanner stdin = new Scanner(System.in);
        int T = stdin.nextInt();
        for (int t = 1; t <= T; ++t) {
            int a = stdin.nextInt();
            int b = stdin.nextInt();
            int k = stdin.nextInt();
            int count = 0;
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j) {
                    count += (i & j) < k ? 1 : 0;
                }
            }
            System.out.println("Case #" + t + ": " + count);
        }
    }
}
