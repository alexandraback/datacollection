import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Mark
 */
public class FairAndSquare {
  static final String inputFileName = "in.txt";
  static final String outputFileName = "out.txt";
  static long A,B;
  
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
        A = in.nextLong();
        B = in.nextLong();
          
        long min = (long)Math.ceil(Math.sqrt(A));
        long max = (long)Math.sqrt(B);
        
        long number = 0;       
        for(int i=1; i<10; i++) {
          if(i>=min && i<=max) {
            long x2 = i*i;
            if(isPal(x2)) {
              number++;
            }
          }
        }
        
        //print("min: "+min+" max: "+max);
        

        
        int digits = (int)Math.ceil(Math.log10(max));
        
        int maxN = digits/2;
        
        for(int s = 1; s<=maxN; s++) {
          int[] d = new int[s];
          d[s-1] = 1;
          
          while(!allZero(d)) {
            long x = 0;
            long y = 1;
            for(int i=0; i<s; i++) {
              x += d[i] * y;
              y *= 10;
            }
            for(int i=0; i<s; i++) {
              x += d[s-i-1] * y;
              y *= 10;
            }
            
            if(x>=min) { 
            
              if(x<=max) {
                
              long x2 = x*x;
              if(isPal(x2)) {
                //print(x2+" "+x);
                number++;
              }
              
              } else {
                break;
              }
              
            
            }
            
            increment(d);
          }
        }
        
        for(int s = 1; s<=maxN; s++) {
          int[] d = new int[s];
          d[s-1] = 1;
          
          loop:
          while(!allZero(d)) {
            
            for(int mid=0; mid<10; mid++) {

              long x = 0;
              long y = 1;
              for(int i=0; i<s; i++) {
                x += d[i] * y;
                y *= 10;
              }
              x += mid * y;
              y*=10;
              for(int i=0; i<s; i++) {
                x += d[s-i-1] * y;
                y *= 10;
              }

              if(x>=min) { 

                if(x<=max) {

                long x2 = x*x;
                if(isPal(x2)) {
                  //print(x2+" "+x);
                  number++;
                } else {
                  //print("WRONG: "+x2+" "+x);
                }

                } else {
                  break loop;
                }


              }
            
            }
            
            increment(d);
          }
        }
        
        
        String str = "Case #"+n+": ";
        str += number;
        print(str);
        out.println(str);
      }
      
      in.close();
      out.close();
    } catch (FileNotFoundException ex) {
      Logger.getLogger(FairAndSquare.class.getName()).log(Level.SEVERE, null, ex);
    }
  }

  private static boolean allZero(int[] d) {
    boolean z = true;
    for(int i=0; i<d.length; i++) {
      if(d[i]!=0) {
        z = false;
        break;
      }
    }
    return z;
  }

  private static boolean isPal(long x2) {
    String s = ""+x2;
    boolean b = true;
    for(int i=0; i<s.length()/2; i++) {
      if(s.charAt(i)!=s.charAt(s.length()-i-1)) {
        b = false;
      }
    }
    return b;
  }

  private static void increment(int[] d) {
    for(int i=0; i<d.length; i++) {
      d[i]++;
      if(d[i]==10) {
        d[i] = 0;
      } else {
        return;
      }
    }
  }
}
