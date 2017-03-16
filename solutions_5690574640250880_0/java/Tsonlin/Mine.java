import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class Mine {
    static class Grid {
        protected int x, y;
        public Grid(int i, int j) { x = i; y = j; }
        // public String toString() { return "(" + x + "," + y + ")"; }
    }
    
    static char[][] board;
    static int R, C, M, B;
    static int opened;
    
    public static void main(String[] args)
    {
        int T, t;
        boolean solved;
        
        Scanner cin = new Scanner(System.in);
        T = cin.nextInt();
        for (t = 1; t <= T; t++)
        {
            R = cin.nextInt();
            C = cin.nextInt();
            M = cin.nextInt();
            B = R * C - M;
            
            board = new char[R][C];
            
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    board[i][j] = '*';
                }
            }
            
            solved = false;
            opened = 0;
            
            if (B == 1)
            {
                solved = true;
                board[0][0] = 'c';
            }
            else 
            {
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        open(i, j);
                        if (solve(i, j))
                        {
                            solved = true;
                            board[i][j] = 'c';
                            break;
                        }
                        close(i, j);
                    }
                    if (solved) break;
                }
            }
            
            System.out.printf("Case #%d:\n", t);
            if (solved)
            {
                for (int i = 0; i < R; i++)
                {
                    System.out.println(board[i]);
                }
            }
            else
            {
                System.out.println("Impossible");
            }
        }
    }
    
    public static boolean solve(int x, int y)
    {
        Queue<Grid> adj = adjOf(x, y);
        int n = adj.size();
        
        if (n == 0) return false;
        if (opened + n > B)  return false;
        
        for (Grid g : adj)
        {
            open(g.x, g.y);
        }
        
        if (opened == B) return true;
        
        for (Grid g : adj)
        {
            if (solve(g.x, g.y)) return true;
        }
        
        for (Grid g : adj)
        {
            close(g.x, g.y);
        }
        return false;
    }
    
    public static Queue<Grid> adjOf(int x, int y)
    {
        Queue<Grid> q = new LinkedList<Grid>();
        
        if (x > 0) 
        {
            if (board[x-1][y] == '*')              q.add(new Grid(x-1, y));
            if (y > 0   && board[x-1][y-1] == '*') q.add(new Grid(x-1, y-1));
            if (y < C-1 && board[x-1][y+1] == '*') q.add(new Grid(x-1, y+1));
        }
        
        if (y > 0   && board[x][y-1] == '*') q.add(new Grid(x, y-1)); 
        if (y < C-1 && board[x][y+1] == '*') q.add(new Grid(x, y+1));
        
        if (x < R-1)
        {
            if (board[x+1][y] == '*')              q.add(new Grid(x+1, y));
            if (y > 0   && board[x+1][y-1] == '*') q.add(new Grid(x+1, y-1));
            if (y < C-1 && board[x+1][y+1] == '*') q.add(new Grid(x+1, y+1));
        }
        
        return q;
    }
    
    public static void open(int x, int y)
    {
        board[x][y] = '.';
        opened++;
    }
    
    public static void close(int x, int y)
    {
        board[x][y] = '*';
        opened--;
    }
}
