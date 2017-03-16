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
public class Lawnmover {
  static final String inputFileName = "in.txt";
  static final String outputFileName = "out.txt";
  static int[][] lawn;
  static int N, M;
  
  public static void print(String text) {
    System.out.println(text);
  }
  
  public static void printLawn() {
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        System.out.print(lawn[i][j]+" ");
      }
      print("");
    }
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
        N = in.nextInt();
        M = in.nextInt();
        lawn = new int[N][M];
        
        for(int i=0; i<N; i++) {
          for(int j=0; j<M; j++) {
            lawn[i][j] = in.nextInt();
          }
        }
        
        String str = "Case #"+n+": ";
        
        mainloop:
        while(true) {
          int min = getMin();
          //print("min: "+min);
          if(min==0) {
            str+="YES";
            break mainloop;
          } 
          for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
              if(lawn[i][j]==min) {
                if(mow(i, j)) {
                  //print("mowing complete");
                  //printLawn();
                } else {
                  //print("Not possible");
                  str+="NO";
                  break mainloop;
                }
              }
            }
          }
        }
        
        print(str);
        out.println(str);
      }
      
      in.close();
      out.close();
    } catch (FileNotFoundException ex) {
      Logger.getLogger(Lawnmover.class.getName()).log(Level.SEVERE, null, ex);
    }
  }

  private static int getMin() {
    int min = Integer.MAX_VALUE;
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        int v = lawn[i][j];
        if(v!=0) {
          min = Math.min(min, v);
        }
      }
    }
    if(min==Integer.MAX_VALUE) return 0;
    return min;
  }

  private static boolean mow(int i, int j) {
    int v = lawn[i][j];
    boolean ok = true;
    for(int ii=0; ii<N; ii++) {
      if(lawn[ii][j]==v || lawn[ii][j]==0) {
        //print("lawn "+ii+" "+j+" equals min");
      } else {
        //print("lawn "+ii+" "+j+" NOT min so stopped");
        ok = false;
        break;
      }
    }
    if(ok) {
      for(int ii=0; ii<N; ii++) {
        //print("setting lawn "+ii+" "+j+" to zero");
        lawn[ii][j] = 0;
      }
      return true;
    }
    ok = true;
    for(int jj=0; jj<M; jj++) {
      if(lawn[i][jj]==v || lawn[i][jj]==0) {
        
      } else {
        ok = false;
        break;
      }
    }
    if(ok) {
      for(int jj=0; jj<M; jj++) {
        lawn[i][jj] = 0;
        
      }
      return true;
    }
    
    return false;
  }
}
