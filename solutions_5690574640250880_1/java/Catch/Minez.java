import java.io.*;
import java.util.*;

public class Minez
{
  public static void main (String [] args) throws IOException
  {
    BufferedReader read = new BufferedReader (new FileReader ("C-large.in"));
    PrintWriter print = new PrintWriter (new FileWriter ("output.txt"));
    int iterations = Integer.parseInt (read.readLine ());
    for (int count = 1; count <= iterations; count ++)
    {
      String [] variables = read.readLine ().split (" ");
      int rows = Integer.parseInt (variables [0]);
      int columns = Integer.parseInt (variables [1]);
      int mines = Integer.parseInt (variables [2]);
      short [] [] minePlacements = new short [rows][columns];
      for (int x = 0; x < rows; x ++)
        for (int y = 0; y < columns; y ++)
        minePlacements [x][y] = 0;
      try
      {
         if (rows* columns - mines == 1)
        {
          for (int x = 0; x < columns; x ++)
            for (int y = 0; y < rows; y ++)
            minePlacements [y][x] = 1;
        }
        else if (rows == 1)
        {
          if ((rows == 2 && mines % 2 == 1)||(rows == 1 && mines > columns))
          {
            Integer.parseInt ("Force break");
          }
          else 
          {
            for (int x = columns- 1; x >= columns - mines / rows; x --)
            {
              for (int y = 0; y < rows; y ++)
              {
                minePlacements [y][x] = 1;
              }
            }
          }
        }
        else if (columns == 1)
        {
          if ((columns == 2 && mines % 2 == 1)||(columns == 1 && mines > rows))
          {
            Integer.parseInt ("Force break");
          }
          else
          {
            for (int x = rows- 1; x >= rows - mines / columns; x --)
            {
              for (int y = 0; y < columns; y ++)
              {
                minePlacements [x][y] = 1;
              }
            }
          }
        }
        else if (rows*columns - mines == 2)
        {
          Integer.parseInt ("Force Break");
        }
        
        else if (rows == 2)
        {
          if ((rows == 2 && mines % 2 == 1)||(rows == 1 && mines > columns))
          {
            Integer.parseInt ("Force break");
          }
          else 
          {
            for (int x = columns- 1; x >= columns - mines / rows; x --)
            {
              for (int y = 0; y < rows; y ++)
              {
                minePlacements [y][x] = 1;
              }
            }
          }
        }
        else if (columns == 2)
        {
          if ((columns == 2 && mines % 2 == 1)||(columns == 1 && mines > rows))
          {
            Integer.parseInt ("Force break");
          }
          else
          {
            for (int x = rows- 1; x >= rows - mines / columns; x --)
            {
              for (int y = 0; y < columns; y ++)
              {
                minePlacements [x][y] = 1;
              }
            }
          }
        }
        else 
        {
          
          
          
          
          for (int y = columns - 1; y >= 0; y --)//columns first
          {
            
            
            
            /*if (count == 6)
            {
              System.out.println ("Case #" + count + ":" + mines);
              for (int x = 0; x < rows; x ++)
              {
                for (int z = 0; z < columns; z ++)
                {
                  if (x == 0 && z == 0)
                    System.out.print ("c");
                  else if (minePlacements [x][z] == 0)
                    System.out.print (".");
                  else 
                    System.out.print ("*");
                }
                System.out.println ();
              }
            }*/
            
            
            if (mines == 0)
            {
              break;
            }
            else if (y < 2)
            {
              if (mines % 2 == 1)//make even
              {
                if ((mines + 3) / 2 > rows - 3)
                  Integer.parseInt ("Derp");
                mines += minePlacements [0][2];
                minePlacements [0][2] = 0;
                mines += minePlacements [1][2];
                minePlacements [1][2] = 0;
                mines += minePlacements [2][2];
                minePlacements [2][2] = 0;
              }
              
                
                int x = rows - 1;
                while (true)
                {
                  if (mines >= 2)
                  {
                    mines -= 2;
                    minePlacements [x][0] = 1;
                    minePlacements [x][1] = 1;
                  }
                  else
                    break;
                  x --;
                }
            }
            else if (mines >= rows)
            {
              mines -= rows;
              for (int x = 0; x < rows; x++)
              {
                minePlacements [x][y] = 1;
              }
            }
            else //if mines is less than rows
            {
              int constant = mines;
              for (int x = rows - 1; x >= rows - constant - 1; x --)
              {
                if (mines == 2 && x == 2 && y == 2)
                {
                  if (rows < 4)
                    Integer.parseInt ("Boo");//case 75
                  mines -= 2;
                  minePlacements [rows - 1][y - 1] = 1;
                  minePlacements [rows - 1][y - 2] = 1;
                }
                if (mines == 1 && x == 1)
                {
                  if (y == 2)
                    Integer.parseInt ("Shet yo");
                  mines --;
                  minePlacements [rows - 1][y - 1] = 1;
                }
                else
                {
                  if (mines == 0)
                    break;
                  mines --;
                  minePlacements [x][y] = 1;
                }
              }
            }
            if (mines < 0)
              System.out.println (count + "dammit");
            
            
        
          }
        }
        print.println ("Case #" + count + ":");
        for (int x = 0; x < rows; x ++)
        {
          for (int y = 0; y < columns; y ++)
          {
            if (x == 0 && y == 0)
              print.print ("c");
            else if (minePlacements [x][y] == 0)
              print.print (".");
            else 
              print.print ("*");
          }
          print.println ();
        }
      }
      catch (Exception e)
      {
        print.println ("Case #" + count + ":");
        if (mines != 0)
          print.println ("Impossible");
        else
        {
          for (int x = 0; x < rows; x ++)
          {
            for (int y = 0; y < columns; y ++)
            {
              if (x == 0 && y == 0)
                print.print ("c");
              else if (minePlacements [x][y] == 0)
                print.print (".");
              else 
                print.print ("*");
            }
            print.println ();
          }
        }
      }
      
    }
    print.close ();
  }
}











