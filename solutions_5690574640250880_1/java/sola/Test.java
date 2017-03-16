package test5;
import java.io.*;
import java.util.*;

public class Test {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    
    static Cell[][] b;
    static int mines;
    public static void main (String[] args) throws IOException {

        //generateInput(150);
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "test.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "test.out"));

        int tc = sc.nextInt();
        
        for (int tci=1;tci<=tc;tci++) {
            int R = sc.nextInt();
            int C = sc.nextInt();
            int M = sc.nextInt();
            
            b = new Cell[R][C];
            for (int i=0;i<R;i++) {
                for (int j=0;j<C;j++) {
                    b[i][j] = new Cell();
                }
            }
            for (int r=0;r<R;r++) {
                for (int c=0;c<C;c++) {
                    b[r][c].mine = true;
                    List<Cell> l = new LinkedList<Cell>();
                    if (checkValid(r-1,c-1,b.length,b[0].length)) {
                        l.add(b[r-1][c-1]);
                    }
                    if (checkValid(r-1,c,b.length,b[0].length)) {
                        l.add(b[r-1][c]);
                    }
                    if (checkValid(r-1,c+1,b.length,b[0].length)) {
                        l.add(b[r-1][c+1]);
                    }
                    if (checkValid(r,c-1,b.length,b[0].length)) {
                        l.add(b[r][c-1]);
                    }
                    if (checkValid(r,c+1,b.length,b[0].length)) {
                        l.add(b[r][c+1]);
                    }
                    if (checkValid(r+1,c-1,b.length,b[0].length)) {
                        l.add(b[r+1][c-1]);
                    }
                    if (checkValid(r+1,c,b.length,b[0].length)) {
                        l.add(b[r+1][c]);
                    }
                    if (checkValid(r+1,c+1,b.length,b[0].length)) {
                        l.add(b[r+1][c+1]);
                    }
                    b[r][c].adjCells = l;
                    b[r][c].adjMines = b[r][c].adjCells.size();
                    b[r][c].added = false;
                    b[r][c].r = r;
                    b[r][c].c = c;
                }
            }
            
            mines = R*C;
            List<Cell> q = new LinkedList<Cell>();
            // click the corner
            b[0][0].mine = false;
            for (Cell c:b[0][0].adjCells) {
                c.adjMines--;
            }
            mines--;
            // TODO
            q.add(b[0][0]);
            b[0][0].added = true;
            while (mines>M) {
                int diff = mines - M;
                int max = 0;
                Cell cur = null;
                Cell cur2 = null;
                for (Cell c:q) {
                    if (c.adjMines==diff) {
                        cur = c;
                        break;
                    }
                    else if (c.adjMines>diff) {
                        continue;
                    }
                    else {
                        if (diff-c.adjMines>1) {
                            if (c.adjMines>max) {
                                max = c.adjMines;
                                cur = c;
                            }
                        }
                        else {
                            cur2 = c;
                        }
                    }
                }
                if (cur==null) {
                    cur = cur2;
                }
                if (cur!=null) {
                    expand(cur);
                    for (Cell c:cur.adjCells) {
                        if (c.added==false) {
                            q.add(c);
                            c.added = true;
                        }
                    }
                    q.remove(cur);
                }
                else {
                    break;
                }
            }
            pw.println("Case #" + tci + ":");
            if (mines==M) {
                for (int r=0;r<R;r++) {
                    for (int c=0;c<C;c++) {
                        if (r==0&&c==0) {
                            pw.print("c");
                        }
                        else {
                            pw.print(b[r][c].mine?"*":".");
                        }
                    }
                    pw.println();
                }
            }
            else {
                pw.println("Impossible");
            }
        }
        pw.close();
        sc.close();
    }

    static class Cell {
        int r,c;
        boolean mine;
        int adjMines;
        List<Cell> adjCells;
        boolean added;
    }
    
    static void expand (Cell cell) {
        assert(cell.mine==false);
        for (Cell c:cell.adjCells) {
            if (c.added==false) {
                c.mine = false;
                for (Cell c2:c.adjCells) {
                    c2.adjMines--;
                }
                mines--;
            }
        }
    }
    
    //static void printBoard
    
    static boolean checkValid (int r, int c, int R, int C) {
        if (r>=0 && r<R && c>=0 && c<C)
            return true;
        else
            return false;
    }
    
    public static void generateInput(int tc) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "test.in"));
        pw.println(tc);
        Random rd = new Random();
        for (int tci = 1; tci <= tc; tci++) {
            int R = rd.nextInt(50)+1;
            int C = rd.nextInt(50)+1;
            int M = rd.nextInt(R*C);
            pw.println(R+" "+C+" "+M);
        }
        pw.close();
    }
}

