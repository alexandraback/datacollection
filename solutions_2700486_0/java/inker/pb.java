
import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

public class pb{
	
	// static
	
	public static void main(String zArgs[]){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt(), cc = 0;
		while(t -- > 0){
			
			int n = sc.nextInt(), x = sc.nextInt(), y = sc.nextInt();
			
			x = Math.abs(x);
			y = Math.abs(y);
			
			double ans = 0.0;
			if( x + y == 0)
			{
				ans = 1.0;
			}
			else{
				int i = ((x + y)/2), sd = i + i + 1, nn = 2*(i)*(i+1)-3*i;
				if( nn <= n){
					n -= nn;
					//System.out.println(Integer.toString(n));
					if(n >= sd+sd-1){
						ans = 1.0;
					}
					else if(x == 0){
						ans = 0.0;
					}
					else{
						double [] dp = new double [sd+2];
						
						dp[0] = 1.0;
						for( int nnn = 1; nnn <= n ; nnn ++)
						{
							double[] dp2 = new double[sd+2];
						for(i = sd - 1 ; i >= 0  ; i --)
						{
							if( nnn - 1 - i == sd-1){
								dp2[i+1] += dp[i];
							}
							else if(i == sd - 1){
								dp2[i] += dp[i];
							}
							else{
								dp2[i+1] += 0.5 *dp[i];
								dp2[i] += 0.5 * dp[i];
							}
						}
							dp = dp2;
						}
						ans = 0.0;
						for(i = sd - 1 ; i >= y+1 ; i --)
							ans += dp[i];
					}
				}
			}
			
			
			
			System.out.println("Case #" + Integer.toString(++cc) + ": " + Double.toString(ans));
		}
	}
}
