import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class First {
	static final String[] digits = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	public static void main(String[] args) throws FileNotFoundException{
		String name = "a-small-attempt0";
		Scanner in = new Scanner(new File(name + ".in"));
		PrintWriter out = new PrintWriter(new File(name + ".out"));
		int tc = in.nextInt();
		for(int i = 1; i <= tc; i++){
			String s = in.next();
			int[] freq = new int[26];
			for(int j = 0; j < s.length(); j++){
				freq[s.charAt(j) - 'A']++;
			}
			out.println("Case #" + i + ": " + solve(freq, 0));
		}
		out.close();
	}
	
	public static String solve(int[] freq, int ind){
		if(isEmpty(freq)){
			return "";
		}
		if(ind == 10){
			return null;
		}
		String res = "";
		String ret = solve(freq, ind + 1);
		if(ret != null) return ret;
		out:
		while(true){
			int[] copy = Arrays.copyOf(freq, freq.length);
			for(int i = 0; i < digits[ind].length(); i++){
				if(copy[digits[ind].charAt(i) - 'A']==0){
					break out;
				}
				copy[digits[ind].charAt(i) - 'A']--;
			}
			freq = copy;
			res += ind;
			String ret1 = solve(freq, ind + 1);
			if(ret1 != null){
				return res + ret1;
			}
		}
		return null;
	}
	
	public static boolean containsZero(int[] ar){
		for(int i = 0; i < ar.length; i++){
			if(ar[i] == 0){
				return true;
			}
		}
		return false;
	}
	
	public static boolean isEmpty(int[] ar){
		for(int i = 0; i < ar.length; i++){
			if(ar[i] > 0){
				return false;
			}
		}
		return true;
	}
}
