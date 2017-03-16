package com.helic.codejam;

import java.util.Scanner;

public class CodeJam1C2 {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		String ans = "";
		int t = scan.nextInt();
		int x = 0;
		int y = 0;
		for (int i=1;i<=t;i++){
			x = scan.nextInt();
			y = scan.nextInt();
			
			ans = "Case #"+i+": ";
			
			if (x>0){
				for (int j=1;j<=x;j++){
					ans = ans +"WE";
				}
			}else if (x<0){
				for (int j=-1;j>=x;j--){
					ans = ans +"EW";
				}
			}
			
			if (y>0){
				for (int j=1;j<=y;j++){
					ans = ans +"SN";
				}
			}else if (y<0){
				for (int j=-1;j>=y;j--){
					ans = ans +"NS";
				}
			}
			
			System.out.println(ans);
		}
	}

}
