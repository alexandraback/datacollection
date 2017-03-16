import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class B {
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
      int X = s.nextInt();
      int Y = s.nextInt();
      
			//SOLVE----------------------------------------------------
			long res = 0;
			int d = 1;
			String moves = "";
			int x=0,y=0;
			
			String W = "W";
			String E = "E";
			String N = "N";
			String S = "S";
			
			if(X<0){
			  W="E";
			  E="W";
			  X = -X;
			}
			
			if(X%2==1){
			  while(x<X){
			    moves+=E;
			    x+=d; d++;
			    if(x>=X)
			      break;
			    
			    moves+=N;
          y+=d; d++;
          
          moves+=W;
          x-=d; d++;
          
          moves+=S;
          y-=d; d++;
			  }
			}
			// x pair
			else{
        while(x<X){
          moves+=W;
          x-=d; d++;
          
          moves+=N;
          y+=d; d++;
          
          moves+=E;
          x+=d; d++;
          if(x>=X)
            break;
          
          moves+=S;
          y-=d; d++;
        }
      }
			
			
			while(y>Y){
			  if(abs(y-Y)>abs(y-d-Y)){
			    moves+=S;
	        y-=d; d++;
			  }
			  else
			    break;
			}
			
			while(y<Y){
        if(abs(y-Y)>abs(y+d-Y)){
          moves+=N;
          y+=d; d++;
        }
        else
          break;
      }
			
			
			
			
			
			while(y>Y){
			  moves+=N;
        y+=d; d++;
        
			  moves+=S;
        y-=d; d++;
			}
			
			while(y<Y){
        moves+=S;
        y-=d; d++;
        
        moves+=N;
        y+=d; d++;
      }
			if(moves.length()>500)
			System.out.println(x + " " + y + " "+moves);

      //PRINT--------------------------------------------------
			System.out.println(moves);
			resultat.append(moves);
			System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
		}
		
    //CLOSE----------------------------------------------------
		out.print(resultat);
		out.close(); s.close();
	}
}