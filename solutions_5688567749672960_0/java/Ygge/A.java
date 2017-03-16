import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class A {

    private static final String FILE_NAME = "A-small-attempt0";

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));
        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            int n = Integer.parseInt(in.readLine());

            Set<Integer> seen = new HashSet<>();
            Queue<Node> nodes = new LinkedList<>();
            nodes.add(new Node(1, 1));
            Node result = null;
            while (true) {
                Node node = nodes.poll();
                if (!seen.add(node.num)) {
                    continue;
                }
                if (node.num == n) {
                    result = node;
                    break;
                }
                if (!seen.contains(node.num+1)) {
                    nodes.add(new Node(node.num+1, node.steps+1));
                }
                int flip = flip(node.num);
                if (!seen.contains(flip)) {
                    nodes.add(new Node(flip, node.steps+1));
                }
            }

            String ans = String.format("Case #%d: %d", c, result.steps);
            System.out.println(ans);
            out.write(ans + "\n");
        }
        out.close();
    }

    private static int flip(int num) {
        String s = Integer.toString(num);
        int result = 0;
        for (int i = s.length()-1; i >= 0; --i) {
            result = 10*result+s.charAt(i)-'0';
        }
        return result;
    }

    private static class Node {
        private final int num, steps;

        public Node(int num, int steps) {
            this.num = num;
            this.steps = steps;
        }
    }
}
