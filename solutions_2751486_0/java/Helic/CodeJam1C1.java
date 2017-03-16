package com.helic.codejam;

import java.util.*;
import java.math.*;

public class CodeJam1C1 {
	
	public static void main(String[] args) {
		int[] a = new int[2000000];
		String s = "";
		int n = 0;
		int l = 0;
		long ans = 0;
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		
		for (int i=1;i<=t;i++){
			s = scan.next();
			n = scan.nextInt();
			l = s.length();
			Arrays.fill(a,0);
			ans = 0;
			int mark = 0;
			int last = 0;
			int left = 0;
			int right = 0;
			for (int k=0;k<l;k++){
				if ((s.charAt(k)=='a')||(s.charAt(k)=='e')||(s.charAt(k)=='i')||(s.charAt(k)=='o')||(s.charAt(k)=='u')){
					mark=0;
				}else{
					mark++;
				}
				a[k+1]=mark;
			}
			
			for (int k=1;k<=l;k++){
				if (a[k]>=n){
					left = (k-n+1-last);
					right = l-k+1;
					ans += left * right;
					last = k-n+1;
				}
			}
			System.out.println("Case #"+i+": "+ans);
		}
		

	}

}
