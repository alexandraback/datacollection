import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class A{
    public static void main(String[] args) throws Exception{
        new A().run();
    }

    char[][] f = new char[4][];

    boolean win(char c){
        // horizontal
        for(int i = 0; i < 4; i++){
            boolean ok = true;
            for(int j = 0; j < 4; j++)
                if(f[i][j] != c && f[i][j] != 'T')
                    ok = false;
            if(ok)
                return true;
        }
        // vertical
        for(int j = 0; j < 4; j++){
            boolean ok = true;
            for(int i = 0; i < 4; i++)
                if(f[i][j] != c && f[i][j] != 'T')
                    ok = false;
            if(ok)
                return true;
        }
        // diagonal
        boolean ok = true;
        for(int i = 0; i < 4; i++)
            if(f[i][i] != c && f[i][i] != 'T')
                ok = false;
        if(ok)
            return true;
        ok = true;
        for(int i = 0; i < 4; i++)
            if(f[3-i][i] != c && f[3-i][i] != 'T')
                ok = false;
        return ok;
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available

        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            for(int i = 0; i < 4; i++)
                f[i] = sc.next().toCharArray();
            boolean empty = false;
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    empty |= f[i][j] == '.';
            System.out.printf("Case #%d: ", o);
            // check X won
            if(win('X')){
                System.out.println("X won");
                continue;
            }
            // check O won
            if(win('O')){
                System.out.println("O won");
                continue;
            }
            if(empty)
                System.out.println("Game has not completed");
            else
                System.out.println("Draw");
        }
    }
}
