import java.io.*;
import java.util.*;

/**
 * Created with IntelliJ IDEA. User: Welcome Date: 6/5/12 Time: 2:10 PM To change this template use File | Settings |
 * File Templates.
 */
public class A {
    public static String path = "./";
//    public static String path = "C:/users/Welcome/downloads/";
    public static String fname = "A-small-attempt0.in";
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(path + fname));
        BufferedWriter writer = new BufferedWriter(new FileWriter(path + fname + ".out"));
        int tests = Integer.parseInt(reader.readLine());
        for (int test = 1; test <= tests; test++) {
            int nclasses = Integer.parseInt(reader.readLine());
            Map<Integer, Node> nodes = new HashMap<Integer, Node>();
            for (int i = 1; i <= nclasses; i++) {
                nodes.put(i, new Node(i));
            }

            for (int i =1; i <= nclasses; i++) {
                Node current = nodes.get(i);
                String[] splits = reader.readLine().trim().split("[ ]");
                for (int j = 1; j < splits.length; j++) {
                    Node node = nodes.get(Integer.parseInt(splits[j]));
                    if (node == null) {
                        System.out.println(nodes);
                        throw new IllegalArgumentException("test " + test + "; current = " + i + "; " +splits[j]);
                    }
                    current.from.add(node);
                }
            }
            boolean retval= false;
            for (int i = 1; i <= nclasses; i++) {
                Node node = nodes.get(i);
                boolean ret = node.isDiamond();
                if (ret) {
                   retval = ret;
                    break;
                }
            }
            String msg = "Case #" + test +": ";
            msg = msg + (retval ? "Yes" : "No") + "\n";
            writer.write(msg);
        }
        reader.close();
        writer.close();
    }

    private static class Node {
        private final int value;
        private final List<Node> from = new ArrayList<Node>();
        private Node(int value) {
            this.value = value;
        }
        boolean isDiamond() {
            Set<Integer> paths = new HashSet<Integer>();
            return isDiamond(paths);
        }

        boolean isDiamond(Set<Integer> paths) {
            if (from != null) {
                for (Node node : from) {
                    if (paths.contains(node.value)) {
                        return true;
                    } else {
                        paths.add(node.value);
                        boolean retval = node.isDiamond(paths);
                        if (retval) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Node node = (Node) o;

            if (value != node.value) return false;

            return true;
        }

        @Override
        public int hashCode() {
            return value;
        }

        public String toString() {
            return String.valueOf(value);
        }
    }
}
