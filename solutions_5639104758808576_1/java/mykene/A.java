package prel;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by rubenverboon on 11/04/15.
 */
public class A {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner sc = new Scanner(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/Prel-A.in"));
    PrintWriter pw = new PrintWriter(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/Prel-A.out"));
    A a = new A();
    int c = sc.nextInt();
    for (int i = 0; i < c; i++) {
      pw.println("Case #" + (i + 1) + ": " + a.solve(sc));
    }
    pw.close();
    sc.close();
  }


  private int solve(Scanner sc) {
    int a = sc.nextInt();
    String s = sc.next();
    int sum =0;
    int people =0;
    for(int i=0;i<=a;i++){
      if(s.charAt(i)!='0'){
        int extra = Math.max(0,  i-people);
        people+=extra+s.charAt(i)-'0';
        sum+=extra;
      }
    }
    return sum;

  }


}
