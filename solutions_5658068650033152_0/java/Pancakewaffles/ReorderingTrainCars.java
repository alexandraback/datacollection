package com.pancakewaffles.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ReorderingTrainCars {

	public ReorderingTrainCars() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
		BufferedWriter bw=new BufferedWriter(new FileWriter("Output.txt"));
		String line;
		line=br.readLine();
		int totalcases=Integer.parseInt(line);
		for(int i=0;i<totalcases;i++){
			String[] NMK=br.readLine().split("\\s+");
			int N= Integer.parseInt(NMK[0]);
			int M= Integer.parseInt(NMK[1]);
			int K= Integer.parseInt(NMK[2]);
			int result=K;
			if(N>=3 && M>=3){
				if(3<=K && K<=4){
					result = K-1;
				}else if(K==5){
					result=4;
				}else if(K>=5){
					result=4;
					int points=5;
					while(points<K){
						points=points+3;
						result=result+2;
						
					
					}
					if(points>K){
						points=points-3;
						result=result-2;
						while(points<K){
							points++;
							result++;
						}
					}
				
					
					
				}
			
			
			}
			bw.write("Case #"+(i+1)+": "+result);
			bw.newLine();
		}
		bw.close();
		br.close();

	}

}
