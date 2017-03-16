package googleContest.Jam2015;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class MineSweeper {

    private static final int MINE = 1;
    private static final int CURSOR = 2;
    public static void main(String[] args) throws FileNotFoundException {
        System.setOut(new PrintStream(args[0]+".out"));
        new MineSweeper().solve(args);
    }
    private int mines;
    private int cols;

    private int rows;
    private void checkMinesCount(int orig_mines, int[][] mat) {
        int count=0;
        for (int r=0;r<rows;r++) {
            for (int c=0; c<cols;c++)
                if (mat[r][c]==MINE)
                    count++;
        }
        if (count!=orig_mines)
            throw new IllegalArgumentException("Mat has more mines then original");
    }

    private void fillCol(int[][] mat, int row, int col) {
        for (int i=row;i<rows;i++) {
            mat[i][col]=MINE;
            if (--mines<=0)
                break;
        }
    }
    private void fillRow(int[][] mat, int row,int col) {
        for (int j=col;j<cols;j++) {
            mat[row][j]=MINE;
            if (--mines<=0)
                break;
        }
    }
    private void printMat(int[][] mat) {
        for (int r = 0;r<rows;r++) {
            for (int c = 0 ; c<cols;c++) {
                if (mat[r][c]==0)
                    System.out.print(".");
                else if (mat[r][c]==MINE)
                    System.out.print("*");
                else
                    System.out.print("c");
            }
            System.out.println();
        }
    }

    /**
     * solve the given riddle
     * first read the amount of riddles in the data, then solve each of it
     * @param scanner to read the input data from
     */
    public void solve(Scanner scanner) {
        int numCases = scanner.nextInt();
        for (int i = 1; i <= numCases; i++) {
            System.out.print("Case #" + i + ": ");
            solveCase(scanner);
        }
    }

    /**
     * solve the given riddle
     * if the args array is not empty, get the input data file from the first value
     * otherwise read the input data from the stdin
     * @param args
     */
    public void solve(String[] args) throws FileNotFoundException {
        InputStream is;
        if (args.length > 0)
            is = new BufferedInputStream(new FileInputStream(args[0]));
        else
            is = System.in;
        Scanner scanner = new Scanner(is);
        solve(scanner);
    }

    /**
     * solve a given case of the underlying riddle
     * @param scanner to get the input data from
     */
    public void solveCase(Scanner scanner) {
        rows = scanner.nextInt();
        cols = scanner.nextInt();
        mines = scanner.nextInt();
        int orig_mines = mines;
        int[][] mat = new int[rows][cols];
        int row = 0;
        int col = 0;
        while (mines>0) {
            int rowsLeft = rows-row;
            int colsLeft = cols-col;
            if (mines<rowsLeft && mines<colsLeft) {
                //fill row first leaving the last two spaces
                if (row<rows-2) {
                    for (int c = col; c<cols-2;c++) {
                        mat[row][c]=MINE;
                        if (--mines<=0)
                            break;
                    }
                }
                //then fill column
                if (col<cols-2) {
                    if (mines<=0)
                        break;
                    for (int r = row+1; r<rows-2;r++) {
                        mat[r][col]=MINE;
                        if (--mines<=0)
                            break;
                    }
                }
                break;
            }
            if (rowsLeft<colsLeft) {
                fillCol(mat,row,col);
                col++;
            }
            else {
                fillRow(mat,row,col);
                row++;
            }
        }
        mat[rows-1][cols-1]=CURSOR;
        System.out.println();
        if (orig_mines!=rows*cols-1 && ((row>=rows-1 && rows>=2) || (col>=cols-1 && cols>=2) || mines>0)) {
            System.out.println("Impossible");
        }
        else {
            checkMinesCount(orig_mines,mat);
            printMat(mat);
        }
    }
}
