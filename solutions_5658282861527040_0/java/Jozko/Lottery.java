package bround;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Lottery {
	static final String inFile = "B-small-attempt0.in";
	static final String outFile = "B-small-attempt0OUT.txt";
	static Scanner scanner;
	static PrintWriter writer;
	
	public static void main(String[] args) throws IOException{
		scanner = new Scanner(new File(inFile));
		writer = new PrintWriter(new File(outFile));
		int numOfTests = scanner.nextInt();
		for(int i = 0; i < numOfTests; i++){
			writer.print("Case #"+(i+1)+": ");
			solve(i+1);
		}
		writer.flush();
		scanner.close();
		writer.close();
		
	}
	public static void solve(int caseNum){
		long A = scanner.nextLong();
		long B = scanner.nextLong();
		long K = scanner.nextLong();
		
		long ans = 0;
		long and = 0;
		for (int a = 0; a < A; a++)
			for (int b = 0; b < B; b++){
				and = a&b;
				if (and >= 0 && K > and) ans++;
			}
		System.out.println(ans);
		writer.println(ans);
				
		
		
		
	}
}
