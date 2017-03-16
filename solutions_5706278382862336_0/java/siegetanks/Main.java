import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
  public static void main (String[] args)  throws java.lang.Exception { 
    Scanner sc = new Scanner(System.in);
    BufferedWriter out = new BufferedWriter(new FileWriter("ans.out"));
    
    int T = sc.nextInt();
    long P, Q;
    StringBuilder ans = new StringBuilder();
    for (int k = 1; k <= T; k++) {
      String[] temp = sc.next().split("/");
      P = Long.parseLong(temp[0]);
      Q = Long.parseLong(temp[1]);
      Long tempo = Q;
      while (tempo != 1) {
        if ((tempo%2) != 0) {
          output(out, k, "impossible");
          break;
        }
        tempo /= 2;
      }
      if (tempo != 1) continue;
      int count = 0;
      while (Q > P) {
        Q /= 2;
        count++;
      }
      output(out, k, "" + count);
    }
    out.close();
  }
  
  public static void output(BufferedWriter out, int caseNum, String string) throws IOException{
    out.write("Case #" + caseNum + ": " + string + "\n"); }
}

class Pair implements Comparable{
  Integer first, second;
  public Pair(Integer f, Integer s) { first = f; second = s; }
  public int compareTo(Object o) {
    if (!this.second.equals(((Pair)o).second)) return this.second - ((Pair)o).second;
    else return this.first - ((Pair)o).first; }
}

class Triple implements Comparable {
  Integer first, second, third;
  public Triple(Integer f, Integer s, Integer t) { first = f; second = s; third = t; }
  public int compareTo(Object o) {
    if (!this.first.equals(((Triple)o).first)) return this.first - ((Triple)o).first;
    else if (!this.second.equals(((Triple)o).second)) return this.second - ((Triple)o).second;
    else return this.third - ((Triple)o).third; }
}