import java.util.*;
import java.io.*;
class pogo
{
       
  void main()throws IOException
  {
      Scanner sc = new Scanner(new File("B-small-attempt0.in"));
      PrintWriter P= new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
      
      int x,y,cx=0,cy=0;
      int k=0;
      int T =sc.nextInt();
      String s;
      
      for(int t=1;t<=T;t++)
      {
          s="";
          x=sc.nextInt();
          y=sc.nextInt(); 
          
          if(x<0)
          cx=-x;
          
          if(y<0)
          cy=-y;
          
         if(x<0)
            {
               
                for(k=0;k<cx;k++)
                {
                    s+="EW";
                }
            }
            
         else
            {
               
                for(k=0;k<x;k++)
                {
                    s+="WE";
                }
            }
          
          if(y<0)
          {
               
                for(k=0;k<cy;k++)
                {
                    s+="NS";
                }
            }
            
            else
            {
               
                for(k=0;k<y;k++)
                {
                    s+="SN";
                }
            }
            
            P.println("Case #"+t+": "+s);
        }
    P.flush();
    P.close();
}
}