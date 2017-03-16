import java.util.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        int taskCount = scan.nextInt();
        scan.nextLine();
        for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
            int H = scan.nextInt();
            int W = scan.nextInt();
            int[][] map = new int[H][W];
            int[] row = new int[H];
            int[] col = new int[W];
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    map[i][j] = scan.nextInt();
                    row[i] = Math.max(row[i], map[i][j]);
                    col[j] = Math.max(col[j], map[i][j]);
                }
            }
            boolean pass = true;
            outer:
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (map[i][j] != Math.min(row[i], col[j])) {
                        pass = false;
                        break outer;
                    }
                }
            }
            System.out.println(String.format("Case #%d: %s", taskIndex, pass ? "YES" : "NO"));
        }
    }
}
