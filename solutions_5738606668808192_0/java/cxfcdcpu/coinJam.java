import java.io.*;
import java.util.*;

public class coinJam{
	
  public static void main(String[] args) {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t = in.nextInt();
	
    for (int i = 1; i <= t; ++i) {
      int n = in.nextInt();
	  int j = in.nextInt();
	  boolean isPrime=false;
	  int c=0;
	  String starting="1";
	  for(int k=1;k<n-1;k++){
		  starting+="0";
	  }
	  starting+="1";
	  long startInt;
	  long[] div=new long[9];
	  System.out.println("Case #" + i + ": ");
	  while(c<j){
		//System.out.println("Current working on: "+starting);
		isPrime=false;
		for(int l=2;l<=10;l++){
			if(!isPrime){
				long current=Long.parseLong(starting,l);
				div[l-2]=checkPrime(current);
				if(div[l-2]==0)isPrime=true;
			}
		}
		if(!isPrime){
			c++;
			System.out.print(starting);
			for(long d:div){
				System.out.print(" "+d);
				
			}
			System.out.println("");
		}  
		  
		startInt=Long.parseLong(starting,2);
		startInt+=2;
		starting=Long.toBinaryString(startInt);
		
	  }
	 
	  
	}
	
	
  }
  
  public static long checkPrime(long current){
	  long mid=(long)Math.sqrt(current)+1;
	  for(int i=2;i<=mid;i++){
		  if(current%i==0)return i;
	  }
	  return 0;
  }
  
}