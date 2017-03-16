
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class MinesweeperMaster {
    public static void main(String[] args) throws IOException {
        //Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
        Scanner sc = new Scanner(new File("C-small-attempt1.in"));
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int R = sc.nextInt();
            int C = sc.nextInt();
            int M = sc.nextInt();
            int j, k;
            j = k = 0;
            char [][] board = new char[R][C];
            for (int l = 0; l < R; l++) {
                Arrays.fill(board[l], '.');
            }
            int minesLeft = M;
            boolean posible = true;
            while(minesLeft>0){
                if(R-j < C-k){
                    if(minesLeft == 1 && R-j == 2){
                        posible = false;
                        break;
                    }
                    if(minesLeft >= R-j){
                        for (int l = j; l < R; l++) {
                            board[l][k] = '*';
                            minesLeft--;
                        }
                        k++;
                    }else{
                        int lowCol = k;
                        while(minesLeft > 0 && lowCol < C-2){
                            if(board[j][lowCol]!='*'){
                                board[j][lowCol] = '*';
                                minesLeft--;
                            }
                            lowCol++;
                        }
                        int lowRow = j;
                        while(minesLeft > 0 && lowRow < R-2){
                            if(board[lowRow][k]!='*'){
                                board[lowRow][k] = '*';
                                minesLeft--;
                            }
                            lowRow++;
                        }
                        if(minesLeft > 0){
                            posible = false;
                            minesLeft = 0;
                        }
                    }
                }else{
                    if(minesLeft == 1 && C-k == 2){
                        posible = false;
                        break;
                    }
                    if(minesLeft >= C-k){
                        for (int l = k; l < C; l++) {
                            board[j][l] = '*';
                            minesLeft--;
                        }
                        j++;
                    }else{
                        int lowRow = j;
                        
                        while(minesLeft > 0 && lowRow < R-2){
                            if(board[lowRow][k]!='*'){
                                board[lowRow][k] = '*';
                                minesLeft--;
                            }
                            lowRow++;
                        }
                        int lowCol = k;
                        while(minesLeft > 0 && lowCol < C-2){
                            if(board[j][lowCol]!='*'){
                                board[j][lowCol] = '*';
                                minesLeft--;
                            }
                            lowCol++;
                        }
                        if(minesLeft > 0){
                            posible = false;
                            minesLeft = 0;
                        }
                    }
                }
                
            }
            
            if(M == (R*C)-1){
                board[R-1][C-1] = 'c';
            }else if(posible){
                posible = false;
                for (int l = j; l < R; l++) {
                    for (int m = k; m < C; m++) {
                        if(board[l][m]!='*' && isZero(board, l, m, R, C)){
                            board[l][m] = 'c';
                            posible = true;
                            break;
                        }
                    }
                    if(posible)break;
                }
            }
            bw.write("Case #" + (int)(i+1) + ": ");
            bw.newLine();
            if(posible){
                for (int l = 0; l < R; l++) {
                    for (int m = 0; m < C; m++) {
                        //System.out.print(board[l][m]);
                        bw.write(board[l][m]);
                    }
                    //System.out.println("");
                    bw.newLine();
                }
            }else{
                //System.out.println("Impossible");
                bw.write("Impossible");
                bw.newLine();
            }
            
        }
        bw.close();
        
    }

    private static boolean isZero(char[][] board, int l, int m, int R, int C) {
        int count = 0;
        if(l > 0 && board[l-1][m] == '*'){
            count++;
        }
        if(l > 0 && m > 0 && board[l-1][m-1] == '*'){
            count++;
        }
        if(l > 0 && m < C-1 && board[l-1][m+1] == '*'){
            count++;
        }
        if(m > 0 && board[l][m-1] == '*'){
            count++;
        }
        if(m < C-1 && board[l][m+1] == '*'){
            count++;
        }
        if(l < R-1 && board[l+1][m] == '*'){
            count++;
        }
        if(l < R-1 && m > 0 && board[l+1][m-1] == '*'){
            count++;
        }
        if(l < R-1 && m < C-1 && board[l+1][m+1] == '*'){
            count++;
        }
        return count == 0;
    }
}
