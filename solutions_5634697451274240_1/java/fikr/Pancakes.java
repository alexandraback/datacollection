// Google Code Jam Qualification Round 2016
// Problem B. Revenge of the Pancakes

import java.util.*;
import java.io.*;

public class Pancakes{
	//static String filename = "B-small-attempt0";	// io filename here, change accordingly
	static String filename = "B-large";	
	static String inname = filename + ".in";    
	static String outname = filename + ".out";  
	static int n;
	public static void main(String[] args){
		try{
			Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
			//Scanner in = new Scanner(System.in);
			BufferedWriter out = new BufferedWriter(new FileWriter(outname));
			int t = in.nextInt();
			in.nextLine();
			for (int cas = 1; cas <= t; cas++){
				String input = in.next();
				int n = input.length();
				boolean[] st = new boolean[n];
				for (int i = 0; i < n; i++){
					if (input.charAt(i) == '-') st[i] = false;
					else st[i] = true;
				}
				int ans = solve(st);
				System.out.print("Case #" + cas + ": " + ans + "\n");
				out.write("Case #" + cas + ": " + ans + "\n");
			}
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private static int solve(boolean[] st) {
		int ans = 0;
		int n = st.length;
		for (int i = n-1; i >= 0; i--){
			if (st[i]) continue;
			else { 
				flip(st, i);
				ans++;
			}
		}
		return ans;
	}
	
	private static void flip(boolean[] st, int i) {
		for (int j = 0; j <= i; j++)
			st[j] = !st[j];
	}
}