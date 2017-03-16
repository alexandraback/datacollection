
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {
    public static void main(String[] args) throws Exception {
//        InputStream in = System.in;
        InputStream in = new FileInputStream("/home/floris/Downloads/C-large.in");
        System.setOut(new PrintStream("/home/floris/temp/codejam2014/src/C.out"));
        Scanner sc = new Scanner(in);

//        for (int cse = 0, cases = 10*2-1; cse <= cases; cse++) {
        for (int cse = 1, cases = sc.nextInt(); cse <= cases; cse++) {
            int rows = sc.nextInt();
            int cols = sc.nextInt();
            int mines = sc.nextInt();

            System.out.printf("Case #%d:%n", cse);
            int[][] field = new int[rows][cols];
            field[0][0]=2;
            if (rows == 1) {
                for (; mines>0; mines--) field[0][cols-mines] = 1;
            } else if (cols==1) {
                for (; mines>0; mines--) field[rows-mines][0] = 1;
            } else if (rows == 2) {
                if ((mines % 2 == 1 ||mines>=rows*cols-3)&& mines != rows*cols-1) {System.out.println("Impossible"); continue;}
                if (mines % 2 == 1) field[1][0] = 1;
                for (int c = cols-1; c>cols-1-mines/2; c--) field[0][c] = field[1][c] = 1;
            } else if (cols == 2) {
                if ((mines % 2 == 1 ||mines>=rows*cols-3) && mines != rows*cols-1) {System.out.println("Impossible"); continue;}
                if (mines % 2 == 1) field[0][1] = 1;
                for (int r = rows-1; r>rows-1-mines/2; r--) field[r][0] = field[r][1] = 1;
            } else {

                if (rows > cols) {
                    int x = mines/cols;
                    for (int r = rows-1; r >= Math.max(rows-x, 3); r--) {
                        for (int c = 0; c < cols; c++) {field[r][c]=1; mines--;}
                    }
                    rows = Math.max(rows-x, 3);
                } else {
                    int x = mines/rows;
                    for (int c = cols-1; c >= Math.max(cols-x, 3); c--) {
                        for (int r = 0; r < rows; r++) {field[r][c]=1; mines--;}
                    }
                    cols = Math.max(cols-x, 3);
                }
                if (rows > cols) {
                    int x = mines/cols;
                    for (int r = rows-1; r >= Math.max(rows-x, 3); r--) {
                        for (int c = 0; c < cols; c++) {field[r][c]=1; mines--;}
                    }
                    rows = Math.max(rows-x, 3);
                } else {
                    int x = mines/rows;
                    for (int c = cols-1; c >= Math.max(cols-x, 3); c--) {
                        for (int r = 0; r < rows; r++) {field[r][c]=1; mines--;}
                    }
                    cols = Math.max(cols-x, 3);
                }
                if (rows == 3 && cols == 3) {
                    switch (mines) {
                        case 0: break;
                        case 1: field[2][2] = 1; break;
                        case 3: field[2][0] = 1; field[2][1] = 1; field[2][2] = 1; break;
                        case 5: field[2][0] = 1; field[2][1] = 1; field[2][2] = 1; field[0][2] = 1; field[1][2] = 1; break;
                        case 8: field[1][1] = 1; field[0][1] = 1; field[1][0] = 1; field[2][0] = 1; field[2][1] = 1; field[2][2] = 1; field[0][2] = 1; field[1][2] = 1; break;
                        default:
                            System.out.println("Impossible"); continue;
                    }
                } else if (rows== cols && mines == rows-1) {
                    for (int i = 0; i < mines-1; ++i) {
                        field[rows-1-i][cols-1] = 1;
                    }
                    field[rows-1][cols-2] = 1;
                } else {
                    if (rows>cols) {
                        for (int i = 0; i< mines; ++i) {
                            field[rows-1-i][cols-1] = 1;
                        }
                    } else {
                        for (int i = 0; i< mines; ++i) {
                            field[rows-1][cols-1-i] = 1;
                        }
                    }
                }
            }
            printField(field);
        }
    }

    private static void printField(int[][] field) {
        for (int r = 0; r < field.length; r++) {
            for (int c = 0; c <field[r].length; c++) {
                switch (field[r][c]) {
                    case 0: System.out.print("."); break;
                    case 1: System.out.print("*"); break;
                    case 2: System.out.print("c"); break;
                }
            }
            System.out.println();
        }
    }
    private static int countMines(int[][] field, int r, int c) {
        int x = 0;
        if (hasMine(field, r-1, c, false)) x++;
        if (hasMine(field, r-1, c-1, false)) x++;
        if (hasMine(field, r, c-1, false)) x++;
        return x;
    }

    private static boolean hasMine(int[][] field, int r, int c, boolean edgeismine) {
        if (r <0 || r>=field.length) return edgeismine;
        if (c <0 || c >= field[0].length) return edgeismine;
        return field[r][c]!=0;
    }
}
