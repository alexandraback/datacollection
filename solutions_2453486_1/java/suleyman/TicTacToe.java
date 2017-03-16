import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Neptun
 * Date: 4/13/13
 * Time: 10:53 AM
 * To change this template use File | Settings | File Templates.
 */
public class TicTacToe {

    FileWriter output;
    FileWriter logger;
    int caseNumber;
    char[][] board;

    TicTacToe() throws IOException {

        board = new char[4][4];

        output = new FileWriter("output");
        logger = new FileWriter("log");
    }

    void closeFiles() throws IOException {

        output.close();
        logger.close();
    }

    void process() throws IOException {

        File input = new File("input");
        Scanner scanner = new Scanner(input);

        caseNumber = scanner.nextInt();

        for(int i=1; i<=caseNumber; i++) {

            for(int j=0; j<4; j++) {

                String line = scanner.next();

                for(int k=0; k<4; k++) {

                    board[j][k] = line.charAt(k);
                }
            }

            printBoard();

            output.write("Case #" + i + ": ");

            int result = calcBoard();

            switch(result) {

                case 0: output.write("Draw\n"); break;
                case 1: output.write("X won\n"); break;
                case 2: output.write("O won\n"); break;
                case 3: output.write("Game has not completed\n"); break;
            }
        }

    }

    void printBoard() throws IOException {

        for(int j=0;j<4;j++){

            for(int k=0;k<4;k++){

                logger.write(board[j][k]);
            }
            logger.write("\n");
        }
        logger.write("\n");
    }

    int calcBoard(){

        for(int i=0;i<4;i++){

            if((board[i][0]=='X' || board[i][0]=='T')&&
                    (board[i][1]=='X' || board[i][1]=='T')&&
                    (board[i][2]=='X' || board[i][2]=='T')&&
                    (board[i][3]=='X' || board[i][3]=='T')){

                return 1;
            }
            if((board[i][0]=='O' || board[i][0]=='T')&&
                    (board[i][1]=='O' || board[i][1]=='T')&&
                    (board[i][2]=='O' || board[i][2]=='T')&&
                    (board[i][3]=='O' || board[i][3]=='T')){

                return 2;
            }
            if((board[0][i]=='X' || board[0][i]=='T')&&
                    (board[1][i]=='X' || board[1][i]=='T')&&
                    (board[2][i]=='X' || board[2][i]=='T')&&
                    (board[3][i]=='X' || board[3][i]=='T')){

                return 1;
            }
            if((board[0][i]=='O' || board[0][i]=='T')&&
                    (board[1][i]=='O' || board[1][i]=='T')&&
                    (board[2][i]=='O' || board[2][i]=='T')&&
                    (board[3][i]=='O' || board[3][i]=='T')){

                return 2;
            }
        }

        if((board[0][0]=='X' || board[0][0]=='T')&&
                (board[1][1]=='X' || board[1][1]=='T')&&
                (board[2][2]=='X' || board[2][2]=='T')&&
                (board[3][3]=='X' || board[3][3]=='T')){

            return 1;
        }
        if((board[0][0]=='O' || board[0][0]=='T')&&
                (board[1][1]=='O' || board[1][1]=='T')&&
                (board[2][2]=='O' || board[2][2]=='T')&&
                (board[3][3]=='O' || board[3][3]=='T')){

            return 2;
        }
        if((board[0][3]=='X' || board[0][3]=='T')&&
                (board[1][2]=='X' || board[1][2]=='T')&&
                (board[2][1]=='X' || board[2][1]=='T')&&
                (board[3][0]=='X' || board[3][0]=='T')){

            return 1;
        }
        if((board[0][3]=='O' || board[0][3]=='T')&&
                (board[1][2]=='O' || board[1][2]=='T')&&
                (board[2][1]=='O' || board[2][1]=='T')&&
                (board[3][0]=='O' || board[3][0]=='T')){

            return 2;
        }
        for(int i=0;i<4;i++){

            for(int j=0;j<4;j++)

                if(board[i][j]=='.')
                    return 3;
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {

        TicTacToe t = new TicTacToe();
        t.process();

        t.closeFiles();
    }
}
