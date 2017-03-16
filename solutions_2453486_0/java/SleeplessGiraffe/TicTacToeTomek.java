   import java.io.*;
   import java.lang.*;
	
   public class TicTacToeTomek
   {
      public static char [][] board = new char[4][4];
      public static void main(String [] args) throws IOException
      {
         BufferedReader read = new BufferedReader (new FileReader("in.txt"));
         BufferedWriter write = new BufferedWriter (new FileWriter("ans.txt"));
         int T = Integer.valueOf(read.readLine());
         boolean X, O, D;
         String input = "";
         for(int i = 0; i < T; i++)
         {
         //input board
            for(int j = 0; j < 4; j++)
            {
               input = read.readLine();
               for(int k = 0; k < 4; k++)
                  board[j][k] = input.charAt(k);
            }
         //find winner
            X = false;
            O = false;
            D = false;
         //check X
            X = checkSlash('X');
            for(int j = 0; j < 4 && !X; j++)
            {
               X = checkRow(j, 'X');
               if(!X)
                  X = checkCol(j, 'X');
            }
            if(!X)
            {
            //check O
               O = checkSlash('O');
               for(int j = 0; j < 4 && !O; j++)
               {
                  O = checkRow(j, 'O');
                  if(!O)
                     O = checkCol(j, 'O');
               }
               //check Draw
               if(!O)
               {
                  D = checkDraw();
               }
            }
            write.write("Case #"+(i+1)+": ");
            if(X)
            {
               write.write("X won");
            }
            else if(O)
            {
               write.write("O won");
            }
            else if(D)
            {
               write.write("Draw");
            }
            else
            {
               write.write("Game has not completed");
            }
            write.newLine();
            input = read.readLine();
         }
         write.close();
      }
      public static boolean checkSlash(char p)
      {
         int count = 0;
         for(int i = 0; i < 4; i++)
         {
            if(board[i][i] == p || board[i][i] == 'T')
               count++;
         }
         if(count != 4)
         {
            count = 0;
            for(int i = 0; i < 4; i++)
            {
               if(board[i][4-i-1] == p || board[i][4-i-1] == 'T')
                  count++;
            }
         }
         if(count == 4)
            return true;
         return false;
      }
      public static boolean checkDraw()
      {
         for(int i = 0; i < 4; i++)
         {
            for(int j = 0; j < 4; j++)
            {
               if(board[i][j] == '.')
                  return false;
            }
         }
         return true;
      }
      public static boolean checkCol(int col, char p)
      {
         int count = 0;
         for(int i = 0; i < 4; i++)
         {
            if(board[i][col] == 'T' || board[i][col] == p)
               count++;
         }
         if(count == 4)
            return true;
         return false;
      }
      public static boolean checkRow(int row, char p)
      {
         int count = 0;
         for(int i = 0; i < 4; i++)
         {
            if(board[row][i] == 'T' || board[row][i] == p)
               count++;
         }
         if(count == 4)
            return true;
         return false;
      }
      public static void setBoard()
      {
         for(int i = 0; i < 4; i++)
         {
            for(int j = 0; j < 4; j++)
               board[i][j] = '.';
         }
      }
   }