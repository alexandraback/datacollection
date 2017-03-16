package com.pancakewaffles.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class PartElf {

	public PartElf() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		BufferedWriter bw=new BufferedWriter(new FileWriter("Output.txt"));
		String line;
		line=br.readLine();
		int totalcases=Integer.parseInt(line);
		for(int i=0;i<totalcases;i++){
			String result="";
			int counter=0;
			String[] PQ=br.readLine().split("/");
			int P= Integer.parseInt(PQ[0]);
			int Q= Integer.parseInt(PQ[1]);
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
