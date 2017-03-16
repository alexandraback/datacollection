import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class QC {

  public static LinkedList<BigInteger> allSquarePalindrome = new LinkedList<BigInteger>();

  static String next(BigInteger n){
    n = n.add(BigInteger.ONE);
    char [] arr = n.toString().toCharArray();
    int init = 0 , end = arr.length - 1;
    while (init < end ){
      if ( arr[init] > arr[end] ){
        arr[end] = arr[init];
        ++init; --end;
      }else if ( arr[init] == arr[end] ){
        ++init; --end;
      }else{
        arr[end] = arr[init];
        int secondEnd = end - 1;
        ++arr[secondEnd];
        while ( arr[secondEnd] > '9' ){
          arr[secondEnd] = '0';
          --secondEnd;
          ++arr[secondEnd];
        }
      }
    }
    return new String(arr);
  }

  static class PalindromeThread implements Runnable{
    BigInteger start;
    BigInteger top;

    PalindromeThread(BigInteger start, BigInteger top) {
      this.start = start;
      this.top = top;
    }

    public void run() {
      for (BigInteger i = start; i.compareTo(top) <= 0; i = new BigInteger(next(i))) {
        BigInteger i2 = i.multiply(i);
        String i2s = i2.toString();
        if ( new StringBuilder(i2s).reverse().toString().equals(i2s) ){
          allSquarePalindrome.add(i2);
        }
      }
    }
  }

  public static void main(String[] args) {

    final String PREFIX = "/home/saul/IdeaProjects/CodeJam/src/";

    try {
      Scanner sc = new Scanner(new File(PREFIX + "C-small-attempt0.in"));
      PrintWriter out = new PrintWriter(new File(PREFIX + "QC.out"));
      //PrintWriter out = new PrintWriter(System.out);
      int n = sc.nextInt();

      int [] fractions = new int[]{0,7};
      PalindromeThread [] p = new PalindromeThread[fractions.length - 1];
      for (int i = 0; i < p.length; i++) {
        p[i] = new PalindromeThread(
          (fractions[i] == 0 ? BigInteger.ZERO : new BigInteger("10").pow(fractions[i]).add(BigInteger.ONE)),
          new BigInteger("10").pow(fractions[i+1]));
      }
      Thread [] t = new Thread[p.length];
      for (int i = 0; i < p.length; i++) {
        t[i] = new Thread(p[i]);
      }
      for (int i = 0; i < t.length; i++) {
        t[i].start();
      }
      for (int i = 0; i < t.length; i++) {
        t[i].join();
      }

      for (int iCases = 0; iCases < n; iCases++) {
        BigInteger a = sc.nextBigInteger() , b = sc.nextBigInteger();
        int ans = 0;
        for ( BigInteger number : allSquarePalindrome ){
          if ( a.compareTo(number) <= 0 && b.compareTo(number) >= 0 ){
            ++ans;
          }
        }
        out.println("Case #" + (iCases+1) + ": " + ans);
      }
      out.close();
    }catch (Exception ex){
      ex.printStackTrace();
    }
  }
}
