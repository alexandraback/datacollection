import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class C2014 {
	public static void main(String[] args) throws IOException {
		Scanner       s         = new Scanner(new FileReader(new File("C.in")));
		PrintWriter   out       = new PrintWriter(new File("C.out"));
		StringBuilder resultat  = new StringBuilder("");
		long time = System.currentTimeMillis();
		
		//TEST CASES----------------------------------------------------
		int TC = s.nextInt();
    for (int tc = 1; tc <= TC; tc++) {
      if(tc!=1) resultat.append("\n");
      resultat.append("Case #"+tc+":\n");
    
      //READ----------------------------------------------------
      int R1 = s.nextInt(), C1 = s.nextInt(), M = s.nextInt();
      int R = min(R1, C1);
      int C = max(R1, C1);
			//SOLVE----------------------------------------------------
			String res = "NON COUVERTE";
			if(M==0)
			  res = printAll(R1,C1,".");
			else if(R==1)
        res = printLine(R1,C1,M,"*");
      else if(M==R*C-1)
        res = printAll(R1,C1,"*");
			
      
      else if(M>=C1 && M%C1==0 && M<=(R1-2)*C1)
        res = printLig(R1,C1,M);
      else if(M>=R1 && M%R1==0 && M<=(C1-2)*R1)
        res = printCol(R1,C1,M);
      
      else if(M<=R1*(C1-2) && M%R1<R1-1)
        res = printCol2(R1,C1,M);
      else if(M<=C1*(R1-2) && M%C1<C1-1)
        res = printLig2(R1,C1,M);
      
      else if(R<=2 && C<=2){
			  if(M==1 || M==2)
			    res = "Impossible";
      }
			else if(R<=2 && C>2){
			  if(M<=R*C-4){
          if(M%2==0){
            res = printRectangle(R1,C1,M);//"possible mostatil";
          }
          else
            res = "Impossible";
        }
        else{
          res = "Impossible";
        }
      }
			else{
  			if(M<(R-2)*(C-2)){
  			  res = printCarre(R1, C1, M);
  			}
  			else if(M<=R*C-4){
  			  if(M%2==((R-2)*(C-2))%2)
  			    res = printCarreRectangle(R1,C1,M); // "possible mostatil";
  			  else
  			    res = "Impossible";
        }
  			else{
  			  res = "Impossible";
  			}
			}
      //PRINT--------------------------------------------------
			System.out.println(res);//R1+" "+C1+" "+M+"\n"+
			resultat.append(res);
			System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
		}
    
    
//    for (int i = 1; i <= 5; i++)
//    {
//      for (int j = 1; j <= 5; j++)
//      {
//        for (int m = 0; m < i*j; m++)
//        {
//          System.out.println(i + " " + j + " " + m);
//        }
//      }
//    }
		
    //CLOSE----------------------------------------------------
		out.print(resultat);
		out.close(); s.close();
	}

  private static String printCol(int r1, int c1, int m)
  {
    char[][] sol = new char[r1][c1];
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c1; j++)
      {
        sol[i][j] = '.';
      }
    }
    sol[0][0] = 'c';
    
    
    for (int i = c1-1; i >= c1-(m/r1) ; i--)
    {
      for (int j = 0; j < r1; j++)
      {
        sol[j][i]='*';
      }
    }
    
    return print(sol);
  }
  
  private static String printCol2(int r1, int c1, int m)
  {
    char[][] sol = new char[r1][c1];
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c1; j++)
      {
        sol[i][j] = '.';
      }
    }
    sol[0][0] = 'c';
    
    int b=0;
    for (int i = c1-1; i >0 && b<m ; i--)
    {
      for (int j = r1-1; j >= 0 && b<m; j--)
      {
        sol[j][i]='*';
        b++;
      }
    }
    
    return print(sol);
  }
  
  
  
  private static String printLig(int r1, int c1, int m)
  {
    char[][] sol = new char[r1][c1];
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c1; j++)
      {
        sol[i][j] = '.';
      }
    }
    sol[0][0] = 'c';
    
    
    for (int i = r1-1; i >= r1-(m/c1) ; i--)
    {
      for (int j = 0; j < c1; j++)
      {
        sol[i][j]='*';
      }
    }
    
    return print(sol);
  }
  
  private static String printLig2(int r1, int c1, int m)
  {
    char[][] sol = new char[r1][c1];
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c1; j++)
      {
        sol[i][j] = '.';
      }
    }
    sol[0][0] = 'c';
    
    int b=0;
    for (int i = r1-1; i >=0 && b<m ; i--)
    {
      for (int j = c1-1; j >= 0 && b<m; j--)
      {
        sol[i][j]='*';
        b++;
      }
    }
    
    return print(sol);
  }

  private static String printCarreRectangle(int r1, int c1, int m)
  {
    char[][] sol = new char[r1][c1];
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c1; j++)
      {
        sol[i][j] = '*';
      }
    }
    sol[0][0] = 'c';
    sol[1][0] = '.';
    sol[0][1] = '.';
    sol[1][1] = '.';
    
    int b = r1*c1-4;
    
    for (int i = 2; i < r1 && b>m; i++)
    {
      sol[i][0]='.';
      sol[i][1]='.';
      b-=2;
    }
    
    for (int i = 2; i < c1 && b>m; i++)
    {
      sol[0][i]='.';
      sol[1][i]='.';
      b-=2;
    }
    
    return print(sol);
  }

  private static String printRectangle(int r1, int c1, int m)
  {
    char[][] sol = new char[r1][c1];
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c1; j++)
      {
        sol[i][j] = '.';
      }
    }
    sol[0][0] = 'c';
    
    if(r1<=c1)
    {
      for (int i = c1-1; i >= c1-(m/2); i--)
      {
        sol[0][i]='*';
        sol[1][i]='*';
      } 
    }
    else{
      for (int i = r1-1; i >= r1-(m/2); i--)
      {
        sol[i][0]='*';
        sol[i][1]='*';
      } 
    }
    
    
    return print(sol);
  }

  private static String printCarre(int r1, int c1, int m)
  {
    char[][] sol = new char[r1][c1];
    for (int i = 0; i < r1; i++)
    {
      for (int j = 0; j < c1; j++)
      {
        sol[i][j] = '.';
      }
    }
    sol[0][0] = 'c';
    
    int count = 0;
    for (int i = r1-1; i >= 2 && count<m; i--)
    {
      for (int j = c1-1; j >= 2 && count<m; j--)
      {
        sol[i][j] = '*';
        count++;
      }
    }
    
    
    
    return print(sol);
  }

  private static String print(char[][] sol)
  {
    String s = "";
    for (int i = 0; i < sol.length; i++)
    {
      for (int j = 0; j < sol[0].length; j++)
      {
        s+=sol[i][j];
      }
      if(i!=sol.length-1)
        s+= "\n";
    }
    return s.trim();
  }

  private static String printLine(int r1, int c1, int m, String ch)
  {
    String s = "c";
    
    if(r1==1){
      for (int i = 0; i < c1-(m+1); i++)
        s += ".";
      for (int i = 0; i < m; i++)
        s += ""+ch;
    }
    else{
      for (int i = 0; i < r1-(m+1); i++)
        s += "\n.";
      for (int i = 0; i < m; i++)
        s += "\n"+ch;
    }
    
    return s.trim();
  }

  private static String printAll(int r, int c, String ch)
  {
    String s = "";
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if(i==0 && j==0)
          s+="c";
        else
          s += ""+ch;
      } 
      s += "\n";
    }
    return s.trim();
  }
}