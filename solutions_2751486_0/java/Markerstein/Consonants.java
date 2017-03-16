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
public class Consonants {
  static final String inputFileName = "in.txt";
  static final String outputFileName = "out.txt";
  
  public static void print(String text) {
    System.out.println(text);
  }
  
  static boolean isConsonant(char c) {
    return !(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
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
        String name = in.next();
        int d = in.nextInt();
        
        int sol = 0;
        
        for(int i=1; i<=name.length(); i++) {
          for(int j=0; j<i; j++) {
            String sub = name.substring(j, i);
            //print("sub: "+sub);
            if(sub.length()>=d) {
              int m = 0;
              boolean hasD = false;
              for(int k=0; k<sub.length(); k++) {
                if(isConsonant(sub.charAt(k))) {
                  m++;
                  if(m>=d) {
                    hasD = true;
                  }
                } else {
                  m=0;
                } 
              }
              if(hasD) {
                sol++;
              }
            }
          }
        }
          
        String str = "Case #"+n+": "+sol;
        
        print(str);
        out.println(str);
      }
      
      in.close();
      out.close();
    } catch (FileNotFoundException ex) {
      Logger.getLogger(Consonants.class.getName()).log(Level.SEVERE, null, ex);
    }
  }
}
