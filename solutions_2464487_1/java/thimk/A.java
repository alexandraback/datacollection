import java.util.*;
import java.math.*;

public class A
{
    public static long paint(long k, long r)
    {
	return k*(2*r+1) + 2*k*(k-1);
    }
    public static void main(String args[])
    {
	Scanner in = new Scanner(System.in);

	int T = in.nextInt();

	for(int caseno = 1; caseno <= T; caseno++){
	    System.out.print("Case #" + caseno + ": ");
	    long r = in.nextLong();
	    long t = in.nextLong();

	    long min, max;
	    min = 1;
	    max = 2;
	    while(paint(max,r) <= t){
		max *=2;
		min *=2;
	    }

	    while(max - min >1){
		long mid = min + (max - min)/2;
		if(paint(mid,r) <= t)
		    min = mid;
		else
		    max = mid;
	    }
		  
	    System.out.println(min);
	}
    }

}