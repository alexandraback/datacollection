package com.pancakewaffles.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

public class PartElf {

	public PartElf() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		BufferedWriter bw=new BufferedWriter(new FileWriter("Output.txt"));
		String line;
		line=br.readLine();
		int totalcases=Integer.parseInt(line);
		for(int i=0;i<totalcases;i++){
			String result="";
			int counter=0;
			String[] PQ=br.readLine().split("/");
			BigInteger p= new BigInteger(PQ[0]);
			BigInteger q= new BigInteger(PQ[1]);
			BigInteger gcd= p.gcd(q);
			long P= p.longValue()/gcd.longValue();
			long Q= q.longValue()/gcd.longValue();
			
			if((Q & (Q -1)) != 0){
				result="impossible";
			}else{
				while(P<Q){
					P=P*2;
					counter++;
					
				}
			}
			if(result != "impossible"){
				result = ""+counter;
			}
			bw.write("Case #"+(i+1)+": "+result);
			bw.newLine();
			
		}
		bw.close();
		br.close();

	}

}
