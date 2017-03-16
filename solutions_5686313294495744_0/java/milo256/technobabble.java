import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class technobabble {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int lines = in.nextInt();

        for (int line = 0; line < lines; line++) {
            int papers = in.nextInt();
            HashMap<String, Integer> firstWords = new HashMap<>();
            HashMap<String, Integer> secondWords = new HashMap<>();
            int[] first = new int[papers];
            int[] second = new int[papers];
            for (int i = 0; i < papers; i++) {
                String s = in.next();
                if(!firstWords.containsKey(s))
                    firstWords.put(s, firstWords.size());
                first[i] = firstWords.get(s);
                s = in.next();
                if(!secondWords.containsKey(s)) {
                    secondWords.put(s, secondWords.size());
                }
                second[i] = secondWords.get(s);
            }

            ArrayList<Integer>[] graph = new ArrayList[firstWords.size() + secondWords.size() + 2];
            for (int i = 0; i < graph.length; i++) {
                graph[i] = new ArrayList<>();
            }
            int FIRST = 0;
            int SECOND = firstWords.size();
            int SOURCE = SECOND + secondWords.size();
            int SINK = SOURCE + 1;
            int[][] flow = new int[graph.length][graph.length];
            for (int i = 0; i < papers; i++) {
                graph[first[i]].add(SECOND + second[i]);
                flow[first[i]][SECOND + second[i]]++;
            }
            for (int i = 0; i < firstWords.size(); i++) {
                graph[SOURCE].add(FIRST + i);
                flow[SOURCE][FIRST + i] = 1;
            }
            for (int i = 0; i < secondWords.size(); i++) {
                graph[SECOND + i].add(SINK);
                flow[SECOND + i][SINK] = 1;
            }

            int ans = papers - (firstWords.size() + secondWords.size() - maxFlow(graph, flow, SOURCE, SINK)); //maxFlow is the number of double covering papers

            System.out.println("Case #" + (line + 1) + ": " + ans);
        }
    }

    private static int maxFlow(ArrayList<Integer>[] graph, int[][] flow, int source, int sink) {
        int ret = 0;
        int found = 0;
        int[][] residual = new int[flow.length][flow.length];
        do {
            boolean[] visited = new boolean[flow.length];
            visited[source] = true;
            found = recurse(graph, flow, residual, visited, Integer.MAX_VALUE, source, sink);
            ret += found;
        } while(found > 0);
        return ret;
    }

    private static int recurse(ArrayList<Integer>[] graph, int[][] flow, int[][] residual, boolean[] visited, int maxFlow, int at, int sink) {
        if(at == sink)
            return maxFlow;

        for (int i = 0; i < flow.length; i++) {
            if(visited[i])
                continue;

            if(flow[at][i] > 0) {
                visited[i] = true;
                int test = recurse(graph, flow, residual, visited, Math.min(maxFlow, flow[at][i]), i, sink);
                visited[i] = false;
                if (test > 0) {
                    flow[at][i] -= test;
                    residual[at][i] += test;
                    return test;
                }
            }
            if(residual[i][at] > 0) {
                visited[i] = true;
                int test = recurse(graph, flow, residual, visited, Math.min(maxFlow, residual[i][at]), i, sink);
                visited[i] = false;
                if (test > 0) {
                    flow[i][at] += test;
                    residual[i][at] -= test;
                    return test;
                }
            }
        }
        return 0;
    }

}
