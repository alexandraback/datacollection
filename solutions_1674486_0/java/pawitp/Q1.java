import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


public class Q1 {
    
    private static boolean found = false;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        for (int i = 0; i < num; i++) {
            int nc = in.nextInt();
            int[][] classes = new int[nc][];
            
            for (int j = 0; j < nc; j++) {
                int np = in.nextInt();
                classes[j] = new int[np];
                for (int k = 0; k < np; k++) {
                    classes[j][k] = in.nextInt() - 1;
                }
            }
            
            System.out.println("Case #" + (i + 1) +": " + solve(classes));
        }
    }

    private static String solve(int[][] classes) {
        // Traverse each class
        found = false;
        for (int i = 0; i < classes.length; i++) {
            ArrayList<Integer> parents = new ArrayList<Integer>();
            findParents(classes, i, parents);
            if (found) break;
        }
        return found ? "Yes" : "No";
    }

    private static void findParents(int[][] classes, int i, ArrayList<Integer> parents) {
        int np = classes[i].length;
        if (np == 0) {
            if (parents.indexOf(i) != -1) {
                found = true;
                return;
            }
            parents.add(i);
        }
        // find parent of each class
        for (int j = 0; j < np; j++) {
            findParents(classes, classes[i][j], parents);
            if (found) {
                return;
            }
        }
    }
}
