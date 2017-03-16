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
      long K = sc.nextInt();
      long C = sc.nextInt();
      long S = sc.nextInt();
      
      //SOLVE----------------------------------------------------
			ArrayList<Long> res = new ArrayList<Long>();
			for (long i = 1; i <= K; i++)
      {
        res.add(i);
      }
			
			for (int c = 1; c < C; c++)
      {
			  ArrayList<Long> newRes = new ArrayList<Long>();
        
			  for (int i = 1; i < res.size(); i=i+2)
        {
          newRes.add((res.get(i-1)-1)*K+res.get(i));
        }
			  
			  if(res.size()%2==1){
			    newRes.add(res.get(res.size()-1));
			  }
			  
			  res = newRes;
      }
			
			String resu = "IMPOSSIBLE";
			if(res.size()<=S){
			  resu = ""+res.get(0);
			  for (int i = 1; i < res.size(); i=i+1){
	        resu += " "+res.get(i);
			  }
			}
						
      //PRINT--------------------------------------------------
			//System.out.println(res.trim());
			resultat.append(resu);
			//System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
		}
		
    //CLOSE----------------------------------------------------
		out.print(resultat);
		out.close(); sc.close();
	}

}