package codejam2015.B1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class CounterCulture {
    public static void main(String[] args) throws IOException {
        String fileName;

//        fileName = "test.in";
        fileName = "A-small-attempt2.in";

        int[] d = prepare();

        try (BufferedReader r = new BufferedReader(new FileReader(fileName));
             BufferedWriter w = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")))) {
            Scanner sc = new Scanner(r);
            int T = sc.nextInt();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                int n = sc.nextInt();
                String calc = "" + d[n];
                w.write("Case #" + (i + 1) + ": " + calc + "\n");
                w.flush();
                System.out.println("res:" + calc);
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }

    }

    private static int[] prepare() {
        int[] d = new int[2000001];

        d[1] = 1;
        Deque<Integer> deque = new ArrayDeque<>();
        deque.add(1);

        while (!deque.isEmpty()) {
            Integer num = deque.pollFirst();
            int next = num + 1;

            if (next < d.length && d[next] == 0 ) {
                d[next] = d[num] + 1;
                deque.addLast(next);
            }

            int reverse = reverse(num);
            if (reverse >= d.length) {
                continue;
            }

            if (d[reverse] == 0) {
                d[reverse] = d[num] + 1;
                deque.addLast(reverse);
            }
        }

        return d;
    }


    private static int reverse(int j) {
        while (j % 10 == 0) {
            j = j / 10;
        }
        StringBuilder reverse = new StringBuilder(Integer.toString(j)).reverse();
        int r = Integer.parseInt(reverse.toString());
        return r;

    }


}
