package online;
import java.io.*;
import java.util.Scanner;


public class Q2 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("/Users/jonyzfu/Documents/B-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new FileWriter("/Users/jonyzfu/Documents/B-small-attempt2.out"));
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) {
			int d = in.nextInt();
			int[] arr = new int[d];
			int res = -1;
			for (int j = 0; j < d; j++) {
				arr[j] = in.nextInt();
				res = Math.max(res, arr[j]);
				
			}
			res = pancake(res, arr);
			out.println("Case #"+i+": "+res);
		}
		in.close();
		out.close();
	}
	
	public static int pancake(int res, int[] arr) {
		int base = 2;
		while (base < res) {
			int sum = 0;
			for (int i = 0; i < arr.length; i++) {
				sum += Math.floor((double)(arr[i] - 1) / (double)base);
				sum += base;
			}
			res = Math.min(res, sum);
			base += 1;
		}
		
		return res;
	}
}