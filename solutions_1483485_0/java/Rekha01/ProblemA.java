package com.google.codejam;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

public class ProblemA {

	/**
	 * @param args
	 */
	public List<String> s= new ArrayList<String>();
	private SortedMap<String, String> map = new TreeMap<String, String>(); //HashMap map = new HashMap<String, String>() ;
	public ProblemA(){
		map.put("y" ,"a");
		map.put("e","o");
		map.put("q","z");
		map.put("j","u");
		map.put("p","r");
		map.put("m","l");
		map.put("s","n");
		map.put("l","g");
		map.put("c","e");
		map.put("k","i");
		map.put("d","s");
		map.put("x","m");
		map.put("v","p");
		map.put("n","b");
		map.put("r","t");
		map.put("i","d");		
		map.put("b","h");
		map.put("t","w");
		map.put("a","y");
		map.put("h","x");
		map.put("w","f");
		map.put("f","c");
		map.put("u","j");
		map.put("o","k");
		map.put("g","v");
		map.put("z","q");
		map.put(" "," ");
		
		
	}
	
	public void calculate(int numcase){
		for(int i = 0 ; i < numcase ;i++){
			String ss = s.get(i);
			String news ="";
			for(int j =0 ; j< ss.length() ; j++){
				news =news+ map.get((String.valueOf(ss.charAt(j))));
			}
			System.out.println("Case #"+(i+1)+": "+news);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ProblemA a = new ProblemA();
		a.fileRead(a);
	}
	
	public void fileRead(ProblemA a){
		 FileInputStream fstream;
			try {
				fstream = new FileInputStream("D:\\1.txt");
				 DataInputStream in = new DataInputStream(fstream);
				    BufferedReader br = new BufferedReader(new InputStreamReader(in));
				    String strLine;
				    //Read File Line By Line
					int testCase =0 ;
				    while ((strLine = br.readLine()) != null)   {
				    // Print the content on the console
				    	 testCase = Integer.parseInt(strLine);
						 List<String> slist= new ArrayList<String>();
				    	for(int i = 0 ; i < testCase ; i++){
							slist.add( br.readLine());	
				    	}
						a.s = slist;
				    }
					
				    
				   in.close() ;
				   a.calculate(testCase);
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		    // Get the object of DataInputStream
			catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		   
	 }
	}


