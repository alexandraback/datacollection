import sun.security.krb5.internal.crypto.crc32;

import java.io.*;
import java.security.SecureRandom;
import java.text.DecimalFormat;
import java.util.*;

/**
 * Created by Rafal on 4/12/14.
 */
public class C {

    public static void main(String[] args) {
        try {
            InputStream in = new FileInputStream("c:/projekty/codejam/src/C.in");
            Scanner scanner = new Scanner(in);
            OutputStream out = new FileOutputStream("c:/projekty/codejam/src/C.out");
            PrintWriter writer = new PrintWriter(new OutputStreamWriter(out, "utf8"));
            int t = scanner.nextInt();
            for (int i = 0; i < t; i++) {
                solve(scanner, i+1, writer);
            }
            writer.close();
        } catch (Exception e) {
            System.out.println("Error: " + e);
            e.printStackTrace();
        }
    }


    public static void solve2(Scanner scanner, int t, PrintWriter out) {
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        Node []nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
            nodes[i].zipCode = scanner.nextInt();
        }

        for (int i = 0; i < m; i++) {
            int n1 = scanner.nextInt() - 1;
            int n2 = scanner.nextInt() - 1;
            nodes[n1].addLinked(nodes[n2]);
            nodes[n2].addLinked(nodes[n1]);
        }

        for (int i = 0; i < nodes.length; i++) {
            Node node = nodes[i];
            node.linkedNodes.sort(new NodeComparator());
        }

        List<Node> nodeList = new ArrayList<>(Arrays.asList(nodes));
        nodeList.sort(new NodeComparator());

        // we start from the first node on the list

        HashSet<Node> visitedSet = new HashSet<>();
        Node node = nodeList.get(0);
        String result = findPath(visitedSet, node, new TreeSet<Node>());
        System.out.println("Case #" + t + ": " + result);
        out.println("Case #" + t + ": " + result);

    }
    public static void solve(Scanner scanner, int t, PrintWriter out) {
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        Node []nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
            nodes[i].zipCode = scanner.nextInt();
        }

        for (int i = 0; i < m; i++) {
            int n1 = scanner.nextInt() - 1;
            int n2 = scanner.nextInt() - 1;
            nodes[n1].addLinked(nodes[n2]);
            nodes[n2].addLinked(nodes[n1]);
        }

        for (int i = 0; i < nodes.length; i++) {
            Node node = nodes[i];
            node.linkedNodes.sort(new NodeComparator());
        }

        List<Node> nodeList = new ArrayList<>(Arrays.asList(nodes));
        nodeList.sort(new NodeComparator());

        // we start from the first node on the list

        HashSet<Node> visitedSet = new HashSet<>();
        Node node = nodeList.get(0);
        String result;
        if (node.linkedNodes.size() > 0) {
            result = "" + node.zipCode;
            result += node.linkedNodes.get(0);
            HashSet<Node> visitedNodes = new HashSet<>();
            visitedNodes.add(node);
            visitedNodes.add(node.linkedNodes.get(0));
            nodeList.remove(node);
            nodeList.remove(node.linkedNodes.get(0));
            List<Node> soFar = new ArrayList<>();
            soFar.add(node);
            soFar.add(node.linkedNodes.get(0));
            // try every possible combination
            String res = getAllCombinations(soFar, nodeList);
            result = res;
        } else {
            result = "" + node.zipCode;
        }
