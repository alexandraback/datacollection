import java.util.*;
import java.io.*;
public class Pancakes {
  public static void main(String[] args) throws IOException{
	  //Scanner in = new Scanner(System.in);
	  Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
    for (int i = 1; i <= t; ++i) {
      String S = in.next();
      int length= S.length();
      int flips = 0;
      for(int j = length-1; j >=0; j--){
    	  if(S.charAt(j)=='+'){
    		  if(flips%2==1){
    			  flips++;
    		  }
      }
    	  else{
    		  if(flips%2==0){
    			  flips++;
    		  }
    	  }
      }
      System.out.println("Case #"+ i + ": " +flips);
      
  }
  }
}