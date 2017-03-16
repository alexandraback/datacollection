import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class FairAndSquare {
	public static Integer[] sqrt = new Integer[1001];
	public static boolean[] squares = new boolean[1001];
	public static Boolean[] palindromes = new Boolean[1001];
	
	public static void main(String args[]) throws IOException {
		Scanner scin = new Scanner(new File("in3.txt"));
		FileWriter fw = new FileWriter(new File("out3.txt"));
		
//		System.out.println(Math.sqrt(Math.pow(10, 14)) < Integer.MAX_VALUE);
//		
//		boolean b[] = new boolean[10000000];
		
		for (int i = 1; i <= Math.sqrt(1000); i++) {
			if (i*i < 1001) {
				squares[i*i] = true;
				sqrt[i*i] = i;
			}
		}
		
		for (int i = 1; i < 1001; i++) {
			if (i % 10 == 0) {
				palindromes[i] = false;
			}
		}
		
		for (int i = 0; i < 10; i++) {
			palindromes[i] = true;
		}

		int T = scin.nextInt();
		
		for (int cs = 1; cs < T+1; cs++) {
			long A = scin.nextLong();
			long B = scin.nextLong();
			
//			System.out.println("=====");
			
			int ctr = 0;
			for (long start = A; start <= B; start++) {
				if (squares[(int)start]) {
					if (sqrt[(int)start] != null){
						if (isPalindrome(sqrt[(int)start])) {
							if (isPalindrome(start)) {
								ctr++;
	//							System.out.println("P");
							}
						}
					}
//					System.out.println(start);
				}
			}
			
			fw.write("Case #" + cs + ": " + ctr + "\n");
		}
		
		fw.close();
	}

	private static boolean isPalindrome(long start) {
		if (palindromes[(int)start] != null) {
			return palindromes[(int)start];
		}
		
		palindromes[(int)start] = isPalindrome(""+start);
		
		return palindromes[(int)start];
	}

	private static boolean isPalindrome(String string) {
		for (int i = 0; i < string.length()/2; i++) {
			if (string.charAt(i) != string.charAt(string.length()-i-1)) {
				return false;
			}
		}
		
		return true;
	}
}