//        String result = findPath(visitedSet, node, new TreeSet<Node>());
        System.out.println("Case #" + t + ": " + result);
        out.println("Case #" + t + ": " + result);

    }

    private static String getAllCombinations(List<Node> listSoFar, List<Node> nodeList) {
        String bestResult = null;
        if (nodeList.size() == 0) {
            if (verifyResult(listSoFar)) {
                String result = getResult(listSoFar);
                if (result != null && (bestResult == null || result.compareTo(bestResult) < 0)) {
                    bestResult = result;
                }
            }
            return bestResult;

        }
        for (int i = 0; i < nodeList.size(); i++) {
            Node node = nodeList.get(i);
            List<Node> n = new ArrayList<>(nodeList);
            List<Node> soFar = new ArrayList<>(listSoFar);
            n.remove(i);
            soFar.add(node);
            if (n.size() > 0) {
                String result = getAllCombinations(soFar, n);
                if (result != null && (bestResult == null || result.compareTo(bestResult) < 0)) {
                    bestResult = result;
                }
            } else {
                if (verifyResult(soFar)) {
                    String result = getResult(soFar);
                    if (result != null && (bestResult == null || result.compareTo(bestResult) < 0)) {
                        bestResult = result;
                    }
                }
            }

        }
        return bestResult;
    }

    private static boolean verifyResult(List<Node> list) {
//        System.out.println("verifying result: " + getResult(list));
//        if (getResult(list).equals("1095328444500122965136642")) {
//            System.out.println("OK");
//        }
        List<Node> currentNodes = new ArrayList<>();
        currentNodes.add(list.get(0));
        XX: for (int i = 1; i < list.size(); i++) {
//            System.out.println("getResult: " + getResult(currentNodes));
            Node n = list.get(i);
            // do we have flight from one of currentNodes to n - go backwards
            for (int j = currentNodes.size() - 1; j >= 0; j--) {
                Node nn = currentNodes.get(j);
                if (nn.linkedNodes.contains(n)) {
                    if (j < currentNodes.size() - 1) {
                        currentNodes = new ArrayList<>(currentNodes.subList(0, j + 1));
                    }
                    currentNodes.add(n);
                    continue XX;
                }
            }
            return false;
        }
        return true;
    }

    private static String getResult(List<Node> soFar) {
        String result = "";
        for (Node node : soFar) {
            result += node.zipCode;
        }
        return result;
    }

    private static String findPath(Set<Node> visitedSet, Node nextNode, TreeSet<Node> possibleNodes) {
        String result = "";
        result += nextNode.zipCode;
        visitedSet.add(nextNode);

        Node first;
        if (possibleNodes.isEmpty()) {
            first = null;
        } else {
            first = possibleNodes.first();
        }
        int lastNotReachable = -1;
        List<Node> linkedNodes = nextNode.linkedNodes;
        XXX:
        for (int i = 0; i < linkedNodes.size(); i++) {
            Node linkedNode = linkedNodes.get(i);
            if (visitedSet.contains(linkedNode)) {
                continue;       // already visited
            }

            if (first != null && first.zipCode < linkedNode.zipCode) {
                // see if this node can be reached from any nodes in possibleNodes
                Set<Node> set = new HashSet<>(visitedSet);
                for (Node possibleNode : possibleNodes) {
                    if (isReachable(possibleNode, linkedNode, set)) {
                        // do not visit this node now!
                        continue XXX;
                    }
                }
                lastNotReachable = linkedNode.zipCode;
            }
        }
        for (int i = 0; i < linkedNodes.size(); i++) {
            Node linkedNode = linkedNodes.get(i);
            if (visitedSet.contains(linkedNode)) {
                continue;       // already visited
            }

            if ((first == null || first.zipCode >= linkedNode.zipCode) ||
                    (lastNotReachable != -1 && linkedNode.zipCode <= lastNotReachable)) {

                TreeSet<Node> newPossibleNodes = new TreeSet<>(possibleNodes);
                newPossibleNodes.addAll(linkedNodes.subList(i+1, linkedNodes.size()));

                result += findPath(visitedSet, linkedNode, newPossibleNodes);
            }
        }
        return result;
    }

    private static boolean isReachable(Node possibleNode, Node linkedNode, Set<Node> visitedSet) {
        if (possibleNode == linkedNode) return true;

        if (visitedSet.contains(possibleNode)) return false;

        visitedSet.add(possibleNode);
        for (int i = 0; i < possibleNode.linkedNodes.size(); i++) {
            Node node = possibleNode.linkedNodes.get(i);
            if (!visitedSet.contains(node)) {
                if (isReachable(node, linkedNode, visitedSet)) {
                    return true;
                }
            }
        }
        return false;
    }

    static class Node implements Comparable {
        int zipCode;

        List<Node> linkedNodes = new ArrayList<>();

        public void addLinked(Node n) {
            linkedNodes.add(n);
        }

        @Override
        public int compareTo(Object o) {
            Node n = (Node) o;
            return zipCode - n.zipCode;
        }
    }


    private static class NodeComparator implements Comparator<Node> {
        @Override
        public int compare(Node o1, Node o2) {
            return o1.zipCode - o2.zipCode;
        }
    }
}
