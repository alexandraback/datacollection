package qual2014;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class C {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("qual2014/C-sample.in"), System.out);
        io = new Kattio(new FileInputStream("qual2014/C-small-0.in"), new FileOutputStream("qual2014/C-small-0.out"));
//        io = new Kattio(new FileInputStream("qual2014/C-large-0.in"), new FileOutputStream("qual2014/C-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new C().solve(io);
        }
        io.close();
    }

    int xsize, ysize, mines;
    boolean field[][], done[][];
    int revealed = 0;

    private void click(int x, int y) {
        if (done[y][x]) return;
        revealed++;
        done[y][x] = true;
        boolean neighborHasMine = false;
        for(int dy=-1;dy<=1;dy++)
            for(int dx=-1;dx<=1;dx++) {
                if (dy == 0 && dx == 0)
                    continue;
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= xsize || ny >= ysize)
                    continue;
                neighborHasMine |= field[ny][nx];
            }
        if (!neighborHasMine) {
            for(int dy=-1;dy<=1;dy++)
                for(int dx=-1;dx<=1;dx++) {
                    if (dy == 0 && dx == 0)
                        continue;
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= xsize || ny >= ysize)
                        continue;
                    click(nx, ny);
                }
        }
    }

    private boolean generate(int x, int y, int minesLeft, int freeLeft) {
        if (x == xsize) {
            return generate(0, y+1, minesLeft, freeLeft);
        }
        if (minesLeft < 0 || freeLeft < 0) return false;
        if (y==ysize) {
            if (minesLeft != 0 || freeLeft != 0) {
                throw new RuntimeException();
            }
            done = new boolean[ysize][xsize];
            revealed = 0;
            click(0,0);
            return revealed == xsize*ysize-mines;
        }
        field[y][x] = false;
        if (generate(x+1, y, minesLeft, freeLeft-1)) return true;
        field[y][x] = true;
        return (generate(x+1, y, minesLeft-1, freeLeft));
    }

    private void solve(Kattio io) {
        ysize = io.getInt();
        xsize = io.getInt();
        mines = io.getInt();

        field = new boolean[ysize][xsize];

        io.println();
        if (generate(1,0,mines,xsize*ysize-mines-1)) {
            for (int y = 0; y < ysize; y++) {
                for (int x = 0; x < xsize; x++) {
                    if (x==0 && y == 0) io.print("c");
                    else if (field[y][x]) io.print("*");
                    else io.print(".");
                }
                io.println();
            }
        } else {
            io.println("Impossible");
        }
        io.flush();
    }
}
