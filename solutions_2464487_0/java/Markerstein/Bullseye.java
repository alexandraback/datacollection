import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Mark
 */
public class Bullseye {
  static final String inputFileName = "in.txt";
  static final String outputFileName = "out.txt";
  
  public static void print(String text) {
    System.out.println(text);
  }

  /**
   * @param args the command line arguments
   */
  public static void main(String[] args) {
    try {
      File file = new File(inputFileName);
      Scanner in = new Scanner(file);
      file = new File(outputFileName);
      PrintWriter out = new PrintWriter(file);
      
      
      int num = in.nextInt();
      
      for(int n=1; n<=num; n++) {
        long r = in.nextLong();
        long t = in.nextLong();
        
        //print("r: "+r+" t: "+t);
        
        double a = 4;
        double b = 4*r+6;
        double c = 4*r+2-2*t;
        
        double sq = Math.sqrt(b*b-4*a*c);
        
        double ans = (-b+sq)/(2*a);
        
        long m = (long)Math.floor(ans);
        
        //print("Estimated m: "+ans);
        
        if(m>0 && m%2==0) m--;
        
        if(m>10) m-=8;
        
        long dt = (m/2+1)*(4*m+4*r+2);
        
        if(m==0) {
          dt=0;
          m = -1;
        }
        
        //print("dt: "+dt);
        
        if(dt>t) {
            print("m: "+m);
            print("Error - dt too large");
            System.exit(0);
        }
        
        if(dt<t) {
        
          while(dt<=t) {
          
            m++;
        
            dt = (m/2)*(4*m+4*r+2) + 2*(r+2*(m/2)) + 1;
            
            //print("trying m: "+m+" dt: "+dt);
            
            
            if(dt<=t) {
              m++;
              
              
              
              dt = (m/2+1)*(4*m+4*r+2);
              
              //print("trying m: "+m+" dt: "+dt);
            }
          
          }
          
          m--;
        
        }
        
        m++;
        
        long mm = 0;
        long tt = 0;
        
        while(tt<=t) {
          long dtt = 2*(r+mm*2)+1;
          tt += dtt;
          mm++;
          //print("m: "+mm+" tt: "+tt);
        }
        mm--;
        
        if(m!=mm) {
          print("---------- error they dont equal ----------");
          System.exit(0);
        }
          
        String str = "Case #"+n+": "+m;
        
        print(str);
        out.println(str);
      }
      
      in.close();
      out.close();
    } catch (FileNotFoundException ex) {
      Logger.getLogger(Bullseye.class.getName()).log(Level.SEVERE, null, ex);
    }
  }
}
