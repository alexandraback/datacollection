package round2c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by rubenverboon on 11/04/15.
 */
public class B {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner sc = new Scanner(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/Prel-B.in"));
    PrintWriter pw = new PrintWriter(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/Prel-B.out"));
    B instance = new B();
    int c = sc.nextInt();
    for (int i = 0; i < c; i++) {
      pw.println("Case #" + (i + 1) + ": " + instance.solve(sc));
    }
    pw.close();
    sc.close();
  }


  private double solve(Scanner sc) {
    int k = sc.nextInt();
    int l = sc.nextInt();
    int s = sc.nextInt();
    String keyboard = sc.next();
    String result = sc.next();

    int[] counts = new int[26];

    for(char a: keyboard.toCharArray()) {
      counts[a-'A']++;
    }

    Double prob = 1.0;

    for(char b: result.toCharArray()){
      prob *= (counts[b-'A']*1.0)/k;
    }
    if(prob>0.0 && s>=l) {
      return (s/l) - (prob)*(s/l);
    } else {
      return 0.0;
    }

  }
}
