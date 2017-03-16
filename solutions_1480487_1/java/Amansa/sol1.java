package ques1;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class sol1 {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		for(int l=0;l<T;l++){
			int n = input.nextInt();
			int[] s = new int[n];
			double x = 0;
			for(int i=0;i<n;i++){
				s[i] = input.nextInt();
				x = x + (double)s[i];
			}
			int m = n;
			int[] a = new int[n];
			for(int i=0;i<n;i++){
				a[i] = 0;
			}
			double p = 2*x;
			for(int i=0;i<n;i++){
				if(s[i]>=(double)2*x/n){
					m--;
					a[i] = 1;
					p = p - s[i];
					//System.out.println(i);
				}
				
			}
			//System.out.println("p = "+p);
			double ans[] = new double[n];
			for(int i=0;i<n;i++){
				if(m!=n){
					if(a[i]==0){
						ans[i] = ((p/m - s[i])*100)/x;
					}
					else
						ans[i] = 0;
				}
				else{
					ans[i] = ((p/m - s[i])*100)/x;
				}
			}
			System.out.println();
			System.out.print("Case #"+(l+1)+": ");
			for(int i=0;i<n;i++){
				//BigDecimal bd = new BigDecimal(ans[i]).setScale(6, RoundingMode.HALF_EVEN);
				//double d = bd.doubleValue();
				System.out.print(ans[i]+" ");
			}
		}
	}
}
