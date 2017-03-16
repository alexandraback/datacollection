import java.math.BigInteger;

public class jamCoinJava {
  static long pots[][] = new long[11][20];

  private static long getFactor(long N, int base) {
    long r;

    BigInteger g = BigInteger.valueOf(1);
    BigInteger zero = BigInteger.valueOf(0);

    for(int i = 1; i <= 31; i++) {
      g = g.multiply(BigInteger.valueOf(base));
    }

    if((N%2 + g.remainder(BigInteger.valueOf(2)).longValue())%2 == 0)
      return 2;

    for(r = 3; r*r < N; r += 2) {
      if((N%r + g.remainder(BigInteger.valueOf(r)).longValue())%r == 0) return r;
    }

    return 0;
  }

  private static long interpret(long N, int base) {
    long res = 0;
    int p = 0;

    while(N != 0) {
      res += (N & 1) * pots[base][p];
      N = N / 2;
      p++;
    }

    return res;
  }

  private static void imprime(long  N) {
    long mask = 0x20000L;

    System.out.print("10000000000000");

    for(int i = 0; i < 18; i++) {
      if((N & mask) != 0) System.out.print("1");
      else System.out.print("0");
      mask = mask/2;
    }
  }

  public static void main(String[] args) {
    long divs[] = new long[11];

    for(int i = 2; i <= 10; i++) {
      pots[i][0] = 1;
      for(int j = 1; j < 19; j++) {
        pots[i][j] = pots[i][j-1]*i;
      }
    }

    System.out.println("Case #1:");

    long N = 0x1;
    int k = 0;
    boolean found;

    while(k < 500 && N <= 0x3FFFFL) {
      //System.out.println(k);
      found = true;

      for(int base = 2; base <= 10; base++) {
        divs[base] = getFactor(interpret(N, base), base);
        if(divs[base] == 0) {
          found = false;
          break;
        }
      }

      if(found) {
        k++;
        imprime(N);
        for(int base = 2; base<= 10; base++) {
          System.out.print(" ");
          System.out.print(divs[base]);
        }
        System.out.print("\n");
      }

      N = N+2;
    }
  }
}
