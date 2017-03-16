package com.googlejam.robert;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class L2 {
	public static void main(String[] args) {
		List<String> inputString = getInputStrings("C:\\Users\\Robert\\Documents\\Java\\input\\B-small-attempt1.in");
		int iterations = Integer.parseInt(inputString.get(0));
		inputString.remove(0);
		List<Object> objectList = S2Parser(inputString, iterations);
		int counter = 1;
		for (Object i: objectList){
			String output="";
			output+="Case #" + counter + ": ";	
			output+=S2Result(i);
			try {
			    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\Robert\\Documents\\Java\\output\\B-small-attempt1.out", true)));
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
		String listString =(String)i;
		int X = Integer.parseInt(listString.split(" ")[0]);
		int Y = Integer.parseInt(listString.split(" ")[1]);
		System.out.println(X);
		System.out.println(Y);
		String North = "SN";
		String South = "NS";
		String East = "WE";
		String West = "EW";
		String solution = "";
		boolean negativeX = false;
		boolean negativeY = false;
		if(X<0){
			X=-1*X;
			negativeX=true;
		}
			
		if(Y<0){
			Y=-1*Y;
			negativeY=true;
		}
		for(int a = 0; a<X;a++){
			if(negativeX){
				solution+=West;
			}
			else{
				solution+=East;
			}
		}
		for(int a = 0; a<Y;a++){
			if(negativeY){
				solution+=South;
			}
			else{
				solution+=North;
			}
		}
		return solution;
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
