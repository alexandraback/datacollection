import java.io.*; 
import java.util.*; 
import java.text.DecimalFormat; 

public class ProblemC
{
    static int z; 
    static char [] [] board; 
    public static int count (int r, int c)
    {
      int counter = 0; 
      if (r == 1 && c != 1)
      {
      for (int x = 0; x < 2; x++)
      {
       for (int y = -1; y < 1; y++)
       {
         if (board [r + x][c + y] != '.')
         {  
           counter++;
           board [r + x][c + y] = '.';
         }
       }
      }
      }
      else if (c == 1 && r != 1)
      {
        if (board [r][c] != '.')
        {
        board [r][c] = '.';
        counter = 1;
        }
        if (c != z && board [r][c + 1] != '.')
        {
         board [r][c + 1] = '.';
         counter++; 
        }
      }
      else
      {
        if (board [r][c] != '.')
        counter = 1; 
        board [r][c] = '.'; 
        
      }
      return counter; 
    }
  
    public static void main (String [] args) throws IOException
    {
      long time = System.currentTimeMillis (); 
      Scanner in = new Scanner (new FileReader ("C-small-attempt2.in")); 
      PrintWriter out = new PrintWriter (new FileWriter ("Cout1.txt")); 
      int asdfg = in.nextInt (); 
      for (int cases = 0; cases < asdfg; cases++)
      {
        int r = in.nextInt (); 
        int c = in.nextInt (); 
        int m = in.nextInt ();
        int left = r * c - m; 
        board = new char [r + 2][c + 2];
        boolean impos = false; 
        big:
        for (z = c; z > 0; z--)
        {
         if (z == 1 && c != 1)
           break;
          left = r * c - m; 
        for (int x = 0; x < r + 2; x++)
        {
          board [x][0] = '.'; 
          board [x][c + 1] = '.'; 
        }
        for (int x = 0; x < c + 2; x++)
        {
          board [0][x] = '.'; 
          board [r + 1][x] = '.'; 
        }
        
        for (int x = 1; x <= r; x++)
        {
          for (int y = 1; y <= c; y++)
          {
            board [x][y] = '*'; 
          }
        }
        lol:
        for (int x = 1; x <= r; x++)
        {
          for (int y = 1; y <= z; y++)
          {
            int temp = count (x, y); 
            if (left - temp < 0)
            {
              if (x > 3 && z > 2)
              {
                board [x-1][z] = '*'; 
                impos = false; 
                break big; 
              }
              impos = true;
              continue big; 
            }
            if (left - temp == 0)
            {
              impos = false;
              break big;
            }
            left -= temp; 
            
          }
        }
        }
        
        board [1][1] = 'c';
        out.println ("Case #" + (cases + 1) + ":");
        if (impos)
        {
        out.println ("Impossible"); 
        }
        else
        {
          for (int x = 1; x <= r; x++)
          {
            for (int y = 1; y <= c; y++)
            {
              out.print (board [x][y]); 
            }
            out.println (); 
          }
        }
         
    }  
    System.out.println (System.currentTimeMillis () - time); 
    in.close ();
    out.close ();
    }
}
