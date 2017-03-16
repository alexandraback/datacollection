package com.google.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class RecycledNumbers {
	public static void main(String argsp[]) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("/Users/ashwinjain/Desktop/SmsLogger/InterviewStreet/src/com/google/codejam/in3b.txt")));
		int cases = Integer.parseInt(br.readLine());
		for(int x=0;x<cases;x++){
			String temp[] = br.readLine().split(" ");
			long a = Long.parseLong(temp[0]);
			long b = Long.parseLong(temp[1]);
			long c=a;
			long count=0;
			while(c<=b){
				String str= c+"";
				HashMap<Long, Boolean> added = new HashMap<Long, Boolean>();
				for(int i=1;i<str.length();i++){
					long d=Long.parseLong(str.substring(i)+str.substring(0, i));
					if(d!=c && d>=a && d<=b && !added.containsKey(d)){
						added.put(d, true);
						count++;
					}
				}
				c++;
			}
			System.out.println("Case #"+(x+1)+": "+count/2);
		}
	}
}
