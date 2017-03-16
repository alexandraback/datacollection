import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Neptun
 * Date: 4/13/13
 * Time: 2:52 PM
 * To change this template use File | Settings | File Templates.
 */
public class Lawnmower {

    FileWriter output;
    FileWriter logger;
    int caseNumber;
    int N;
    int M;
    int[][] board;

    Lawnmower() throws IOException {

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

            N = scanner.nextInt();
            M = scanner.nextInt();

            board = new int[N][M];

            for(int j=0; j<N; j++) {

                for(int k=0; k<M; k++) {

                    board[j][k] = scanner.nextInt();
                }
            }

            printBoard();

            output.write("Case #"+ i + ": ");

            boolean result = calcBoard();

            if(result)
                output.write("YES");
            else
                output.write("NO");

            output.write("\n");
        }
    }

    void printBoard() throws IOException {

        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){

                logger.write(String.valueOf(board[j][k]));
            }
            logger.write("\n");
        }
        logger.write("\n");
    }

    boolean calcBoard(){

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){

                int vertical = 1;
                int horizontal = 1;

                for(int k=0;k<M;k++){

                    if(board[i][k] > board[i][j]){

                        horizontal = 0;
                        break;
                    }
                }
                for(int k=0;k<N;k++){

                    if(board[k][j] > board[i][j]){

                        vertical = 0;
                        break;
                    }
                }
                if(horizontal == 0 && vertical == 0)
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {

        Lawnmower l = new Lawnmower();
        l.process();

        l.closeFiles();
    }
}
