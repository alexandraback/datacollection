import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class B {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new File("B-small-attempt0.in"));
    PrintWriter out = new PrintWriter(new File("B-small-attempt0.out"));

    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      
      in.nextInt();
      in.nextInt();
      s = in.nextInt();
      k = in.next().toCharArray();
      l = in.next().toCharArray();
      res = new char[s];
      a = new ArrayList<Integer>();
      
      find(0);
      
      double res = 0;
      int max = 0;
      for(int i : a) {
        res += i;
        max = Math.max(max, i);
      }
      res /= a.size();
      out.println("Case #" + t + ": " + (max - res));
      
    }

    out.close();
  }

  static int s;
  static char k[];
  static char l[];
  
  static char res[];
  private static void find(int idx) {
    if (idx == res.length){
      solve();
      return ;
    }
    for (int i = 0; i < k.length; i++) {
      res[idx] = k[i];
      find(idx + 1);
    }
    
  }
  
  static ArrayList<Integer> a;
  
  private static void solve() {
    int countSubstrings = 0;
    
    if (l.length <= res.length) {
      for (int i = 0; i < res.length; i++) {
        int countGoodChars = 0;
        for (int j = 0; j < l.length; j++) {
          if (i + j < res.length && l[j] == res[i+j]) {
            countGoodChars++;
          } else {
            break;
          }
        }
        if (countGoodChars == l.length) {
          countSubstrings++;
        }
      }
    }
    a.add(countSubstrings);
    
  }

}
