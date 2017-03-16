/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;

/**
 *
 * @author Vojta
 */
public class Diamond {

    /**
     * @param args the command line arguments
     */
    private static class Node {

        Set<Integer> childs = new HashSet<Integer>();
    }

    public static boolean isDiam(List<Node> nodes) {
        for (int start = 1; start < nodes.size(); start++) {
            boolean [] closed = new boolean[nodes.size()];
            Queue<Integer> l = new LinkedList<Integer>();
            l.add(start);
            while (!l.isEmpty()) {
                Integer node = l.poll();
                if (closed[node]) return true;
                closed[node] = true;
                
                for (Integer succ : nodes.get(node).childs) {
                    l.add(succ);
                }
                
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int inputs = sc.nextInt();
        for (int i = 0; i < inputs; i++) {
            int classes = sc.nextInt();
            List<Node> nodes = new ArrayList<Node>();
            nodes.add(new Node());
            for (int j = 1; j < classes + 1; j++) {
                int childs = sc.nextInt();
                nodes.add(new Node());
                for (int k = 0; k < childs; k++) {
                    nodes.get(j).childs.add(sc.nextInt());
                }
            }
            int cas = i + 1;
            System.out.println("Case #" + cas + ": " + (isDiam(nodes)==true?"Yes" : "No"));

        }
    }
}
