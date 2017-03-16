package com.chcat;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class R12A {

	private static int T;
	private static int t;
	private static String solution = "NOT SOLVED";
	
	private static long A;
	private static int N;
	private static long[] sizes;
	private static long[] addings;
	
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
		String[] AN = readed_line.split(" ");
		
		A = Long.parseLong(AN[0]);
		N = Integer.parseInt(AN[1]);
		sizes = new long[N];
		addings = new long[N];
		
		readed_line = reader.readLine();
		String[] sizes_string = readed_line.split(" ");
		
		
		for (int i=0;i<N;i++){
			sizes[i] = Long.parseLong(sizes_string[i]);
		}
		
		Arrays.sort(sizes);
		
		//solution = readed_line;
	}
	
	private static void writeTestCaseSolution() throws IOException{
		writer.append("Case #"+String.valueOf(t)+": "+solution);
		writer.newLine();
	}
	
	private static void solveTestCase(){
		
		if (A<=1){
			solution = String.valueOf(N);
			return;
		}
		
		System.out.println(String.valueOf(A)+ " - " + String.valueOf(N));
		for (int i=0;i<N;i++){
			System.out.print(String.valueOf(sizes[i])+" ");
		}
		System.out.println("");
		
		int count;
		
		for (int i=0;i<N;i++){
			count=0;
			
			if (sizes[i] < A){
				A = A+sizes[i];
				
			} else {
				while(A<=sizes[i]){
					A = A+A-1;
					count++;
				}
				A = A+sizes[i];
				addings[i]=count;
			}
			System.out.print(String.valueOf(A)+" !! ");
		}
		System.out.println("");
		for (int i=0;i<N;i++){
			System.out.print(String.valueOf(addings[i])+" ! ");
			
		}
		System.out.println("");

		
		long[] left = new long[N];
		
		for(int i=0;i<N;i++){
			for (int j=i;j<N;j++){
				left[i] += addings[j];
			}
		}
		
		for (int i=0;i<N;i++){
			System.out.print(String.valueOf(left[i])+" ! ");
			
		}
		System.out.println("");
		
		int stop=N;
		long solutionl = N;
		long current = 0;
		
		for (int i=0;i<N;i++){
			current = current + addings[i];
			
			if (solutionl > current + N-i-1){
				solutionl = current + N-i-1;
			}
			
//			if (left[i]>N-i){
//				stop = i;
//				break;
//			}
		}
		
		System.out.println(String.valueOf(stop)+ "!"  );
		
//		long result =0;
//		for (int i=0;i<stop;i++){
//			result = result + addings[i];
//		}
		//result = result+N-stop;
		solution = String.valueOf(solutionl);
	}
}
