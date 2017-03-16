import java.io.*;
import java.util.*;

public class fractiles{
	
  public static void main(String[] args) {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t = in.nextInt();
	
    for (int i = 1; i <= t; ++i) {
      int k = in.nextInt();
	  int c = in.nextInt();
	  int s = in.nextInt();
	  long total=(long)Math.pow(k,c);
	  System.out.print("Case #"+i+":");
	  if(s<(int)Math.ceil(k/c))System.out.println(" IMPOSSIBLE");
	  else{
		
		for(int start=1;start<=k;start=start+c){
			long target=0;
			for(int cstart=c-1;cstart>=0;cstart--){
				target+=((start+c-cstart-2)%k)*(long)Math.pow(k,cstart);
			}
			target++;
			System.out.print(" "+target);
		}  
		System.out.println("");
		  
	  }
	}
  }
}