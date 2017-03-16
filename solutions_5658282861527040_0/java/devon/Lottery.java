package com.devon;

import java.io.InputStream;
import java.util.Scanner;

public class Lottery {
	public void go(InputStream is) {
		Scanner s = new Scanner(is);
		int count = s.nextInt();
		for(int i=0;i<count;i++) {
			int a = s.nextInt();
			int b = s.nextInt();
			int k = s.nextInt();
			
			long choices = calc(a,b,k);
			System.out.println("Case #"+(i+1)+": " +  choices);
		}
		
	}

	private long calc(int a, int b, int k) {
		long result = 0;
		for(int i=0;i<a;i++) {
			for(int j=0;j<b;j++) {
				if( (i & j) < k) {
					result++;
				}
			}
		}
		
		
		return result;
	}
}
