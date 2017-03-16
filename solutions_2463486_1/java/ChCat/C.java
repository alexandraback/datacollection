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
import java.util.Arrays;

public class C {
	private static int T;
	private static int t;
	private static String solution = "NOT SOLVED";

	//private static String A;
	//private static String B;
	
	private static long A;
	private static long B;
	
	private static ArrayList<Long> fs = new ArrayList<Long>();
	
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
			
			
			for (long i=0;i<=10000000l;i++){
				if (test(i)&&test(i*i)){
					fs.add(i*i);
				}
			}
			
			
			
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
	
//	private static short[] find_fs_root(short[] a){
//		
//		//short[] result = new short[n];
//		
//	}
	
	private static boolean is_greater_or_equal(short[] a, short[] b){
		if (b.length>a.length){
			return false;
		}
		
		for (int i=0; i<a.length; i++){
			if (a[i]<b[i]){
				return false;
			}
		}
		
		return true;
	}
	
	private static void readTestCaseConditions() throws IOException{
		String str = reader.readLine();
		String[] AB = str.split(" ");
//		A = AB[0];
//		B = AB[1];
		A = Long.parseLong(AB[0]);
		B = Long.parseLong(AB[1]);
		//B= 100000000000000l;
	}
	
	private static void writeTestCaseSolution() throws IOException{
		writer.append("Case #"+String.valueOf(t)+": "+solution);
		writer.newLine();
	}
	
	private static void solveTestCase(){
//		short[] a = parse(A);
//		short[] b = parse(B);
//		
//		short[] c = multiply(a,b);
//		
//		solution = array_to_string(c);
		
		int count = 0;
	
		
		for (int i=0; i< fs.size(); i++){
			if (fs.get(i)>=A && fs.get(i)<=B){
				count ++;
			}
		}
		
		
		
		solution = String.valueOf(count);
	}
	
	private static String array_to_string (short[] a){
		StringBuilder sb = new StringBuilder();
		for (int i=0; i<a.length;i++){
			sb.append(a[i]);
		}
		return sb.toString();
	}
	
	private static short[] parse(String str){
		short[] result = new short[str.length()];
		for (int i=0; i<str.length();i++){
			if (str.charAt(i)=='0'){
				result[i] = 0;
			}
			if (str.charAt(i)=='1'){
				result[i] = 1;
			}
			if (str.charAt(i)=='2'){
				result[i] = 2;
			}
			if (str.charAt(i)=='3'){
				result[i] = 3;
			}
			if (str.charAt(i)=='4'){
				result[i] = 4;
			}
			if (str.charAt(i)=='5'){
				result[i] = 5;
			}
			if (str.charAt(i)=='6'){
				result[i] = 6;
			}
			if (str.charAt(i)=='7'){
				result[i] = 7;
			}
			if (str.charAt(i)=='8'){
				result[i] = 8;
			}
			if (str.charAt(i)=='9'){
				result[i] = 9;
			}
		}
		
		return result;
	}
	
	
	
	private static short[] multiply(short[] a, short[] b){
		
		int x = a.length;
		int y = b.length;
		
		int max_position = x+y;
		
		short[] result = new short[max_position];
		
		fill_array(result, (short) 0);
		
		
		int carry=0;
		
		for (int k=x-1+y-1; k>=0; k--){
			int sum = 0;
			
			for (int i=k;i>=0;i--){
				int j = k-i;
				
				if (i<x && j<y){
					sum+=a[i]*b[j];
				}
			}
			
			sum +=carry;
			if (sum>9){
				carry = (sum - (sum %10))/10;
				sum = sum %10;
			}
			
			result[k+1]=(short) sum;
		}
		
		result[0]=(short) carry;
		
		if (result[0]!=0){
			return result;
		} else {
			return Arrays.copyOfRange(result, 1, max_position);
		}
		
		
	}
	
	private static void fill_array(short[] a, short value){
		for (int i=0; i<a.length;i++){
			a[i]=value;
		}
	}
	
	private static boolean test(String string){
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
	
	private static boolean test(long i){
		String string = String.valueOf(i);
		
		return test(string);
	}
}
