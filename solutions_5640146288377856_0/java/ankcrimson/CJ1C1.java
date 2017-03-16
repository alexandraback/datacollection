package com;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;

public class CJ1C1 {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		InputStream is=new FileInputStream("A-small");
		//InputStream is=new FileInputStream("1t");
		BufferedReader br=new BufferedReader(new InputStreamReader(is));
		long t=Long.parseLong(br.readLine());
		for(long i=0;i<t;i++)
		{
			long sum=0;
			
			String tc=br.readLine();
			String[] vals=tc.split(" ");
			long r=Long.parseLong(vals[0]);
			long c=Long.parseLong(vals[1]);
			long w=Long.parseLong(vals[2]);
			long w1=w-1;
			long c1=c;
			//long r1=r-1;
			
			c1=(long)(c/w);
			
			sum=r*c1;
			
			if(c%w!=0)
				sum++;
			
			sum+=(w1);
			
			System.out.println(tc+"=>"+"Case #"+(i+1)+": "+sum);
		}
	}

}
