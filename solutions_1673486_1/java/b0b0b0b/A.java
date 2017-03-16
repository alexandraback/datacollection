import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class A {
  public static void main(String[]args) throws Exception {
    File f = new File(args[0]);
    File f2 = new File(f.getParentFile(),f.getName()+".out");
    Scanner s = new Scanner(f);
    int T = s.nextInt();
    for (int t = 1; t <= T; t++) {
      int A = s.nextInt();
      int B = s.nextInt();
      double d[] = new double[A];
          
      for (int i=0;i<A;i++)
        d[i]=s.nextDouble();
      
      println(f2,"Case #"+t+": "+solve(A,B,d));
    }
    s.close();
  }
  private static String solve(int a, int b, double[] d) {
    double p = 1;
    for (int i=0;i<a;i++) {
      p *= d[i];
    }
    double kepgoing = p * (b-a+1) + (1-p) * (b-a+1 + b+1);
    double pushenter = 1 + b + 1;
    double best = Math.min(kepgoing, pushenter);
    for (int backspaces=1; backspaces<a; backspaces++) {
      double correct = 1;
      for (int i=0;i<a-backspaces;i++) {
        correct *= d[i];
      }
      double val = correct * (b-a+backspaces+backspaces+1) + (1-correct) * (b-a+backspaces+backspaces+1 + b+1);
      if (val < best) best = val;
    }
    return best+"";
  }
  static void println(File f, String s) throws Exception {
    FileWriter w = new FileWriter(f,true);
    w.write(s+"\n");
    w.close();
    System.out.println(s);
  }
}
