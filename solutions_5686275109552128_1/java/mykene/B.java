package prel;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created by rubenverboon on 11/04/15.
 */
public class B {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner sc = new Scanner(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/Prel-B.in"));
    PrintWriter pw = new PrintWriter(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/Prel-B.out"));
    B b = new B();
    int c = sc.nextInt();
    for (int i = 0; i < c; i++) {
      pw.println("Case #" + (i + 1) + ": " + b.solve(sc));
    }
    pw.close();
    sc.close();
  }


  private int solve(Scanner sc) {
    int D = sc.nextInt();
    PriorityQueue<Pancake> P = new PriorityQueue<>((a, b) -> b.length() - a.length());
    for (int i = 0; i < D; i++)
      P.add(new Pancake(sc.nextInt(), i));
    return solve(P);
  }

  private int solve(PriorityQueue<Pancake> stack) {
    Pancake first = stack.poll();
    int max = first.length();
    if (max <= 3 || first.d>7) return max;
    first.cut();
    stack.add(first);
    return Math.min(max, 1 + solve(stack));
  }


  class Pancake {
    int p;
    int d;
    int n;

    Pancake(int p, int n) {
      this.p = p;
      this.d = 1;
      this.n = n;
    }

    void cut() {
      d++;
    }

    int length() {
      int c = (p % d == 0) ? 0 : 1;
      return (p / d) + c;
    }

    @Override
    public boolean equals(Object obj) {
      if (obj instanceof Pancake) {
        Pancake that = (Pancake) obj;
        return that.n == this.n;
      }
      return false;
    }

    @Override
    public int hashCode() {
      return n;
    }
  }

}
