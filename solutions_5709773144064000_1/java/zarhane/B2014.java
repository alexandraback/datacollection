import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class B2014 {
	public static void main(String[] args) throws IOException {
		Scanner       s         = new Scanner(new FileReader(new File("B.in")));
		PrintWriter   out       = new PrintWriter(new File("B.out"));
		StringBuilder resultat  = new StringBuilder("");
		long time = System.currentTimeMillis();
		
		//TEST CASES----------------------------------------------------
		int TC = s.nextInt();
    for (int tc = 1; tc <= TC; tc++) {
      if(tc!=1) resultat.append("\n");
      resultat.append("Case #"+tc+": ");
    
      //READ----------------------------------------------------
      double C = s.nextDouble();
      double F = s.nextDouble();
      double X = s.nextDouble();
      
			//SOLVE----------------------------------------------------
      double t = 0;
      double M = 0;
      double TF = 2;
      
      
      if(C>=X)
        t = X/2;
      else{
        while(M<X){
          //System.err.println("M=" + M + " " + "X=" + X + " " + "C=" + C + " " + "TF=" + TF + " F=" +F+" t="+t);
          if(M<C){
            //System.err.println("M<C");
            t += (C-M)/TF;
            M = C;
          }
          else{
            double a = (X-M+C)/(TF+F);
            double na = (X-M)/TF;
            if(a<na){
              //System.err.println("Achat");
              M -= C;
              TF += F;
            }else{
              //System.err.println("Non Achat");
              if((X - (C*TF)/F)>M){
                //System.err.println("  Pas fin");
                t += ((X - (C*TF)/F)-M)/TF;
                M = X - (C*TF)/F;
              }
              else{
                //System.err.println("  Fin"+((X-M)/TF));
                t+= (X-M)/TF;
                M=X;
              }
            }
          }
        }
      }

      //PRINT--------------------------------------------------
			System.out.println(t);
			resultat.append(t);
			System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
		}
		
    //CLOSE----------------------------------------------------
		out.print(resultat);
		out.close(); s.close();
	}
}