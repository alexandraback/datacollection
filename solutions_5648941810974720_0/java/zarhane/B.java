import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class B {
  public static void main(String[] args) throws IOException {
    String        pb        = "B";
    Scanner       sc        = new Scanner(new FileReader(new File(pb+".in")));
    PrintWriter   out       = new PrintWriter(new File(pb+".out"));
    StringBuilder resultat  = new StringBuilder("");
    //long time = System.currentTimeMillis();
    
    //TEST CASES----------------------------------------------------
    int TC = sc.nextInt();
    sc.nextLine();
    for (int tc = 1; tc <= TC; tc++) {
      if(tc!=1) resultat.append("\n");
      resultat.append("Case #"+tc+": ");
    
      
      
      //READ----------------------------------------------------
      char[] input = sc.nextLine().toCharArray();
      
      char[] letters = "ONETWTHRFUIVSXGZ".toCharArray();
      
      HashMap<Character, Integer> count = new HashMap<Character, Integer>();
      for (int i = 0; i < letters.length; i++)
      {
        count.put(letters[i],0);
      }
      
      for (int i = 0; i < input.length; i++)
      {
        char c = input[i];
        //System.out.println(c);
        count.put(c, count.get(c)+1);
      }
      
      int[] numberCount = new int[10];
      
      numberCount[0] = count.get('Z');
      numberCount[2] = count.get('W');
      numberCount[4] = count.get('U');
      numberCount[6] = count.get('X');
      numberCount[8] = count.get('G');
      numberCount[1] = count.get('O')-numberCount[0]-numberCount[2]-numberCount[4];
      numberCount[3] = count.get('H')-numberCount[8];
      numberCount[5] = count.get('F')-numberCount[4];
      numberCount[7] = count.get('V')-numberCount[5];
      numberCount[9] = count.get('I')-numberCount[5]-numberCount[6]-numberCount[8];
      
      StringBuffer res =  new StringBuffer("");
      
      for (int i = 0; i < numberCount.length; i++)
      {
        for (int j = 0; j < numberCount[i]; j++)
        {
          res.append(i);
        }
      }
      
      //PRINT--------------------------------------------------
      System.out.println(res);
      resultat.append(res);
//      System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
      
    }
    
    //CLOSE----------------------------------------------------
    out.print(resultat);
    out.close(); sc.close();
  }

}