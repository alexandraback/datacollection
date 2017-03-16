import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class C {
	public static void main(String[] args) throws IOException {
		Scanner       s         = new Scanner(new FileReader(new File("input.in")));
		PrintWriter   out       = new PrintWriter(new File("output.out"));
		StringBuilder resultat  = new StringBuilder("");
		long time = System.currentTimeMillis();
		
		//TEST CASES----------------------------------------------------
		int TC = s.nextInt();
    for (int tc = 1; tc <= TC; tc++) {
      if(tc!=1) resultat.append("\n");
      resultat.append("Case #"+tc+": ");
    
      //READ----------------------------------------------------
      long A = s.nextLong();
      int N = s.nextInt();
      long[] a = new long[N];
      for (int i = 0; i < N; i++)   a[i] = s.nextLong();
      //long E = s.nextLong(), R = s.nextLong();
			
			//SOLVE----------------------------------------------------
			long res = 0;
			
			Arrays.sort(a);
			long[] op = new long[N];
			int oper = 0;
			long minOper = N;
			
			if(A==1)
			  minOper = N;
			else{
  			for (int i = 0; i < a.length; i++)
        {
          while(A<=a[i]){
            
            A = A+ (A-1);
            
            oper++;
            //System.out.println(A+" "+oper);
          }
        
          A+=a[i];
          op[i] = oper+(N-i-1);
          
          System.out.println("op[i] "+op[i]);
          
          if(op[i]<minOper){
            minOper = op[i];
            System.out.println("minOper=" + minOper);
          }
        }
			}
			
			
			

      //PRINT--------------------------------------------------
			System.out.println(minOper);
			resultat.append(minOper);
			System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
		}
		
    //CLOSE----------------------------------------------------
		out.print(resultat);
		out.close(); s.close();
	}
}