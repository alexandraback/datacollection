import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class D2014 {
	public static void main(String[] args) throws IOException {
		Scanner       s         = new Scanner(new FileReader(new File("D.in")));
		PrintWriter   out       = new PrintWriter(new File("D.out"));
		StringBuilder resultat  = new StringBuilder("");
		long time = System.currentTimeMillis();
		
		//TEST CASES----------------------------------------------------
		int TC = s.nextInt();
    for (int tc = 1; tc <= TC; tc++) {
      if(tc!=1) resultat.append("\n");
      resultat.append("Case #"+tc+": ");
    
      //READ----------------------------------------------------
      int N = s.nextInt();
      
      double[] n = new double[N];
      for (int i = 0; i < N; i++)   n[i] = s.nextDouble();
      
      double[] a = new double[N];
      for (int i = 0; i < N; i++)   a[i] = s.nextDouble();
      
      
      
			//SOLVE----------------------------------------------------
      Arrays.sort(n);
      Arrays.sort(a);
      
      int res1=0;
      int res2=0;
      
      int j=0;
      for (int i = 0; i < n.length; i++)
      {
        for (; j < a.length; j++)
        {
          if(n[i]<a[j]){
            //System.err.println("i="+i+" j="+j+" : "+n[j] + " " + a[i]);
            j++;
            break;
          }
          else{
            res2++;
          }
        }
      }
      
      
      j=0;
      for (int i = 0; i < a.length; i++)
      {
        for (; j < n.length; j++)
        {
          if(a[i]<n[j]){
            //System.err.println("i="+i+" j="+j+" : "+n[j] + " " + a[i]);
            res1++;
            j++;
            break;
          }
        }
      }
      
      String res = res1+" "+res2;
			
      //PRINT--------------------------------------------------
			System.out.println(res);
			resultat.append(res);
			System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
		}
		
    //CLOSE----------------------------------------------------
		out.print(resultat);
		out.close(); s.close();
	}
}