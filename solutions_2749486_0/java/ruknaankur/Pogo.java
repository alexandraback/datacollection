package com.google.code.jam.thirteen;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.math.BigInteger;

public class Pogo {
	
	public static final int  N = 1;
	public static final int  S = -1;
	public static final int  E = 1;
	public static final int  W = -1;
	

public static void main(String[] args) {
		
		try
		{
			long startTime = System.currentTimeMillis();
			//Reader reader = new FileReader("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\input\\1cb\\sample.in");
			Reader reader = new FileReader("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\input\\1cb\\B-small-attempt1.in");
			//Reader reader = new FileReader("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\input\\1cb\\B-large.in");
			BufferedReader bufReader = new BufferedReader(reader);
			int totalCases = Integer.parseInt(bufReader.readLine().trim());

			//File file = new File("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\output\\1cb\\sample.out");
			File file = new File("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\output\\1cb\\B-small-attempt1.out");
			//File file = new File("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\output\\1cb\\B-large.out");
			FileWriter writer = new FileWriter(file);
			
			for (int i = 1; i <= totalCases; i++)
			{
				String x = bufReader.readLine();
				String[] numbers = x.split(" ");
				Integer X = Integer.parseInt(numbers[0]);
				Integer Y = Integer.parseInt(numbers[1]);
				
				String res = getMovesToReach(X, Y);
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


private static String getMovesToReach(Integer x, Integer y) {
	int totalMovesInX = 2*(Math.abs(x) - 1) + 1;
	
	String moves = "";
	
	String nextMove = "";
	if (x > 0)
	{
		// start with W
		nextMove = "E";
	}
	else 
	{
		// start With E
		nextMove = "W";
	}
	
	for (int i =0; i< totalMovesInX; i++)
	{
		moves = moves + nextMove;
		nextMove = nextMove.equals("W") ? "E" : "W";
	}
	
	int totalMovesInY = 2*(Math.abs(y)) ;
	nextMove = "";
	
	if (y > 0)
	{
		// start with N
		nextMove = "S";
	}
	else 
	{
		// start With S
		nextMove = "N";
	}
	
	for (int i =0; i< totalMovesInY; i++)
	{
		moves = moves + nextMove;
		nextMove = nextMove.equals("N") ? "S" : "N";
	}
	
	return moves;
}
}
