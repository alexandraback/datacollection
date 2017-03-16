package com.googlejam.robert;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class L1 {
	public static void main(String[] args) {
		List<String> inputString = getInputStrings("C:\\Users\\Robert\\Documents\\Java\\input\\A-small-attempt0.in");
		int iterations = Integer.parseInt(inputString.get(0));
		inputString.remove(0);
		List<Object> objectList = S2Parser(inputString, iterations);
		int counter = 1;
		System.out.println(largestConsonant("rtz"));
		for (Object i: objectList){
			String output="";
			output+="Case #" + counter + ": ";	
			output+=S2Result(i);
			try {
			    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\Robert\\Documents\\Java\\output\\A-small-attempt0.out", true)));
			    out.println(output);
			    out.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			System.out.println(output);
			counter++;
		}
		
	}
	private static List<Object> S2Parser(List<String> inputString,
			int iterations) {
		List<Object> list = new ArrayList<Object>();
		for(String i: inputString){
			list.add(i);
		}
		return list;
	}
	
	private static List<String> allSubstrings(String i){
		List<String> substrings = new ArrayList<String>();
		for(int a =1; a<=i.length();a++){
			substrings.addAll(allSubstringsOfSize(a,i));
		}
		return substrings;
	}
	
	private static List<String> allSubstringsOfSize(int length, String i){
		List<String> substrings = new ArrayList<String>();
		for(int a = 0; a<i.length()-length+1;a++){
			String sub = i.substring(a, length+a);
			substrings.add(sub);
		}
		return substrings;
	}
	
	private static int largestConsonant(String s){
		int max = 0;
		int temp = 0;
		for(int i = 0; i<s.length();i++){
			char c = s.charAt(i);
			if(c!='a' && c!='e' && c!='i'&& c!='o'&& c!='u')
				temp = temp+1;
			else{
				if (temp>=max)
					max=temp;
				temp = 0;
			}
		}
		if (temp>=max)
			max=temp;
		return max;
	}
	
	private static List<Object> doubleParse(List<String> inputString, int iterations){
		List<Object> list = new ArrayList<Object>();
		boolean second = false;
		String line = "";
		for(String i: inputString){			
			if(!second){
				line+=i.split(" ")[0];
				second = true;
			}
			else{
				line+=" "+i;
				list.add(line);
				line="";
				second = false;
			}
		}
		return list;
	}
	
	private static List<Integer> convertList(String s){
		List<Integer> list = new ArrayList<Integer>();
		for(String a: s.split(" ")){
			list.add(Integer.parseInt(a));
		}
		return list;
	}
	
	private static String S2Result(Object i) {
		String string = ((String)i).split(" ")[0];
		int n = Integer.parseInt(((String)i).split(" ")[1]);
		int counter = 0;
		System.out.println(string);
		System.out.println(n);
		List<String> substrings = allSubstrings(string);
		//System.out.println(substrings);
		for(String a: substrings){
			if(largestConsonant(a)>=n){
				counter++;
			}
		}
		return String.valueOf(counter);
	}
	public static List<String> getInputStrings(String filename){
		
		List<String> inputString = new ArrayList<String>();
		BufferedReader br = null;
		 
		try { 
			String sCurrentLine;
	 
			br = new BufferedReader(new FileReader(filename));
	 
			while ((sCurrentLine = br.readLine()) != null) {
				//System.out.println(sCurrentLine);
				inputString.add(sCurrentLine);
			}
	 
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
		return inputString;
	}
}
