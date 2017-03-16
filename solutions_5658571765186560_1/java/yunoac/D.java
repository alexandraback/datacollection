package QR;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {

	static PrintWriter writer;

	public static void main(String[] args) throws IOException {
		writer = new PrintWriter(new FileWriter("out"));
		Scanner reader = new Scanner(new FileReader("in"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			int X = reader.nextInt();
			int R = reader.nextInt();
			int C = reader.nextInt();
			boolean canDo = solveBig(X, Math.min(R, C), Math.max(R, C));
			System.out.println(canDo);
			writer.printf("Case #%d: %s\n", tc, canDo ? "GABRIEL" : "RICHARD");
		}
		writer.close();
		reader.close();
	}
	
	static boolean solveBig(int X, int R, int C) {
		if(X == 1) return true;
		if(X == 2) return R * C % 2 == 0;
		if(X == 3) return R * C % 3 == 0 && R >= 2;
		if(X == 4) return R * C % 4 == 0 && R >= 3;
		if(X == 5) return R * C % 5 == 0 && R >= 3 && !(R == 3 && C == 5);
		if(X == 6) return R * C % 6 == 0 && R >= 4;
		return false;
	}
	
	/*
	static boolean solveSmall(int X, int R, int C) {
		if(R == 1 && C == 1) return X <= 1;
		if(R == 1 && C == 2) return X <= 2;
		if(R == 1 && C == 3) return X <= 1;
		if(R == 1 && C == 4) return X <= 2;
		if(R == 2 && C == 2) return X <= 2;
		if(R == 2 && C == 3) return X <= 3;
		if(R == 2 && C == 4) return X <= 2;
		if(R == 3 && C == 3) return X == 1 || X == 3;
		if(R == 3 && C == 4) return true;
		if(R == 4 && C == 4) return X <= 2 || X == 4;
		System.out.println("shit happens: " + R + " " + C);
		return false;
	}
	*/
	
}
