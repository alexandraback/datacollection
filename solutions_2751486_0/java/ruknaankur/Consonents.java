package com.google.code.jam.thirteen;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Consonents {
	
	public static Set<String> uniqueStrings = new HashSet<String>();
	public static int  offset = 1000000;
	public static Pattern p = Pattern.compile(".*[aeiou]+.*");

public static void main(String[] args) {
			try
		{
			long startTime = System.currentTimeMillis();
			//Reader reader = new FileReader("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\input\\1ca\\sample.in");
			Reader reader = new FileReader("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\input\\1ca\\A-small-attempt0.in");
			//Reader reader = new FileReader("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\input\\1ca\\A-large.in");
			BufferedReader bufReader = new BufferedReader(reader);
			int totalCases = Integer.parseInt(bufReader.readLine().trim());

			//File file = new File("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\output\\1ca\\sample.out");
			File file = new File("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\output\\1ca\\A-small-attempt0.out");
			//File file = new File("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\output\\1ca\\A-large.out");
			FileWriter writer = new FileWriter(file);
			
			for (int i = 1; i <= totalCases; i++)
			{
				String x = bufReader.readLine();
				String[] numbers = x.split(" ");
				
				String L = numbers[0];
				Integer n = Integer.parseInt(numbers[1]);
				//BigInteger A = new BigInteger(numbers[0]);
				//BigInteger B = new BigInteger(numbers[1]);
				
				String res = countNValue(L, n);
				if (i == 1)
					writer.write("Case #"+i+": " + res);
				else
					writer.write("\nCase #"+i+": " + res);
			}
			
			writer.close();
			System.out.println("Total time = " +( System.currentTimeMillis() - startTime));
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}


public static String countNValue(String input, int n){
	BigInteger count = new BigInteger("0");
	if(n == 0){
		return"" +mult(n);
	}
	HashSet<Long> countSet = new HashSet<Long>();
	int len = input.length();
	int prevStart = -1;
	for(int i =0; i <= len-n; i++){
		String subStr = input.substring(i, i+n);
		Matcher matcher =p.matcher(subStr);
        if(!matcher.matches()){
        	//fillSet(i, i+n, len, countSet);
        	int k = i+1;
        	if(prevStart != -1){
        		k -= prevStart;
        	}
        	prevStart = i+1;
        	BigInteger c = new BigInteger(""+(k)).multiply(new BigInteger(""+(len-i-n+1)));
        	count = count.add(c);
        }
	}
	return count.toString()+"";
}

public static BigInteger mult(int n){
	BigInteger i = new BigInteger("2");
	BigInteger two = new BigInteger("2");
	for(int j = 0; j < n; j++){
		i = i.multiply(two);
	}
	return i;
}
/*
private static String countNValue(String name, Integer n) {
	
	String[] arr = name.split("");
	
	int consecutiveConsonents = 0;
	int startIndex = -1;
	int endIndex = 0;
	for (int i=0; i<arr.length; i++)
	{
		if (vowels.contains(arr[i]))
		{
			consecutiveConsonents = 0;
			startIndex = -1;
			endIndex = -1;
		}
		else 
		{
			if (startIndex < 0)
				startIndex = i;
			endIndex = i;
			consecutiveConsonents ++;
		}
		if (consecutiveConsonents == n)
		{
			// store start & end index;
			consecutiveConsonents = 0;
			startIndex = -1;
		}
	}
	
	return null;
}
*/
}
