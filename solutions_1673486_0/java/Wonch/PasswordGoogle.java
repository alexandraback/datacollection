package com.dennis.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class PasswordGoogle {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		
		BufferedReader fin = new BufferedReader(new FileReader("pass.in"));
		PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("pass.out")));

		StringTokenizer stringy;
		
		int num = Integer.parseInt(fin.readLine());
		
		for(int asdf = 0; asdf <num; asdf++){
			stringy = new StringTokenizer(fin.readLine());
			int altyped = Integer.parseInt(stringy.nextToken());
			int numchar = Integer.parseInt(stringy.nextToken());
			//expected if press enter right away
			double expectedenter;
			//expected if keep typing after pressing backspace n times
			double expectedtyping[];
			
			
			stringy = new StringTokenizer(fin.readLine());
			double probs[] = new double[altyped];
			
			for(int a  = 0; a<altyped; a++){
				probs[a] = 1- Double.parseDouble(stringy.nextToken());
			}
			
			double sum = 0; 
			
			//sum of probability of the nth digit being the first wrong
			double sumprobs[] = new double[altyped +1];
			sumprobs[0] = probs[0];
			
			for(int a = 1; a<altyped; a++){
				sumprobs[a] =sumprobs[a-1]+ (1-sumprobs[a-1])*probs[a];
			}
			System.out.println();
			
			
			sumprobs[altyped] = 1-sumprobs[altyped-1];
			
			for(int a = 0; a<=altyped; a++){
				System.out.print(sumprobs[a] + " ");
			}
			System.out.println();
			expectedtyping = new double[altyped+1];
			
			for(int a = 0; a< altyped;a++){
				expectedtyping[a] = sumprobs[altyped-a-1]*(2*numchar-altyped+2*a+2) + (1-sumprobs[altyped-a-1])*(numchar-altyped+2*a+1);
			}
			
			
			
			expectedtyping[altyped] = numchar+altyped+1;
			expectedenter = 2+numchar;
			
			for(int a = 0; a<=altyped; a++){
				System.out.print(expectedtyping[a] + " ");
			}
			
			double min = Double.MAX_VALUE;
			for(int a= 0 ; a<expectedtyping.length;a++){
				if(min>expectedtyping[a]) min =expectedtyping[a]; 
			}
			
			if(min>expectedenter)
				min = expectedenter;
			
			fout.println("Case #" + (asdf+1) + ": " + min);
			
			
		}
		
		fout.close();
		System.exit(0);
		
	}

}
