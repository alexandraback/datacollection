import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class A {

    private static final String FILE_NAME = "A-large";

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            int n = Integer.parseInt(in.readLine());
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; ++i) {
                String[] split = in.readLine().split(" ");
                int k = Integer.parseInt(split[0]);
                nodes[i] = new Node();
                for (int j = 0; j < k; ++j) {
                    nodes[i].inheritsFrom.add(Integer.parseInt(split[j+1])-1);
                }
            }
            String diamond = "No";
            for (int i = 0; i < nodes.length; ++i) {
                boolean seen[] = new boolean[nodes.length];
                if (diamond(nodes, i, seen)) {
                    diamond = "Yes";
                    break;
                }
            }
            String result = String.format("Case #%d: %s", c, diamond);
            System.out.println(result);
            out.write(result);
            out.write("\n");
        }
        out.close();
    }

    private static boolean diamond(Node[] nodes, int index, boolean[] seen) {
        if (seen[index]) {
            return true;
        }
        seen[index] = true;
        for (Integer from : nodes[index].inheritsFrom) {
            if (diamond(nodes, from, seen)) {
                return true;
            }
        }
        return false;
    }

    private static class Node {
        List<Integer> inheritsFrom = new ArrayList<Integer>();
    }
}
