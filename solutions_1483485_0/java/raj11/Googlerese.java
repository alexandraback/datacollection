package com.google.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Googlerese {
	static char mapping[] = {
			'y', 'n', 'f', 'i', 'c',
			'w', 'l', 'b', 'k', 'u',
			'o', 'm', 'x', 's', 'e',
			'v', 'z', 'p', 'd', 'r',
			'j', 'g', 't', 'h', 'a', 'q'
	};
	
	static char mapping2[]={
		'y', 'h', 'e', 's', 'o',
		'c', 'v', 'x', 'd', 'u',
		'i', 'g', 'l', 'b', 'k',
		'r', 'z', 't', 'n', 'w',
		'j', 'p', 'f', 'm', 'a', 'q'
	};
	public static void main(String argsp[]) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("/Users/ashwinjain/Desktop/SmsLogger/InterviewStreet/src/com/google/codejam/in.txt")));
		int cases = Integer.parseInt(br.readLine());
		
		for(int i=0;i<cases;i++){
			String str = br.readLine();
			str=str.trim();
			String ans= "";
			for(int j=0;j<str.length();j++){
				char temp = str.charAt(j);
				if(temp!=' '){
					ans=ans+mapping2[temp-'a'];
				}else{
					ans+=' ';
				}
			}
			System.out.println("Case #"+(i+1)+": "+ans);
		}
		
	}
}
