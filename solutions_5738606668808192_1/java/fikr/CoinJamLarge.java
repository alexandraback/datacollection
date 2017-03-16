// Google Code Jam Qualification Round 2016
// C. Coin Jam

import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class CoinJamLarge{
	//static String filename = "C-small-attempt00";	// io filename here, change accordingly
	static String filename = "C-large";
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
		for (long i = start; i < end; i+=2){
			if (isProbableJamCoin(i)){
				boolean isJamCoin = true;
				String bin = Long.toBinaryString(i);
				String line = (bin + " ");
				for (int k = 2; k <= 10; k++){
					BigInteger num = new BigInteger(bin, k);
					BigInteger factor = findFactor(num);
					if (factor.compareTo(BigInteger.ZERO) < 0){
						//System.out.println("Skip " + bin);
						isJamCoin = false;
						break;
					}
					else line += (factor + " ");
				}
				if (isJamCoin){
					count++;
					line += "\n";
					ret += line;
					System.out.print(line);
				}
			}
			if (count >= j) break;
		}
		return ret;
	}

	private static BigInteger findFactor(BigInteger a) {
		BigInteger two = BigInteger.valueOf(2);
		if (a.compareTo(two) <= 0) return BigInteger.ONE.negate();
		else if (a.mod(two).compareTo(BigInteger.ZERO) == 0) return two;
		for (BigInteger i = BigInteger.valueOf(3); i.multiply(i).compareTo(a) <= 0; i = i.add(two)){
			if (a.mod(i).compareTo(BigInteger.ZERO) == 0) return i;
			else if (i.compareTo(BigInteger.valueOf(1000000)) > 0) return BigInteger.ONE.negate();
		}
		return BigInteger.ONE.negate();
	}

	private static boolean isProbableJamCoin(long a) {
		String bin = Long.toBinaryString(a);
		for (int i = 2; i <= 10; i++){
			BigInteger num = new BigInteger(bin, i);
			if (num.isProbablePrime(100)) return false;
		}
		return true;
	}
}