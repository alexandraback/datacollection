package com.pong;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CookieClickerAlpha {
	
//	static String inputFileName = "Inputs/sample.in.txt";
	static String inputFileName = "Inputs/B-small-attempt0.in.txt";
//	static String inputFileName = "Inputs/B-large-attempt0.in.txt";
	static String outputFileName = "output.txt";
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader br = null;		
		int N = 0;
		
		// read the input from a file
		try {
			br = new BufferedReader(new FileReader(inputFileName));
			
			String line = br.readLine();
			N = Integer.parseInt(line);	
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
		File file = new File(outputFileName);
		if (!file.exists()) {
			try {
				file.createNewFile();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		FileWriter fw = null;
		try {
			fw = new FileWriter(file.getAbsoluteFile());
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		BufferedWriter bw = new BufferedWriter(fw);
		
		// Solve the problem
		double C = 0, F = 0, X = 0;
		double minDuration = 0.0;
		double newFarmDuration = 0.0;
		double cookiePerSecond = 2.0;
		int farmBought = 0;
		
		for (int n = 1; n <= N; n++) {
			try {
				String line = br.readLine();
				String[] values = line.split(" ");
				C = Double.parseDouble(values[0]);
				F = Double.parseDouble(values[1]);
				X = Double.parseDouble(values[2]);
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			
			cookiePerSecond = 2.0;
			farmBought = 0;
			newFarmDuration = 0.0;
			minDuration = X / cookiePerSecond;
			
			double tempDuration = 0.0;
			
			while (tempDuration <= minDuration) {
				// buy farm and check if the duration is less
				newFarmDuration += C / cookiePerSecond;
				cookiePerSecond += F;
				
				tempDuration = newFarmDuration + X / cookiePerSecond;
				if (tempDuration < minDuration) {
					minDuration = tempDuration;				
				}
			}
			
			
			try {
				System.out.println(String.format("Case #%d: %.7f", n, minDuration));
				bw.write(String.format("Case #%d: %.7f\n", n, minDuration));
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		try {
			br.close();
			bw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("done");
	}
	
	public double FindMinimumDuration(double C, double F, double X) {
		
		
		return 0.0;
	}
}
