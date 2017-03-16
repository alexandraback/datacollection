import java.io.*;
import java.util.*;

public class C
{
  static final int I = 2;
  static final int J = 3;
  static final int K = 4;
  static int[][] table;
  long curj, curk;

  String s;
  long reps;
  long len; 

  public C(String s, long reps) {
    this.s = s;
    this.reps = reps;
    this.len = s.length() * reps;
  }

  public int getc(long i) {
    char c = s.charAt((int)(i % s.length()));
    return c - 'i' + 2;
  }

  public static int getc(String s, int i) {
    return s.charAt(i) - 'i' + 2;
  }

  public static int op(int a, int b) {
    int res = table[Math.abs(a)][Math.abs(b)];
    //System.out.format("%d %d %d\n", a, b, res);
    if(a * b < 0)
      return -res;
    else
      return res;
  }

  public static int eval(String s) {
    int res = 1;
    for(int i = 0; i < s.length(); i++) {
      res = op(res, getc(s, i));
    }
    return res;
  }
  
  public int FGM( int value, int power ){
    int arrayLength = 0; 
    int temp = power;
    int totalValue = 1; //this may be something else if there is something before complete cycles, like BC ABC ABC ABC, it'll be BC
    while( temp != 0 ){
        arrayLength ++;
        temp /= 2;
    }
    
    int[] valuePowers = new int[arrayLength];
    valuePowers[0] = value;
   for( int i = 1 ; i < arrayLength; i++){ //for each power of value
       valuePowers[i] = op(valuePowers[i - 1 ], valuePowers[i - 1]);
   }
   //now multiply values
   temp = power;
   int counter = 0;
   while( temp != 0){
       if (temp % 2 == 1 ){
              totalValue = op(totalValue, valuePowers[ counter ]); //change it into oppppp!
              
       }
       counter ++;
       temp /= 2;
   }
   return totalValue;
  }  

  public boolean solve(long start, int target) {
    int res = 1;
    long p = start;

    if(target == K) {
      long currep = p / s.length() + 1;
      int repsleft = (int)(reps - currep);
      for(long i = p % s.length(); i < s.length(); i++) 
        res = op(res, getc(i));
      if(repsleft > 0)
        res = op(res, FGM(eval(s), repsleft));
      if(res == K)
        return true;
      else
        return false; 
    }

    while(p < len && (p - start + 1) <= 5*s.length()) {
      res = op(res, getc(p));
      if(target == I && res == I) {
        curj = p + 1;
        return solve(p + 1, J);
      } else if(target == J && res == J) {
        curk = p + 1;
        return solve(p + 1, K);
      }
      p++;
    }

    return false;
  }

    public static void main(String[] args)
  {  
    int[][] init = {
      {0, 0, 0, 0, 0},
      {0, 1, I, J, K},
      {0, I, -1, K, -J},
      {0, J, -K, -1, I},
      {0, K, J, -I, -1}
    };
    table = init;

    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    sc.nextLine();
    for(int t = 1; t <= T; t++) {
      long L = sc.nextLong();
      long X = sc.nextLong();
      sc.nextLine();
      String s = sc.nextLine();
      C problem = new C(s, X);
      //System.out.format("%s = %d\n", s, eval(s));
      System.out.format("Case #%d: %s\n", t, problem.solve(0, I) ? "YES" : "NO");
    }
    sc.close();
    }
}