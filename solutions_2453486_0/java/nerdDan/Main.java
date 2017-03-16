import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int nCase = cin.nextInt();
        for(int iCase = 1; iCase<=nCase; iCase++) {
            String[] board = new String[4];
            for(int i = 0; i<4; i++) 
                board[i] = cin.next();
            boolean win = false;
            for(int i = 0; i<4; i++) {
                win = true;
                for(int j = 0; j<4; j++)
                    if(board[i].charAt(j)!='X' && board[i].charAt(j)!='T') {
                        win = false;
                        break;
                    }
                if(win)
                    break;
                win = true;
                for(int j = 0; j<4; j++)
                    if(board[j].charAt(i)!='X' && board[j].charAt(i)!='T') {
                        win = false;
                        break;
                    }
                if(win)
                    break;
            }
            if(!win) {
                win = true;
                for(int i = 0; i<4; i++)
                    if(board[i].charAt(i)!='X' && board[i].charAt(i)!='T') {
                        win = false;
                        break;
                    }
            }
            if(!win) {
                win = true;
                for(int i = 0; i<4; i++)
                    if(board[i].charAt(3-i)!='X' && board[i].charAt(3-i)!='T') {
                        win = false;
                        break;
                    }
            }
            if(win) {
                System.out.println("Case #"+iCase+": X won");
                continue;
            }
            for(int i = 0; i<4; i++) {
                win = true;
                for(int j = 0; j<4; j++)
                    if(board[i].charAt(j)!='O' && board[i].charAt(j)!='T') {
                        win = false;
                        break;
                    }
                if(win)
                    break;
                win = true;
                for(int j = 0; j<4; j++)
                    if(board[j].charAt(i)!='O' && board[j].charAt(i)!='T') {
                        win = false;
                        break;
                    }
                if(win)
                    break;
            }
            if(!win) {
                win = true;
                for(int i = 0; i<4; i++)
                    if(board[i].charAt(i)!='O' && board[i].charAt(i)!='T') {
                        win = false;
                        break;
                    }
            }
            if(!win) {
                win = true;
                for(int i = 0; i<4; i++)
                    if(board[i].charAt(3-i)!='O' && board[i].charAt(3-i)!='T') {
                        win = false;
                        break;
                    }
            }
            if(win) {
                System.out.println("Case #"+iCase+": O won");
                continue;
            }
            for(int i = 0; i<4; i++)
                for(int j = 0; j<4; j++)
                    if(board[i].charAt(j)=='.') {
                        win = true;
                        break;
                    }
            if(win)
                System.out.println("Case #"+iCase+": Game has not completed");
            else
                System.out.println("Case #"+iCase+": Draw");
        }
    }

}
