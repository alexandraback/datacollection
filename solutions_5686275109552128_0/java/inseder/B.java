package codejam15;

import java.io.*;
import java.util.PriorityQueue;

public class B {
    public static void main(String[] args) throws NumberFormatException,
            IOException {

        BufferedReader br = new BufferedReader(
                new InputStreamReader(System.in), 1024 * 1024 * 2);

        int t = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();
        for (int x = 1; x <= t; x++) {
            int n = Integer.parseInt(br.readLine());
            int v[] = readArrayLine(br.readLine(), n);

            PriorityQueue<Integer> queue = new PriorityQueue<>((o1, o2) -> o2 - o1);
            for (int i : v) {
                queue.add(i);
            }
//            int passed = 0;
//            int consumed = 0;
//
//            while (true) {
//                int val = queue.peek() - consumed;
//                if (val <= 0) {
//                    break;
//                }
//                int a = 1 + val / 2 + val % 2;
//                if (a < val) {
//                    queue.poll();
//                    queue.add(val / 2);
//                    queue.add(val / 2 + val % 2);
//                    System.out.println("split");
//                } else {
//                    consumed++;
//                    System.out.println("eat");
//                }
//                passed++;
//            }


            sb.append("Case #" + x + ": " + f(queue, 0, 0, queue.peek()) + "\n");
        }
        BufferedWriter bw = new BufferedWriter(new FileWriter("ii/outBJam.txt"));
        bw.write(sb.toString());
        bw.close();
        System.out.println(sb.toString());
    }

    public static int f(PriorityQueue<Integer> queue, int passed, int consumed, int max) {
        if(passed > max){
            return Integer.MAX_VALUE;
        }
        int val = queue.peek() - consumed;
        if (val <= 0) {
            return passed;
        }
        PriorityQueue<Integer> q1 = new PriorityQueue<>(queue);
        PriorityQueue<Integer> q2 = new PriorityQueue<>(queue);
        q2.poll();
        q2.add(consumed + val / 2);
        q2.add(consumed + val / 2 + val % 2);
        int direct = f(q1, passed + 1, consumed + 1, max);
//        System.out.println("direct: " + passed + ":" + consumed + " " + q1);
        int split = f(q2, passed + 1, consumed, max);
//        System.out.println("split: " + passed + ":" + consumed + " " + q2);
        return Math.min(direct, split);
    }

    public static int[] readArrayLine(String line, int n) {
        int[] ret = new int[n];
        int start = 0;
        int end = line.indexOf(' ', start);
        for (int i = 0; i < n; i++) {
            if (end > 0)
                ret[i] = Integer.parseInt(line.substring(start, end));
            else
                ret[i] = Integer.parseInt(line.substring(start));
            start = end + 1;
            end = line.indexOf(' ', start);
        }
        return ret;
    }
}
