package com.miv;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static final String inputFileLoc = "C:\\Google Code Jam\\A-small-attempt0.in";
	static final String outputFileLoc = "C:\\Google Code Jam\\output.out";
	
	static PrintWriter writer;
	
	public static void main(String[] args) {
		ArrayList<String> input = new ArrayList<String>();
		
		// Create output writer
		try {
			writer = new PrintWriter(outputFileLoc, "UTF-8");
		} catch (FileNotFoundException | UnsupportedEncodingException e1) {
			e1.printStackTrace();
		}
		
		// Read input
		BufferedReader br = null;
		try {
			String sCurrentLine;
			br = new BufferedReader(new FileReader(inputFileLoc));
			while ((sCurrentLine = br.readLine()) != null) {
				input.add(sCurrentLine);
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
		
		// Do stuff
		process(input);
		
		// convert 110111 (base 3) to base 10
		//System.out.println(Integer.valueOf(Integer.toString(Integer.parseInt("110111", 3), 10)));
		
		// Close writer
		writer.close();
	}
	
	public static void write(String text) {
		writer.println(text);
	}
	
	public static void write(ArrayList<String> texts) {
		for(String s : texts) {
			writer.println(s);
		}
	}
	
	public static void process(ArrayList<String> input) {
		int cases = Integer.valueOf(input.get(0));
		
		for(int i = 0; i < cases; i++) {
			String string = input.get(i + 1);
			
			int O = countOccurrences(string, 'O');
			int N = countOccurrences(string, 'N');
			int E = countOccurrences(string, 'E');
			int T = countOccurrences(string, 'T');
			int W = countOccurrences(string, 'W');
			int H = countOccurrences(string, 'H');
			int R = countOccurrences(string, 'R');
			int F = countOccurrences(string, 'F');
			int U = countOccurrences(string, 'U');
			int I = countOccurrences(string, 'I');
			int V = countOccurrences(string, 'V');
			int X = countOccurrences(string, 'X');
			int S = countOccurrences(string, 'S');
			int G = countOccurrences(string, 'G');
			int Z = countOccurrences(string, 'Z');
			
			int zero = Z;
			Z -= zero;
			E -= zero;
			R -= zero;
			O -= zero;
			
			int two = W;
			T -= two;
			W -= two;
			O -= two;
			
			int four = U;
			F -= four;
			O -= four;
			U -= four;
			R -= four;
			
			int six = X;
			S -= six;
			I -= six;
			X -= six;
			
			int eight = G;
			E -= eight;
			I -= eight;
			G -= eight;
			H -= eight;
			T -= eight;
			
			int five = F;
			F -= five;
			I -= five;
			V -= five;
			E -= five;
			
			int seven = V;
			S -= seven;
			E -= seven;
			V -= seven;
			E -= seven;
			N -= seven;
			
			int three = H;
			T -= three;
			H -= three;
			R -= three;
			E -= three;
			E -= three;
			
			int nine = I;
			N -= nine;
			I -= nine;
			N -= nine;
			E -= nine;
			
			int one = O;
			O -= one;
			N -= one;
			E -= one;
			
			String number = "";
			for(int a = 0; a < zero; a++) {
				number += "0";
			}
			for(int a = 0; a < one; a++) {
				number += "1";
			}
			for(int a = 0; a < two; a++) {
				number += "2";
			}
			for(int a = 0; a < three; a++) {
				number += "3";
			}
			for(int a = 0; a < four; a++) {
				number += "4";
			}
			for(int a = 0; a < five; a++) {
				number += "5";
			}
			for(int a = 0; a < six; a++) {
				number += "6";
			}
			for(int a = 0; a < seven; a++) {
				number += "7";
			}
			for(int a = 0; a < eight; a++) {
				number += "8";
			}
			for(int a = 0; a < nine; a++) {
				number += "9";
			}
			
		    write("Case #" + (i + 1) + ": " + number);
		}
	}
	
	public static int countOccurrences(String string, char c) {
		int ret = 0;
		for(int i = 0; i < string.length(); i++) {
			if(string.charAt(i) == c) {
				ret++;
			}
		}
		return ret;
	}
	
	public static int countNodes(Node node, ArrayList<Integer> countedIDs) {
		int count = 0;
		for(Node n : node.nodes) {
			if(!countedIDs.contains(n.id)) {
				countedIDs.add(n.id);
				count++;
				
				int asd = countNodes(n, countedIDs);
				if(asd > 0)
				count += asd;
			}
		}
		return count;
	}
	
	
	public static class Node {
		ArrayList<Node> nodes = new ArrayList<Node>();
		
		int id;
		
		public Node(int id) {
			this.id = id;
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	public static boolean contains(String[] array, String value) {
		for(int i = 0; i < array.length; i++) {
			if(array[i].equals(value)) {
				return true;
			}
		}
		return false;
	}
	
	public static boolean startsWith(String[] array, String value) {
		for(int i = 0; i < array.length; i++) {
			if(array[i].startsWith(value)) {
				return true;
			}
		}
		return false;
	}
	
	public static boolean startsWith(ArrayList<String> array, String value) {
		for(int i = 0; i < array.size(); i++) {
			if(array.get(i).startsWith(value)) {
				return true;
			}
		}
		return false;
	}
	
	/**
	 int n = Integer.valueOf(input.get(i + 1));
			
			//int[][] table = new int[n][n];
			String[] list = new String[2*n - 1];
			
		    int col = 0;
			for(int r = 0; r < 2*n - 1; r++) {
				Scanner fi = new Scanner(input.get(i + 2 + r));
			    fi.useDelimiter("[^\\p{Alnum},\\.-]"); 
			    int counter = 0;
			    while (true) {
			        if (fi.hasNextInt()) {
			        	if(list[col] == null) list[col] = "";
			        	list[col] += fi.nextInt();
			        	counter++;
			        	if(counter >= n) {
			        		col++;
			        		counter = 0;
			        	}
			        }
			        else {
			            break;
			        }
			    }
			    fi.close();
			}
			
			ArrayList<String> list2 = new ArrayList<String>();
			for(int a = 0; a < list.length; a++) {
				list2.add(list[a]);
			}
			
			String[] order = new String[n];
		    
			int index = 0;
			int smallest = Integer.valueOf(list[0].charAt(0));
			
			for(int a = 1; a < list2.size(); a++) {
				int asd = Integer.valueOf(list2.get(a).charAt(0));
				if(asd < smallest) {
					smallest = asd;
					index = a;
				}
			}
			order[0] = list2.get(index);
			list2.remove(index);
			System.out.println(order[0]+"___________");
			
			for(int c=0;c<list2.size();c++) {
				System.out.println(list2.get(c));
			}
			
			for(int b = 0; b < n; b++) {
				String rowString = "";
				
				ArrayList<String> list3 = new ArrayList<String>();
				for(int a = 0; a < list2.size(); a++) {
					list3.add(list2.get(a));
				}
				
				System.out.println(!startsWith(list, rowString));
				while(startsWith(list, rowString)) {
					rowString = "";
					for(int a = 1; a < list3.size(); a++) {
						int asd = Integer.valueOf(list3.get(a).charAt(0));
						if(asd < smallest) {
							smallest = asd;
							index = a;
						}
					}
					for(int c = 0; c < b; c++) {
						for(int r = 0; r < b; r++) {
							rowString += list2.get(c).charAt(r);
						}
					}
					
					System.out.println(rowString+"___________");
					
					list3.remove(index);
				}
				/**
				for(int c = 0; c < b; c++) {
					String columnString = "";
					for(int r = 0; r < b; r++) {
						columnString += list2.get(c).charAt(r);
					}
					System.out.println("Col: " + columnString);
					if(!startsWith(list, columnString)) {
						System.out.println("Doest not have");
						break;
					} else {
						for(int a = 1; a < list2.size(); a++) {
							int asd = Integer.valueOf(list2.get(a).charAt(0));
							if(asd < smallest) {
								smallest = asd;
								index = a;
							}
						}
						list2.remove(index);
					}
				}
			}
			
			ArrayList<String> list3 = new ArrayList<String>();
			for(int a = 0; a < list.length; a++) {
				list3.add(list[a]);
			}
			
			for(int r = 0; r < n; r++) {
				String row = "";
				for(int c = 0; c < n; c++) {
					row += order[r].charAt(c);
				}
				//System.out.println(row);
				if(!contains(list, row)) {
					System.out.println("final: " + row);
					return;
				}
			}
			for(int c = 0; c < n; c++) {
				String row = "";
				for(int r = 0; r < n; r++) {
					row += order[c].charAt(r);
				}
				
				//System.out.println(row);
				if(!contains(list, row)) {
					System.out.println("final: " + row);
					return;
				}
			}
			
	 */
}
