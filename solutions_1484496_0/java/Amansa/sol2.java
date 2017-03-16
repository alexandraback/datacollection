package ques2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class sol2 {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		for(int l=0;l<T;l++){
			int n = input.nextInt();
			int[] s = new int[20];
			for(int i=0;i<n;i++){
				s[i] = input.nextInt();
			}
			int i,ans=0;
			//Arrays.sort(s);
			for(i=1;i<Math.pow(2,n);i++){
				String bin = Integer.toBinaryString(i);
				char[] b = new char[n];
				for(int k=0;k<bin.length();k++){
					b[k] = bin.charAt(bin.length()-k-1);					
				}
				for(int k=bin.length();k<n;k++){
					b[k] = '0';
				}
				int sum = 0;
				for(int j=0;j<n;j++){
					if(b[j]!='0'){
						sum = sum + s[j];
					}
				}
				ans = check(sum, i, s, n);
				if(ans!=0){
					//System.out.println("i="+i+" ans="+ans);
					break;
				}
			}
			if(ans==0){
				System.out.println("Case #"+(l+1)+": Impossible");
			}
			System.out.println("Case #"+(l+1)+": ");
			String bin = Integer.toBinaryString(i);
			char[] b = new char[n];
			//System.out.println(bin);
			for(int k=0;k<bin.length();k++){
				b[k] = bin.charAt(bin.length()-k-1);					
			}
			for(int k=bin.length();k<n;k++){
				b[k] = '0';
			}
			for(int j=0;j<n;j++){
				if(b[j]!='0'){
					System.out.print(s[j]+" ");
				}
			}
			System.out.println();
			bin = Integer.toBinaryString(ans);
			for(int k=0;k<bin.length();k++){
				b[k] = bin.charAt(bin.length()-k-1);					
			}
			for(int k=bin.length();k<n;k++){
				b[k] = '0';
			}
			for(int j=0;j<n;j++){
				if(b[j]!='0'){
					System.out.print(s[j]+" ");
				}
			}
			System.out.println();
		}
	}
	static int check(int sm, int m, int[] s, int n){
		//System.out.println(sm+" is sum ");
		for(int i=0;i<Math.pow(2,n);i++){
			if(i!=m){
				String bin = Integer.toBinaryString(i);
				char[] b = new char[n];
				for(int k=0;k<bin.length();k++){
					b[k] = bin.charAt(bin.length()-k-1);					
				}
				for(int k=bin.length();k<n;k++){
					b[k] = '0';
				}
				int sum = 0;
				for(int j=0;j<n;j++){
					if(b[j]!='0'){
						sum = sum + s[j];
					}
				}
				if(sum == sm){
					return i;
				}
			}
		}
		return 0;
	}
}
