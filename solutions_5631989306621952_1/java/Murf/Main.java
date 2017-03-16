import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;

public class Main
{
   public static void main(String[] args) throws Exception
   {
      Scanner inp = new Scanner(new File("inSmall.txt"));
      PrintWriter pw = new PrintWriter(new File("outSmall.txt"));
      int c = 0;
      int cases = inp.nextInt();
      while( c < cases )
      {
         String r= "";
         String word = inp.next();
         for( int i=0; i<word.length(); i++) 
         {
            if(r.length() < 1 || word.charAt(i) < r.charAt(0) ) 
            {
               r = r + word.charAt(i);
            }
            else
            {
               r = word.charAt(i) + r;
            }
         } 
         System.out.println("Case " + (c+1) + ": " + r );
         pw.println("Case " + (c+1) + ": " + r );
         
         c++;
      }
      pw.close();
   }
}