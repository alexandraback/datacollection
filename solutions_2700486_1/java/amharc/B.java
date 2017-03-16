import java.util.*;
import java.io.*;
import java.math.*;

public class B {
  Scanner sc;
  BigDecimal newton[];
  
  public B() {
    sc = new Scanner(System.in);
    newton = new BigDecimal[100005];
  }

  public void solveAll() {
    int T = sc.nextInt();
    for(int tc = 1; tc <= T; ++tc) {
      System.out.printf("Case #%d: %.8f\n", tc, testcase());
    }
  }

  long count_blocks_upto(int lev) {
    long blk = 0;
    for(int i = 0; i <= lev; ++i) {
      blk += 4 * i + 1;
    }
    return blk;
  }

  void gen_newton(int N) {
    newton[0] = (new BigDecimal(0.5)).pow(N);

    for(int i = 1; i <= N / 2; ++i) {
      newton[i] = newton[i - 1].multiply(new BigDecimal(N - i + 1)).divide(new BigDecimal(i));
    }

    for(int i = N / 2 + 1; i <= N; ++i)
      newton[i] = newton[N - i];
  }

  double testcase() {
    int X, Y, N;
    N = sc.nextInt();
    X = sc.nextInt();
    Y = sc.nextInt();

    if(X < 0)
      X = -X;

    int lev = (X + Y) / 2;

    if(count_blocks_upto(lev - 1) >= N)
      return 0;
    if(count_blocks_upto(lev) <= N)
      return 1;

    if(X == 0)
      return 0;

    N -= count_blocks_upto(lev - 1);
    gen_newton(N);

    BigDecimal res = BigDecimal.ZERO;

    for(int right = 0; right <= N; ++right) {
      int cnt = right;

      if(right > 2 * lev)
        cnt = 2 * lev;

      if(N - right > 2 * lev)
        cnt += N - right - 2 * lev;

      if(cnt > Y)
        res = res.add(newton[right]);
    }
    
    return res.doubleValue();
  }

  public static void main(String[] args) {
    B solver = new B(); 
    solver.solveAll();
  }
}

