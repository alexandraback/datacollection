import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class TaskC {
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C-small-attempt0.out")));
    SolverC solver = new SolverC();
    solver.solve(in, out);
    in.close();
    out.close();
  }
}

class SolverC{
  public void solve(BufferedReader in, PrintWriter out) throws IOException {
    int ntest = Integer.parseInt(in.readLine());
    ArrayList<Long> cache = new ArrayList<Long>();
    for (long i = 1; i < (long)(10e7 + 1000); i++)
      if (isPal(i) && isPal(i * i))
        cache.add(i * i);
    for (int itest = 1; itest <= ntest; itest++) {
      StringTokenizer st = new StringTokenizer(in.readLine());
      long a = Long.parseLong(st.nextToken()), b = Long.parseLong(st.nextToken());
      int res = 0;
      for (Long i : cache){
        if (a <= i && i <= b)
          res++;
      }
      out.println(String.format("Case #%d: %d", itest, res));
    }
  }

  public boolean isPal(long n){
    long k = n;
    long revN = 0;
    while (k != 0){
      revN *= 10;
      revN += (k % 10);
      k /= 10;
    }
    return revN == n;
  }
}
