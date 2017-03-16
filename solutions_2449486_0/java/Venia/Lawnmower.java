public class Lawnmower {


    static boolean possibleQ(int grid [][]) {
        for (int i=0; i<grid.length; i++)
            for (int j=0; j<grid[0].length; j++)
                if (!possibleQ(grid, i, j)) return false;

        return true;
    }

    static boolean possibleQ(int [][] grid, int x, int y) {
        int axy = grid[x][y];
        boolean OK = true;
        for (int i=0; i<grid[0].length; i++)
            if (axy < grid[x][i]) {
                OK = false;
                break;
            }
        if (OK) return true;
        OK = true;
        for (int i=0; i<grid.length; i++)
            if (axy < grid[i][y]) {
                OK = false;
                break;
            }
        return OK;
    }

    public static void main(String [] argv) {
        Kattio io = new Kattio(System.in, System.out);
        int T = io.getInt();
        for (int test = 0; test< T; test++) {
            int N = io.getInt();
            int M = io.getInt();
            int grid [][]  = new int [N][M];
            for (int n = 0; n<N; n++)
                for (int m=0; m<M; m++)
                    grid[n][m] = io.getInt();
            io.println("Case #" + (test+1) + (possibleQ(grid) ? ": YES" : ": NO"));
        }
        io.close();
    }
}
