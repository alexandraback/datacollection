import java.io.*;
import java.util.*;

public class Diamond {

    public static void main (String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new FileReader (args[0]));
        FileWriter output = new FileWriter("diamondOutput.txt");
        int numTests = Integer.parseInt(input.readLine());

        for (int test = 1; test <= numTests; test++) {
            boolean found = false;
            output.write("Case #" + test + ": ");
            int numClasses = Integer.parseInt(input.readLine());

            boolean[][] adjMatrix = new boolean[numClasses][numClasses];

            for (int i = 0; i < numClasses; i++) {
                String[] inheritsFrom = input.readLine().split(" ");
                for (int j = 1; j < inheritsFrom.length; j++) {
                    int other = Integer.parseInt(inheritsFrom[j]);
                    adjMatrix[i][other - 1] = true;
                }
            }

            for (int i = 0; i < numClasses; i++) {
                if (dfsCheck(adjMatrix, i)) {
                    output.write("Yes\n");
                    found = true;
                    break;
                }
            }
            if (!found) {
                output.write("No\n");
            }
        }
        output.flush();
    }

    public static boolean dfsCheck (boolean[][] matrix, int vertex) {
        boolean[] visited = new boolean[matrix.length];
        Stack<Integer> s = new Stack<Integer>();
        s.push(vertex);
        while(!s.isEmpty()) {
            int curr = s.pop();
            if (visited[curr]) {
                return true;
            }
            visited[curr] = true;
            for (int next = 0; next < matrix.length; next++) {
                if (matrix[curr][next]) {
                    s.push(next);
                }
            }
        }
        return false;
    }
}
