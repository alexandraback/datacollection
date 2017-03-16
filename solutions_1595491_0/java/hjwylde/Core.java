package qualification.b;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Core {
  
  public static void main(String[] args) {
    int t, n, s, p;
    
    try {
      Scanner scan = new Scanner(new File(args[0]));
      
      t = scan.nextInt();
      for (int i = 1; i <= t; i++) {
        n = scan.nextInt();
        s = scan.nextInt();
        p = scan.nextInt();
        
        System.out.println(solve(i, n, s, p, scan));
      }
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
  }
  
  public static String solve(int caseNumber, int n, int s, int p, Scanner scan) {
    int rangeMin, rangeMax;
    rangeMin = p + (2 * Math.max(0, p - 2)); // inc
    rangeMax = p + (2 * Math.max(0, p - 1)); // exc
    
    List<Integer> aboveP = new ArrayList<Integer>();
    int score, used;
    used = 0;
    for (int i = 0; i < n; i++) {
      score = scan.nextInt();
      
      if (score < rangeMin)
        continue;
      else if (score >= rangeMax)
        aboveP.add(score);
      else if (((score - rangeMin) <= 1) && (used < s)) {
        used++;
        aboveP.add(score);
      }
    }
    
    return "Case #" + caseNumber + ": " + aboveP.size();
  }
}