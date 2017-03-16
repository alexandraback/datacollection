import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class TicTacToeTomec
{

   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));
      
      int numCases = scan.nextInt();
      for(int z = 1; z <= numCases; z++)
      {
         String [] board = new String[4];
         for (int i = 0; i < 4; i++)
         {
            board[i] = scan.next();
         }
         
         int winner = 0;
         for (int i = 0; i < 4; i++)
         {
            winner |= getWinner(board[i].charAt(0), board[i].charAt(1), 
                  board[i].charAt(2), board[i].charAt(3));
            
            winner |= getWinner(board[0].charAt(i), board[1].charAt(i), 
                  board[2].charAt(i), board[3].charAt(i));
            
         }
         winner |= getWinner(board[0].charAt(0), board[1].charAt(1), 
               board[2].charAt(2), board[3].charAt(3));

         winner |= getWinner(board[0].charAt(3), board[1].charAt(2), 
               board[2].charAt(1), board[3].charAt(0));
         
         boolean hasEmpty = false;
         for (int i = 0; i < 4; i++)
         {
            for (int j = 0; j < 4; j++) 
            {
               hasEmpty |= board[i].charAt(j) == '.';
            }
         }
         
         System.out.print("Case #" + z + ": ");
         switch(winner)
         {
         case 0:
            if (hasEmpty)
            {
               System.out.println("Game has not completed");
            }
            else
            {
               System.out.println("Draw");
            }
            break;
         case 1:
            System.out.println("X won");
            break;
         case 2:
            System.out.println("O won");
            break;
         case 3:
            System.out.println("Draw");
            break;
         }
      }
      
   }

   private static int getWinner(char a, char b, char c, char d)
   {
      if (matchX(a) && matchX(b) && matchX(c) && matchX(d))
         return 1;
      
      if (matchO(a) && matchO(b) && matchO(c) && matchO(d))
         return 2;
      
      return 0;
   }

   private static boolean matchX(char a)
   {
      return a == 'X' || a == 'T';
   }

   private static boolean matchO(char a)
   {
      return a == 'O' || a == 'T';
   }

}
