import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

//import javax.print.attribute.standard.MediaSize.ISO;


public class TicTacToeTomek {
    
    
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("tictac.txt"));
            int num = in.nextInt();
            in.nextLine();
            for(int n = 1; n <= num; n++) {
                String board[] = new String[4];
                for(int i = 0; i < 4; i ++) {
                    board[i] = in.nextLine();
                }
                try{
                in.nextLine();
                } catch(Exception e){}
                
                int x = getPoint(board, 'X');
                int o = getPoint(board, 'O');
                if(x == 4) {
                    print(n,"X won");
                } else if (o == 4) {
                    print(n,"O won");
                } else if (isOver(board)) {
                    print(n,"Draw");
                } else {
                    print(n,"Game has not completed");
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
    
    public static void print(int n, String result) {
        System.out.println(String.format("Case #%d: %s", n,result));
    }
    
    public static int getPoint(String[] board,char c) {

        for (int i = 0; i < 4; i++) {
            int rtn = 0;
            for (int j = 0; j < 4; j++) {
                if (board[i].charAt(j) == c || board[i].charAt(j) == 'T') {
                    rtn++;
                }
            }
            if(rtn == 4) {
                return 4;
            }
        }
        
        for (int j = 0; j < 4; j++) {
            int rtn = 0;
            for (int i = 0; i < 4; i++) {
                if (board[i].charAt(j) == c || board[i].charAt(j) == 'T') {
                    rtn++;
                }
            }
            if (rtn == 4) {
                return 4;
            }
        }
        
        int rtn = 0;
        for(int i = 0; i < 4; i ++) {
            if (board[i].charAt(i) == c || board[i].charAt(i) == 'T') {
                rtn++;
            }
            if(rtn == 4) {
                return rtn;
            }
        }
        
        rtn = 0;
        for(int i = 0; i < 4; i ++) {
            if (board[i].charAt(3-i) == c || board[i].charAt(3-i) == 'T') {
                rtn++;
            }
            if(rtn == 4) {
                return rtn;
            }
        }
        return 0;
    }
    
    static boolean  isOver(String[] board) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++){
                if(board[i].charAt(j) == '.') {
                    return false;
                }
            }
        }
        return true;
    }
    
}
