/**
 * Author: Chan Jun Wei
 */

import java.io.FileReader;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.*;

public class Enclosure
{
  static String fileName = "Enclosure";
  static final String OUTPUT_VALID = "Case #%d: %d";  
  
  public static void main( String [ ] args )
  {
    File file=new File(fileName + ".in");
    try
    {
      // Opening of files for input and output
      Scanner sc=new Scanner(file);
      PrintWriter writer = new PrintWriter(fileName + ".out");
      
      // Scanner sc = new Scanner(System.in);
      //   PrintWriter writer = new PrintWriter(System.out);
      
      int T;
      int row, col, intersect;
      
      T = sc.nextInt();
      
      for (int cases = 1; cases <= T; cases++){
        int noOfStones = 0;
        int minStone = 10000;
        col = sc.nextInt();
        row = sc.nextInt();
        intersect = sc.nextInt();
        
        if (col < 3 || row < 3 || intersect < 5){
          noOfStones = intersect;
        } else if (row * col - intersect < 4) {
          noOfStones = (row - 2) * 2 + (col - 2) * 2 + row * col - intersect;
        } else {
          int noOfInter = 0;
          
          int curInter = -1;
          for (int c = 3; c <= col; c++){            
            for (int r = 3; r <= row; r++){
              if (r == 3){
                noOfStones = 4 + (c - 3) * 2;
              } else {
                noOfStones += 2;
              }
              
              noOfInter = noOfStones + (c - 2) * (r - 2);
              
              if (intersect - noOfInter < c){
                if (minStone > noOfStones + intersect - noOfInter){
                  minStone = noOfStones + intersect - noOfInter;
                  curInter = noOfInter + intersect - noOfInter;
                  //System.out.println(minStone);
                }
                break;
              }
            }
          }
          noOfStones = minStone;
        }
        
        writer.println(String.format(OUTPUT_VALID, cases, noOfStones));
      }
      
      sc.close();
      writer.close();
    }
    catch( Exception e )  
    { e.printStackTrace(System.out); }
    finally  
    {// Close the files if they have been opened.
      //file.delete();
    }
  }
}