package com.chcat;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class R1C {
	private static int T;
	private static int t;
	
	private static int R;
	private static int N;
	private static int M;
	private static int K;
	
	private static int[] guess;
	private static int[] current;
	private static int[] max;
	
	private static String solution = "NOT SOLVED";
	
	private static BufferedReader reader;
	private static BufferedWriter writer;
	
	public static void main(String[] args) {
		String input_file_name;
		String output_file_name;
		
		if (args.length < 2) {
			input_file_name="r:\\input.txt";
			output_file_name = "r:\\output.txt";
		} else {
			input_file_name = args[0];
			output_file_name = args[1];
		}
		
		try {
			writer = new BufferedWriter(new FileWriter(output_file_name));
			reader = new BufferedReader(new InputStreamReader(new DataInputStream(new FileInputStream(input_file_name))));
			
			String readed_line = reader.readLine();
			T = Integer.parseInt(readed_line);
			
			for (t = 1; t<=T; t++){
				readTestCaseConditions();
				//solveTestCase();
				//writeTestCaseSolution();
			}
			
			reader.close();
			
			writer.flush();
			writer.close();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
		}	
	}
	
	private static void readTestCaseConditions() throws IOException{
		String readed_line = reader.readLine();
		
		String RNMK[] = readed_line.split(" ");
		
		R = Integer.parseInt(RNMK[0]);
		N = Integer.parseInt(RNMK[1]);
		M = Integer.parseInt(RNMK[2]);
		K = Integer.parseInt(RNMK[3]);
		
		writer.append("Case #1:");
		writer.newLine();
		
		for (int r=0; r<R;r++){
			
			guess = new int[8];
			max = new int[8];
			
			readed_line = reader.readLine();
			String[] ps = readed_line.split(" ");
			
			for (int k=0;k<K;k++){
				int c= Integer.parseInt(ps[k]);
				if (c>1){
				
				current = new int[8];
				decompose(c);
				
				
				
				
				}
			}
			
			analyse();
			
			solveTestCase();
			writeTestCaseSolution();
		}
		
		
		solution = readed_line;
	}
	
	private static void analyse(){
		guess[3]=max[3];
		guess[1]=max[1];
		int a = max[0];
		int b = N - max[3] - max[1];
		if (a<=b){
			guess[0] = a;
		} else {
			guess[2] = a-b;
			guess[0] = b - guess[2];
		}
	
	}
	
	private static void decompose(int i){
		while (i%2 == 0){
			current[0]++;
			i=i/2;
		}
		while (i%3 == 0){
			current[1]++;
			i=i/3;
		}
		while (i%5 == 0){
			current[3]++;
			i=i/5;
		}
	
		if (current[0]>max[0]){
			max[0]=current[0];
		}
		if (current[1]>max[1]){
			max[1]=current[1];
		}
		if (current[3]>max[3]){
			max[3]=current[3];
		}
	}
	
	private static void writeTestCaseSolution() throws IOException{
		int j=M-2;
		for(int i=0;i<N;i++){
			if (j>=0){
				if (guess[j]>0){
					writer.append(String.valueOf(j+2));
					guess[j]--;
				} else {
					j--;
					i--;
				}
				
			} else {
				writer.append(String.valueOf(2));
			}
		}
		writer.newLine();
	}
	
	private static void solveTestCase(){
		
	}
}
