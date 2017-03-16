import java.io.*;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class B {

    private static final String FILE_NAME = "B-small-attempt1";

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            String[] row = in.readLine().split(" ");
            int x = Integer.parseInt(row[0]);
            int y = Integer.parseInt(row[1]);

            Node goal = findGoal(x, y);
            StringBuilder sb = new StringBuilder();
            printPath(goal, sb);
            write(out, String.format("Case #%d: %s", c, sb.toString()));
        }
        out.close();
    }

    private static void printPath(Node node, StringBuilder sb) {
        if (node.parent != null) {
            printPath(node.parent, sb);
            sb.append(node.move);
        }
    }

    private static Node findGoal(int x, int y) {
        Set<Node> seenNodes = new HashSet<Node>();
        Queue<Node> nodes = new LinkedList<Node>();
        Node node = new Node(0, 0, 0, null, null);
        seenNodes.add(node);
        nodes.add(node);
        while (!nodes.isEmpty()) {
            node = nodes.poll();
            for (int i = 0; i < 4; ++i) {
                Node newNode = createNode(node, i);
                if (!seenNodes.add(newNode)) {
                    continue;
                }
                if (newNode.x == x && newNode.y == y) {
                    return newNode;
                }
                nodes.add(newNode);
            }
        }
        throw new RuntimeException("Could not find goal node");
    }

    private static Node createNode(Node node, int dir) {
        String move;
        int dx, dy;
        if (dir == 0)      { move = "N"; dx = 0;           dy = node.t+1;    }
        else if (dir == 1) { move = "S"; dx = 0;           dy = -(node.t+1); }
        else if (dir == 2) { move = "E"; dx = node.t+1;    dy = 0;           }
        else if (dir == 3) { move = "W"; dx = -(node.t+1); dy = 0;           }
        else { throw new RuntimeException("Unsupported move"); }
        return new Node(node.x+dx, node.y+dy, node.t+1, node, move);
    }

    private static void write(BufferedWriter out, String message) throws IOException {
        out.write(message);
        out.write("\n");
        System.out.println(message);
    }

    private static final class Node {
        private final int x, y, t;
        private final Node parent;
        private final String move;

        private Node(int x, int y, int t, Node parent, String move) {
            this.x = x;
            this.y = y;
            this.t = t;
            this.parent = parent;
            this.move = move;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Node node = (Node) o;

            if (x != node.x) return false;
            if (y != node.y) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }
    }
}
