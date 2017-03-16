import java.io.*;
import java.util.*;

public class BoredTravelingSalesmanSolver {
//        private static final String INPUT_FILE_NAME = "B-large.in";
                            private static final String INPUT_FILE_NAME = "C-small-attempt0.in";
//    private static final String INPUT_FILE_NAME = "input.in";
    //    private static final String OUTPUT_FILE_NAME = "B-large.out";
                        private static final String OUTPUT_FILE_NAME = "C-small-attempt0.out";
//    private static final String OUTPUT_FILE_NAME = "output.out";

    private int n;
    private int m;
    private Node[] nodes;
    private List<Node> list;
    private List<List<Node>> all;
    private boolean[] used;
    private int count;
    private StringBuilder answer;

    public static void main(String[] args) throws IOException {
        StringBuilder builder = new StringBuilder();

        try (BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(INPUT_FILE_NAME)))) {
            Scanner scanner = new Scanner(reader);
            scanner.useLocale(Locale.ENGLISH);
            int testCasesCount = scanner.nextInt();

            for (int i = 1; i <= testCasesCount; i++) {
                System.out.println("Case #" + i);
                scanner.nextLine();
                BoredTravelingSalesmanSolver solver = new BoredTravelingSalesmanSolver();

                solver.readData(scanner);
                String solution = solver.solve();

                builder.append("Case #");
                builder.append(i);
                builder.append(": ");
                builder.append(solution);
                builder.append("\r\n");
            }
        }

        try (BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUTPUT_FILE_NAME)
        ))) {
            writer.write(builder.toString());
        }
    }

    private String solve() {
        if (n == 1) {
            return String.valueOf(nodes[0].code);
        }

        answer = new StringBuilder();
        used = new boolean[n];
        SortedSet<Node> set = new TreeSet<>(Arrays.asList(nodes));
        list = new ArrayList<>(set);
        all = new ArrayList<>();
        permutation(new ArrayList<Node>(), list, all);

        for (List<Node> path : all) {
            answer.setLength(0);
            Node current = path.get(0);
            List<Node> p = new ArrayList<>();
            p.add(current);
            answer.append(current.code);
            boolean ok = true;

            for (int i = 1; i < n; i++) {
                Node child = path.get(i);
                if (current.has(child)) {
                    current = child;
                    p.add(child);
                    answer.append(child.code);
                } else {
                    while (!p.isEmpty()) {
                        if (!p.get(p.size() - 1).has(child)) {
                            p.remove(p.size() - 1);
                        } else {
                            break;
                        }
                    }

                    if (p.isEmpty()) {
                        ok = false;
                        break;
                    } else {
                        p.add(child);
                        answer.append(child.code);
                        current = child;
                    }
                }
            }

            if (ok) {
                break;
            }
        }

        return answer.toString();
    }

    private void permutation(List<Node> current, List<Node> left, List<List<Node>> all) {
        if (!left.isEmpty()) {
            for (Node next : left) {
                ArrayList<Node> c = new ArrayList<>(current);
                c.add(next);
                ArrayList<Node> l = new ArrayList<>(left);
                l.remove(next);

                permutation(c, l, all);
            }
        } else {
            all.add(current);
        }
    }

    private void go(Node node) {
        if (count == n) {
            return;
        }
        used[node.index] = true;
        count++;
        answer.append(node.code);
        if (count == n) {
            return;
        }
        for (Node child : node.children) {
            if (!used[child.index]) {
                go(child);
            }
        }
    }

    private void readData(Scanner scanner) {
        n = scanner.nextInt();
        m = scanner.nextInt();

        nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(scanner.nextInt(), i);
        }

        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt() - 1;
            int y = scanner.nextInt() - 1;

            nodes[x].children.add(nodes[y]);
            nodes[y].children.add(nodes[x]);
        }
    }

    private static class Node implements Comparable<Node> {
        private int code;
        private int index;
        private SortedSet<Node> children = new TreeSet<>();

        private Node(int code, int index) {
            this.code = code;
            this.index = index;
        }

        public boolean has(Node child) {
            return children.contains(child);
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(code, o.code);
        }
    }
}
