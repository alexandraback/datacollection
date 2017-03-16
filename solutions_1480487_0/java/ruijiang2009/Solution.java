import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.lang.Math;
import java.util.Arrays;

public class Solution {
	public static int testSize = 0;
	/*
	public static int[] convertString2Nums(int n, String str) {
		int[] result = new int[n];
		
		int begIndex = 0;
		int endIndex = 0;
		
		for(int i = 0; i < n - 1; i++) {
			endIndex = str.indexOf(' ', begIndex);
			result[i] = Integer.parseInt(str.substring(begIndex, endIndex));
			begIndex = endIndex + 1;
		}
		result[n - 1] = Integer.parseInt(str.substring(begIndex, str.length()));
		return result;
	}
	*/
	public static int[] convert2Nums(String str) {
		String[] tmp = str.split(" ");
		int N = tmp.length;
		int[] result = new int[N];
		for(int i = 0; i < N; i++) {
			result[i] = Integer.parseInt(tmp[i]);
		}
		return result;	
	}
	

	public static double[] SafetyNumbers(String input) {
		int[] params = convert2Nums(input);
		int N = params[0];
		int[] J = new int[N];
		for(int i = 0; i < N; i++) {
			J[i] = params[i+1];
		}
		double result[] = new double[N];
		double X = 0; /*sum of points*/
		
		for(int i = 0; i < N; i++) {
			X += (double) J[i];
			result[i] = -1;
		}
		
		double min = 2 * X / (double)N;
		int subSum = 0;
		int minus = 0;
		for(int i = 0; i < N; i++) {
			if(min < J[i]) {
				result[i] = 0.0;
				subSum += J[i];
				minus ++;
			}
		}
		
		double min2 = (2 * X - subSum) / (N - minus); 
		for(int i = 0; i < N; i++) {
			if(-1 == result[i]) {
				result[i] = (min2 - (double)J[i] ) * 100 /X;
			}
		}
		
		return result;
	}

	public static void Output(String inPath, String outPath) {
		try {
			FileInputStream fstream = new FileInputStream(inPath);
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			File of = new File(outPath);
			of.delete();
			BufferedWriter bw = new BufferedWriter(new FileWriter(new File(outPath), true));
			
			String line = br.readLine();
			
			int[] parameters = convert2Nums(line);
			int numOfTest = parameters[0];
			StringBuilder sb;
			String str = new String();
			for(int i = 0; i < numOfTest; i ++) {
				line = br.readLine();
				double[] result = SafetyNumbers(line);
				sb = new StringBuilder();
				int len = result.length;
				sb.append(new String("Case #" + (i+1) + ": "));
				for(int j = 0; j < len; j++) {
					str = String.format("%.5f ", result[j]);
					sb.append(str);
				}
				str = sb.toString();
				System.out.println(str);
				bw.write(str);
				bw.newLine();
			}	 
			
			in.close();
			bw.close();
		} catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}
	
	//public static 
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String inFile  = new String();
		String outFile = new String();
		testSize = 1;
		switch(testSize) {
			case 0:
				inFile = new String("./A-test.in");
				outFile = new String("./A-test.out");
				break;
				
			case 1:
				inFile = new String("./A-small-attempt1.in");
				outFile = new String("./A-small-attempt1.out");
				break;
				
			case 2:
				inFile = new String("./A-large.in");
				outFile = new String("./A-large.out");
				break;
			default:
				break;
		}		
		Output(inFile, outFile);
	}


}
