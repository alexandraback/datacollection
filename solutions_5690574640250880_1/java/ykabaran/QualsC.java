package codejam2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class QualsC {
  
  private static final boolean DEBUG = false;
  private static final String IMPOSSIBLE = "Impossible";
  private static final char EMPTY = '.', MINE = '*', CLICK = 'c';
  
  // variables here
  private int numRows, numCols, numMines, numSpaces;

  // solution algorithm here
  public void solveCases(String inputSize) throws IOException {
    String infilename = "C" + inputSize + "in.in";
    String outfilename = "C" + inputSize + "out.in";

    // create output file if it does not exist, otherwise overwrite everything
    // in it
    File file = new File("data/quals/" + outfilename);
    if (!file.exists()) {
      file.createNewFile();
    }

    // create reader and writer for the input and output files
    BufferedReader br = new BufferedReader(new FileReader("data/quals/"
        + infilename));
    BufferedWriter bw = new BufferedWriter(new FileWriter(
        file.getAbsoluteFile()));

    // get the number of test cases to use throughout solving process
    int numCases = Integer.parseInt(br.readLine());

    // create some temporary variables to use for storing input variabes and
    // output string
    String line;
    String[] splitted;
    for (int i = 1; i <= numCases; i++) {
      // read in variables here
      line = br.readLine();
      splitted = line.split(" ");
      numRows = Integer.parseInt(splitted[0]);
      numCols = Integer.parseInt(splitted[1]);
      numMines = Integer.parseInt(splitted[2]);
      
      if(DEBUG){
        System.out.println("Solving case " + i);
      }
      line = "Case #" + i + ":\n" + solve() + "\n"; // solve here
      if(DEBUG){
        System.out.println(line);
      }
      bw.write(line);
    }
    br.close();
    bw.close();
  }
  
  private String printBoard(char[][] board){
    StringBuilder result = new StringBuilder();
    for(int i=0; i<numRows; ++i){
      for(int j=0; j<numCols; ++j){
        result.append(board[i][j]);
      }
      if(i<numRows-1){
        result.append('\n');
      }
    }
    return result.toString();
  }
  
  private char[][] getBoard(){    
    char[][] board = new char[numRows][numCols];
    board[0][0] = CLICK;
    
    // simplest case no mines
    if(numMines<1){
      for(int i=0; i<numRows; ++i){
        for(int j=0; j<numCols; ++j){
          board[i][j] = EMPTY;
        }
      }
      board[0][0] = CLICK;
      return board;
    }
    
    int spacesLeft = numSpaces-1;
    
    // second simplest case, only one space
    if(spacesLeft<1){
      for(int i=0; i<numRows; ++i){
        for(int j=0; j<numCols; ++j){
          board[i][j] = MINE;
        }
      }
      board[0][0] = CLICK;
      return board;
    }
    // we have a single row
    if(numRows<2){
      int index = 1;
      while(spacesLeft>0){
        board[0][index] = EMPTY;
        ++index;
        --spacesLeft;
      }
      while(index<numCols){
        board[0][index] = MINE;
        ++index;
      }
      return board;
    }
    
    // we have a single column
    if(numCols<2){
      int index = 1;
      while(spacesLeft>0){
        board[index][0] = EMPTY;
        ++index;
        --spacesLeft;
      }
      while(index<numRows){
        board[index][0] = MINE;
        ++index;
      }
      
      return board;
    }
    
    // we have only two rows
    // and we are certain we have an even number of spaces
    if(numRows<3){
      board[1][0] = EMPTY;
      --spacesLeft;
      int index = 1;
      while(spacesLeft>0){
        board[0][index] = EMPTY;
        board[1][index] = EMPTY;
        ++index;
        spacesLeft -= 2;
      }
      while(index<numCols){
        board[0][index] = MINE;
        board[1][index] = MINE;
        ++index;
      }
      
      return board;
    }
    
    // we have only two columns
    // and we are certain we have an even number of spaces
    if(numCols<3){
      board[0][1] = EMPTY;
      --spacesLeft;
      int index = 1;
      while(spacesLeft>0){
        board[index][0] = EMPTY;
        board[index][1] = EMPTY;
        ++index;
        spacesLeft -= 2;
      }
      while(index<numRows){
        board[index][0] = MINE;
        board[index][1] = MINE;
        ++index;
      }
      
      return board;
    }
    
    // from this point forward we have at least 3 rows and columns
    // we have 4 spaces
    if(numSpaces == 4){
      board[0][1] = EMPTY;
      board[1][0] = EMPTY;
      board[1][1] = EMPTY;
      for(int i=0; i<numRows; ++i){
        for(int j=0; j<numCols; ++j){
          if(i<2 && j<2){
            continue;
          }
          board[i][j] = MINE;
        }
      }
      
      return board;
    }
    
    // we have 6 spaces
    if(numSpaces == 6){
      board[0][1] = EMPTY;
      board[1][0] = EMPTY;
      board[1][1] = EMPTY;
      board[2][0] = EMPTY;
      board[2][1] = EMPTY;
      for(int i=0; i<numRows; ++i){
        for(int j=0; j<numCols; ++j){
          if(i<3 && j<2){
            continue;
          }
          board[i][j] = MINE;
        }
      }
      
      return board;
    }
    
    // we have at least 8 spaces
    for(int i=0; i<numRows; ++i){
      for(int j=0; j<numCols; ++j){
        board[i][j] = MINE;
      }
    }
    board[0][0] = CLICK;
    board[0][1] = EMPTY;
    board[0][2] = EMPTY;
    board[1][0] = EMPTY;
    board[1][1] = EMPTY;
    board[1][2] = EMPTY;
    board[2][0] = EMPTY;
    board[2][1] = EMPTY;
    spacesLeft = numSpaces - 8;
    
    // fill first two rows with the rest of the spaces
    for(int i=3; i<numCols; ++i){
      if(spacesLeft>1){
        board[0][i] = EMPTY;
        board[1][i] = EMPTY;
        spacesLeft -= 2;
      } else if(spacesLeft == 1){
        board[2][2] = EMPTY;
        return board;
      } else {
        return board;
      }
    }
    
    // fill first two columns with the rest of the spaces
    for(int i=3; i<numRows; ++i){
      if(spacesLeft>1){
        board[i][0] = EMPTY;
        board[i][1] = EMPTY;
        spacesLeft -= 2;
      } else if(spacesLeft == 1){
        board[2][2] = EMPTY;
        return board;
      } else {
        return board;
      }
    }
    
    int curCol = 2, curRow = 2;
    boolean isTurnRow = true;
    
    while(spacesLeft>0){
      if(isTurnRow){
        for(int i=curCol; i<numCols; ++i){
          board[curRow][i] = EMPTY;
          --spacesLeft;
          if(spacesLeft<1){
            return board;
          }
        }
        ++curRow;
      } else {
        for(int i=curRow; i<numRows; ++i){
          board[i][curCol] = EMPTY;
          --spacesLeft;
          if(spacesLeft<1){
            return board;
          }
        }   
        ++curCol;
      }
      isTurnRow = !isTurnRow;
    }
    
    return board;
  }
  
  private boolean isImpossible(){
    if(numMines<1){
      return false;
    }
    
    // if only one space exists then we win by clicking it
    if(numSpaces<2){
      return false;
    }
    
    // if either dimensions are 1, then we win by piling everything
    // on one side and clicking the other
    if(numRows<2 || numCols<2){
      return false;
    }
    
    // if either dimensions are 2, then we only win if we have 4 or more
    // even number of spaces, and lose otherwise
    if(numRows < 3 || numCols < 3){
      if(numSpaces<4){
        return true;
      }
      if(numSpaces%2==0){
        return false;
      }
      return true;
    }
    
    // we have an at least 3 by 3 board
    // 4 spaces, 6 spaces, and more than 8 spaces wins
    if(numSpaces == 4 || numSpaces == 6 || numSpaces>=8){
      return false;
    }
    // the rest loses
    return true;
  }
  
  private String solve() {
    long startTime;
    if(DEBUG){
      System.out.println("Board Dim: " + numRows + "x" + numCols);
      System.out.println("Number of Mines: " + numMines);
      startTime = System.currentTimeMillis();
    }
    
    numSpaces = (numRows * numCols) - numMines;
    
    String result = IMPOSSIBLE;
    if(!isImpossible()){
      result = printBoard(getBoard());
    }
    
    if(DEBUG){
      long endTime = System.currentTimeMillis();
      System.out.println("Solution took: " + (endTime-startTime) + "ms");
    }
    return result;
  }

  public static void main(String[] args) {
    QualsC prob = new QualsC();
    try {
      prob.solveCases("l");
    } catch (IOException e) {
      System.out.println("Cannot read or write to files.");
      System.out.println(e.getMessage());
    }
  }
}
