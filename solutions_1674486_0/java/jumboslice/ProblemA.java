package round1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class ProblemA
{
    public static void main(String[] args) throws FileNotFoundException
    {
        Scanner sc = new Scanner(new File("inputs/round1c/problemA.in"));

        int numCases = sc.nextInt();

        for (int currCase = 1; currCase <= numCases; currCase++)
        {
            int n = sc.nextInt();
            boolean[][] graph = new boolean[n+1][n+1];
            LinkedList<State> queue = new LinkedList<State>();

            for (int i = 1; i <= n; i++)
            {
                int m = sc.nextInt();
                for (int j = 0; j < m; j++)
                {
                    graph[i][sc.nextInt()] = true;
                }
                
                if (m == 0)
                {
                    State start = new State();
                    start.loc = i;
                    start.path = new HashSet<Integer>();
                    queue.add(start);
                }
            }
            
            boolean isDiamond = false;
            
            while(queue.size() > 0 && !isDiamond)
            {
                isDiamond = isDiamond(graph, queue.poll());
            }


            System.out.printf("Case #%s: %s\n", currCase, isDiamond ? "Yes" : "No");
        }
    }

    private static boolean isDiamond(boolean[][] graph, State start)
    {
        LinkedList<State> queue = new LinkedList<State>();
        queue.add(start);
        HashMap<Integer, LinkedList<State>> map = new HashMap<Integer, LinkedList<State>>();
        boolean isDiamond = false;

        while (queue.size() > 0)
        {
            State curr = queue.poll();

            if (map.containsKey(curr.loc))
            {
                LinkedList<State> list = map.get(curr.loc);

                for (State s : list)
                {
                    HashSet<Integer> intersection = new HashSet<Integer>(curr.path);
                    intersection.retainAll(s.path);

                    if (intersection.size() > 0)
                    {
                        isDiamond = true;
                        break;
                    }
                }

                if (isDiamond) break;
            }
            else
            {
                map.put(curr.loc, new LinkedList<State>());
            }

            map.get(curr.loc).add(curr);

            for (int i = 0; i < graph.length; i++)
            {
                if (graph[i][curr.loc])
                {
                    State next = new State();
                    next.loc = i;
                    next.path = new HashSet<Integer>(curr.path);
                    next.path.add(curr.loc);

                    queue.add(next);
                }
            }
        }

        return isDiamond;
    }
}

class State
{
    int loc;
    HashSet<Integer> path;
}