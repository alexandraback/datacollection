package com.miv;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {
	static final String inputFileLoc = "C:\\Google Code Jam\\B-small-attempt4.in";
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
			String[] strings = input.get(i + 1).split("\\s+");
			StringBuilder left = new StringBuilder(strings[0]);
			StringBuilder right = new StringBuilder(strings[1]);
			
			boolean leftIsGreater = true;
			boolean doneWithCompare = false;
			for(int a = 0; a < left.length(); a++) {
				char leftChar = left.charAt(a);
				char rightChar = right.charAt(a);
				
				if(!doneWithCompare && leftChar != '?' && rightChar != '?') {
					int l = Integer.valueOf(leftChar+"");
					int r = Integer.valueOf(rightChar+"");
					if(l > r) {
						leftIsGreater = true;
						doneWithCompare = true;
					} else if(l < r) {
						leftIsGreater = false;
						doneWithCompare = true;
					}
				}
				
				if(!doneWithCompare) {
					if(leftChar == '?' && rightChar != '?') {
						left.setCharAt(a, rightChar);
						leftChar = rightChar;
					}
					else if(leftChar != '?' && rightChar == '?') {
						right.setCharAt(a, leftChar);
						rightChar = leftChar;
					}
				}
				
				// both are ?
				if(!doneWithCompare && (leftChar == '?' || rightChar == '?')) {
					// next ones
					int b = a+1;
					if(b < left.length()) {
						char aa = left.charAt(b);
						char bb = left.charAt(b);
						if(aa != '?' && bb != '?') {
							if(Integer.valueOf(aa+"") - Integer.valueOf(bb+"") > 0) {
								if(leftChar == '?') {
									left.setCharAt(a, '0');
									leftChar = '0';
								}
								if(rightChar == '?') {
									right.setCharAt(a, '1');
									rightChar = '1';
								}
							} else {
								if(leftChar == '?') {
									left.setCharAt(a, '1');
									leftChar = '1';
								}
								if(rightChar == '?') {
									right.setCharAt(a, '0');
									rightChar = '0';
								}
							}
						} else {
							if(leftChar == '?') {
								left.setCharAt(a, '0');
								leftChar = '0';
							}
							if(rightChar == '?') {
								right.setCharAt(a, '0');
								rightChar = '0';
							}
						}
					} else {
						if(leftChar == '?') {
							left.setCharAt(a, '0');
							leftChar = '0';
						}
						if(rightChar == '?') {
							right.setCharAt(a, '0');
							rightChar = '0';
						}
					}
					
					
				}
				
				else if(doneWithCompare && (leftChar == '?' || rightChar == '?')) {
					if(leftIsGreater) {
						if(leftChar == '?') {
							left.setCharAt(a, '0');
							leftChar = '0';
						}
						if(rightChar == '?') {
							right.setCharAt(a, '9');
							rightChar = '9';
						}
					} else {
						if(leftChar == '?') {
							left.setCharAt(a, '9');
							leftChar = '9';
						}
						if(rightChar == '?') {
							right.setCharAt(a, '0');
							rightChar = '0';
						}
					}
				}
				
				if(!doneWithCompare) {
					if(leftChar == '?' && rightChar != '?') {
						left.setCharAt(a, rightChar);
						leftChar = rightChar;
					}
					else if(leftChar != '?' && rightChar == '?') {
						right.setCharAt(a, leftChar);
						rightChar = leftChar;
					}
				}
								
				if(!doneWithCompare && leftChar != '?' && rightChar != '?') {
					int l = Integer.valueOf(leftChar+"");
					int r = Integer.valueOf(rightChar+"");
					if(l > r) {
						leftIsGreater = true;
						doneWithCompare = true;
					} else if(l < r) {
						leftIsGreater = false;
						doneWithCompare = true;
					}
				}
			}
					
			//System.out.println(left+" "+right);
		    write("Case #" + (i + 1) + ": " + left + " " + right);
		}
	}
}
