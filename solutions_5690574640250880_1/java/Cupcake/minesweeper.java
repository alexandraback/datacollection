import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: yilin
 * Date: 14-4-12
 * Time: 上午12:58
 * To change this template use File | Settings | File Templates.
 */

public class minesweeper {

    public static void printBoard(int r, int c, char[][] board,PrintWriter writer){
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                writer.print(board[i][j]);
            }
            writer.println();
        }
    }

    // assume x<=y;
    // 1 means okey, 0 means mine;
    public static void fillBoard(int x, int y, int m, PrintWriter writer){
        char[][] board = new char[x][y];
        for(int i =0;i<x;i++){
            for(int j =0;j<y;j++){
                board[i][j]='*';
            }
        }
        int n = x*y-m;
        if(n==1){
            board[0][0]='c';
            printBoard(x,y,board,writer);
            return;
        }
        if(x>1 && y >1){
            // multiple line board;
            int a=2;
            while(a<=x){
                int b=2;
                while(b<=y){
                    int left = n-a*b;
                    if(left == 0){
                        for(int i=0;i<a;i++){
                            for(int j=0;j<b;j++){
                                board[i][j]='.';
                            }
                        }
                        board[0][0]='c';
                        printBoard(x,y,board,writer);
                        return;
                    }
                    if(left>=2){
                        if(left<a || left <b){
                            for(int i=0;i<a;i++){
                                for(int j=0;j<b;j++){
                                    board[i][j]='.';
                                }
                            }
                            if(left<a && b<y){
                                for(int i=0;i<left;i++){
                                    board[i][b]='.';
                                }
                                board[0][0]='c';
                                printBoard(x,y,board,writer);
                                return;
                            }else if (left <b && a<x){
                                for(int j =0;j<left;j++){
                                    board[a][j]='.';
                                }
                                board[0][0]='c';
                                printBoard(x,y,board,writer);
                                return;
                            }
                        }
                    }
                    if(left ==1){
                        if(a>=3 && b>=3){
                            for(int i=0;i<a;i++){
                                for(int j=0;j<b;j++){
                                    board[i][j]='.';
                                }
                            }
                            if(a<x){
                                board[a][0]='.';
                                board[a][1]='.';
                                board[a-1][b-1]='*';
                            }else if (b<y){
                                board[0][b]='.';
                                board[1][b]='.';
                                board[a-1][b-1]='*';
                            }

                            board[0][0]='c';
                            printBoard(x,y,board,writer);
                            return;
                        }
                    }


                    b++;
                }
                a++;
            }
        }
        writer.println("Impossible") ;
        return;
    }
        public static void checkBoard(int x, int y, int m, PrintWriter writer){
        char[][] board = new char[x][y];
        //1 by 1
        int s = x*y;
        if(m==s){
            writer.println("Impossible") ;
            return;
        }
        if (x==1 && y==1){
            if (m==0){
                board[0][0]='c';
                printBoard(x,y,board,writer);
                return;
            }

        }else if(x==1 || y ==1){
            for(int i =0;i<x;i++){
                for(int j =0;j<y;j++){
                    board[i][j]='*';
                }
            }
            if(x==1){
                for(int i=0;i<y-m;i++){
                    board[0][i]='.';
                }
                board[0][0]='c';
                printBoard(x,y,board,writer);
                return;
            }else{
                for(int i=0;i<s-m;i++){
                    board[i][0]='.';
                }
                board[0][0]='c';
                printBoard(x,y,board,writer);
                return;
            }
        }else{
            fillBoard(x,y,m,writer);
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new FileReader("input"));
        PrintWriter writer = new PrintWriter("result");
        input.nextLine();
        int counter =0;




        while(input.hasNext()){
            counter++;
            int r = input.nextInt();
            int c =input.nextInt();
            int m = input.nextInt();
            writer.println("Case #"+counter+":");
            //writer.printf("%d %d %d \n",r,c,m);
            checkBoard(r, c, m,writer);

        }
        writer.close();

    }
}
