import java.util.*;
import java.io.*;
public class gold {
  public static void main(String[] args) throws IOException{
    //Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
  Scanner in = new Scanner(System.in);
    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
    for (int i = 1; i <= t; ++i) {
      int k = in.nextInt();
      int c = in.nextInt();
      int s = in.nextInt();
      long kcMinusOne=1;
      long[] values = new long[k];
      for(int j=1;j<c;j++){
    	  kcMinusOne= kcMinusOne*k;
      }
      System.out.print("Case #" + i + ":");
      for(int j=0; j<k; j++){
    	  values[j]=1+j*kcMinusOne;
    	  System.out.print(" " + values[j]);
      }
      System.out.println();
      
    }
  }
}