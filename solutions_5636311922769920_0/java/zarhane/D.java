import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class D {
	public static void main(String[] args) throws IOException {
    String        pb        = "D";
    Scanner       sc        = new Scanner(new FileReader(new File(pb+".in")));
    PrintWriter   out       = new PrintWriter(new File(pb+".out"));
		StringBuilder resultat  = new StringBuilder("");
		long time = System.currentTimeMillis();
		
		//TEST CASES----------------------------------------------------
		int TC = sc.nextInt();
    for (int tc = 1; tc <= TC; tc++) {
      if(tc!=1) resultat.append("\n");
      resultat.append("Case #"+tc+": ");
    
      //READ----------------------------------------------------
      int K = sc.nextInt();
      int C = sc.nextInt();
      int S = sc.nextInt();
      
      //SOLVE----------------------------------------------------
			String res = "";
			for (int i = 1; i <= K; i++)
      {
        res+=" "+i;
      }
						
      //PRINT--------------------------------------------------
			//System.out.println(res.trim());
			resultat.append(res.trim());
			//System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
		}
		
    //CLOSE----------------------------------------------------
		out.print(resultat);
		out.close(); sc.close();
	}

}