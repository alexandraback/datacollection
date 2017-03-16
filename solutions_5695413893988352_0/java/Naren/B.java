import java.lang.*;
import java.util.*;
import java.io.*;

public class B {
	private static final String prefix = "C:\\Users\\sivasub\\Downloads\\".replace("\\", "/");
	private static final String fileName = prefix + "B-small-attempt0";
	
	public static int getNumber(char[] A, int n, int a, int b, int c) {
		int singles = A[n-1] == '?' ? c : A[n-1] - '0';
		
		int tens = 0;
		
		if(n>1) {
			tens = A[n-2] == '?' ? b : A[n-2] - '0';
		}
		
		int hundreds = 0;
		if(n>2) {
			hundreds = A[n-3] == '?' ? a : A[n-3] - '0';
		}
		
		return hundreds * 100 + tens * 10 + singles;
	}
	
	
	public static void main(String args[]) throws Exception {

		try(InputStream input = new FileInputStream(fileName + ".in");
			Scanner sc = new Scanner(input);
			PrintStream output = new PrintStream(fileName + ".out")) {
			
			int T = sc.nextInt();
			
			for(int t = 1; t <= T; t++) {
				//Input
				char[] A = sc.next().toCharArray();
				char[] B = sc.next().toCharArray();
				int n = A.length;
				int bestX = 1000, bestY = 10000000;
				for(int a = 0; a < 10; a++) {
					for(int b = 0; b < 10; b++) {
						for(int c = 0; c < 10; c++) {
							for(int d = 0; d < 10; d++) {
								for(int e = 0; e < 10; e++) {
									for(int f = 0; f < 10; f++) {
										int X = getNumber(A, n, a, b, c);
										int Y = getNumber(B, n, d, e, f);
										if(Math.abs(bestY - bestX) >= Math.abs(Y - X)) {
											
											if(Math.abs(bestY - bestX) == Math.abs(Y - X)) {
												if(bestX >=X) {
													if(bestX == X) {
														if(bestY > Y ) {
															bestX = X;
															bestY = Y;
														}
													} else {
														bestX = X;
														bestY = Y;
													}
												}
											} else {
												bestX = X;
												bestY = Y;
											}
										}
									}
								}
							}
						}
					}
				}
				
				//Output
				output.println("Case #" + t + ": " + String.format("%0" + n + "d", bestX) + " " + String.format("%0" + n + "d", bestY));
			}
		}
	}
}
