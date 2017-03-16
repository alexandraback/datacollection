package com.kushd.cj2014;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class PartElf {
	
	
	public static void main(String[] args) {
		FileInputStream fio=null;
		DataInputStream in=null;
		try {
			fio = new FileInputStream("/Users/kushal/Downloads/A-large.in");
			in = new DataInputStream(fio);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine = br.readLine();
			int tc = Integer.parseInt(strLine);
			for(int i=0;i<tc;i++){
				strLine = br.readLine();
				String[] values = strLine.split("/");
				long p = Long.parseLong(values[0]);
				long q = Long.parseLong(values[1]);
				
				String ans = process(p,q);
				System.out.println("Case #"+(i+1)+": "+ans);
			}
			
			
			in.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private static String process(long p, long q) {
		long tempP = p;
		long tempQ = q;
		int ans=0;
		while(tempP < tempQ && ans < 40){
			ans=ans+1;
			tempP = tempP*2;
		}
		tempP = tempP - tempQ;
		if(tempP ==0){
			return Integer.toString(ans);
		}
		int genLeft=40-ans;
		while(genLeft >0){
			genLeft = genLeft-1;
			tempP = tempP*2;
			if(tempP >= tempQ){
				tempP = tempP - tempQ;
				if(tempP ==0){
					return Integer.toString(ans);
				}
			}
		}
		return "impossible";
	}
}