package com.chcat;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class C {
	private static int T;
	private static int t;
	private static String solution = "NOT SOLVED";
	
	private static int A;
	private static int B;
	
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
		String[] AB = readed_line.split(" ");
		
		A = Integer.parseInt(AB[0]);
		B = Integer.parseInt(AB[1]);
		
	}
	
	private static void writeTestCaseSolution() throws IOException{
		writer.append("Case #"+String.valueOf(t)+": "+solution);
		writer.newLine();
	}
	
	private static void solveTestCase(){
		int count = 0;
		
		int a = (int) Math.floor(Math.pow(A, 0.5f));
		if (a*a<A){
			a=a+1;
		}
		int b = (int) Math.floor(Math.pow(B, 0.5f));

		
		//a=0;
		//b=1000;
		System.out.print(a);
		System.out.print("-");
		System.out.print(b);
		System.out.println();
		
		for (long i=a; i<= b; i++){
			if (test(i)&&test(i*i)){
				count++;
			}
		}
		
		solution = String.valueOf(count);
	}
	
	private static boolean test(long i){
		String string = String.valueOf(i);
		
		int length = string.length();
		int half = length /2;
		int second_half; 
		if (length %2 ==1){
			second_half =  length /2+1 ;
		} else {
			second_half =  length /2;
		}
		
		String part = string.substring(0,half);
		String second_part = string.substring(second_half,length);
		
	
		
		for (int j=0; j< half; j++){
			if (part.charAt(j)!=second_part.charAt(half - j-1)){
				return false;
			}
		}
		
		return true;
	}
}
