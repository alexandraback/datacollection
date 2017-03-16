import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class CJ2014Round1CA {

  public static final ArrayList<Long> factors = new ArrayList<Long>(41);
  
  static {
    long val = 1;
    for (int i = 0; i < 41; i++) {
      factors.add(val);
      val *= 2;
    }
  }
  
  
  public static long GCD(long a, long b) {
    if (b==0) return a;
    return GCD(b,a%b);
 }
  
  public static int getAnswer(long P, long Q) {
    long gcd = GCD(P, Q);
    P = P / gcd;
    Q = Q / gcd;
    int indexP = 0;
    int indexQ = 0;
    for (int i = 1; i < 40; i++) {
      if (factors.get(i) <= P) {
        indexP++;
      }
      if (factors.get(i) <= Q) {
        indexQ++;
      }
    }
    if (factors.get(indexQ) != Q) {
      return -1;
    }
    return indexQ - indexP;
  }
  
  public static boolean isTest = false;
  public static boolean isSmall = false;
  public static void main(String[] args) {
    try {
      BufferedReader br = null;
      BufferedWriter bw = null;
      if (isTest) {
        br = new BufferedReader(new FileReader("test.txt"));
        bw = new BufferedWriter(new FileWriter("output.txt"));
      } else if (isSmall) {
        br = new BufferedReader(new FileReader("A-small-attempt1.in"));
        bw = new BufferedWriter(new FileWriter("A-small.out.txt"));
      } else {
        br = new BufferedReader(new FileReader("A-large.in"));
        bw = new BufferedWriter(new FileWriter("A-large.out.txt"));
      }

      String line = br.readLine().trim();
      int numOfGames = Integer.parseInt(line);
      String[] inVals;
      for(int i = 1; i<=numOfGames; i++) {
        inVals = br.readLine().trim().split("/");
        long P = Long.parseLong(inVals[0]);
        long Q = Long.parseLong(inVals[1]);
        int result = CJ2014Round1CA.getAnswer(P, Q);
        if (result < 0) {
          System.out.println("Case #"+i+": impossible");
          bw.write("Case #"+i+": impossible\n");
        } else {
          System.out.println("Case #"+i+": " + result);
          bw.write("Case #"+i+": " + result + "\n");
        }
      }
      br.close();
      bw.flush();
      bw.close();
    }
    catch (FileNotFoundException e) {
      System.out.println("ERROR: Cannot find file.");
      return;
    }
    catch (IOException e) {
    }
  }

}
