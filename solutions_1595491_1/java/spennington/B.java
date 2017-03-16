import java.util.ArrayList;
import java.util.Scanner;

public class B {

  public static void output(int T, int count) {
    System.out.print(String.format("Case #%d: ", T));
    System.out.print(count);
    System.out.println();
  }
  
  public static int getScores(int total, int p) {
    int first = p;
    int second = p;
    int third = p;
    
    if (first + second + third > total) {
      second--;
    } else {
      return 0;
    }
    
    if (first + second + third > total) {
      third--;
    } else {
      return 0;
    }
    
    if (first + second + third > total) {
      second--;
    } else {
      return 0;
    }
    
    if (first + second + third > total) {
      third--;
    } else {
      return 1;
    }
    
    if (first + second + third > total) {
      return -1;
    } else {
      return 1;
    }
    
  }
  
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    in.nextLine();
  
    for (int i=0; i<T; i++) {
      int N = in.nextInt();
      int S = in.nextInt();
      int p = in.nextInt();
      int count = 0;
      ArrayList<Integer> t = new ArrayList<Integer>();
      
      for (int j=0; j<N; j++) {
        int tmp = in.nextInt();
        if (tmp >= p) {
          t.add(tmp);
        }
      }
      
      for (int j=0; j<t.size(); j++) {
        int tmp = t.get(j);
        int score = getScores(tmp, p);
        if (score == 0) {
          count++;
        } else if (score == 1 && S > 0) {
          count++;
          S--;
        }
      }
      
      output(i + 1, count);
    }
  }
}
