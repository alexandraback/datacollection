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
      //if(i==36)
  	//	System.out.println(k + " "+ c + " " + s);
      if(c*s<k)
      {
    	  System.out.println("Case #" + i + ": IMPOSSIBLE");
      }
      else{
      long valueTrack;
      long[] exponent = new long[c+1];
      exponent[0]=1;
      System.out.print("Case #" + i + ":");
      for(int n =1; n<=c;n++){
		  exponent[n]=exponent[n-1]*k;
		 
	  }
      long[] values = new long[s];
      int count = 0;
      for(int r=0; r<s; r++){
    	  valueTrack=0;
    	  for(int j=0;j<c;j++){
    		  if(count<k){
    			  valueTrack=valueTrack+((r*c)+(j))*exponent[j];
    			  count++; 
    		  }
    	  }
    	  
    	
    	  values[r]=1+valueTrack;
    	  if(count<k)
    	  {
    		  System.out.print(" " + values[r]);
    	  }
    	  else if (count==k)
    	  {
    		  System.out.print(" " + values[r]);
    		  count++;
    	  }
    	  
      }
      System.out.println();
      }
    }
  }
}