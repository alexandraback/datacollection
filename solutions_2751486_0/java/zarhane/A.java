import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class A {
  
  static String cons = "aeiou";
  
	public static void main(String[] args) throws IOException {
		Scanner       s         = new Scanner(new FileReader(new File("input.in")));
		PrintWriter   out       = new PrintWriter(new File("output.out"));
		StringBuilder resultat  = new StringBuilder("");
		long time = System.currentTimeMillis();
		
		//TEST CASES----------------------------------------------------
		int TC = s.nextInt();
		s.nextLine();
    for (int tc = 1; tc <= TC; tc++) {
      if(tc!=1) resultat.append("\n");
      resultat.append("Case #"+tc+": ");
    
      //READ----------------------------------------------------
      String[] line = s.nextLine().split(" ");
      String nam = line[0];
      //System.out.println("NAME="+nam);
      char[] name = line[0].toCharArray();
      int n = Integer.parseInt(line[1]);
      
			//SOLVE----------------------------------------------------
			long res = 0;
			
			for (int i = 0; i < name.length; i++)
      {
			  for (int j = i+1; j <= name.length; j++)
	      {
			    //System.out.println(nam.substring(i, j));
	        if(count(name, i,j,n)){
	          //System.out.println("\tYES");
	          res++;
	        }
	      } 
      }

      //PRINT--------------------------------------------------
			System.out.println(res);
			resultat.append(res);
			System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
		}
		
    //CLOSE----------------------------------------------------
		out.print(resultat);
		out.close(); s.close();
	}

  private static boolean count(char[] name, int i, int j, int n)
  {
    int counter = 0;
    for (int k = i; k < j; k++)
    {
      if(!cons.contains(""+name[k]))
        counter++;
      else
        counter=0;
      
      if(counter>=n)
        return true;
    }
    return false;
  }
}