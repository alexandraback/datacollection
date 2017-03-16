import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class FairSquare {

  public BufferedReader br;
  public List<Long> list;
  public int t;
  public long a, b;

  public int lowerBound(long n) {
    int ret = Collections.binarySearch(list, n);
    return ret < 0 ? -ret - 2 : ret;
  }

  public boolean isPalindrome(long n) {
    return new StringBuilder(String.valueOf(n)).reverse().toString().equals(String.valueOf(n));
  }

  public void gen() {
    list = new ArrayList<Long>();
    for (long i = 1L; i <= 10000000L; i++)
      if (isPalindrome(i) && isPalindrome(i * i))
        list.add(i * i);
  }

  public void go() throws Throwable {
    gen();
    br = new BufferedReader(new InputStreamReader(System.in));
    t = Integer.parseInt(br.readLine());
    for (int caseNo = 1; caseNo <= t; caseNo++) {
      String[] ss = br.readLine().split(" +");
      a = Long.parseLong(ss[0]);
      b = Long.parseLong(ss[1]);
    	System.out.println("Case #" + caseNo + ": " + (lowerBound(b) - lowerBound(a-1)));
    }
  }

  public static void main(String[] args) throws Throwable {
    new FairSquare().go();
  }

}
