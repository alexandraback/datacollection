package prel;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by rubenverboon on 11/04/15.
 */
public class D {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner sc = new Scanner(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/Prel-D.in"));
    PrintWriter pw = new PrintWriter(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/Prel-D.out"));
    D a = new D();
    int c = sc.nextInt();
    for (int i = 0; i < c; i++) {
      pw.println("Case #" + (i + 1) + ": " + a.solve(sc));
    }
    pw.close();
    sc.close();
  }


  private String solve(Scanner sc) {
    int x = sc.nextInt();
    int r = sc.nextInt();
    int c = sc.nextInt();
    if(r>c) {
      int temp =r;
      r= c;
      c=temp;
    }

    if((r*c)%x!=0 || x>=7|| (r*c)<x) return "RICHARD";
    if(x<=2) return "GABRIEL";
    if(x==3) return (r>1&&c>1&&(r>2||c>2))? "GABRIEL":"RICHARD";
    if(x==4) {
      if(r<3||c<4) return "RICHARD";
      return "GABRIEL";
    }
    return "";
  }


}
