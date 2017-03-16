// Google Code Jam Qualification Round 2016
// C. Coin Jam

import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class CoinJam{
	static String filename = "C-small-attempt0";	// io filename here, change accordingly
	//static String filename = "C-large";
	//static String filename = "C-sample";	
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
				int n = in.nextInt();
				int j = in.nextInt();
				String ans = solve(n, j);
				//System.out.print("Case #" + cas + ": \n" + ans + "\n");
				out.write("Case #" + cas + ": \n" + ans + "\n");
			}
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private static String solve(int n, int j) {
		String ret = "";
		int count = 0;
		long start = (1L<<(n-1))+1;
		long end = 1L<<n;
		//System.out.println(start + " " + end);
		for (long i = start; i < end; i+=2){
			if (isJamCoin(i)){
				count++;
				String bin = Long.toBinaryString(i);
				String line = (bin + " ");
				for (int k = 2; k <= 10; k++){
					BigInteger num = new BigInteger(bin, k);
					line += (findFactor(num.longValue()) + " ");
				}
				line += "\n";
				ret += line;
				//System.out.print(line);
			}
			if (count >= j) break;
		}
		return ret;
	}

	private static long findFactor(long a) {
		if (a <= 2) return -1;
		else if (a%2 == 0) return 2;
		for (long i = 3; i*i <= a; i+=2L){
			if (a%i == 0) return i;
		}
		return -1;
	}

	private static boolean isJamCoin(long a) {
		String bin = Long.toBinaryString(a);
		for (int i = 2; i <= 10; i++){
			BigInteger num = new BigInteger(bin, i);
			if (isPrime(num.longValue())) return false;
		}
		return true;
	}

	private static boolean isPrime(long a) {
		if (a < 2) return false;
		else if (a == 2) return true;
		else if (a%2 == 0) return false;
		for (long i = 3; i*i <= a; i+=2){
			if (a%i == 0) return false;
		}
		return true;
	}
}