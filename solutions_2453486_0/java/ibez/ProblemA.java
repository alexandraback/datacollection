package qualification;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemA {
    public static void main(String[] args) {
        try {
            Scanner inputScanner = new Scanner(new File("input.txt"));
            FileWriter writer = new FileWriter(new File("output.txt"));
            
            int T = inputScanner.nextInt();
            inputScanner.nextLine();
            
            int[][] board = new int[4][4];
            
            for (int t = 1; t <= T; t++) {
                boolean finished = true;
                boolean xWon = false;
                boolean oWon = false;
                
                for (int i = 0; i < 4; i++) {
                    String line = inputScanner.nextLine();
                    for (int j = 0; j < 4; j++) {
                        if (line.charAt(j) == 'X') {
                            board[i][j] = 1;
                        } else if (line.charAt(j) == 'O') {
                            board[i][j] = -1;
                        } else if (line.charAt(j) == 'T') {
                            board[i][j] = 0;
                        } else if (line.charAt(j) == '.') {
                            finished = false;
                            board[i][j] = -1000;
                        } else {
                            assert(false);
                        }
                    }
                }
                if (t != T) {
                    inputScanner.nextLine();
                }
                
                // check horizontals and verticals and diagonals
                int sum3 = 0;
                int sum4 = 0;
                for (int i = 0; i < 4; i++) {
                    int sum1 = 0;
                    int sum2 = 0;
                    
                    sum3 += board[i][i];
                    sum4 += board[i][3 - i];
                    for (int j = 0; j < 4; j++) {
                        sum1 += board[i][j];
                        sum2 += board[j][i];
                    }
                    if (sum1 == 3 || sum1 == 4 || sum2 == 3 || sum2 == 4) {
                        xWon = true;
                        break;
                    }
                    if (sum1 == -3 || sum1 == -4 || sum2 == -3 || sum2 == -4) {
                        oWon = true;
                        break;
                    }
                }
                if (sum3 == 3 || sum3 == 4) {
                    xWon = true;
                }
                if (sum3 == -3 || sum3 == -4) {
                    oWon = true;
                }
                if (sum4 == 3 || sum4 == 4) {
                    xWon = true;
                }
                if (sum4 == -3 || sum4 == -4) {
                    oWon = true;
                }
                
                String result = "";
                if (xWon) {
                    result = "Case #" + t + ": X won";
                } else if (oWon) {
                    result = "Case #" + t + ": O won";
                } else if (finished) {
                    result = "Case #" + t + ": Draw";
                } else {
                    result = "Case #" + t + ": Game has not completed";
                }
                System.out.println(result);
                writer.write(result + "\n");

            }
            
            inputScanner.close();
            writer.close();
            
            
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        
    }
}

