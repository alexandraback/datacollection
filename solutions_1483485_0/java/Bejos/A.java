/**
 * Speaking in Toungues
 */
package com.google.jam.qualification;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Scanner;

public class A {
	
	public static HashMap<Character,Character> translateTable = new HashMap<Character,Character>();
	
	public static void initTable() {
		translateTable.put('a', 'y');
		translateTable.put('b', 'h');
		translateTable.put('c', 'e');
		translateTable.put('d', 's');
		translateTable.put('e', 'o');
		translateTable.put('f', 'c');
		translateTable.put('g', 'v');
		translateTable.put('h', 'x');
		translateTable.put('i', 'd');
		translateTable.put('j', 'u');
		translateTable.put('k', 'i');
		translateTable.put('l', 'g');
		translateTable.put('m', 'l');
		translateTable.put('n', 'b');
		translateTable.put('o', 'k');
		translateTable.put('p', 'r');
		translateTable.put('q', 'z');
		translateTable.put('r', 't');
		translateTable.put('s', 'n');
		translateTable.put('t', 'w');
		translateTable.put('u', 'j');
		translateTable.put('v', 'p');
		translateTable.put('w', 'f');
		translateTable.put('x', 'm');
		translateTable.put('y', 'a');
		translateTable.put('z', 'q');
	}
	
	public static void main(String[] args) {
		initTable();
		try {
			FileOutputStream fos = new FileOutputStream("A-small-attempt0.out");
			System.setOut(new PrintStream(fos, true));
			
			FileInputStream fis=new FileInputStream(new File("A-small-attempt0.in"));
			InputStreamReader in=new InputStreamReader(fis);
			BufferedReader br=new BufferedReader(in);
			
			int lineNumber = 0;
			String line="";
			int nbLine = Integer.parseInt(br.readLine());
			
			while((line=br.readLine())!=null){
				lineNumber++;
				Scanner sc = new Scanner(line);
				String sentence = "";
				
				while(sc.hasNext()) {
					String wordA = sc.next();
					String wordB = "";
					for(int i=0; i<wordA.length(); i++) {
						wordB = wordB + translateTable.get(wordA.charAt(i));
					}
					sentence += sentence.equals("") ? wordB : " " + wordB;					
				}
				
				System.out.println("Case #" + lineNumber + ": " + sentence);

			}
	
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println("File not found");
			e.printStackTrace();
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}