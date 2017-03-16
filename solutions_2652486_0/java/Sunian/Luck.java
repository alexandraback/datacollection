package Round1A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class Luck {
	static int M = 999999;
	public static void main(String[] args) {
		FileWriter fstream = null;
		try {
			fstream = new FileWriter("B.txt");
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		  BufferedWriter out = new BufferedWriter(fstream);
		  

		Scanner input = null;
		try {	input = new Scanner(new File("bin\\Round1A\\C-small-1-attempt2.in"));	} catch (FileNotFoundException e) {		e.printStackTrace();	}
		input.nextLine();
		String[] s = input.nextLine().split(" ");
		int R = Integer.parseInt(s[0]);
		int N = Integer.parseInt(s[1]);
		M = Integer.parseInt(s[2]);
		int K = Integer.parseInt(s[3]);
		System.out.println("Case #" + 1 + ": ");
		for (int i = 1; i <= R; i++) {
			s = input.nextLine().split(" ");
//			HashSet<String> guessed = new HashSet<String>();
			int products[] = new int[K];
			int guess[] = new int[N];
			for (int j = 0; j < K; j++) {
				products[j] = Integer.parseInt(s[j]);
			}
			for (int j = 0; j < N; j++) {
				guess[j] = 2;
			}
			boolean ok = true;
			do {
				ok = true;
				for (int j = 0; j < K; j++) {
					if (!tryGuess(guess, products[j])){
						ok = false;
						break;
					}
				}
				if (ok) break;
//				System.out.println(Arrays.toString(guess));
			} while (incrementGuess(guess, 0));
//			try {
//				out.write("Case #" + i + ": " + sqrt.toString() + "\n");
//			} catch (IOException e1) {
//				e1.printStackTrace();
//			}
//			Arrays.sort(products);
			System.out.println(guess[0] + "" + guess[1] + "" + guess[2]);
		}
	}
	static boolean incrementGuess(int[] guess, int index){
		if (index >= guess.length) return false;
		guess[index]++;
		if (guess[index] > M){
			if (!incrementGuess(guess, index + 1)) return false;
			guess[index] = guess[index + 1];
		}
		return true;
	}
	static boolean tryGuess(int[] guess, int product){
		if (product < 2) return true;
		return 	(guess[0] == product) ||
				(guess[1] == product) ||
				(guess[2] == product) ||
				(guess[0]*guess[1]*guess[2] == product) ||
				(guess[0]*guess[1] == product) ||
				(guess[2]*guess[1] == product) ||
				(guess[2]*guess[0] == product )
				;
	}
	static ArrayList<Integer> getFactors(int p){
		ArrayList<Integer> factors = new ArrayList<Integer>();
		for (int i = 2; i <= M; i++) {
			if (p%i == 0) factors.add(i);
		}
		return factors;
	}
}
