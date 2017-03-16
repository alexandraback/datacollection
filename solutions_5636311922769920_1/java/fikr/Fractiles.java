// Google Code Jam Qualification Round 2016
// Problem D. Fractiles

import java.util.*;
import java.io.*;

public class Fractiles{
	//static String filename = "D-small-attempt0";	// io filename here, change accordingly
	static String filename = "D-large";	
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
				int k = in.nextInt();
				int c = in.nextInt();
				int s = in.nextInt();
				ArrayList<Long> ret = solve(k, c, s);
				String ans = "";
				if (ret == null || ret.size() == 0) ans = "IMPOSSIBLE";
				else {
					for (int i = 0; i < ret.size(); i++){
						ans += (ret.get(i) + " ");
					}
				}
				System.out.print("Case #" + cas + ": " + ans + "\n");
				out.write("Case #" + cas + ": " + ans + "\n");
			}
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private static ArrayList<Long> solve(int k, int c, int s) {
		if (s < k/c) return new ArrayList<Long>();
		ArrayList<Long> ret = new ArrayList<Long>(k/c);
		long i = 0;
		while (i < k){
			long curr = 0;
			for (int j = 0; j < c; j++){
				curr += i*(pow(k, j));
				i++;
				if (i >= k) break;
			}
			ret.add(curr+1);
		}
		return ret;
	}

	private static long pow(long a, long b) {
		if (b == 0) return 1;
		else if (b == 1) return a;
		long res = 1;
		for (long i = 1; i <= b; i++)
			res *= a;
		return res;
	}
}