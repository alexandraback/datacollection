// Google Code Jam Round 1B 2015
// Problem A. Counter Culture

import java.util.*;
import java.io.*;

public class CounterCulture{
	static String filename = "A-large";	// io filnename here
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
				long n = in.nextLong();
				long ans = countTo(n); 
				System.out.print("Case #" + cas + ": " + ans + "\n");
				out.write("Case #" + cas + ": " + ans + "\n");
			}
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	private static long countTo(long n){
		if (n < 10) return n;
		else if (n%10 == 0) return countTo(n-1)+1;
		long t = 10;
		long ret = 0;
		if (n >= 10) ret += 9;
		while (n > t*10){
			int l = (""+t).length()-1;
			long nextFlip = 1;
			int i = 0;
			for (; i < l/2; i++)
				nextFlip *= 10;
			for (; i < l; i++){
				nextFlip *= 10;
				nextFlip += 9;
			}
			long nines = 9;
			for (i = 0; i < l; i++){
				nines *= 10;
				nines += 9;
			}
			ret += nines-flip(nextFlip)+nextFlip-t+2;
			//System.out.println(ret + " " + nines + " " + flip(nextFlip) + " " + nextFlip + " " + t);
			t *= 10;
		}
		//if ((n+"").charAt(0) == '1' || n%10 == 0) ret += n-t+1;
		//else {
		int l = (""+n).length();
		int mid = 1;
		for (int i = 0; i < l/2; i++){
			mid *= 10;
		}
		long addret = n%mid;
		addret += flip(n/mid)+1;
		ret += Math.min(n-t+1, addret);
		//}
	return ret;
	}

	private static long flip(long n){
		long ret = 0;
		while(n > 0){
			long d = n%10;
			n /= 10;
			ret *= 10;
			ret += d;
		}
		return ret;
	}
}