import java.util.*;
import java.io.*;

public class CoinJam {
  public static void main(String[] args) throws Exception {
    Scanner scan = new Scanner(new File("C-large.in"));
    PrintWriter pw = new PrintWriter(new File("C.out"));

    Scanner scanp = new Scanner(new File("primes.txt"));
    //Scanner scan = new Scanner(System.in);
    //PrintWriter pw = new PrintWriter(System.out);
   
    // get prime numbers
    long[] primes = new long[7660];
    int index = 0;
    while(scanp.hasNext()) {
      primes[index] = scanp.nextLong();
      index++;
    }
    
    int t = scan.nextInt();
    
    for(int i=0; i<t; i++) {
      int n = scan.nextInt();
      int j = scan.nextInt();
      
      // starting coin candidate
      char[] start = new char[n];
      start[0] = '1';
      start[start.length-1] = '1';
      for(int k=1; k<start.length-1; k++) {
        start[k] = '0';
      }
      
      String cur = String.valueOf(start);
      long[] divisors = new long[11];
      
      pw.println("Case #" + (i+1) + ": ");
      // try to find j jamcoins
      while(j > 0) {
        for(int k=0; k<divisors.length; k++) divisors[k] = 0;
        
        // check if cur is a jamcoin
        for(int k=2; k<=10; k++) {
          // in base k, find a divisor
          long value = inBase(cur, k);
          for(int p=0; p<primes.length; p++) {
            if(value%primes[p] == 0 && value!=primes[p]) {
              divisors[k] = primes[p];
              break;
            }
          }
          
          // if no divisor, cut losses and go on
          if (divisors[k] == 0) break;
        }
        
        //if found jamcoin, j-- and print out
        if (divisors[10] != 0) {
          pw.print(cur + " ");
          for(int k=2; k<=10; k++) {
            pw.print(divisors[k] + " ");
          }
          pw.println();
          j--;
        }
        
        // move to the next jamcoin
        cur = nextCoin(cur);
      }
    }
    

    pw.close();  
    
  }
  
  // gives the value of the candidate coin in the given base
  public static long inBase(String coin, long base) {
    long value = 0;
    int index = coin.length()-1;
    long multiplier = 1;
    
    while(index >= 0) {
      if (coin.charAt(index) == '1') {
        value += multiplier;
      }
      
      multiplier *= base;
      index--;
    }
    
    return value;
  }
  
  public static String nextCoin(String curCoin) {
    char[] next = new char[curCoin.length()];
    for (int i=0; i<curCoin.length(); i++) next[i] = curCoin.charAt(i);
    
    int i=next.length-2;
    while(next[i] == '1') {
      next[i] = '0';
      i--;
    }
    next[i] = '1';
    
    return String.valueOf(next);
  }
}