import java.io.*;
import java.util.*;

public class C{
  //1=0, i=1, j=2, k=3, -1=4, -i=5, -j=6, -k=7
  static int[][] table = new int[][]{{0, 1, 2, 3, 4, 5, 6, 7},
                                     {1, 4, 3, 6, 5, 0, 7, 2},
                                     {2, 7, 4, 1, 6, 3, 0, 5},
                                     {3, 2, 5, 4, 7, 6, 1, 0},
                                     {4, 5, 6, 7, 0, 1, 2, 3},
                                     {5, 0, 7, 2, 1, 4, 3, 6},
                                     {6, 3, 0, 5, 2, 7, 4, 1},
                                     {7, 6, 1, 0, 3, 2, 5, 4}};
  
  public static void main (String[] args) throws IOException{
    Scanner in = new Scanner (new FileReader("C-small-attempt1.in"));
    PrintWriter out = new PrintWriter ("C.out");
    int cases = in.nextInt();
    testLoop:
    for (int casenum = 1; casenum <= cases; casenum++){
      int l = in.nextInt();
      long x = in.nextLong();
      String part = in.next();
      int[] frag = new int[(int)l];
      for (int i = 0; i < l; i++){
        switch (part.charAt(i)){
          case 'i':
            frag[i] = 1;
            break;
          case 'j':
            frag[i] = 2;
            break;
          case 'k':
            frag[i] = 3;
        }
      }
      int i = 0;
      boolean[] j = new boolean[8];
      boolean[] newj = new boolean[8];
      boolean[] k = new boolean[8];
      boolean[] newk = new boolean[8];      
      for (int a = 0; a < x; a++){
        for (int b = 0; b < l; b++){
          i = table[i][frag[b]];
          Arrays.fill (newk, false);
          Arrays.fill (newj, false);
          for (int c = 0; c < 8; c++){
            if (j[c])
              newj[table[c][frag[b]]] = true;
            if (k[c])
              newk[table[c][frag[b]]] = true;
          }
          newj[0] = newj[0] || i == 1;
          newk[0] = newk[0] || newj[2];
          for (int c = 0; c < 8; c++){
            j[c] = newj[c];
            k[c] = newk[c];
          }
        }
      }
      
      if (k[3])
        out.println ("Case #" + casenum + ": YES");
      else
        out.println ("Case #" + casenum + ": NO");
     }
    out.close();
    in.close();
  }
}