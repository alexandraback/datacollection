package com.chcat;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class B {
	private static int T;
	private static int t;
	
	private static int M;
	private static int N;
	private static int[][] pattern;
	private static int[] row_max;
	private static int[] column_max;
	
	
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
		
		String[] NM =  readed_line.split(" ");
		String[] pattern_string_values;
		
		N = Integer.parseInt(NM[0]);
		M = Integer.parseInt(NM[1]);
		
		pattern = new int[N][];
		
		for (int i=0; i < N; i++){
			pattern[i] = new int[M];
			
			readed_line = reader.readLine();
			pattern_string_values = readed_line.split(" ");
			
			for (int j=0; j<M;j++){
				pattern[i][j] = Integer.parseInt(pattern_string_values[j]);
			}
		}
		
	}
	
	private static void writeTestCaseSolution() throws IOException{
		writer.append("Case #"+String.valueOf(t)+": "+solution);
		writer.newLine();
	}
	
	private static void solveTestCase(){
		row_max = new int[N];
		column_max = new int[M];
				
		for (int row = 0; row<N; row++){
			for (int column = 0; column < M; column++){
				if (pattern[row][column]>row_max[row]){
					row_max[row] = pattern[row][column];
				}
				if (pattern[row][column]>column_max[column]){
					column_max[column] = pattern[row][column];
				}
			}
		}
		
		solution = "YES";
		
		for (int row = 0; row<N; row++){
			for (int column = 0; column < M; column++){
				if (pattern[row][column]<row_max[row] && pattern[row][column] < column_max[column]){
					solution = "NO";
					return;
				}
			}
		}
		
	}
}
