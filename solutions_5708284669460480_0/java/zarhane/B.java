import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class B {
  
  static int countOccur = 0;
  static String W = ""; 
  static int max = 0;
  static long allPoss = 0;
  
	public static void main(String[] args) throws IOException {
    String        pb        = "B";
    Scanner       sc        = new Scanner(new FileReader(new File(pb+".in")));
    PrintWriter   out       = new PrintWriter(new File(pb+".out"));
		StringBuilder resultat  = new StringBuilder("");
		long time = System.currentTimeMillis();
		
		//TEST CASES----------------------------------------------------
		int TC = sc.nextInt();
    for (int tc = 1; tc <= TC; tc++) {
      if(tc!=1) resultat.append("\n");
      resultat.append("Case #"+tc+": ");
    
      countOccur = 0;
      max = 0;
      allPoss = 0;
      
      //READ----------------------------------------------------
      int K = sc.nextInt();
      int L = sc.nextInt();
      int S = sc.nextInt(); sc.nextLine();
      
      char[] KY = sc.nextLine().toCharArray();
      W = sc.nextLine();
      
      for (int j0 = 0; j0 < K; j0++)
      {
        String str0 = KY[j0]+"";
        for (int j1 = 0; j1 < K; j1++)
        {
          String str1 = str0;
          if(S<=1){
            process(str1);
            break;
          }
          else for (int j2 = 0; j2 < K; j2++)
          {
            String str2 = str1+KY[j1];
            if(S<=2){
              process(str2);
              break;
            }
            else for (int j3 = 0; j3 < K; j3++)
            {
              String str3 = str2+KY[j2];
              if(S<=3){
                process(str3);
                break;
              }
              else for (int j4 = 0; j4 < K; j4++)
              {
                String str4 = str3+KY[j3];
                if(S<=4){
                  process(str4);
                  break;
                }
                else for (int j5 = 0; j5 < K; j5++)
                {
                  String str5 = str4+KY[j4];
                  if(S<=5){
                    process(str5);
                    break;
                  }
                  else for (int j6 = 0; j6 < K; j6++)
                  {
                    String str6 = str5+KY[j5];
                    if(S<=6){
                      process(str6);
                      break;
                    }
                    else {
                        process(str6+KY[j6]);
                    }
                  }
                }
              }
            }
          }
        }
      }
      
       
      double res = 0;
      
      //System.out.println("-----------------"+max + " " + countOccur + " " + allPoss);
      
      res = max - (countOccur+0.0)/allPoss;
      
      
      
      
      //PRINT--------------------------------------------------
			System.out.println(res);
			resultat.append(res);
			System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
		}
		
    //CLOSE----------------------------------------------------
		out.print(resultat);
		out.close(); sc.close();
	}

  private static void process(String str)
  {
    //System.out.println(str+" "+W);
    
    int lastIndex = 0;
    int count =0;
    
    while(lastIndex != -1){

      lastIndex = str.indexOf(W,lastIndex);

      if( lastIndex != -1){
            count ++;
            lastIndex++;
     }
    }
    
   // System.out.println(str+" "+W+" -> "+ count);
    
    if(max<count)
      max = count;
    
    allPoss++;
    
    countOccur += count;
  }

  private static int countOccur(String w, char[] cs)
  {
    // TODO Auto-generated method stub
    return 0;
  }

}