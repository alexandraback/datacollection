import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

import commons.FileUtilities;

public class Diamond {
    public static void main(String[] args) throws IOException {

        List<String> cases = FileUtilities.readFile(new File(
                "A-large.in"));

        int nrCases = new Scanner(cases.get(0)).nextInt();
        List<String> result = new LinkedList<String>();

        
        
        int line = 0;
        
        for (int i = 1; i <= nrCases; i++) {
            HashMap<Integer, Node> graph = new HashMap<Integer, Node>();
            
            line++;
            Scanner s = new Scanner(cases.get(line));

            int N = s.nextInt();

            for (int j = 1; j <= N; j++) {
                line++;
                Scanner s1 = new Scanner(cases.get(line));
                
                int inherits = s1.nextInt();

                Node n = new Node();
                n.number = j;
                n.inherits = new LinkedList<Integer>();
                n.inheritedFrom = new HashSet<Integer>();
                for (int k = 0; k < inherits; k++) {
                    n.inherits.add(s1.nextInt());
                }
                graph.put(n.number, n);
            }
            in:
            {
                for (Node n : graph.values()) {

                    Queue<Node> q = new LinkedList<Node>();
                    for (int inh : n.inherits) {
                        q.offer(graph.get(inh));
                        if (!(graph.get(inh).inheritedFrom.add(n.number))) {
                            result.add("Yes");
                            break in;
                        }
                    }

                    while (!q.isEmpty()) {
                        Node n1 = q.poll();
                        for (int inh : n1.inherits) {
                            q.offer(graph.get(inh));
                            if (!(graph.get(inh).inheritedFrom.add(n.number))) {
                                result.add("Yes");
                                break in;
                            }
                        }
                    }
                }
                result.add("No");
            }
        }
        FileUtilities.writeFile(result, new File("A-large.out"));
    }

    public static class Node {
        public int number;
        public List<Integer> inherits;
        public Set<Integer> inheritedFrom;
    }
}
