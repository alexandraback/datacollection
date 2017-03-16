
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Karim
 */
public class MinesweeperMaster {

    public static int[][] board;
    public static int R, C, M, MM, REMAIN;
    public static int XX = -1, YY = -1;
    public static boolean end = false;

    public static void createBoard(int x, int y) {
        if (MM == 0) {
            // first permutation of the board
//            printBoard();
            start();
            return;
        }
        int temp = y;
        for (int i = x; i < R; i++) {
            for (int j = temp; j < C; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 9;
                    MM--;
                    createBoard(i, j + 1);
                    if (end) {
                        break;
                    }
                    MM++;
                    board[i][j] = 0;
                }
            }
            if (end) {
                break;
            }
            temp = 0;
        }
    }

    public static void start() {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] != 9) {
                    // this is the start cell
                    int[][] newBoard = copy(board);
//                    System.out.println("first call ");
//                    printBoard();
                    open(i, j);
//                    System.out.println("After call");
//                    printBoard();
//                    System.out.println("Remain="+REMAIN);
                    if (REMAIN == 0) {
                        XX = i;
                        YY = j;
                        end = true;
                        board = copy(newBoard);
                        break;
                    } else {
                        REMAIN = (R * C) - M;
//                        System.out.println("NEW BOARD");
//                        for (int x=0;x<R;x++){
//                            for (int y=0;y<C;y++){
//                                System.out.print(newBoard[x][y]+" ");
//                            }
//                            System.out.println("");
//                        }
                        board = copy(newBoard);
                    }
                }
            }
            if (end) {
                break;
            }
        }
    }

    public static int[][] copy(int[][] old){
        int[][] newBoard=new int[R][C];
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++){
                newBoard[i][j]=old[i][j];
            }
        }
        return newBoard;
    }
    
    public static void open(int i, int j) {
        if (i < 0 || i >= R || j < 0 || j >= C) {
            // stop here
            return;
        }
        if (available(i, j) == true) {
            if (board[i][j] != -1) {
                REMAIN--;
                board[i][j] = -1;
                open(i, j - 1);
                open(i, j + 1);
                open(i - 1, j);
                open(i + 1, j);
                open(i - 1, j - 1);
                open(i - 1, j + 1);
                open(i + 1, j - 1);
                open(i + 1, j + 1);
            } else {
                //already opened before
            }

        } else {
            if (board[i][j] != -1) {
                REMAIN--;
                board[i][j] = -1;
            }
        }
    }

    public static boolean available(int i, int j) {
        try {
            if (board[i][j + 1] == 9) {
                return false;
            }
        } catch (Exception e) {
        }
        try {
            if (board[i][j - 1] == 9) {
                return false;
            }
        } catch (Exception e) {
        }
        try {
            if (board[i - 1][j] == 9) {
                return false;
            }
        } catch (Exception e) {
        }
        try {
            if (board[i + 1][j] == 9) {
                return false;
            }
        } catch (Exception e) {
        }
        try {
            if (board[i - 1][j - 1] == 9) {
                return false;
            }
        } catch (Exception e) {
        }
        try {
            if (board[i - 1][j + 1] == 9) {
                return false;
            }
        } catch (Exception e) {
        }
        try {
            if (board[i + 1][j - 1] == 9) {
                return false;
            }
        } catch (Exception e) {
        }
        try {
            if (board[i + 1][j + 1] == 9) {
                return false;
            }
        } catch (Exception e) {
        }
        return true;
    }

    public static void printBoard() {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println("");
        }
        System.out.println("");
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner r = new Scanner(new File("C-small.in"));
        PrintWriter out = new PrintWriter("C-small.out");
//        Scanner r = new Scanner(System.in);
        int T = r.nextInt();
        for (int i = 0; i < T; i++) {
            R = r.nextInt();
            C = r.nextInt();
            M = r.nextInt();
            MM = M;
            REMAIN = (R * C) - M;
            board = new int[R][C];
            end = false;
            XX = -1;
            YY = -1;
            createBoard(0, 0);
//            board=new int[][]{{9},
//                              {0},
//                              {0}
//                               };
//            open(2,0);
//            start();
//            System.out.println("REMAIN="+REMAIN);
            if (XX != -1 && YY != -1) {
//                System.out.println("Case #"+(i+1)+":");
                out.println("Case #" + (i + 1) + ":");
                for (int x = 0; x < R; x++) {
                    for (int y = 0; y < C; y++) {
                        if (x == XX && y == YY) {
//                            System.out.print("c");
                            out.print("c");
                        } else if (board[x][y] == 9) {
//                            System.out.print("*");
                            out.print("*");
                        } else {
//                            System.out.print(".");
                            out.print(".");
                        }
                    }
                    out.println("");
//                    System.out.println("");
                }
            } else {
//                System.out.println("Case #"+(i+1)+":");
//                System.out.println("Impossible");
                out.println("Case #" + (i + 1) + ":");
                out.println("Impossible");
            }
            out.flush();
        }
    }
}
