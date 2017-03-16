package firstB;

import java.io.*;
import java.util.*;

public class P1 {
	public static final String filename = "A-small-attempt1";
	public static Scanner in;
	public static PrintStream out;

	public static void main(String[] args) throws Exception {
		in = new Scanner(new File(filename + ".in"));
		out = new PrintStream(new FileOutputStream(filename + ".out"));
		
		int num = Integer.parseInt(in.nextLine());
		for (int i = 1; i <= num; i++) {
			int n = Integer.parseInt(in.nextLine());
			int res = solve(n);
			print("Case #" + i + ": " + res);
		}
		in.close();
		out.close();
	}
	
	public static int solve(int n) {
		int[] arr = new int[n + 1];
		for (int i = 0; i <= n; i++)
			arr[i] = i;
		
		for (int i = 1; i <= n; i++) {
			int count = arr[i - 1];
			if (arr[i] > count)
				arr[i] = count + 1;
			int num = arr[i];
			int x = flip(i);
			if (x <= n && x > i && arr[x] > arr[i])
				arr[x] = num + 1;
		}
		return arr[n];
	}
	
	public static int flip(int n) {
		String s = "" + n;
		String ns = "";
		for (int i = 0; i < s.length(); i++)
			ns += s.charAt(s.length() - i - 1);
		
		return Integer.parseInt(ns);
	}
	
	public static void print(String s) {
		System.out.println(s);
		out.println(s);
	}
}
