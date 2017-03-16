import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class A {
	public static void main(String[] args) throws IOException {
    String        pb        = "A";
    Scanner       sc        = new Scanner(new FileReader(new File(pb+".in")));
    PrintWriter   out       = new PrintWriter(new File(pb+".out"));
		StringBuilder resultat  = new StringBuilder("");
		long time = System.currentTimeMillis();
		String[] car = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    
		//TEST CASES----------------------------------------------------
		int TC = sc.nextInt();
    for (int tc = 1; tc <= TC; tc++) {
      if(tc!=1) resultat.append("\n");
      resultat.append("Case #"+tc+": ");
    
      //READ----------------------------------------------------
      long N = sc.nextLong();
      
      
			//SOLVE----------------------------------------------------
			String res = "INSOMNIA";
			boolean[] found = new boolean[10];
			int countFound = 0; 
			for (long i = 1; N>0 && i <= 1000000000; i++)
      {
        String n = ""+(i*N);
        for (int j = 0; j <= 9; j++)
        {
          if(!found[j] && n.contains(car[j])){
            found[j]=true;
            countFound++;
            //System.out.println(n + " contains " + car[j]+" count="+countFound);
            if(countFound==10)
              break;
          }
        }
        if(countFound==10){
          res=n;
          break;
        }
      }
			
			
      //PRINT--------------------------------------------------
			System.out.println(res);
			resultat.append(res);
//			System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
			
		}
		
    //CLOSE----------------------------------------------------
		out.print(resultat);
		out.close(); sc.close();
	}

}