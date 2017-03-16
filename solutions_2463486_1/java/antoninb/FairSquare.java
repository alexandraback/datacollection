package qualifs;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Scanner;

public class FairSquare {
	
	public static int max = 7;
	public static LinkedList<Long> squares = new LinkedList<Long>();
	
	public static boolean testPalindrome(long x){
		char[] chars = String.valueOf(x).toCharArray();
		for(int i = 0; i < chars.length / 2; i++){
			if(chars[i] != chars[chars.length - 1 - i]) return false;
		}
		return true;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int length = max / 2;
		int base = (int) Math.pow(10, length);
		for(int i = 0; i < base; i++){
			String middle = "";
			for(int j = -1; j <= 9; j++){
				if(j >= 0) middle = j + "";
				String b = "";
				if(i != 0) b = i + "";
				
				String e = "";
				for(int k = b.length() - 1; k >= 0; k--){
					e += b.charAt(k);
				}
				
				String pal = b + middle + e;
				if(pal.equals("")) continue;
				
				long num = Long.parseLong(pal);
				
				long square = num * num;
				
				if(testPalindrome(square)){
					squares.add(square);
				}
			}
		}
		
		String fileName = "../C-large-1.in";
		Scanner sC = null;
		try {
			sC = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		sC.useLocale(Locale.US);
		
		int T = sC.nextInt();
		long A, B;
		int nb;
		
		for(int t = 0; t < T; t++){
			A = sC.nextLong();
			B = sC.nextLong();
			nb = 0;
			
			for(long square: squares){
				if(square >= A && square <= B) nb++;
			}
			
			System.out.println("Case #" + (t + 1) + ": " + nb);
		}

	}

}
