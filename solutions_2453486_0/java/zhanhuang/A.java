import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.PrintWriter;

public class A{
    public static void main(String[] args) throws IOException{
        File file = new File("A-small-attempt0.in");
        Scanner fileScanner = new Scanner(file);
        
        PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
        
        
        char[][] boardArray = new char[4][4];
        
        String line = null;
        line = fileScanner.nextLine();
        int testCaseNum = Integer.parseInt(line);
        
        for(int i =0; i < testCaseNum; i++){
            for(int j = 0; j < 4; j++){
                line = fileScanner.nextLine();
                boardArray[j] = line.toCharArray();
            }
            
            char player = ' ';
            boolean boardFilled = true;
            
            //horizontal and vertical
            for(int j = 0; j < 4; j++){
                if(boardArray[j][0] == '.'){
                    boardFilled = false;
                }else{
                    player = boardArray[j][0];
                    for(int k = 1; k < 4; k++){
                        if(boardArray[j][k] == player || boardArray[j][k] == 'T'){
                            
                        } else if (player == 'T' && boardArray[j][k] != '.'){
                            player = boardArray[j][k];
                        } else{
                            if(boardFilled && boardArray[j][k] == '.')
                                boardFilled = false;
                            player = ' ';
                            if(!boardFilled)
                                break;
                        }
                    }
                    if(player != ' ')
                        break;
                }
                
                if(boardArray[0][j] != '.'){
                    player = boardArray[0][j];
                    for(int k = 1; k < 4; k++){
                        if(boardArray[k][j] == player || boardArray[k][j] == 'T'){
                            
                        } else if (player == 'T' && boardArray[k][j] != '.'){
                            player = boardArray[k][j];
                        } else{
                            player = ' ';
                            break;
                        }
                    }
                    if(player != ' ')
                        break;
                }
            }
            
            //diagonal
            if(player == ' ' && boardArray[0][0] != '.'){
                player = boardArray[0][0];
                for(int k = 1; k < 4; k++){
                    if(boardArray[k][k] == player || boardArray[k][k] == 'T'){
                        
                    } else if (player == 'T' && boardArray[k][k] != '.'){
                        player = boardArray[k][k];
                    } else{
                        player = ' ';
                        break;
                    }
                }
            }
            if(player == ' ' && boardArray[0][3] != '.'){
                player = boardArray[0][3];
                for(int k = 1; k < 4; k++){
                    if(boardArray[k][3-k] == player || boardArray[k][3-k] == 'T'){
                        
                    }else if (player == 'T' && boardArray[k][3-k] != '.'){
                        player = boardArray[k][3-k];
                    }else{
                        player = ' ';
                        break;
                    }
                }
            }
            
            
            
            writer.print("Case #" + (i+1) + ": ");
            if(player != ' ' && player != '.'){
                writer.print(player + " won");
            } else if (boardFilled){
                writer.print("Draw");
            } else{
                writer.print("Game has not completed");
            }
            writer.println();
            
            //empty line
            if(i < testCaseNum - 1)
                line = fileScanner.nextLine();
        }
        
        writer.close();
    }
}