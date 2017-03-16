package com.chcat;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class R12B {

	private static int T;
	private static int t;
	private static int X;
	private static int Y;
	private static long N;
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
				solveTestCase();
				writeTestCaseSolution();
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
		
		String[] NXY = readed_line.split(" ");
		
		N = Long.parseLong(NXY[0]);
		X = Integer.parseInt(NXY[1]);
		Y = Integer.parseInt(NXY[2]);
		
		//solution = readed_line;
	}
	
	private static void writeTestCaseSolution() throws IOException{
		writer.append("Case #"+String.valueOf(t)+": "+solution);
		writer.newLine();
	}
	
	private static void solveTestCase(){
		double result = 0;
		
		if ((X+Y)%2!=0 || Y<0){
			solution = String.valueOf(result);
			return;
		}
		
		if (X<0){
			X = -1*X;
		}
		
		
		if (X==0){
			int i = (X+Y)/2-1;
			int triangle = (i+1)*(i+1);
			int pile =  2*triangle-i-1;
			int maxamaunt = pile+2*(i+1)+2*(i+1)+1;
	
			System.out.println(String.valueOf(X)+"-"+String.valueOf(Y)+" "+ String.valueOf(N)+"! "+String.valueOf(maxamaunt));
			
			if (N<maxamaunt){
				result = 0;
				solution = String.valueOf(0);
				return;
			}
			
			
			
			
			result = 1;
			solution = String.valueOf(1);
			return;
			
			
		} else {
			
			
			int i = (X+Y)/2-1;
			int triangle = (i+1)*(i+1);
			int pile =  2*triangle-i-1;
			
			int minamaunt = pile + Y+1; 
			int maxamaunt = pile+2*(i+1)+Y+1; 
			
			System.out.println(String.valueOf(X)+"-"+String.valueOf(Y)+" "+ String.valueOf(N)+"! "+String.valueOf(minamaunt)+" "+String.valueOf(maxamaunt));
		
			
			if (N<minamaunt){
				result = 0;
				solution = String.valueOf(result);
				return;
			}
			
			if (N>=maxamaunt){
				result = 1;
				solution = String.valueOf(1);
				return;
			}
			
			long free = N - pile;
			int need = Y+1;
			
			long sum=1;
			for (int j=1;j<need;j++){
				sum+=binom(free, j);
			}
			
			result =1 - ((double)sum)/Math.pow(2, free);
			
			solution = String.valueOf(result);
		}
		
		
		
	}
	
	private static long binom(long n, long m){
		long result = fact(n);
		result = result / fact(m);
		result = result /fact(n-m);
		
		
		return result;
	}
	
	private static long fact(long h){
		if (h<1){
			return 1;
		}
		
		long result = 1;
		for (long i =1;i<=h;i++){
			result = result*i;
		}
		return result;
	}
}
