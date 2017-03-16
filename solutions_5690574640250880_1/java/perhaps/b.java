package code_jam;

import java.io.*;
import java.util.*;

public class b {
  static boolean[][][] f = new boolean[51][][];
  static int[][][] use = new int[51][][];
  static int r, c;
  public static void output(FileWriter outf, int i, int j, int k) throws Exception{
    System.out.println(i+"\t"+j+"\t"+k +"\t"+ use[i][j][k]);
    for (int l=0; l<j; l++) 
      if (i == r-1 && l==0) outf.write('c'); else outf.write('.');
    for (int l=j; l<c; l++)
      outf.write('*');
    outf.write('\n');
    if (i>0) output(outf, i-1, use[i][j][k], k-j);
  }
  
  public static void main(String[] args) throws Exception{
    Scanner inf = new Scanner(new FileReader("in.txt"));
    FileWriter outf = new FileWriter("out.txt");

    for (int i=0; i<=50; i++) {
      f[i] = new boolean[51][];
      use[i] = new int[51][];
      for (int j=0; j<51; j++) {
        f[i][j] = new boolean[2502];
        use[i][j] = new int[2502];
      }
    }
    
    int nn = inf.nextInt();
    for (int ii = 0; ii < nn; ii++) {
      System.out.println("Case #" + (ii+1) + ":\n");
      outf.write("Case #" + (ii+1) + ":\n");
      r = inf.nextInt();
      c = inf.nextInt();
      int m = inf.nextInt();
      if (r * c - 1 == m) {
        outf.write("c");
        for (int i=0; i<r; i++) {
          for (int j=0; j<c; j++)
            if (i + j > 0) outf.write("*");
          outf.write("\n");
        }
        continue;
      }
      if (r == 1 || c == 1) {
        for (int i=0; i<m; i++)
          if (r==1) outf.write("*"); else outf.write("*\n");
        for (int i=m; i<r-1 || i<c-1; i++)
          if (r==1) outf.write('.'); else outf.write(".\n"); 
        outf.write("c\n");
        continue;
      }
      int e = c*r - m;
      for (int i=0; i<=c; i++) {
        for (int j=0; j<=e; j++)
          f[0][i][i] = false;
        if (i!=1) f[0][i][i] = true;
      }
      f[0][0][0] = true;
      
      
      for (int i=1; i<r; i++)
        for (int j=0; j<=c; j++)
          for (int k=j; k<=e; k++) {
            if (j==1) {
              f[i][j][k]=false;
              continue;
            }
            if (i<r-1) {
              for (int last=0; last<=j; last++) 
                if (f[i-1][last][k-j]) {
                  f[i][j][k] = true;
                  use[i][j][k] = last;
                  break;
                }
            } else {
              f[i][j][k] = f[i-1][j][k-j];
              use[i][j][k] = j;
            }
          }
      boolean flag = true;
      for (int i=2; i<=c; i++)
        if (f[r-1][i][e]) {
          output(outf, r-1, i, e);
          flag = false;
          break;
        }
      if (flag) outf.write("Impossible\n");
    }
    inf.close();
    outf.close();
  }
}
