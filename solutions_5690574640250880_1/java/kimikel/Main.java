
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
    
    public static void main(String args[]) throws FileNotFoundException {
        
        final Scanner in = new Scanner(new File("/home/mikel/Desktop/codejam/input.txt"));
        final PrintWriter out = new PrintWriter(new File("/home/mikel/Desktop/codejam/output.txt"));
        
        final int t = in.nextInt();
        for (int it = 1; it <= t; it++) {
            
            
            final int r = in.nextInt();
            final int c = in.nextInt();
            final int m = in.nextInt();
            
            /*int remainingMines = m;
            final boolean grid[][] = new boolean[r][c];
            
            int putRows = 0;
            for (int i = 0; i < r-3; i++) {
                if (c < remainingMines) {
                    for (int j = 0; j < c; j++) {
                        grid[i][j] = true;
                        remainingMines--;
                    }
                    putRows++;
                }
            }
            
            int putColumns = 0;
            for (int j = 0; j < c-3; j++) {
                if (r-putRows < remainingMines) {
                    for (int i = putRows; i < r; i++) {
                        grid[i][j] = true;
                        remainingMines--;
                    }
                    putColumns++;
                }
            }*/
            
            final boolean[][] grid = solve(r, c, m);
            
            out.println("Case #" + it + ":");
            if (grid != null) {
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if (i == r-1 && j == c-1) out.print("c");
                        else if (grid[i][j]) out.print("*");
                        else out.print(".");
                    }
                    out.println();
                }
            } else {
                out.println("Impossible");
            }
        }
        
        out.close();
    }
    
    private static boolean[][] solve(int r, int c, int m) {
        for (int rows = 0; rows < r; rows++) {
            if (rows*c <= m) {
                final boolean[][] res = solve(r, c, m, rows);
                if (res != null) return res;
            }
        }
        return null;
    }
    
    private static boolean[][] solve(int r, int c, int m, int rows) {
        for (int columns = 0; columns < c; columns++) {
            if (rows*c+columns*r-rows*columns <= m) {
                final boolean[][] res = solve(r, c, m, rows, columns);
                if (res != null) return res;
            }
        }
        return null;
    }
    
    private static boolean[][] solve(int r, int c, int m, int rows, int columns) {
        final int put = rows*c+columns*r-rows*columns;
        final int remaining = m - put;
        
        if (remaining == 0) {
            final boolean grid[][] = new boolean[r][c];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < c; j++) {
                    grid[i][j] = true;
                }
            }
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < columns; j++) {
                    grid[i][j] = true;
                }
            }
            if (validate(r, c, m, grid)) return grid;
        } else {
            for (int extraRows = 0; extraRows <= r-rows-2 && extraRows <= remaining-1; extraRows++) {
                final boolean[][] res = solve(r, c, m, rows, columns, extraRows);
                if (res != null) return res;
            }
        }
        return null;
        //final int considering = (r-rows)+(c-columns)-1;
    }
    
    private static boolean[][] solve(int r, int c, int m, int rows, int columns, int extraRows) {
        final int put = rows*c+columns*r-rows*columns+1+extraRows;
        final int extraColumns = m-put;
        if (extraColumns > c-columns-2) return null;
        
        boolean[][] grid = new boolean[r][c];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < c; j++) {
                grid[i][j] = true;
            }
        }
        for (int i = 0; i < rows+extraRows+1; i++) grid[i][columns] = true;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < columns; j++) {
                grid[i][j] = true;
            }
        }
        for (int j = 0; j < columns+extraColumns+1; j++) grid[rows][j] = true;
        if (validate(r, c, m, grid)) return grid;
        return null;
    }
    
    private static boolean validate(int r, int c, int m, boolean[][] grid) {
        int mines = 0;
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) if (grid[i][j]) mines++;
        if (mines != m) throw new RuntimeException("Txanboi galanta!");
        
        final boolean[][] clean = new boolean[r][c];
        final int cleaned = clean(r, c, grid, clean, 0, r-1, c-1);
        
        System.err.println(cleaned);
        
        return cleaned+m == r*c;
    }
    
    private static int clean(int r, int c, boolean[][] grid, boolean[][] clean, int count, int i, int j) {
        if (out(r, c, i, j) || clean[i][j]) return count;
        
        clean[i][j] = true;
        count++;
        
        if (safe(r, c, grid, i-1, j-1) && 
                safe(r, c, grid, i-1, j) && 
                safe(r, c, grid, i-1, j+1) && 
                safe(r, c, grid, i, j-1) && 
                safe(r, c, grid, i, j+1) && 
                safe(r, c, grid, i+1, j-1) && 
                safe(r, c, grid, i+1, j) && 
                safe(r, c, grid, i+1, j+1)) {
            count = clean(r, c, grid, clean, count, i-1, j-1);
            count = clean(r, c, grid, clean, count, i-1, j);
            count = clean(r, c, grid, clean, count, i-1, j+1);
            count = clean(r, c, grid, clean, count, i, j-1);
            count = clean(r, c, grid, clean, count, i, j+1);
            count = clean(r, c, grid, clean, count, i+1, j-1);
            count = clean(r, c, grid, clean, count, i+1, j);
            count = clean(r, c, grid, clean, count, i+1, j+1);
        }
        
        return count;
    }
    
    private static boolean safe(int r, int c, boolean[][] grid, int i, int j) {
        return out(r, c, i, j) || !grid[i][j];
    }
    
    private static boolean out(int r, int c, int i, int j) {
        return i >= r || j >= c || i < 0 || j < 0;
    }
    
}
