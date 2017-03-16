import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class A_Osmos {
  Scanner in;

  public static void main(String[] args) throws Exception  {
    new A_Osmos().run();
  }

  void run() throws Exception {
    //System.setIn(new FileInputStream("A-test.in"));
    //System.setIn(new FileInputStream("A-small-attempt0.in"));
    //System.setOut(new PrintStream("A-small-attempt0.out"));
    System.setIn(new FileInputStream("A-large.in"));
    System.setOut(new PrintStream("A-large.out"));
    in = new Scanner(System.in);
    int T = in.nextInt();
    for (int c = 1; c <=T; ++c) {
      int S = in.nextInt(), N = in.nextInt();
      int [] m = new int [N];
      for(int i  = 0; i < N; ++i)
        m[i] = in.nextInt();
      //System.out.println(Arrays.toString(m));

      Arrays.sort(m);
      int ac = S;
      int pos = 0;
      int res = 0;
      int res2 = N;
      while(pos < N) {
        res2 = Math.min(res2, res + N-pos);
        if(ac>m[pos]){
          ac += m[pos];
          pos++;
        } else{
          ac+=(ac-1);
          if(ac-1 == 0)
            pos++;
          res++;
        }
      }
      System.out.println(String.format("Case #%d: %d", c, Math.min(res,res2)));
    }
  }
}
