import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

/**
 * Created by wagner on 04/16/16.
 */
public class BFF {
    public static void main(String[] args) throws FileNotFoundException {
        File file = new File(args[0]);
        Scanner scanner = new Scanner(file);
        int nCases = scanner.nextInt();
        for(int i = 1; i <= nCases; i++) {
            int nChildren = scanner.nextInt();
            int[] bffGraph = new int[nChildren];
            Map<Integer, List<Integer>> bffFrom = new HashMap<>(nChildren);
            for(int j = 0; j < nChildren; j++) {
                bffFrom.put(j, new ArrayList<>());
            }
            for(int j = 0; j < nChildren; j++) {
                int childIndex = scanner.nextInt() - 1;
                bffGraph[j] = childIndex;
                bffFrom.get(childIndex).add(j);
            }

            int max = 0;
            for(int j = 0; j < nChildren && max < nChildren; j++) {
                boolean[] visited = new boolean[nChildren];
                int current = j;
                int pathsize = 0;
                while(!visited[current]) {
                    visited[current] = true;
                    pathsize++;
                    current = bffGraph[current];
                }
                if(current == j){
                    if(pathsize > max) {
                        max = pathsize;
                    }
                } else if(bffGraph[bffGraph[current]] == current) {
                    if(bffFrom.get(bffGraph[current]).size() > 1 && pathsize < nChildren && pathsize + 1 > max) {
                        max = pathsize + 1;
                    } else if(pathsize > max) {
                        max = pathsize;
                    }
                }
            }
            System.out.println("Case #" + i + ": " + max);
        }

    }
}
