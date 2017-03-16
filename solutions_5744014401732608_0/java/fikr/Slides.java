// Google Code Jam Round 1C 2016
// Problem B. Slides!

import java.util.*;
import java.io.*;

public class Slides{
	//static String filename = "B-sample";			// io filename here, change accordingly
	static String filename = "B-small-attempt1";	
	//static String filename = "B-large";	
	static String inname = filename + ".in";    
	static String outname = filename + ".out";  
	public static void main(String[] args){
		try{
			Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
			//Scanner in = new Scanner(System.in);
			BufferedWriter out = new BufferedWriter(new FileWriter(outname));
			int t = in.nextInt();
			in.nextLine();
			for (int cas = 1; cas <= t; cas++){
				int b = in.nextInt();
				long m = in.nextLong();
				int[][] mat = solve(b,m);
				String ans ="";
				if (mat == null) ans = "IMPOSSIBLE";
				else ans = "POSSIBLE\n" + print(mat);
				System.out.print("Case #" + cas + ": " + ans + "\n");
				out.write("Case #" + cas + ": " + ans + "\n");
			}
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	private static int[][] solve(int b, long m) {
		//System.out.println(twoPow(b-2));
		if (m > twoPow(b-2)) return null;
		int[][] ret = new int[b][b];
		for (int i = 0; i < b; i++){
			for (int j = i+1; j < b; j++){
				if (i<j) ret[i][j] = 1;
			}
		}
		long toRem = twoPow(b-2)-m;
		long d = twoPow(b-2);
		int pt = 0;
		while (toRem > 0){
			if (toRem >= d){
				ret[0][pt] = 0;
				toRem -= d;
			}
			if (d > 1) d>>=1;
			pt++;
		}
		return ret;
	}
	private static String print(int[][] mat) {
		String ret = "";
		int n = mat.length;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				ret += mat[i][j];	
			} if (i < n-1) ret += "\n";
		}
		return ret;
	}
	private static long twoPow(int n){
		return 1L << n;
	}
}