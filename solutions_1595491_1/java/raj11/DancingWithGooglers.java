package com.google.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class DancingWithGooglers {
	public static void main(String argsp[]) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("/Users/ashwinjain/Desktop/SmsLogger/InterviewStreet/src/com/google/codejam/in2b.txt")));
		int cases = Integer.parseInt(br.readLine());
		
		for(int x=0;x<cases;x++){
			String temp[] = br.readLine().split(" ");
			int googlers = Integer.parseInt(temp[0]);
			int suprises = Integer.parseInt(temp[1]);
			int minScore = Integer.parseInt(temp[2]);
			
			int nums[] = new int[googlers];
			for(int i=0;i<googlers;i++) {
				nums[i]=Integer.parseInt(temp[i+3]);
			}
			
			int n[] = new int[googlers];
			int s[] = new int[googlers];
			
			for(int i=0;i<googlers;i++){
				if(nums[i]==0){
					n[i]=0;s[i]=0;
				}else if(nums[i]==1){
					n[i]=1;s[i]=1;
				}else if(nums[i]==2){
					n[i]=1;s[i]=2;
				}else if(nums[i]%3==0){
					n[i]=nums[i]/3;
					s[i]=n[i]+1;
				}else if(nums[i]%3==1){
					n[i]=nums[i]/3+1;
					s[i]=n[i];
				}else if(nums[i]%3==2){
					n[i]=nums[i]/3+1;
					s[i]=n[i]+1;
				}
			}
			int ans=0;
			int tempans = 0;
			for(int i=0;i<googlers;i++){
				if(n[i]>=minScore){
					ans++;
					s[i]=-1;
				}
				if(s[i]>=minScore){
					tempans++;
				}
			}
			
			ans = ans+Math.min(suprises, tempans);
			System.out.println("Case #"+(x+1)+": "+ans);
		}
		
	}
}
