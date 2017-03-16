import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

public class TicTacToeTomek {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("A-large.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("output.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TicTacToeTomek solver = new TicTacToeTomek();
        solver.solve(1, in, out);
        out.close();
    }
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int t=in.nextInt();

        for(int j=0;j<t;j++){

            out.print("Case #"+(j+1)+": ");
            String board[]=new String[4];
            for(int i=0;i<4;i++){
                board[i]=in.next();
            }
            if(isCharWin(board,'X')){
                out.println("X won");
            }
            else if(isCharWin(board,'O')){
                out.println("O won");
            }
            else {
                if(isDraw(board)){
                    out.println("Draw");
                }
                else{
                    out.println("Game has not completed");
                }
            }
        }

    }

    public boolean isCharWin(String board[],char ch){
        boolean isWin=false;
        //row
        out:for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length();j++){
                if(board[i].charAt(j)==ch||board[i].charAt(j)=='T'){
                    continue ;
                }
                else{
                    continue out;
                }
            }
            isWin=true;
            break ;
        }
        //column
        out:for(int i=0;i<board[0].length();i++){
            for(int j=0;j<board.length;j++){
                if(board[j].charAt(i)==ch||board[j].charAt(i)=='T'){
                    continue;
                }
                else{
                    continue out;
                }
            }
            isWin=true;
            break ;
        }
        int d=0;
        //first diagonal
        for(int i=0;i<board.length;i++){
            if(board[i].charAt(i)==ch||board[i].charAt(i)=='T'){
                d++;
            }
        }
        if(d==board.length){
           isWin=true;
        }
        //second
        d=0;
        for(int i=0;i<board.length;i++){
            if(board[i].charAt(board.length-i-1)==ch||board[i].charAt(board.length-i-1)=='T'){
                d++;
            }
        }
        if(d==board.length){
            isWin=true;
        }
        return isWin;
    }

    public boolean isDraw(String board[]){
        for (int i=0;i<board.length;i++){
            if(board[i].contains("."))return false;
        }
        return true;
    }
}

