package contests.GoogleCodeJam.GCJ2012.round1C;

import java.io.FileNotFoundException;
import java.util.*;

/**
 */
public class ProblemFirst {


    static class Pair implements Comparable<Pair> {
        public int left, right;

        public Pair(int anInt, int anInt1) {
            left = anInt;
            right = anInt1;
        }

        @Override
        public int compareTo(Pair pair) {
            if (pair.left < left)
                return 1;
            if (pair.left > left)
                return -1;

            if (pair.right < right)
                return -1;
            if (pair.right > right)
                return 1;

            return 0;
        }
    }

    public static void main(String args[]) throws FileNotFoundException {
        Scanner scanner = new Scanner(ProblemFirst.class.getResourceAsStream("a_small.in"));

        int tests = scanner.nextInt();

        for (int test = 1; test <= tests; test++) {
            int numClasses = scanner.nextInt();

            List<List<Integer>> matrix = new ArrayList<List<Integer>>();

            for(int i =0; i < numClasses; i++){

                int numInherit = scanner.nextInt();
                List<Integer> graph = new ArrayList<Integer>();

                for(int j = 0; j < numInherit; j++)
                    graph.add(scanner.nextInt()-1); // from 1 to N

                matrix.add(graph);
            }

            boolean found = false;
            for(int i = 0; i < numClasses; i++){
                if(hasDiamond(matrix, i)){
                    found = true;
                    break;
                }
            }

            System.out.println("Case #" + test + ": " + (found?"Yes":"No") );
        }

    }

    private static boolean hasDiamond(List<List<Integer>> matrix, int init) {
        Boolean [] visited = new Boolean[matrix.size()];

        for(int i = 0; i < matrix.size(); i++)
            visited[i] = false;

        Queue<Integer>  visit = new LinkedList<Integer>();

        visit.add(init);

        while(!visit.isEmpty()){
            Integer cur = visit.remove();
            if(visited[cur])
                return true;
            visited[cur] = true;

            List<Integer> neighbors = matrix.get(cur);

            visit.addAll(neighbors);
        }

        return false;
    }
}


