package es.hlastras.gcj2016.round1c;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class R1C2016C{
	
	private static String INPUT_FILE = "test.txt";
//	private static String INPUT_FILE = ".in";
	private static String OUTPUT_FILE = ".out";

	public static void main(String[] args) throws Exception {		
		
		System.out.println("Starting");
		long init = System.currentTimeMillis();
		new R1C2016C().execute();
		long end = System.currentTimeMillis();
		System.out.println("End");
		System.out.println("Time: "+(end-init)+" miliseconds");

	}

	
	public void execute() throws Exception {
		BufferedReader input = new BufferedReader(new FileReader(INPUT_FILE));
		PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILE));
		Scanner sc = new Scanner(input);
		
		String result = "";
		
		int cases = sc.nextInt();		
		for (int i = 0; i < cases; i++) {
			result = "";
			
			
			
			System.out.println("Case #"+(i+1)+": "+result);
			output.println("Case #"+(i+1)+": "+result);
		}
		
		
		
		sc.close();
		input.close();
		output.close();	
	}
}
