import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {
    public static void main(String[] args) throws Exception {
        PrintWriter writer = new PrintWriter(new FileOutputStream("B.out"));
        Scanner scanner = new Scanner(new FileInputStream("B.in"));
        //PrintWriter writer = new PrintWriter(System.out);
        //Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int D = scanner.nextInt();
            PriorityQueue<Pile> queue = new PriorityQueue<Pile>(D);
            for (int i = 0; i < D; i++) {
                int p = scanner.nextInt();
                queue.add(new Pile(p));
            }
            int minTime = Integer.MAX_VALUE;
            int turn = 0;
            while (turn < minTime) {
                Pile p = queue.poll();
                int time = turn + p.max;
                if (time < minTime) {
                    minTime = time;
                }
                turn++;
                queue.add(p.split());
            }
            writer.println(String.format("Case #%d: %d", t + 1, minTime));
        }
        scanner.close();
        writer.close();
    }

    private static class Pile implements Comparable<Pile> {
        final int original;
        final int splitBy;
        final int max;

        Pile(int original) {
            this(original, 1);
        }

        Pile(int original, int splitBy) {
            this.original = original;
            this.splitBy = splitBy;
            int tmp = original / splitBy;
            if (original % splitBy != 0) {
                tmp++;
            }
            this.max = tmp;
        }

        Pile split() {
            return new Pile(original, splitBy + 1);
        }

        @Override
        public int compareTo(Pile o) {
            return Integer.compare(o.max, max);
        }
    }
}

