package y2015.Round1B;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.Scanner;

public class ProbA {

	private static Reader in;
	private static PrintWriter out;	
	public static final String NAME = "A-small-practice.in";
	//public static final String NAME = "test.in";
	public static final String OUTNAME = "output.out";
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader(NAME));
		BufferedWriter bw = new BufferedWriter(new FileWriter(OUTNAME));
		
		int[] dp = new int[1000100];
		
		dp[0] = 0;
		
		for (int i = 1; i < dp.length; i++) {
			
			int reverse = reverse(i);
			int reOfre = reverse(reverse);
			if (reverse < i-1 && reverse >= 0 && reOfre == i) {
				dp[i] = Math.min(dp[i-1]+1, dp[reverse]+1);
			} else {
				dp[i] = dp[i-1]+1;
			}
			
		}
		
		String output = "";
		int cases = Integer.valueOf(sc.nextLine());
		for (int c = 1; c <= cases; c++) {
			output += "Case #" + c + ": ";
			
			int N = sc.nextInt();
			//System.out.println("N: " + N);			
			int result = dp[N];

			//System.out.println(result);
			//int result = 0;
			output += result + "\n";
			
			if (sc.hasNext()) sc.nextLine();
		}		
		bw.write(output);
		bw.close();
	}
	
	/*
	public static int recurse(int current, int target, int counts) {
		
		if (current == target) {
			return counts;
		}
		
		if (current > target) {
			return Integer.MAX_VALUE;
		}
		
		int reverse = reverse(current);
		
		if (reverse > current+1 && reverse <= target) {
			int newCount = counts;
			return Math.min(recurse(current+1, target, ++newCount), recurse(reverse, target, ++counts));
		} else {
			return recurse(current+1, target, ++counts);
		}
		
	}
	*/
	
	public static int reverse(int n) {
		int reverse = 0;
		while( n != 0 )
	      {
	          reverse = reverse * 10;
	          reverse = reverse + n%10;
	          n = n/10;
	      }
		return reverse;
	}

	public static class ArrayUtil {
		
		public static void printArray(int[] arr, int size) {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < arr.length; i++) {
				if (i > 0) {
					sb.append(",");
				}
				
				int padding = size - String.valueOf(arr[i]).length();
				while (padding > 0) {
					sb.append(" ");
				}				
				sb.append(arr[i]);
			}
			System.out.println(sb);
		}
		
		public static void printArray(float[] arr, int size) {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < arr.length; i++) {
				if (i > 0) {
					sb.append(",");
				}
				
				int padding = size - String.valueOf(arr[i]).length();
				while (padding > 0) {
					sb.append(" ");
					padding--;
				}				
				sb.append(arr[i]);
			}
			System.out.println(sb);
		}		
		
		public static int bitToInt(String num) {
			int result = 0;
			int length = num.length();
			for (int i = 0; i < length; i++) {
				int pow = length - 1 -i;
				if (i == length - 1) {
					result += Integer.valueOf(String.valueOf(num.charAt(length - 1)));
				} else {
					result += (int) Math.pow(2, length - 1 - i);	
				}
			}
			return result;
		}		
		
	}		

}
