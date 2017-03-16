
import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

public class pa{
	
	// static

	public static void main(String zArgs[]){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt(), cc = 0;
		while(t -- > 0){
			
			int a = sc.nextInt(), n = sc.nextInt();
			
			int [] arr = new int [n];
			for(int i = 0; i < n ; i ++)
				arr[i] = sc.nextInt();
			Arrays.sort(arr);
			
			int ans = n, tans = 0;
			
			if(a != 1){
			for(int i = 0 ; i < n ; i ++){
				
				if(a > arr[i]){
				}
				else{
					while(a <= arr[i])
					{
						a += a - 1;
						tans ++;
					}
					
				}
				a += arr[i];

				ans = Math.min(ans, tans + (n - i - 1));
			}
			}
			
			System.out.println("Case #" + Integer.toString(++cc) + ": " + Integer.toString(ans));
		}
	}
}
